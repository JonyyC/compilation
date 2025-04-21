%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
int yylex(void);
int  yyerror(const char *s);
// Declaring expression operators for the parser.
const char *exp_literals[] = {
    "+", "-", "*", "/", ">", "<", "==", ">=", "<=", "!=", "and", "or", "not", "||", "[]", "*id", "&id", "*()", "&[]"
};
typedef struct node
{
    char *token;
    int num_nodes;
    struct node **nodes;
} node;
node *mknode(char *token, int num, ...);
void print_tree(node *tree, int iden);
void print_pars(node *tree, int iden);
void print_func(node* tree, int iden);
void print_exp_operator(node *tree, int iden);
void print_state_placement(node *tree, int iden);
void print_state_placement_str(node *tree, int iden);
void print_ret(node *tree, int iden);
void print_decleration(node *tree, int iden);
void print_ids(node *tree, int iden);
void print_ids_str(node *tree, int iden);
void print_elifs(node *tree, int iden);
 
int is_operator(const char *token);
void print_spaces(int iden);
char *yytext;
typedef union {
    struct node *node;
    char *str;
    int i;
    float f;
} YYSTYPE;
#define  YYSTYPE_IS_DECLARED 1
// HOW TO ADD RET_NONE ?
// %token == >= <= != 
// printtree($1, 0);
%}

%token BOOL_TOK CHAR_TOK INT_TOK REAL_TOK STRING_TOK INT_PTR CHAR_PTR REAL_PTR PAR
%token BOOL CHAR INT REAL STRING
%token VOID ID
%token IF ELIF ELSE 
%token  WHILE FOR DO

%token VAR BEG END DEF CALL NULL_TOK RETURN RETURNS type
%token AND NOT OR

%token EQ GE LE NE

%left OR
%left AND
%left '>' '<' EQ GE LE NE

%left '+' '-'
%left '*' '/'

%%
program: funcs {$$.node = mknode("PROGRAM",1, $1); print_tree($$.node, 0);};
funcs: func {$$.node  = mknode("",1, $1);}
        | func funcs {$$.node  = mknode("",2, $1, $2);}
        | {$$.node = mknode("EMPTY-PROGRAM",0);};

func: DEF ID '(' parameter_list ')' ':' ret_type func_body {$$.node  = mknode("FUNC",4, $2, $4, $7, $8);};

parameter_list: PAR TYPE_TOK ':' ID ';' parameter_list {printf("the ID in the yacc file is : %s and the par is : %s\n", $4.node->token, $1.node->token); $$.node = mknode("PARS",4, $1, $2, $4, $6);}
        | PAR TYPE_TOK ':' ID {$$.node  = mknode("PARS",4, $1, $2, $4, NULL);}
        | {$$.node  = mknode("PARS NONE",0);};

ret_type: RETURNS TYPE_TOK { char *label = (char *)malloc(strlen("RET ") + strlen($2.node->token) + 1); sprintf(label, "RET %s", $2.node->token); $$.node  = mknode(label,0); free(label);}
        | {$$.node  = mknode("RET_NONE",0);};

TYPE_TOK: BOOL_TOK {$$.node = $1.node;}| CHAR_TOK {$$.node = $1.node;}| INT_TOK {$$.node = $1.node;}| REAL_TOK {$$.node = $1.node;}| STRING_TOK {$$.node = $1.node;}
        | INT_PTR {$$.node = $1.node;}| CHAR_PTR {$$.node = $1.node;}| REAL_PTR {$$.node = $1.node;} ;

TYPE_VALUE: BOOL {$$.node = $1.node;}| CHAR {$$.node = $1.node;}| INT {$$.node = $1.node;}| REAL {$$.node = $1.node;} | STRING {$$.node = $1.node;};

func_body: VAR declarations BEG code_body ret END {$$.node  = mknode("DECL",2, $2, mknode("BODY",2, $4, $5));}
        | BEG code_body ret END {$$.node  = mknode("BODY",2, $2, $3);};

ret: RETURN expression ';' {$$.node = mknode("RET ",1, $2);}
        | {$$.node = NULL;};

declarations: type TYPE_TOK ':' IDS ';' declarations {$$.node = mknode("", 3, $2, $4, $6);}
        | type TYPE_TOK ':' IDS ';' {$$.node = mknode("", 3, $2, $4, NULL);}
        | type STRING_TOK ':' IDS_S ';' declarations {$$.node = mknode("string", 3, $2, $4, $6);}
        | type STRING_TOK ':' IDS_S ';' {$$.node = mknode("string", 3, $2, $4, NULL);}
        | {$$.node = NULL;};

IDS: ID ':' TYPE_VALUE ',' IDS {$$.node = mknode("", 3, $1, $3, $5);}
        | ID ':' TYPE_VALUE {$$.node = mknode("VAL", 2, $1, $3);}
        | ID ',' IDS {$$.node = mknode("", 2, $1, $3);}
        | ID {$$.node = $1.node;};

IDS_S: ID '[' INT ']' ':' STRING ',' IDS_S {$$.node = mknode("", 4, $1, $3, $6, $8);} 
        | ID '[' INT ']' ':' STRING {$$.node = mknode("VAL", 3, $1, $3, $6);}
        | ID '[' INT ']' ',' IDS_S {$$.node = mknode("", 3, $1, $3, $6);}
        | ID '[' INT ']' {$$.node = mknode("", 2, $1, $3);} ; 

code_body: statements {$$.node = $1.node;}

statements: statement statements {$$.node = mknode("",2, $1, $2);}
        | statement {$$.node = mknode("",2, $1, NULL);}
        | {$$.node = NULL;};

statement: ID '=' expression ';' {$$.node = mknode("=",2, $1, $3);}
        | ID '=' function_call ';' {$$.node = mknode("=",2, $1, $3);}
        | ID '[' expression ']' '=' expression ';' {$$.node = mknode("[]=",3, $1, $3,$6);} // Only for string! e.g. str[4 + 5] = 'a';
        | ID '[' expression ']' '=' function_call ';' {$$.node = mknode("[]=",3, $1, $3, $6);} // Only for string!
        | '*' ID '=' expression ';' {$$.node = mknode("*=", 2, $2, $4);} // ID MUST BE PTR?
        | function_call ';' {$$.node = $1.node;}
        | IF  expression ':' block {$$.node = mknode("IF",2, $2, $4);}
        | IF  expression ':' block ELSE ':' block {$$.node = mknode("IF-ELSE",3, $2, $4, $7);}
        | IF expression ':' block elifs {$$.node = mknode("IF-ELIF",3, $2, $4, $5);}
        | IF expression ':' block elifs ELSE ':' block {$$.node = mknode("IF-ELIF-ELSE",4, $2, $4, $5, $8);} 
        | WHILE expression ':' block {$$.node = mknode("WHILE", 2, $2, $4);}
        | DO ':' block WHILE ':' expression ';' {$$.node = mknode("DO-WHILE", 2, $6, $3);}
        | FOR '(' init ';' expression ';' update')' ':' block {$$.node = mknode("FOR", 4, $3, $5, $7, $10);}
        | func {$$.node = $1.node;};

elifs: ELIF expression ':' block elifs {$$.node = mknode("ELIF", 3, $2, $4, $5);}
        | ELIF expression ':' block {$$.node = mknode("ELIF", 3, $2, $4, NULL);};

block: VAR declarations BEG statements END {$$.node = mknode("BLOCK", 1, mknode("DECL",2, $2, mknode("BODY-BLOCK",1, $4)));}
        | BEG statements END {$$.node = mknode("BLOCK", 1, $2);};
        | statement {$$.node = $1.node;}

init : ID '=' expression {$$.node = mknode("init", 1, mknode("=", 2, $1, $3));};
update : ID '=' expression {$$.node = mknode("update", 1, mknode("=", 2, $1, $3));};

expression: expression '+' expression {$$.node = mknode("+", 2, $1, $3);} // cannot be empty!
        | expression '-' expression {$$.node = mknode("-", 2, $1, $3);}
        | expression '*' expression {$$.node = mknode("*", 2, $1, $3);}
        | expression '/' expression {$$.node = mknode("/", 2, $1, $3);}
        | expression '>' expression {$$.node = mknode(">", 2, $1, $3);}
        | expression '<' expression  {$$.node = mknode("<", 2, $1, $3);}
        | expression EQ expression {$$.node = mknode("==", 2, $1, $3);}
        | expression GE expression {$$.node = mknode(">=", 2, $1, $3);}
        | expression LE expression {$$.node = mknode("<=", 2, $1, $3);}
        | expression NE expression {$$.node = mknode("!=", 2, $1, $3);}
        | expression AND expression  {$$.node = mknode("and", 2, $1, $3);}
        | expression OR expression {$$.node = mknode("or", 2, $1, $3);}
        | expression NOT expression {$$.node = mknode("not", 2, $1, $3);}
        | NOT expression {$$.node = mknode("not", 2, $2, mknode("",0));}
        | ID '[' expression ']' {$$.node = mknode("[]", 2, $1, $3);} // Only for string!
        | '|' ID '|' {$$.node = mknode("||", 2, $2, mknode("",0));} // Only for string! |str| return size

        | '*' ID {$$.node = mknode("*id", 2, $2, mknode("",0));} // ID MUST BE PTR
        | '*' '(' ID '+' expression ')'{$$.node = mknode("*()", 2, mknode("+", 2, $3, $5), mknode("",0));} // expression supposed to be INT.
        | '*' '(' ID '-' expression ')'{$$.node = mknode("*()", 2, mknode("-", 2, $3, $5), mknode("",0));} // expression supposed to be INT.
        | '&' ID {$$.node = mknode("&id", 2, $2, mknode("",0));} // ID int/real/char/strings.
        | '&' ID '[' expression ']' {$$.node = mknode("&[]", 2, $2, $4);} // Only for string!  expression supposed to be INT.
        
        | ID {$$.node = $1.node;}
        | TYPE_VALUE {$$.node = $1.node;}
        | NULL_TOK {$$.node = mknode("NULL", 0);};


function_call: CALL ID '(' args ')' {$$.node = mknode("CALL",2, $2, mknode("ARGS", 1, $4));};

args: argument_list {$$.node = $1.node;}
        | {$$.node = mknode("ARGS_NONE", 0);};

argument_list: expression ',' argument_list {$$.node = mknode("",2, $1, $3);}
        | expression {$$.node = mknode("",2, $1, NULL);}
        
// comment: '#->' text '<-#' ;
// text: .\ ;
%%
#include "lex.yy.c"

int main(){
    return yyparse();
}
int is_operator(const char *token){
    int size = sizeof(exp_literals)/sizeof(exp_literals[0]);
    for (int i = 0; i < size ; i++){
        if(strcmp(token, exp_literals[i]) == 0){
            return 1;
        }
    }
    return 0;
}

// print the elifs as (ELIF 
//                        expression
//                        block     
//                    elifs ... ) 
// index 0 - expression, 1 - block/statement, 2 - elifs.
void print_elifs(node *tree, int iden){
    print_spaces(iden);
    printf("(%s\n", tree->token);
    print_tree(tree->nodes[0], iden + 1);
    print_tree(tree->nodes[1], iden + 1);
    print_spaces(iden);
    printf(")\n");
    print_tree(tree->nodes[2], iden);
 }

// print the nested id's.
//  (type_value id, id:value, id, ...)
//  (type_value id:value, id, id, ...)
void print_ids(node *tree, int iden){
    if(tree->num_nodes == 0){ // The tree is only id.
        printf("%s", tree->token);
    }else if(tree->num_nodes == 2){ // The tree is id, ids or id:value.
        // index 0 - id, 1 - ids/value
        if (strcmp(tree->token, "VAL") == 0 ){ // value
            printf("%s:%s", tree->nodes[0]->token, tree->nodes[1]->token);
        }else{  // id
            printf("%s, ", tree->nodes[0]->token);
            print_ids(tree->nodes[1],iden);
        }
    }
    else{ // The tree needs to have 3 childrens. type:value, ids
        // index 0 - id, 1 - value, 2 - ids.
        printf("%s:%s, ", tree->nodes[0]->token, tree->nodes[1]->token);
        print_ids(tree->nodes[2], iden);
    }
}
// index 0 - id, 1 - int, 2 - string value
void print_ids_str(node *tree, int iden){
    if(tree->num_nodes == 2){ // The tree is only id, int
        printf("%s[%s]", tree->nodes[0]->token, tree->nodes[1]->token);
    }else if(tree->num_nodes == 3){ // The tree is id, int and ids or string value.
        // index 0 - id, 1 - int, 2 - ids/value
        if (strcmp(tree->token, "VAL") == 0 ){ // value
            printf("%s[%s]:%s", tree->nodes[0]->token, tree->nodes[1]->token, tree->nodes[2]->token);
        }else{  // id int, ids
            printf("%s[%s], ", tree->nodes[0]->token, tree->nodes[1]->token);
            print_ids_str(tree->nodes[2],iden);
        }
    }
    else{ // The tree needs to have 4 childrens. id [int]:value, ids
        // index 0 - id, 1 - int, 2- value, 3 - ids.
        printf("%s[%s]:%s, ", tree->nodes[0]->token, tree->nodes[1]->token, tree->nodes[2]->token);
        print_ids_str(tree->nodes[3], iden);
    }
}

// the tree here could be (type id),(type id:value), (type id, id:value, ..., id) 
// index 0 - type, 1 - ids, 2 - next declaration.
void print_decleration(node *tree, int iden){
    // print the declarations as dec(type id)
    if (tree == NULL) return;
    print_spaces(iden);
    printf("(%s ", tree->nodes[0]->token);

    if (strcmp(tree->token,"string") == 0){
        print_ids_str(tree->nodes[1], iden); // print the string ids. (has to be id[int], id[int]:string, ...)
    }
    else{
        print_ids(tree->nodes[1],iden);
    }
    printf(")\n");
    print_decleration(tree->nodes[2], iden);
    return;
}

// print the return type as (ret type) and not as (ret \n type .. ) 
void print_ret(node *tree, int iden){
    
    print_spaces(iden);
    printf("(%s", tree->token);
    if (tree->num_nodes == 0){
        printf(")\n");
        return;
    }
    if (is_operator(tree->nodes[0]->token)){
        printf("\n");
        print_exp_operator(tree->nodes[0], iden + 1);
        print_spaces(iden);
    }
    else{
        printf("%s", tree->nodes[0]->token); 
    }
    printf(")\n");
}

// print the placement statements ID '=' expression
void print_state_placement(node *tree, int iden){
    print_spaces(iden);
    printf("(%s ", tree->token);
    printf("%s ", tree->nodes[0]->token); // print the ID
    if(is_operator(tree->nodes[1]->token)){ // print the expression
        printf("\n");
        print_exp_operator(tree->nodes[1], iden + 1);
        print_spaces(iden);
    }
    else{
        printf("%s", tree->nodes[1]->token); 
    }
    printf(")\n");
}

//  print the string placement statements ID [expression1] '=' expression2
// index 0 - id, 1 - expression1, 2 = expression2.
// check if expression2 must be char/id. else change the printing to (= a[expression1] expression2)
void print_state_placement_str(node *tree, int iden){
    print_spaces(iden);
    printf("(= ");
    printf("%s ", tree->nodes[0]->token); // print the ID
    if (is_operator(tree->nodes[1]->token)){ // print expression1
        printf("\n");
        print_spaces(iden + 1);
        printf("[\n");
        print_exp_operator(tree->nodes[1], iden + 2);
        print_spaces(iden + 1);
        printf("]\n");
    }
    else{
        printf("[%s]\n", tree->nodes[1]->token); 
    }

    if (is_operator(tree->nodes[2]->token)){ // print expression2
        printf("\n");
        print_exp_operator(tree->nodes[2], iden + 1);
    }
    else{
        print_spaces(iden + 1);
        printf("%s\n", tree->nodes[2]->token); 
    }
    print_spaces(iden);
    printf(")\n");
}

// print expression operators as (op
//                                  (op1)
//                                  (op2) ..
void print_exp_operator(node *tree, int iden){
    print_spaces(iden);
    printf("(%s ", tree->token);
    int opleft = is_operator(tree->nodes[0]->token);
    int opright = is_operator(tree->nodes[1]->token);
    if (opleft || opright){
        if (opleft && opright){
            printf("\n");
            print_exp_operator(tree->nodes[0], iden + 1);
            print_exp_operator(tree->nodes[1], iden + 1);
        }
        else{
            if (opleft){
                printf("\n");
                print_exp_operator(tree->nodes[0], iden + 1);
                // add check if right son is empty (prob the 'not' operator with one child)
                if (strcmp(tree->nodes[1]->token, "") != 0){
                    print_spaces(iden + 1);
                    printf("%s", tree->nodes[1]->token);
                    printf("\n");
                }
            }
            else{
                printf("\n");
                print_spaces(iden + 1);
                printf("%s", tree->nodes[0]->token);
                printf("\n");
                print_exp_operator(tree->nodes[1], iden + 1);
            }
        }
    }
    else{
        printf("%s %s)\n", tree->nodes[0]->token, tree->nodes[1]->token);
        return;
    }
    print_spaces(iden);
    printf(")\n");
}
void print_pars(node *tree, int iden){
    // print the function parameters as (par# type id)
    if (tree->num_nodes == 0) return;
    print_spaces(iden);
    printf("(%s %s %s)\n",tree->nodes[0]->token,tree->nodes[1]->token,tree->nodes[2]->token);
    if (tree->nodes[3] != NULL){
        print_pars(tree->nodes[3], iden);
    }
}
void print_func(node* tree, int iden){
    // print the function name
    print_spaces(iden);
    printf("%s\n", tree->nodes[0]->token);
    // print the function parameters
    print_spaces(iden);
    if (tree->nodes[1]->num_nodes == 0){
        printf("(%s)\n", tree->nodes[1]->token);
    }
    else{
        printf("(%s\n", tree->nodes[1]->token); 
        print_pars(tree->nodes[1], iden + 1);
        print_spaces(iden);
        printf(")\n"); 
    } 
    // print the function return type
    print_spaces(iden);
    printf("(%s)\n", tree->nodes[2]->token); 
    // the function body is printed in the printtree function.
}

// <------------------------------------------------------------- PRINT START'S HERE 
void print_tree(node *tree, int iden)
{
    if (tree == NULL) return;
    // If the token is a function, print the function name and parameters.
    if (strcmp(tree->token, "FUNC") == 0) {
        print_spaces(iden);
        printf("(%s\n", tree->token);
        print_func(tree, iden + 1);
        // print the func_body (can be DEC,BODY or BODY)
        print_tree(tree->nodes[3], iden + 1);
        print_spaces(iden);
        printf(")\n");
        return;
    }
    // If the token is a declaration, print the declaration and then the body.
    // because func_body can be DEC, BODY or BODY.
    if (strcmp(tree->token, "DECL") == 0) {
        print_spaces(iden);
        printf("(%s\n", tree->token);
        print_decleration(tree->nodes[0], iden + 1);
        print_spaces(iden);
        printf(")\n");
        // print the body
        print_tree(tree->nodes[1], iden);
        return;
    }

    // If the token is a placement statement ('=') then print it as (= id expression).
    if (strcmp(tree->token, "=") == 0){
        print_state_placement(tree, iden);
        return;
    }
    if (strcmp(tree->token, "[]=") == 0){
        print_state_placement_str(tree, iden);
        return;
    }

    // If the token is expression operator, print the expression.
    if (is_operator(tree->token)){
        print_exp_operator(tree, iden);
        return;
    }

    // If the token is a return, print the return type and expression.
    if (strcmp(tree->token, "RET ") == 0){
        print_ret(tree, iden);
        return;
    }

    if (strcmp(tree->token , "ELIF") == 0){
        print_elifs(tree, iden);
        return;
    }
    // If the tree token is empty or NULL, print only the childrens.
    if (tree->token == NULL || strcmp(tree->token, "") == 0) {
        for (int i = 0; i < tree->num_nodes; i++){
            print_tree(tree->nodes[i], iden);
        }
        return;
    }
    print_spaces(iden);
    // If the tree has no childrens print as (token) 
    if (tree->num_nodes == 0){
        printf("(%s)\n", tree->token);
        return;
    }
    // If the tree has token and childrens print as (token 
    //                                                 (child1...
    //                                                 (child2...
    //                                              ) 
    printf("(%s\n", tree->token);
    for (int i = 0; i < tree->num_nodes; i++){
        print_tree(tree->nodes[i], iden + 1);
    }
    print_spaces(iden);
    printf(")\n");
}

void print_spaces(int iden){
    for (int i = 0; i < iden; i++) printf("    ");
}
int yyerror(const char *s) {
    fprintf(stderr, "Error: %s, token: %s in line:%d\n", s, yytext, yylineno);
    return 1;
}

node *mknode(char *token, int num, ...){
    node *newnode = (node *)malloc(sizeof(node));
    newnode-> token = strdup(token);
    newnode->num_nodes = num;
    if (num == 0){
        newnode->nodes = NULL;
        return newnode;
    }
    newnode->nodes = (node **)malloc(sizeof(node*)*num);
    va_list args;
    va_start(args, num);
    for (int i = 0 ; i < num; i++){
        newnode->nodes[i] = va_arg(args, node*);
    }
    va_end(args);
    return newnode;
}