%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
int yylex(void);
int  yyerror(const char *s);

// semantic analyzer:
typedef struct Var 
{
    char *id; // id for the variable
    char *typeVar; // func/var/arg
    char * value; // the type of value or returned value. INT, CHAR, ->INT, ->VOID
    int size; // for string array
    struct Var *next;
    
    int param_count; // only for FUNC type.
    char **param_types; // only for FUNC type.
    int ret; // only for FUNC type.
} Var;
typedef struct Symbol_table
{
    char * name;
    struct Var *first;
    struct Symbol_table *previous;
} Symbol_table;
typedef struct Stack
{
    struct Symbol_table *scope;
} Stack;

// first part:
// Declaring expression operators for the parser.
const char *exp_literals[] = {
    "+", "-", "*", "/", ">", "<", "==", ">=", "<=", "!=", "and", "or", "not", "||", "[]", "*id", "&id", "*()", "&[]","u-"
};
const char *tokens_types[] = {"ID", "CHAR", "INT", "REAL", "BOOL", "NULL"};
typedef struct node
{
    char *token;
    int num_nodes;
    struct node **nodes;
} node;


node *mknode(char *token, int num, ...);
int is_operator(const char *token);
int is_id_or_literal(const char *token);
void print_tree(node *tree, int iden);
void free_tree(node *tree);
void print_pars(node *tree, int iden);
void print_func(node* tree, int iden);
void print_exp_operator(node *tree, int iden);
void print_state_placement(node *tree, int iden);
void print_state_placement_ptr(node *tree, int iden);
void print_state_placement_str(node *tree, int iden);
void print_ret(node *tree, int iden);
void print_decleration(node *tree, int iden);
void print_ids(node *tree, int iden, char *value_type);
void print_ids_str(node *tree, int iden);
void print_elifs(node *tree, int iden);
void print_spaces(int iden);
void print_call(node *tree, int iden);


char * eval_expression(node* exp);
int check_op_in_arr(char *op, const char *ops_args[]);
char * handle_regular_op(char*op, node *e1,node * e2);
char * handle_uminus_op(char*op, node *e1,node * e2);
char * handle_compare_op(char*op, node *e1,node * e2);
char * handle_compare_eq_op(char*op, node *e1, node * e2);
char * handle_bool_op(char*op, node *e1, node * e2);
char * handle_string_char_op(char*op, node *e1,node * e2);
char * handle_string_int_op(char*op, node *e1,node * e2);
char * handle_ptr_op(char*op, node *e1,node * e2);
char * handle_address_op(char*op, node *e1, node * e2);
char * handle_dereferenced_op(char*op, node *e1, node * e2);
void eval_state_placement(node * tree);
void eval_state_placement_ptr(node * tree);
void eval_state_placement_str(node * tree);
void eval_ret(node * tree);
void eval_IF_WHILE_FOR_exp(node * tree);
void eval_args_call(node* tree, Var *func);
void eval_declaration_value(node *tree,const char *value_type);
void eval_allocated_strign_num(node *tree);
char * remove_ptr(char *type);

void check_par_num(char * id);
Var * check_func(char * id);
void check_main(const char *msg);
void check_return_func();

int count_args(node *tree);
int count_params(node* tree);
char ** list_param_types(node* tree, int count);


void push_scope(char * name);
void pop_scope();
void free_symbol_table(Symbol_table *st);
void insert_var(const char *id, const char *typeVar, const char *value, int size);
void insert_var_func(const char *id, const char *typeVar, const char *value, int count, char **param_types);
Var * lookup_var(const char *id, int check);
char* get_first_scope();

void print_scopes();

char *yytext;
typedef union {
    struct node *node;
    char c;
    char *str;
    int i;
    float f;
} YYSTYPE;
#define  YYSTYPE_IS_DECLARED 1

// Init global scope:
static Stack *start;
static int par_num_global;
static int main_flag;

// 3AC:
static FILE *emit_stream = NULL;    // define another output for 3AC the code and then count the bytes per function
static char *body_buf;              
static size_t body_sz;              

void emit(const char *fmt, ...) { // emit the code into the second buffer
    va_list ap;
    va_start(ap, fmt);
    vfprintf(emit_stream ? emit_stream : stdout, fmt, ap);
    va_end(ap);
}
#define MAX_TEMPS 100
char *temp_types[MAX_TEMPS];
char *stack_3ac[MAX_TEMPS];

int top = 0;
static int n_label;
static int n_temp;
static int bytes_per_function;

void insert_stack(char *var);
void demote_stack(int amount);
char* get_new_temp();
char* get_new_label();
int calc_bytes_args(char *func_name);
int calc_bytes_declared(char *func_name);
int is_return_value(char *f_id);
int return_bytes_value(char *f_id);
void eval_dereference_arr();
void eval_address_arr();
void eval_func_3ac(node *node);
void eval_statments_3ac(node *node);
void eval_return_3ac(node *ret);
void eval_expression_3ac(node *node);
void eval_function_call_3ac(node* node);
int eval_args_3ac(node * node);
int byte_size_per_type(char *type_var);
void eval_body_3ac(node *body_node);
void eval_block_3ac(node* root_block);
void eval_expression_sc_3ac(node *expr, const char *Ltrue, const char *Lfalse, const char* temp);
void eval_elifs_3ac(node *node, const char* Lend, const char* Lif_else);
void eval_if_3ac(node *node);
void eval_if_else_3ac(node *node);
void eval_if_elif_3ac(node *node);
void eval_all_while_3ac(node *node);
void eval_for_3ac(node *for_root);


// try calc bytes:
char * return_temp_type(char *temp);
void insert_temp_type(char *temp, char *temp_type);
char * return_id_type(char *id);
int is_var(char *id);
%}

%token BOOL_TOK CHAR_TOK INT_TOK REAL_TOK STRING_TOK INT_PTR CHAR_PTR REAL_PTR PAR
%token BOOL CHAR INT REAL STRING
%token VOID ID
%token IF ELIF ELSE 
%token WHILE FOR DO

%token VAR BEG END DEF CALL NULL_TOK RETURN RETURNS MAIN type
%token AND NOT OR

%token EQ GE LE NE

%nonassoc  LOWER_THAN_ELSE
%right     ELIF
%right     ELSE

%left  OR
%left  AND
%right NOT

%left  EQ NE
%left  '>' '<' GE LE

%left  '+' '-'
%left  '*' '/'
%right UMINUS

%%
program: funcs {$$.node = mknode("PROGRAM",1, $1);print_tree($$.node, 0); free_tree($$.node); };
funcs: func funcs {$$.node  = mknode("",2, $1, $2);} 
        | {$$.node = NULL;};

func: DEF ID '(' parameter_list ')' ':' ret_type func_body {$$.node  = mknode("FUNC",4, $2, $4, $7, $8);};

parameter_list: PAR TYPE_TOK ':' ID ';' parameter_list {$$.node = mknode("PARS",4, $1, $2, $4, $6);}
        | PAR TYPE_TOK ':' ID {$$.node  = mknode("PARS",4, $1, $2, $4, NULL);}
        | {$$.node  = mknode("PARS NONE",0);};

ret_type: RETURNS TYPE_TOK {$$.node = $2.node;} //char *label = (char *)malloc(strlen("RET ") + strlen($2.node->token) + 1); sprintf(label, "RET %s", $2.node->token); $$.node  = mknode(label,0); free(label);
        | {$$.node  = mknode("RET_NONE",0);};

TYPE_TOK: BOOL_TOK {$$.node = $1.node;}| CHAR_TOK {$$.node = $1.node;}| INT_TOK {$$.node = $1.node;}| REAL_TOK {$$.node = $1.node;}
        | INT_PTR {$$.node = $1.node;}| CHAR_PTR {$$.node = $1.node;}| REAL_PTR {$$.node = $1.node;};

TYPE_VALUE: BOOL {$$.node = $1.node;}| CHAR {$$.node = $1.node;}| INT {$$.node = $1.node;}| REAL {$$.node = $1.node;} | STRING {$$.node = $1.node;} | NULL_TOK {$$.node = $1.node;};

func_body: VAR declarations BEG code_body ret END {$$.node  = mknode("DECL",2, $2, mknode("BODY",2, $4, $5));}
        | BEG code_body ret END {$$.node  = mknode("BODY",2, $2, $3);};

ret: RETURN expression ';' {$$.node = mknode("RET",1, $2);}
        | {$$.node = NULL;};

declaration
  : type TYPE_TOK   ':' IDS   ';' {$$.node = mknode("", 3, $2, $4, NULL);}
  | type STRING_TOK ':' IDS_S ';' {$$.node = mknode("string", 3, $2, $4, NULL);};

declarations
  : {$$.node = NULL;}
  | declaration declarations  {$$.node = mknode($1.node->token, 3, $1.node->nodes[0], $1.node->nodes[1], $2.node);} ;

IDS: ID ':' TYPE_VALUE ',' IDS {$$.node = mknode("", 3, $1, $3, $5);}
        | ID ':' TYPE_VALUE {$$.node = mknode("VAL", 2, $1, $3);}
        | ID ',' IDS {$$.node = mknode("", 2, $1, $3);}
        | ID {$$.node = $1.node;};

IDS_S: ID '[' INT ']' ':' STRING ',' IDS_S {$$.node = mknode("", 4, $1, $3, $6, $8);} 
        | ID '[' INT ']' ':' STRING {$$.node = mknode("VAL", 3, $1, $3, $6);}
        | ID '[' INT ']' ',' IDS_S {$$.node = mknode("", 3, $1, $3, $6);}
        | ID '[' INT ']' {$$.node = mknode("", 2, $1, $3);} ; 

code_body: statements {$$.node = $1.node;};

statements: statement statements {$$.node = mknode("",2, $1, $2);}
        | {$$.node = NULL;};

statement: ID '=' expression ';' {$$.node = mknode("=",2, $1, $3);}
        | ID '[' expression ']' '=' expression ';' {$$.node = mknode("[]=",3, $1, $3,$6);} // Only for string! e.g. str[4 + 5] = 'a';
        | '*' ID '=' expression ';' {$$.node = mknode("*=", 2, $2, $4);} // ID MUST BE PTR

        | function_call ';' {$$.node = $1.node;}
        | IF  expression ':' statement  %prec LOWER_THAN_ELSE {$$.node = mknode("IF",2, $2, $4);}
        | IF  expression ':' statement ELSE ':' statement {$$.node = mknode("IF-ELSE",3, $2, $4, $7);}
        | IF expression ':' statement elifs  %prec LOWER_THAN_ELSE {$$.node = mknode("IF-ELIF",3, $2, $4, $5);}
        | IF expression ':' statement elifs ELSE ':' statement {$$.node = mknode("IF-ELIF-ELSE",4, $2, $4, $5, $8);} 
        | WHILE expression ':' statement {$$.node = mknode("WHILE", 2, $2, $4);}
        | DO ':' statement WHILE ':' expression ';' {$$.node = mknode("DO-WHILE", 2, $6, $3);}
        | FOR '(' init ';' expression ';' update')' ':' statement {$$.node = mknode("FOR", 4, $3, $5, $7, $10);}
        | func {$$.node = $1.node;}
        | block {$$.node = $1.node;};
        
// Cannot be empty!
elifs: ELIF expression ':' statement {$$.node = mknode("ELIF", 3, $2, $4, NULL);} 
        |ELIF expression ':' statement elifs {$$.node = mknode("ELIF", 3, $2, $4, $5);};

block: VAR declarations BEG statements ret END {$$.node = mknode("BLOCK", 2, mknode("DECL",2, $2, mknode("BODY",1, $4)), $5);}
        | BEG statements ret END {$$.node = mknode("BLOCK", 2, $2, $3);};

init : ID '=' expression {$$.node = mknode("init", 1, mknode("=", 2, $1, $3));};
update : ID '=' expression {$$.node = mknode("update", 1, mknode("=", 2, $1, $3));};

// cannot be empty!
expression: '(' expression ')'{$$.node = $2.node;} 
        | expression '+' expression {$$.node = mknode("+", 2, $1, $3);} 
        | '-' expression %prec UMINUS {$$.node = mknode("u-", 2, $2, mknode("",0));} 
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
        | NOT expression {$$.node = mknode("not", 2, $2, mknode("",0));}
        | '|' ID '|' {$$.node = mknode("||", 2, $2, mknode("",0));} // Only for string! |str| return size

        | '*' ID {$$.node = mknode("*id", 2, $2, mknode("",0));} // ID MUST BE PTR 
        | '*' '(' ID '+' expression ')'{$$.node = mknode("*()", 2, mknode("+", 2, $3, $5), mknode("",0));} // expression supposed to be INT. and ID is char_ptr
        | '*' '(' ID '-' expression ')'{$$.node = mknode("*()", 2, mknode("-", 2, $3, $5), mknode("",0));} // expression supposed to be INT. and ID is char_ptr
        | '&' ID {$$.node = mknode("&id", 2, $2, mknode("",0));} // ID int/real/char/string[i]
        | '&' ID '[' expression ']' {$$.node = mknode("&[]", 2, $2, $4);} // Only for string!  expression supposed to be INT, returns char*
        | ID '[' expression ']' {$$.node = mknode("[]",2, $1, $3);} // Only for string/ epxression INT and returns char.

        | function_call {$$.node = $1.node;}

        | ID {$$.node = $1.node;}
        | TYPE_VALUE {$$.node = $1.node;};
        

function_call: CALL ID '(' args ')' {$$.node = mknode("CALL",2, $2, mknode("ARGS", 1, $4));};

args: argument_list {$$.node = $1.node;}
        | {$$.node = mknode("ARGS_NONE", 0);};

argument_list: expression ',' argument_list {$$.node = mknode("",2, $1, $3);}
        | expression {$$.node = mknode("",2, $1, NULL);}
        

%%
#include "lex.yy.c"

int main(){
    start = (Stack *)malloc(sizeof(Stack));
    Symbol_table *global_table = (Symbol_table *)malloc(sizeof(Symbol_table));
    global_table->name = strdup("GLOBAL");
    global_table->first = NULL;
    global_table->previous = NULL;
    start->scope = global_table;
    main_flag = 0;
    int res = yyparse();
    if(!main_flag){
        yyerror("function _main_ is missing in the code!\n");
    }
    return res;
}
int yyerror(const char *s) {
    if(strcmp(s, "syntax error") == 0){
       fprintf(stderr, "\nError: %s, token: %s in line:%d\n", s, yytext, yylineno); 
    }
    else{
        fprintf(stderr, "\nError: %s\n",s);
    }
    // clean allocated memory..
    while(start->scope != NULL){
        pop_scope();   
    }
    exit(1);
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

void print_spaces(int iden){
    for (int i = 0; i < iden; i++) emit("    ");
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
int is_id_or_literal(const char *token){

    int size = sizeof(tokens_types)/sizeof(tokens_types[0]);
    for (int i = 0; i < size ; i++){
        if(strcmp(token, tokens_types[i]) == 0){
            return 1;
        }
    }
    return 0;
}
// tree must be argument_list 
int count_args(node *tree){
    if(tree == NULL){
        return 0;
    }
    return count_args(tree->nodes[1]) + 1 ; 
}
// tree must be parameter_list
int count_params(node * tree){
    if(tree == NULL){
        return 0;
    }
    if(tree->num_nodes == 0){
        return 0;
    }
    return count_params(tree->nodes[3]) + 1 ; 
}
// tree must be parameter_list
char ** list_param_types(node* tree,  int count){
    if(count == 0){
        return NULL;
    }
    char **param_types = malloc(sizeof(char*) * count);
    
    for(int i = 0; i < count; i++){
        param_types[i] = strdup(tree->nodes[1]->token);
        tree = tree->nodes[3];
    }

    return param_types;
}

// print the elifs as (ELIF 
//                        expression
//                        block     
//                    elifs ... ) 
// index 0 - expression, 1 - block/statement, 2 - elifs.
void print_elifs(node *tree, int iden){
    print_tree(tree->nodes[0], iden + 1);
    print_tree(tree->nodes[1], iden + 1);
    print_tree(tree->nodes[2], iden);
 }

// print the nested id's.
//  (type_value id, id:value, id, ...)
//  (type_value id:value, id, id, ...)
//  tree can be id node or ids 
void print_ids(node *tree, int iden, char *value_type){
    bytes_per_function += byte_size_per_type(value_type);

    if(tree->num_nodes == 1){ // The tree is only id.
        insert_var(tree->token, "VAR", value_type, 1); // <- add id node to the scope -> 
    }else{
        insert_var(tree->nodes[0]->token, "VAR", value_type, 1); // <- add id to the scope ->
        if(tree->num_nodes == 2){ // The tree is id, ids or id:value.
            // index 0 - id, 1 - ids/value
            if (strcmp(tree->token, "VAL") == 0 ){ // value
                eval_declaration_value(tree->nodes[1], value_type); // check if the value is match to the type: 
            }else{  // id, ids
                print_ids(tree->nodes[1],iden, value_type);
            }
        }
        else{ // The tree needs to have 3 childrens. type:value, ids
            // index 0 - id, 1 - value, 2 - ids.
            eval_declaration_value(tree->nodes[1], value_type); // check if the value is match to the type:
            print_ids(tree->nodes[2], iden, value_type);
        }
    } 
}
// index 0 - id, 1 - int, 2 - string value
void print_ids_str(node *tree, int iden){
    eval_allocated_strign_num(tree->nodes[1]);
    insert_var(tree->nodes[0]->token, "VAR", "STRING", atoi(tree->nodes[1]->token)); // <- add id to the scope ->

    if(tree->num_nodes == 2){ // The tree is only id, int
        // eval_allocated_strign_num(tree->nodes[1]);

    }else if(tree->num_nodes == 3){ // The tree is id, int and ids or string value.
        // index 0 - id, 1 - int, 2 - ids/value
        if (strcmp(tree->token, "VAL") == 0 ){ // value

            eval_declaration_value(tree->nodes[2], "STRING"); // check if the value is match to the type:
        }else{  // id int, ids

            
            print_ids_str(tree->nodes[2],iden);
        }
    }
    else{ // The tree needs to have 4 childrens. id [int]:value, ids
        // index 0 - id, 1 - int, 2- value, 3 - ids.
        eval_declaration_value(tree->nodes[2], "STRING"); // check if the value is match to the type:
        print_ids_str(tree->nodes[3], iden);
    }
}

// the tree here could be (type id),(type id:value), (type id, id:value, ..., id) 
// index 0 - type_token, 1 - ids, 2 - next declaration.
void print_decleration(node *tree, int iden){
    if (tree == NULL) return;
    if (strcmp(tree->token,"string") == 0){
        print_ids_str(tree->nodes[1], iden); // print the string ids. (has to be id[int], id[int]:string, ...)
    }
    else{
        print_ids(tree->nodes[1], iden, tree->nodes[0]->token);
    }
    print_decleration(tree->nodes[2], iden);
    return;
}


// print the return type as (ret type) and not as (ret \n type .. ) 
// index 0 - expression or no index
void print_ret(node *tree, int iden){
    if (tree->num_nodes == 0){
        return;
    }

    eval_ret(tree);
    if (is_operator(tree->nodes[0]->token)){
        print_exp_operator(tree->nodes[0], iden + 1);
    }
    else{
        if(strcmp(tree->nodes[0]->token, "CALL") == 0 ){
            print_tree(tree->nodes[0], iden + 1);
        }
    }
}

// print the placement statements ID '=' expression
// index 0 - ID, 1 - expression/function_call
void print_state_placement(node *tree, int iden){
    eval_state_placement(tree);

    if(is_operator(tree->nodes[1]->token)){ // print the expression

        print_exp_operator(tree->nodes[1], iden + 1);
    }
    else{
        if (strcmp(tree->nodes[1]->token, "CALL") == 0){ 
            print_tree(tree->nodes[1], iden + 1);
        }
    }
}

// print the placement statements ID '*=' expression
// index 0 - ID, 1 - expression/function_call
void print_state_placement_ptr(node *tree, int iden){
    eval_state_placement_ptr(tree);

    if(is_operator(tree->nodes[1]->token)){ // print the expression
        print_exp_operator(tree->nodes[1], iden + 1);
    }
    else{
        if (strcmp(tree->nodes[1]->token, "CALL") == 0){     
            print_tree(tree->nodes[1], iden + 1);
        }
    }
}

//  print the string placement statements ID [expression1] '=' expression2
// index 0 - id, 1 - expression1, 2 = expression2.
// check if expression2 must be char/id. else change the printing to (= a[expression1] expression2)
void print_state_placement_str(node *tree, int iden){
    eval_state_placement_str(tree);

    if (is_operator(tree->nodes[1]->token)){ // print expression1
        print_exp_operator(tree->nodes[1], iden + 2);
    }

    if (is_operator(tree->nodes[2]->token)){ // print expression2
        print_exp_operator(tree->nodes[2], iden + 1);
    }

}

// print expression operators as (op
//                                  (op1)
//                                  (op2) ..
void print_exp_operator(node *tree, int iden){
    int opleft = is_operator(tree->nodes[0]->token);
    int opright = is_operator(tree->nodes[1]->token);
    if (opleft || opright){
        if (opleft && opright){
            print_exp_operator(tree->nodes[0], iden + 1);
            print_exp_operator(tree->nodes[1], iden + 1);
        }
        else{
            if (opleft){
                print_exp_operator(tree->nodes[0], iden + 1);
                if (strcmp(tree->nodes[1]->token, "") != 0){
                    if(strcmp(tree->nodes[1]->token, "CALL") == 0){
                        print_tree(tree->nodes[1], iden + 1);
                    }
                }
            }
            else{
                if(strcmp(tree->nodes[0]->token, "CALL") == 0){                   
                    print_tree(tree->nodes[0], iden + 1);
                }
                print_exp_operator(tree->nodes[1], iden + 1);
            }
        }
    }
    else{ // both could be id/literal or function calls
        if(strcmp(tree->nodes[0]->token, "CALL") == 0 && strcmp(tree->nodes[1]->token, "CALL") == 0){ // check if left node is function_call
            print_tree(tree->nodes[0], iden + 1);
            print_tree(tree->nodes[1], iden + 1);
        }
        else if(strcmp(tree->nodes[0]->token, "CALL") == 0){       
            print_tree(tree->nodes[0], iden + 1);
        }
        else if(strcmp(tree->nodes[1]->token, "CALL") == 0){          
            print_tree(tree->nodes[1], iden + 1);  

        }else{
            return;
        }
    }

}

// print the function parameters as (par# type id)
// index 0 - par#, 1 - type, 2 - id, 3 - next par# tree.
void print_pars(node *tree, int iden){ 
    check_main("MAIN function shouldn't receive any arguments!");
    check_par_num(tree->nodes[0]->token);

    insert_var(tree->nodes[2]->token, "ARG", tree->nodes[1]->token, 1); // <- add parameters to current scope ->
    if (tree->nodes[3] != NULL){
        print_pars(tree->nodes[3], iden);
    }

}
// index 0 - id, 1 -par_list, 2 - return type, 3 - body
void print_func(node* tree, int iden){
    if (tree->nodes[1]->num_nodes == 0){ // print the function parameters
    }
    else{
        par_num_global=0; 
        print_pars(tree->nodes[1], iden + 1);
    } 
    if(strcmp(tree->nodes[2]->token, "RET_NONE") != 0){
        check_main("MAIN function shouldn't returns any type!");
    }
    // the function body is printed in the printtree function.
}
// index 0 - id, 1 - args
void print_call(node *tree, int iden){
    char *func_id = tree->nodes[0]->token;
    Var * f = check_func(func_id); // <- check if function id exists ->
    int parms_count = f->param_count;
    int args_count = 0;
    if(tree->nodes[1]->nodes[0]->num_nodes == 0){
        if(parms_count != args_count){  
            char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Function %s got %d arguments but need %d parameters", func_id, args_count, parms_count); yyerror(error_msg);  
        }
    }else{
        args_count = count_args(tree->nodes[1]->nodes[0]);
        if(parms_count != args_count){  
            char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Function %s got %d arguments but need %d parameters", func_id, args_count, parms_count); yyerror(error_msg);  
        }
        eval_args_call(tree->nodes[1]->nodes[0], f);
        if(parms_count != args_count){
            char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Function %s got %d arguments but need %d parameters", func_id, args_count, parms_count);yyerror(error_msg);  
        }
        print_tree(tree->nodes[1], iden);
    }
}

void print_tree(node *tree, int iden) // <------------------------------------------------------------------- PRINT START'S HERE 
{
    if (tree == NULL) return;
    // If the token is a function, print the function name and parameters.
    if (strcmp(tree->token, "FUNC") == 0) {
        bytes_per_function = 0;
        int count = count_params(tree->nodes[1]);
        char ** param_types = list_param_types(tree->nodes[1],count); 
        insert_var_func(tree->nodes[0]->token, "FUNC", tree->nodes[2]->token, count, param_types); // <- add function to current scope ->
        push_scope(tree->nodes[0]->token); // <- Create new scope ->
        print_func(tree, iden + 1); // <- args added here! ->
        print_tree(tree->nodes[3], iden + 1); // print the func_body (can be DEC,BODY or BODY)
        check_return_func();
        eval_func_3ac(tree); // <- needs to know the args and function bytes
        
        pop_scope(); // <-  Remove the new scope ->
        return;
    }
    // If the token is a declaration, print the declaration and then the body.
    // because func_body can be DEC, BODY or BODY.
    if (strcmp(tree->token, "DECL") == 0) {  
        print_decleration(tree->nodes[0], iden + 1); // <- decleration inserted here ->
        // print the body
        print_tree(tree->nodes[1], iden);
        return;
    }

    // // If the token is block type, create new SCOPE, the print tree handles the printing..
    if (strcmp(tree->token, "BLOCK") == 0){
        push_scope(tree->token);   
        for (int i = 0; i < tree->num_nodes; i++){
            print_tree(tree->nodes[i], iden + 1);
        }  
        pop_scope();
        return;
    }

    if (strcmp(tree->token, "CALL") == 0){     
        print_call(tree, iden + 1);     
        return;
    }
    // If the token is a placement statement '='/'*='/'[]=' then print it as (= id expression).
    if (strcmp(tree->token, "=") == 0){
        print_state_placement(tree, iden);
        return;
    }
    if (strcmp(tree->token, "*=") == 0){
        print_state_placement_ptr(tree, iden);
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
    eval_IF_WHILE_FOR_exp(tree);

    if (strcmp(tree->token , "ELIF") == 0){
        print_elifs(tree, iden);
        return;
    }
    // If the token is a return, print the return type and expression.
    if (strcmp(tree->token, "RET") == 0){
        print_ret(tree, iden);
        return;
    }
    // If the tree token is empty or NULL, print only the childrens.
    if (tree->token == NULL || strcmp(tree->token, "") == 0) {
        for (int i = 0; i < tree->num_nodes; i++){
            print_tree(tree->nodes[i], iden);
        }
        return;
    }
    // If the tree has no childrens print as (token) 
    if (tree->num_nodes == 0){
        return;
    }
    // If the tree is ID/LITERAL: print only the ID/LITERAL without the type 
    if(tree->nodes[0] != NULL && is_id_or_literal(tree->nodes[0]->token)){
        return;
    }
    // If the tree has token and childrens print as (token 
    //                                                 (child1...
    //                                                 (child2...
    //                                              ) 
    for (int i = 0; i < tree->num_nodes; i++){
        print_tree(tree->nodes[i], iden + 1);
    } 
}

void free_tree(node *tree) {
    if (tree == NULL) return;

    for (int i = 0; i < tree->num_nodes; i++) {
        if (tree->nodes[i] != NULL) {
            free_tree(tree->nodes[i]); 
        }
    }

    if (tree->token != NULL) {
        free(tree->token);
    }

    if (tree->nodes != NULL) {
        free(tree->nodes);
    }
    free(tree);
}

// Semantic checker

void push_scope(char * name){
    Symbol_table *new_scope = (Symbol_table *)malloc(sizeof(Symbol_table));
    new_scope->first = NULL;
    new_scope->name = strdup(name); // delete later!
    new_scope->previous = start->scope;
    start->scope = new_scope;
}
void pop_scope(){
    if (start->scope == NULL){
        yyerror("Can't pop an empty stack!");
    }
    Symbol_table * curr_scope = start->scope;
    start->scope = curr_scope->previous;
    free_symbol_table(curr_scope);
}

void free_symbol_table( Symbol_table *st){
    while(st->first != NULL){
        Var * temp_var = st->first;
        st->first = temp_var->next;
        free(temp_var->id);
        free(temp_var->typeVar);
        free(temp_var->value); 
    }
    free(st->name);
    free(st);
}

// Insert var to current scope.
void insert_var(const char *id, const char *typeVar, const char *value, int size){
    lookup_var(id, 0);
    
    Var * new_var = (Var*)malloc(sizeof(Var));
    new_var->id = strdup(id);
    new_var->typeVar = strdup(typeVar);
    new_var->value = strdup(value);
    if(size){
        new_var->size = size;
    }
    new_var->next = NULL;

    if (start->scope){
        Var * temp_var = start->scope->first;
        if(temp_var){
            new_var->next = temp_var; 
        }
        start->scope->first = new_var;
    }else{
        yyerror("Can't assign new var outside of scope");
    }
}

void insert_var_func(const char *id, const char *typeVar, const char *value, int count, char **param_types){
    lookup_var(id, 0);
    if(strcmp(id,"_main_") == 0){
        main_flag = 1;
    }
    Var * new_var = (Var*)malloc(sizeof(Var));
    new_var->id = strdup(id);
    new_var->typeVar = strdup(typeVar);
    new_var->value = strdup(value);
    new_var->param_count = count;
    new_var->param_types = param_types;
    new_var->ret = 0;
    new_var->next = NULL;

    if (start->scope){
        Var * temp_var = start->scope->first;
        if(temp_var){
            new_var->next = temp_var; 
        }
        start->scope->first = new_var;
    }else{
        yyerror("Can't assign new var outside of scope");
    }
}

// Search and return Var* if var in current scope or outer scope.
// check: 0 - redeclaration error. 1 - return var; 
Var *  lookup_var(const char *id, int check){
    char * scope_name = start->scope->name; 
    if(!check){
        Symbol_table * s = start->scope;
        for(Var * v = s->first; v; v = v->next){
            if(strcmp(id, v->id) == 0){
                if(!check){             
                    char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Redeclaration in scope: \"%s\" on id: '%s' \n", scope_name, id); yyerror(error_msg);  
                }
                return v;
            }
        }    
    }
    for(Symbol_table *s = start->scope; s; s=s->previous){
        for(Var * v = s->first; v; v = v->next){
            if(strcmp(id, v->id) == 0){
                return v;
            }
        }
    }
    if(check){
        char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "ID:\"%s\" is not defined!\n",id ); yyerror(error_msg);  
    }
    return NULL;
}

char* get_first_scope(){
    Symbol_table * curr = start->scope;
    char *s_id = curr->name;
    while(strcmp(s_id, "BLOCK") == 0){
        curr = curr->previous;
        s_id = curr->name;
    }
    return s_id;
}

// check if par# is in right order (par1, par2..)
void check_par_num(char * id){
    par_num_global += 1;   
    int num_inx = atoi(id + 3);
    if(num_inx != par_num_global){
        char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Parameter ordering error: expected par%d but got %s",par_num_global, id); yyerror(error_msg);  
    }
}

// check if the curr scope is main
void check_main(const char *msg){
    if(strcmp(start->scope->name, "_main_") == 0){
        yyerror(msg);
    }
}
// check if the id is function. if so return the function VAR
Var * check_func(char * id){
    Var * f = lookup_var(id, 1);
    if(f == NULL){
        char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "id:\"%s\" is not defined!", id); yyerror(error_msg); 
    }
    if(strcmp(f->typeVar, "FUNC") != 0){     
        char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "id:\"%s\" is not a function!", id); yyerror(error_msg);
    }
    return f;
}
// check if the function returned value when she needed
void check_return_func(){
    char * f_id = start->scope->name;
    Var *v = lookup_var(f_id, 1);
    if((strcmp(v->value,"RET_NONE") != 0) && v->ret == 0){
        char error_msg[128]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "function \"%s\" must return a value!", f_id); yyerror(error_msg);
    }
}

void print_scopes(){
    printf("*********************************************->\n");
    Symbol_table *curr = start->scope;
    while (curr != NULL){
        printf("For scope : %s\n", curr->name);
        Var *v = curr->first;
        while (v != NULL){
            if(strcmp(v->typeVar,"FUNC") == 0){
                printf("id: '%s', type: %s, value: %s number of parameters:%d --- ", v->id, v->typeVar, v->value, v->param_count);
                printf("gets: ");
                for(int i = 0; i < v->param_count; i++){
                    printf("%s ", v->param_types[i]);
                }
                printf("\n");
            }else{
                printf("id: %s, type: %s, value: %s, size: %d\n", v->id, v->typeVar, v->value, v->size);
            }  
            v = v->next;
        }
        curr = curr->previous;
    }
    printf("<-*********************************************\n");
}

const char *regular_ops[] = {"+", "-", "*", "/", NULL}; // must be between INT,REAL
const char *uminus_ops[] = {"u-", NULL}; // must be between INT,REAL
const char *compare_ops[] = {">", "<", ">=", "<=", NULL}; // must be between  INT,REAL ?
const char *compare_eq_ops[] = { "==", "!=", NULL};// can be between INT,REAL, CHAR, NULL, STRING?
const char *bool_ops[] = {"and", "or", "not", NULL}; // must be between bool, return BOOL
const char *string_ops_char[] = {"&[]", "[]", NULL}; // only on string. return CHAR_PTR / CHAR
const char *string_ops_int[] = {"||", NULL}; // only on string. return INT
const char *ptr_ops[] = {"*id", NULL}; // must be on ID->PTR type, return the type of the ID
const char *address_ops[] = {"&id", NULL}; // can INT,REAL,CHAR points to var (type) (return should be the same type) 
const char *dereferenced_ops[] = {"*()", NULL}; // Must be between ID (id should be CHAR*) and INT, returns CHAR
// Recursive evaluation
// ops: "+", "-", "*", "/", ">", "<", "==", ">=", "<=", "!=", "and", "or", "not", "||", "[]", "*id", "&id", "*()", "&[]"
char * eval_expression(node* exp){
    // printf("got in eval_expression with node: %s\n", exp->token);
    if(exp->num_nodes == 1){ // Literal/ID    
        char *type_var = exp->nodes[0]->token;
        if(strcmp(type_var,"ID") == 0){
            Var* v = lookup_var(exp->token, 1);
            return v->value;
        }

        return type_var;
    }
    else if(exp->num_nodes == 2){ // another expression (prob operator
        
        char *op = exp->token;
        node *e1 = exp->nodes[0]; // left tree
        node *e2 = exp->nodes[1]; // right tree
        if(check_op_in_arr(op, regular_ops)){
            return handle_regular_op(op,e1,e2);

        }else if(check_op_in_arr(op, uminus_ops)){
            return handle_uminus_op(op, e1, e2);

        }else if(check_op_in_arr(op, compare_ops)){
            return handle_compare_op(op,e1,e2);

        }else if(check_op_in_arr(op, compare_eq_ops)){
            return handle_compare_eq_op(op,e1,e2);

        }else if(check_op_in_arr(op, bool_ops)){
            return handle_bool_op(op,e1,e2);

        }else if(check_op_in_arr(op, string_ops_char)){
            return handle_string_char_op(op,e1,e2);

        }else if(check_op_in_arr(op, string_ops_int)){
            return handle_string_int_op(op,e1,e2);

        }else if(check_op_in_arr(op, ptr_ops)){
            return handle_ptr_op(op,e1,e2);

        }else if(check_op_in_arr(op, address_ops)){
            return handle_address_op(op,e1,e2);

        }else if(check_op_in_arr(op, dereferenced_ops)){
            return handle_dereferenced_op(op,e1,e2);
        }
        else if(strcmp(op, "CALL") == 0){
            Var * f = check_func(e1->token);
            return f->value;
        }
        printf("op %s doesnt belong to any list\n",op);
    }
    yyerror("Shouldn't print this!! 1\n");
}



int check_op_in_arr(char *op, const char *ops_args[]){
    for(int i = 0 ; ops_args[i] != NULL ; i++){
        if(strcmp(op, ops_args[i]) == 0 ){
            return 1;
        }
    }
    return 0;
}

char * handle_regular_op(char*op, node *e1,node * e2){
    if(e1 == NULL || e2 == NULL){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    const char *e1_type =  eval_expression(e1); // check if they ID or value_literal (id lookup inside)
    const char *e2_type =  eval_expression(e2); // check if they ID or value_literal (id lookup inside)
    if( (strcmp(e1_type, "INT") == 0) && (strcmp(e2_type, "INT") == 0) ){
        return "INT";
    }
    if( (strcmp(e1_type, "INT") == 0) && (strcmp(e2_type, "REAL") == 0) || (strcmp(e1_type, "REAL") == 0) && (strcmp(e2_type, "INT") == 0) || (strcmp(e1_type, "REAL") == 0) && (strcmp(e2_type, "REAL") == 0) ){
        return "REAL";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support between %s, %s types!\n", op, e1_type, e2_type); yyerror(error_msg); 
}

char * handle_uminus_op(char*op, node *e1,node * e2){
    if(e1 == NULL || e2 == NULL){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    // left is expression, right is nothing.
    const char *e1_type =  eval_expression(e1);
    if(strcmp(e1_type, "INT") == 0){
        return "INT";
    }
    if(strcmp(e1_type, "REAL") == 0){
        return "REAL";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '-' doesn't support on %s type! only on INT/REAL\n", e1_type); yyerror(error_msg); 
}

char * handle_compare_op(char*op, node *e1,node * e2){
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    const char *e1_type =  eval_expression(e1); 
    const char *e2_type =  eval_expression(e2); 
    if((strcmp(e1_type, "INT") == 0) || (strcmp(e1_type, "REAL") == 0)){
        if((strcmp(e2_type, "INT") == 0) || (strcmp(e2_type, "REAL") == 0)){
            return "BOOL"; 
        }
    }

    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support between %s, %s types!\n", op, e1_type, e2_type); yyerror(error_msg); 
}
char * handle_compare_eq_op(char*op, node *e1, node * e2){
    if(e1 == NULL || e2 == NULL){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1); 
    char *e2_type =  eval_expression(e2); 
    if( (strcmp(e1_type, e2_type) == 0)){
        return "BOOL";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support between two diffrent (%s, %s) types!\n", op, e1_type, e2_type); yyerror(error_msg); 
}
char * handle_bool_op(char*op, node *e1, node * e2){
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1);
    if(e2->num_nodes == 0){ // NOT op with only left child! 
        if(strcmp(e1_type, "BOOL") == 0){
            return "BOOL";
        }
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on %s type. only on BOOL\n", op, e1_type); yyerror(error_msg); 
    }
    char *e2_type =  eval_expression(e2); 
    if((strcmp(e1_type, "BOOL") == 0) && (strcmp(e1_type, e2_type) == 0)){
        return "BOOL";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support between %s, %s types!\n", op, e1_type, e2_type); yyerror(error_msg); 
}
char * handle_string_char_op(char*op, node *e1, node * e2){
    // left child is ID, right is expression!
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    if(strcmp(e1->nodes[0]->token, "ID") != 0) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on literal type!\n", op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1);
    char *e2_type =  eval_expression(e2);
    if( (strcmp(e1_type, "STRING") == 0)){
        if((strcmp(e2_type, "INT") == 0)){
            if(strcmp(op, "[]") == 0){
                return "CHAR";
            }
            return "CHAR_PTR"; 
        }
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support indexing on non INT type, %s", op, e2_type); yyerror(error_msg);  
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on non STRING type, %s", op, e1_type); yyerror(error_msg); 
}

char * handle_string_int_op(char*op, node *e1, node * e2){
    // left child is ID, right is nothing.
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    if(strcmp(e1->nodes[0]->token, "ID") != 0) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on literal type!\n", op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1);
    if((strcmp(e1_type, "STRING") == 0)){
        return "INT";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on  %s type!", op, e1_type); yyerror(error_msg); 
}

char * handle_ptr_op(char*op, node *e1, node * e2){
    // left child is ID, right is nothing.
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    if(strcmp(e1->nodes[0]->token, "ID") != 0) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on literal type!\n", op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1);
    if((strcmp(e1_type, "INT_PTR") == 0)){
        return "INT";
    }
    if((strcmp(e1_type, "CHAR_PTR") == 0)){
        return "CHAR";
    }
    if((strcmp(e1_type, "REAL_PTR") == 0)){
        return "REAL";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on  %s type! only on X_PTR types!", op, e1_type); yyerror(error_msg); 
}

char * handle_address_op(char*op, node *e1, node * e2){
    // left child is ID, right is nothing.
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    if(strcmp(e1->nodes[0]->token, "ID") != 0) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on literal type!\n", op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1);
    // Change all to X_PTR?
    if((strcmp(e1_type, "INT") == 0)){
        return "INT_ADDRESS";
    }
    if((strcmp(e1_type, "CHAR") == 0) ){
        return "CHAR_ADDRESS";
    }
    if((strcmp(e1_type, "REAL") == 0)){
        return "REAL_ADDRESS";
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on  %s type!", op, e1_type); yyerror(error_msg); 
}

char * handle_dereferenced_op(char*op, node *e1, node * e2){
    // left child is (ID +/- EXPR), right is nothing.
    if(e1 == NULL || e2 == NULL) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Error reading parser in op '%s'\n",op); yyerror(error_msg); 
    }
    // e1 -> node('op',2, ID, EXPRESSION);
    if(strcmp(e1->nodes[0]->nodes[0]->token, "ID") != 0) {
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support on literal type!\n", op); yyerror(error_msg); 
    }
    char *e1_type =  eval_expression(e1->nodes[0]);
    char *e2_type =  eval_expression(e1->nodes[1]);
    if((strcmp(e1_type, "CHAR_PTR") == 0)){
        if((strcmp(e2_type, "INT") == 0)){
            return "CHAR";
        }else{
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' doesn't support between %s, %s types!\n", op, e1_type, e2_type); yyerror(error_msg); 
        }
    }
    char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "operator '%s' support only on CHAR_PTR type and not %s type!\n", op, e1_type); yyerror(error_msg); 
}
void eval_state_placement(node * tree){
    Var *v = lookup_var(tree->nodes[0]->token, 1); // search if the variable exists in scope.
    char *t1 = v->value;
    if(strcmp(tree->nodes[1]->token, "CALL") == 0){
        // check if the function returns the same type as var
        Var *f = lookup_var(tree->nodes[1]->nodes[0]->token, 1);
        check_func(f->id);
        char *t2 = f->value;
        if(strcmp(t1, t2) != 0){
            if(((strcmp(t1,"REAL") == 0) && (strcmp(t2,"INT") == 0)) || ((strcmp(t1,"INT_PTR") == 0) && (strcmp(t2,"INT_ADDRESS") == 0)) || ((strcmp(t1,"CHAR_PTR") == 0) && (strcmp(t2,"CHAR_ADDRESS") == 0)) || ((strcmp(t1,"REAL_PTR") == 0) && (strcmp(t2,"REAL_ADDRESS") == 0))){
                return;
            }
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "id \"%s\" and function \"%s\" returns diffrent types! %s,%s\n",v->id, f->id, t1, t2); yyerror(error_msg); 
        }
    }else{
        // Check if the expression is the same type as var
        char *t2 = eval_expression(tree->nodes[1]);
        if(strcmp(t2,"NULL") == 0) { 
            // Check pointer.
            if((strcmp(t1,"REAL_PTR") == 0) || (strcmp(t1,"INT_PTR") == 0) || (strcmp(t1,"CHAR_PTR") == 0)){
                return;
            }
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Cant assign %s to id:\"%s\" from NULL pointer type %s",t2, v->id, t1); yyerror(error_msg); 
        }
        if(strcmp(t1, t2) != 0){
            if(((strcmp(t1,"REAL") == 0) && (strcmp(t2,"INT") == 0)) || ((strcmp(t1,"INT_PTR") == 0) && (strcmp(t2,"INT_ADDRESS") == 0)) || ((strcmp(t1,"CHAR_PTR") == 0) && (strcmp(t2,"CHAR_ADDRESS") == 0)) || ((strcmp(t1,"REAL_PTR") == 0) && (strcmp(t2,"REAL_ADDRESS") == 0))){
                return;
            }
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Cant assign %s type to id:\"%s\" from type %s\n",t2, v->id, t1); yyerror(error_msg); 
        }
    }
}
// ID must be pointer type but final value can only be INT, REAL, CHAR because the dereference operator.
void eval_state_placement_ptr(node * tree){
    Var *v = lookup_var(tree->nodes[0]->token, 1); // search if the variable exists in scope.
    char *t1 = v->value;
    if(strcmp(t1,"INT_PTR") != 0 && strcmp(t1,"CHAR_PTR") != 0 && strcmp(t1,"REAL_PTR") != 0){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Cant dereference on non pointer type! on id:\"%s\" with type %s\n",v->id, t1); yyerror(error_msg); 
    }
    t1 = remove_ptr(t1);
    if(strcmp(tree->nodes[1]->token, "CALL") == 0){
        // check if the function returns the same type as var
        Var *f = lookup_var(tree->nodes[1]->nodes[0]->token, 1);
        check_func(f->id);
        char *t2 = f->value;
        if(strcmp(t1, t2) != 0){
            if((strcmp(t1,"REAL") == 0) && (strcmp(t2,"INT") == 0)){
                return;
            }
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "dereference on id \"%s\" and function \"%s\" returns diffrent types! %s,%s\n",v->id, f->id, t1, t2); yyerror(error_msg); 
        }
    }else{
        // Check if the expression is the same type as var
        char *t2 = eval_expression(tree->nodes[1]);
        if(strcmp(t2,"NULL") == 0) { 
            // * dereference is cannot be NULL!
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Cant assign %s to dereference on id:\"%s\"",t2, v->id); yyerror(error_msg); 
        }
        if(strcmp(t1, t2) != 0){
            if((strcmp(t1,"REAL") == 0) && (strcmp(t2,"INT") == 0)){
                return;
            }
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Cant assign %s type to dereference on id:\"%s\" from type %s\n",t2, v->id, t1); yyerror(error_msg); 
        }
    }
}

void eval_state_placement_str(node * tree){
    Var *v = lookup_var(tree->nodes[0]->token, 1); // search if the variable exists in scope.
    char *t1 = v->value;
    char *t2;
    char *t3;
    if(strcmp(t1,"STRING") != 0){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Can't assign non STRING type on id: %s!\n",v->id); yyerror(error_msg); 
    }
    t2 = eval_expression(tree->nodes[1]);
    if(strcmp(t2,"INT") != 0){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Can't index on STRING type with non INT type on id:\"%s\"!\n",v->id); yyerror(error_msg); 
    }

    if(strcmp(tree->nodes[2]->token, "CALL") == 0){
        // check if the function returns the same type as var
        Var *f = lookup_var(tree->nodes[2]->nodes[0]->token, 1);
        check_func(f->id);
        t3 = f->value;
        if(strcmp(t3, "CHAR") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "excpected CHAR but function %s returns %s\n", f->id, t3); yyerror(error_msg); 
        }
    }else{
        // Check if the expression is the same type as var
        t3 = eval_expression(tree->nodes[2]);
        if(strcmp(t3, "CHAR") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "statement %s[index] excpected CHAR but got %s instead\n",v->id, t3); yyerror(error_msg); 
        }
    }
}
void eval_ret(node * tree){
    int flag  = 1;
    char *f_id = start->scope->name;
    if(strcmp(f_id, "BLOCK") == 0){
        flag = 0;
        f_id = get_first_scope();
    }
    Var *f = lookup_var(f_id, 1);
    char *f_ret = f->value;
    
    char *ret_type = eval_expression(tree->nodes[0]);
    if(strcmp(ret_type, "STRING") == 0){
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "function \"%s\" cant return STRING!\n", f_id); yyerror(error_msg); 
    }
    if(strcmp(ret_type, f_ret) != 0){
        if(strcmp(f_ret, "REAL") != 0 && strcmp(ret_type, "INT") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "function \"%s\" return %s but excpect to return %s type \n", f_id, ret_type, f_ret); yyerror(error_msg); 
        }
    }
    f->ret = flag; // set flag to identify when function returned value or not.
}
void eval_IF_WHILE_FOR_exp(node * tree){
    // If the token is IF.. / WHILE.. then eval its exression first. index 0 - exp, 1 - block (print_tree handle the printing)
    if ((strcmp(tree->token , "IF") == 0) || (strcmp(tree->token , "IF-ELSE") == 0) || (strcmp(tree->token , "IF-ELIF") == 0) || (strcmp(tree->token , "IF-ELIF-ELSE") == 0)){
        char *t = eval_expression(tree->nodes[0]);
        if(strcmp(t, "BOOL") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "IF must get BOOL type expression! got %s instead\n", t); yyerror(error_msg); 
        }
    }
    if ((strcmp(tree->token , "ELIF") == 0) ){
        char *t = eval_expression(tree->nodes[0]);
        if(strcmp(t, "BOOL") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "ELIF must get BOOL type expression! got %s instead\n", t); yyerror(error_msg); 
        }
    }
    if (strcmp(tree->token , "WHILE") == 0){
        char *t = eval_expression(tree->nodes[0]);
        if(strcmp(t, "BOOL") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "WHILE must get BOOL type expression! got %s instead\n", t); yyerror(error_msg); 
        }
    }
    if (strcmp(tree->token , "DO-WHILE") == 0){
        char *t = eval_expression(tree->nodes[0]);
        if(strcmp(t, "BOOL") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "DO-WHILE must get BOOL type expression! got %s instead\n", t); yyerror(error_msg); 
        }
    }
    if (strcmp(tree->token , "FOR") == 0){
        char *t = eval_expression(tree->nodes[1]);
        if(strcmp(t, "BOOL") != 0){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "FOR must get BOOL type expression in the evaluation part! got %s instead\n", t); yyerror(error_msg); 
        }
    }
}

void eval_args_call(node* tree, Var *func){

    char **param_types = func->param_types;
    int count = 0;
    // iterate over the args and eval their type and comapre to the index of the iteration on the parameters types
    node *next = tree;
    while(next != NULL){
        char* arg_type = eval_expression(next->nodes[0]);
        if(strcmp(param_types[count], arg_type) != 0){
            if(strcmp(param_types[count],"REAL") == 0 && strcmp(arg_type,"INT") == 0){
                return;
            }
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "function %s got %s type intead of %s in par%d", func->id, arg_type, param_types[count], count + 1); yyerror(error_msg); 
        }
        count += 1;
        next = next->nodes[1];
    }
}

void eval_declaration_value(node *tree, const char *value_type){
    if(strcmp(tree->nodes[0]->token, value_type) != 0){
        if(((strcmp(value_type,"INT_PTR") == 0) || (strcmp(value_type, "CHAR_PTR") == 0) || (strcmp(value_type,"REAL_PTR") == 0)) && (strcmp(tree->nodes[0]->token, "NULL") == 0)){
            return; 
        }
        else if(((strcmp(value_type,"INT_PTR") == 0) || (strcmp(value_type, "CHAR_PTR") == 0) || (strcmp(value_type,"REAL_PTR") == 0)) && (strcmp(tree->nodes[0]->token, "NULL") != 0)){
            char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Cant declare pointer type %s with initial value other then NULL!", value_type); yyerror(error_msg); 
        }
        if(strcmp(value_type,"REAL") == 0 && strcmp(tree->nodes[0]->token, "INT") == 0){ 
            return;
        }
        char error_msg[256]; printf("\n"); snprintf(error_msg, sizeof(error_msg), "Declared value and initial value are not the same! (%s,%s)", value_type,tree->nodes[0]->token ); yyerror(error_msg); 
    }
    
}

void eval_allocated_strign_num(node *tree){
    if(strcmp(tree->nodes[0]->token, "INT") != 0 ){
        printf("\n"); yyerror("unauthorized action. cant allocate on NoN INT type");
    }
    int num_int = atoi(tree->token);
    bytes_per_function += num_int;
    if(num_int < 0){
        printf("\n"); yyerror("Cant allocate negative number on STRING!\n");
    }
}

char * remove_ptr(char *t_type){
    if(strcmp(t_type, "INT_PTR") == 0){
        return "INT";
    }
    if(strcmp(t_type, "CHAR_PTR") == 0){
        return "CHAR";
    }
    if(strcmp(t_type, "REAL_PTR") == 0){
        return "REAL";
    }
}

// 3AC:
char* get_new_temp(){
    char *temp = (char*)malloc(10 * sizeof(char));
    snprintf(temp, 10, "t%d", n_temp);
    n_temp++;
    return temp;
}
char* get_new_label(){
    char *temp = (char*)malloc(10 * sizeof(char));
    snprintf(temp, 10, "L%d", n_label);
    n_label++;
    return temp;
}
void insert_stack(char *var){
    stack_3ac[top] = strdup(var);
    top++;
}
void demote_stack(int amount){
    if(amount > top){
        yyerror("cant demote from stack\n");
    }
    while(amount > 0){
        free(stack_3ac[top - 1]);
        amount--;
        top--;
    }
}

// index: 0-func name, 1-params, 2-ret_type, 3-body_func(VAR dec BEG code_body END) 
void eval_func_3ac(node *root){
    int base_temp_count = n_temp;  // record starting temp index

    printf("%s:\n", root->nodes[0]->token); // function label


    // 2) Switch our emitter into a memory‐stream:
    emit_stream = open_memstream(&body_buf, &body_sz);
    if (!emit_stream) { perror("open_memstream"); exit(1); }

    eval_body_3ac(root->nodes[3]); // generate body

    // 4) Done generating:
    fflush(emit_stream);
    fclose(emit_stream);
    emit_stream = NULL; 

    // calculate number of temporaries used
    int temps_used = n_temp - base_temp_count;
    bytes_per_function += temps_used * 4;
    // print BeginFunc line now
    print_spaces(2); printf("BeginFunc %d\n", bytes_per_function);

    // 7) Dump the buffered body:
    fwrite(body_buf, 1, body_sz, stdout);
    free(body_buf);

    // and finally print EndFunc
    print_spaces(2); printf("EndFunc\n\n");

}

// func body could be with declerations and body or just body
void eval_body_3ac(node *body_node){
    node *statements;
    node *ret;
    if(strcmp(body_node->token,"BODY") == 0){  
        statements = body_node->nodes[0];
        ret = body_node->nodes[1];
    }else{
        statements = body_node->nodes[1]->nodes[0];
        ret = body_node->nodes[1]->nodes[1];
    }
    eval_statments_3ac(statements);
    eval_return_3ac(ret);
}

void eval_statments_3ac(node *statements){
    if(statements == NULL){
        return;
    }
    node *statement = statements->nodes[0];
    if(strcmp( statement->token, "=") == 0){
        eval_expression_3ac(statement->nodes[1]);
        print_spaces(2); emit("%s = %s\n", statement->nodes[0]->token, stack_3ac[top-1]);
        demote_stack(1);
    }
    else if(strcmp(statement->token, "[]=") == 0){
        eval_expression_3ac(statement->nodes[1]);
        eval_expression_3ac(statement->nodes[2]);
        char *address = get_new_temp();
        print_spaces(2); emit("%s = &id %s\n",address, statement->nodes[0]->token);
        char *address_index = get_new_temp();
        print_spaces(2); emit("%s = %s + %s\n",address_index, address, stack_3ac[top-2]);
        print_spaces(2); emit("*id %s = %s\n",address_index, stack_3ac[top-1]);
        demote_stack(2);

        // // calc the bytes on address(4) address+index(4)
        // bytes_per_function += 8;
    }
    else if(strcmp(statement->token, "*=") == 0){
        eval_expression_3ac(statement->nodes[1]);
        print_spaces(2); emit("*id %s = %s\n", statement->nodes[0]->token, stack_3ac[top-1]);
        demote_stack(1);
    }
    else if(strcmp(statement->token, "CALL") == 0){
        eval_function_call_3ac(statement->nodes[1]->nodes[0]);
        if(is_return_value(statement->nodes[0]->token)){
            char *temp = get_new_temp();
            print_spaces(2); emit("%s = Lcall %s\n",temp, statement->nodes[0]->token);

            // calc the bytes based on the return value?
            // bytes_per_function += return_bytes_value(statement->nodes[0]->token);
        }else{
            print_spaces(2); emit("Lcall %s\n", statement->nodes[0]->token);
        }

        int bytes_args = calc_bytes_args(statement->nodes[0]->token);
        if(bytes_args > 0){
            print_spaces(2); emit("PopParams %d\n", bytes_args);
        }

    }
    else if(strcmp(statement->token, "IF") == 0){
        eval_if_3ac(statement);
    }
    else if(strcmp(statement->token, "IF-ELSE") == 0){
        eval_if_else_3ac(statement);
    }
    else if(strcmp(statement->token, "IF-ELIF") == 0 || strcmp(statement->token, "IF-ELIF-ELSE") == 0){
        eval_if_elif_3ac(statement);
    }
    else if(strcmp(statement->token, "WHILE") == 0 || strcmp(statement->token, "DO-WHILE") == 0){
        eval_all_while_3ac(statement);
    }
    else if(strcmp(statement->token, "FOR") == 0){
        eval_for_3ac(statement);
    }
    else if(strcmp(statement->token, "BLOCK") == 0){
        eval_block_3ac(statement);
    }
    if(strcmp(statement->token, "FUNC") == 0){
        print_spaces(2); emit("Def function %s\n",statement->nodes[0]->token );
    }

    eval_statments_3ac(statements->nodes[1]); // eval next statement.
}

// index 0-RET(expression) | NULL
void eval_return_3ac(node *ret){
    if(ret == NULL){
        return;
    }
    eval_expression_3ac(ret->nodes[0]);
    print_spaces(2); emit("Return %s\n", stack_3ac[top - 1]);
    demote_stack(1);
}

void eval_expression_3ac(node *node){
    if(node == NULL){
        return;
    }

    // id / value
    if (node->num_nodes == 1){
        insert_stack(node->token);
        return;
    }

    // Unary operator
    if(is_operator(node->token) && strcmp(node->nodes[1]->token, "") == 0){
        eval_expression_3ac(node->nodes[0]);
        char *temp = get_new_temp();
        if(strcmp(node->token,"u-") == 0){
            print_spaces(2); emit("%s = -%s\n", temp, stack_3ac[top-1]);
        }else if(strcmp(node->token,"*()") == 0){
            print_spaces(2); emit("%s = *id %s\n", temp, stack_3ac[top-1]);
        }else{
            print_spaces(2); emit("%s = %s %s\n", temp, node->token, stack_3ac[top-1]);
        }

        demote_stack(1);
        insert_stack(temp);
        return;
    }

    // Binary operator
    if(is_operator(node->token)){
        eval_expression_3ac(node->nodes[0]);
        eval_expression_3ac(node->nodes[1]);
        if(strcmp(node->token, "[]") == 0){
            eval_dereference_arr();
            return;
        }
        if(strcmp(node->token, "&[]") == 0){
            eval_address_arr();
            return;
        }
        
        char *temp = get_new_temp();
        print_spaces(2); emit("%s = %s %s %s\n", temp, stack_3ac[top-2], node->token, stack_3ac[top-1]);
        demote_stack(2);
        insert_stack(temp);
        return;
    }

    // Function call
    if(strcmp(node->token, "CALL") == 0){
        eval_function_call_3ac(node->nodes[1]->nodes[0]);
        char *temp = get_new_temp();
        print_spaces(2); emit("%s = Lcall %s\n", temp, node->nodes[0]->token);
        insert_stack(temp);
        int bytes_args = calc_bytes_args(node->nodes[0]->token);
        if(bytes_args > 0){
            print_spaces(2); emit("PopParams %d\n", bytes_args);
        }
        return;
    }

    yyerror("error 3AC in eval expression\n");
}

void eval_function_call_3ac(node* node){
    int num = 0;
    if(node->num_nodes == 2){
        num = eval_args_3ac(node);
    }
    if(num > 0){
        while(num > 0){
            print_spaces(2); emit("PushParams");
            emit(" %s \n", stack_3ac[top -1]);
            demote_stack(1);
            num--;
        }
    }
}

int eval_args_3ac(node * node){
    if (node == NULL){
        return 0;
    }
    eval_expression_3ac(node->nodes[0]);
    return eval_args_3ac(node->nodes[1]) + 1;
}

// Short-circuit condition
// The third value is for nested AND inside OR so that the left label is not printed (null specify the left son and keep checking the right son withtout unneccesary labels) 
// and to still have the end label for the AND to jump to.
void eval_expression_sc_3ac(node *expr, const char *Ltrue, const char *Lfalse, const char* temp) {
    if (expr == NULL) return;
    if (strcmp(expr->token, "and") == 0) {
        char *Lmid = get_new_label();
        // A AND B: if A true jump to evaluate B, else jump to lfalse
        // if B true, jump to Ltrue else jump to Lfalse
        eval_expression_sc_3ac(expr->nodes[0],Lmid , temp, temp);
        print_spaces(1); emit("%s:\n", Lmid);
        eval_expression_sc_3ac(expr->nodes[1], Ltrue, temp, temp);
        free(Lmid);
    }
    else if (strcmp(expr->token, "or") == 0) {
        // A or B: if A true -> Ltrue, else evaluate B
        eval_expression_sc_3ac(expr->nodes[0], Ltrue, NULL, temp);
        eval_expression_sc_3ac(expr->nodes[1], Ltrue, temp, temp);
    }
    else {
        // base operation, eval the expression and then use it
        eval_expression_3ac(expr);
        print_spaces(2); emit("If %s goto %s\n", stack_3ac[top-1], Ltrue);
        demote_stack(1);
        if(Lfalse != NULL){
            print_spaces(2); emit("goto %s\n", Lfalse);
        }
    }
}

// index 0-exp, 1-block/statement
void eval_if_3ac(node *node) {
    char *Ltrue  = get_new_label();
    char *Lfalse = get_new_label();

    // eval Short-circuit condition
    eval_expression_sc_3ac(node->nodes[0], Ltrue, Lfalse, Lfalse);

    // if-body
    print_spaces(1); emit("%s:\n", Ltrue);
    eval_block_3ac(node->nodes[1]);

    // false
   print_spaces(1); emit("%s:\n", Lfalse);
   free(Ltrue); free(Lfalse);
}

// Updated IF-ELSE without temps
void eval_if_else_3ac(node *node) {
    char *Lthen   = get_new_label();
    char *Lelse   = get_new_label();
    char *Lend    = get_new_label();
    // eval Short-circuit condition
    eval_expression_sc_3ac(node->nodes[0], Lthen, Lelse, Lelse);
    // if-body
    print_spaces(1); emit("%s:\n", Lthen);
    eval_block_3ac(node->nodes[1]);
    print_spaces(2); emit("goto %s\n", Lend);
    // else:
    print_spaces(1); emit("%s:\n", Lelse);
    eval_block_3ac(node->nodes[2]);
    // false
    print_spaces(1); emit("%s:\n", Lend);
    free(Lthen); free(Lelse);free(Lend);
}

// index 0-exp, 1-block/statement, 2-elif | 3-else
void eval_if_elif_3ac(node *node){
    char *Lthen   = get_new_label();
    char *Lelif   = get_new_label();
    char *Lend    = get_new_label();
    // eval Short-circuit condition
    eval_expression_sc_3ac(node->nodes[0], Lthen, Lelif, Lelif);
    // if-body
    print_spaces(1); emit("%s:\n", Lthen);
    eval_block_3ac(node->nodes[1]);
    print_spaces(2); emit("goto %s\n", Lend);
    // else: eval recursive elifs:
    print_spaces(1); emit("%s:\n", Lelif);
    
    if(node->num_nodes == 4){ // handle if_elifs_else
        char *Lelse = get_new_label();
        eval_elifs_3ac(node->nodes[2], Lend, Lelse);
        print_spaces(1); emit("%s:\n", Lelse);
        eval_block_3ac(node->nodes[3]);
        free(Lelse);
    }else{
        eval_elifs_3ac(node->nodes[2], Lend, NULL);
    }
    // end
    print_spaces(1); emit("%s:\n", Lend);
    free(Lthen); free(Lelif);free(Lend);
}

// index 0-exp, 1-block/statement, 2-next-elif/null
void eval_elifs_3ac(node *node, const char* Lend, const char* Lif_else){
    if(node == NULL){
        return;
    }
    char *Lthen = get_new_label();
    char *Lelse;
    int flag_to_clear = 0;

    if(node->nodes[2] != NULL){
        flag_to_clear = 1;
        Lelse = get_new_label(); 
    }else{  // last elif
        if(Lif_else != NULL){ // has another else after this elif
            Lelse = strdup(Lif_else);
        }else{
            Lelse = strdup(Lend);
        }
    }
    eval_expression_sc_3ac(node->nodes[0], Lthen, Lelse, Lelse);
    // if-body
    print_spaces(1); emit("%s:\n", Lthen);
    eval_block_3ac(node->nodes[1]);
    
    if(node->nodes[2] != NULL){
        // else:
        print_spaces(2); emit("goto %s\n", Lend);
        print_spaces(1); emit("%s:\n", Lelse);
        eval_elifs_3ac(node->nodes[2], Lend, Lif_else);
    }
    if(flag_to_clear)free(Lelse);
    free(Lthen);
}

// can be BLOCK(DECL(decs, BODY(statements)), ret) OR BLOCK(statements, ret) OR statements
void eval_block_3ac(node* root_block){
    node *statements;
    if(strcmp(root_block->token, "BLOCK") == 0){ 
        if(strcmp(root_block->nodes[0]->token, "DECL") == 0){
            statements = root_block->nodes[0]->nodes[1]->nodes[0]; // get the statements from the body. (different from the first body)
        }
        else{
            statements = root_block->nodes[0];
        }
    }else{
        statements = mknode("",1,root_block);
    }

    eval_statments_3ac(statements);
}

// index 0-exp, 1-block/statement
void eval_all_while_3ac(node *node){
    char *Lstart = get_new_label();
    char *Ltrue  = get_new_label();
    char *Lfalse = get_new_label();

    // start of the loop
    print_spaces(1);emit("%s:\n", Lstart);
    // eval Short-circuit condition
    eval_expression_sc_3ac(node->nodes[0], Ltrue, Lfalse, Lfalse);

    // while-body
    print_spaces(1);emit("%s:\n", Ltrue);
    eval_block_3ac(node->nodes[1]);
    print_spaces(2); emit("goto %s\n", Lstart);
    // false
    print_spaces(1);emit("%s:\n", Lfalse);
    free(Lstart); free(Ltrue);free(Lfalse);
}

// index 0-init_exp("="(id,exp)), 1-eval_exp, 2-update_exp, 3-block/statement
void eval_for_3ac(node *for_root){
    char *Lstart = get_new_label();
    char *Ltrue  = get_new_label();
    char *Lfalse = get_new_label();

    // eval init_exp 
    eval_statments_3ac(for_root->nodes[0]);
    // start of the loop
    print_spaces(1);emit("%s:\n", Lstart);
    // eval Short-circuit condition
    eval_expression_sc_3ac(for_root->nodes[1], Ltrue, Lfalse, Lfalse);
    // for-body
    print_spaces(1);emit("%s:\n", Ltrue);
    eval_block_3ac(for_root->nodes[3]);
    // eval update
    eval_statments_3ac(for_root->nodes[2]);
    print_spaces(2); emit("goto %s\n", Lstart);
    // false
    print_spaces(1);emit("%s:\n", Lfalse);
    free(Lstart); free(Ltrue);free(Lfalse);
}

int calc_bytes_args(char *func_name){
    Var *f = lookup_var(func_name, 1);
    int params_count = f->param_count;
    char **params = f->param_types;
    int sum_bytes = 0;
    while(params_count > 0){
        sum_bytes += byte_size_per_type(params[params_count-1]);
        params_count--;
    }
    return sum_bytes;
}

int calc_bytes_declared(char *func_name){
    Symbol_table *curr = start->scope;
    Var *variable = curr->first;
    int sum_declared_bytes = 0;

    while(variable != NULL){
        if(strcmp(variable->typeVar, "VAR") == 0){
            if(strcmp(variable->value, "STRING") == 0){
                sum_declared_bytes += variable->size;
            }else{
                sum_declared_bytes += byte_size_per_type(variable->value);
            }
        }
        variable = variable->next;
    }
    return sum_declared_bytes;
}

void eval_dereference_arr(){ // left child is ID right is expression id = string[expression]
    if(top<1){
        yyerror("error in eval arr\n");
    }
    char *address = get_new_temp();
    print_spaces(2); emit("%s = &id %s\n",address, stack_3ac[top-2]);
    char *address_index = get_new_temp();
    print_spaces(2); emit("%s = %s + %s\n",address_index, address, stack_3ac[top-1]);
    char *value = get_new_temp();
    print_spaces(2); emit("%s = *id %s\n",value, address_index);
    demote_stack(2);
    insert_stack(value);
}

void eval_address_arr(){ // eval the address from &string[expression]
    if(top<1){
        yyerror("error in eval arr\n");
    }
    char *address = get_new_temp();
    print_spaces(2); emit("%s = &id %s\n",address, stack_3ac[top-2]);
    char *address_index = get_new_temp();
    print_spaces(2); emit("%s = %s + %s\n",address_index, address, stack_3ac[top-1]);
    demote_stack(2);
    insert_stack(address_index);
}

int byte_size_per_type(char *type_var){
    if(strcmp(type_var, "CHAR") == 0 || strcmp(type_var, "BOOL") == 0){
        return 1;
    }
    else if(strcmp(type_var, "INT") == 0 || strcmp(type_var, "INT_PTR") == 0 || strcmp(type_var, "CHAR_PTR") == 0 || strcmp(type_var, "REAL_PTR") == 0){
        return 4;
    }else{
        return 8;
    }
}
// check if funtion returns value
int is_return_value(char *f_id){
    Var *f = lookup_var(f_id, 1);
    if(strcmp(f->value, "RET_NONE") == 0){
        return 0;
    }
    return 1;
}

int return_bytes_value(char *f_id){
    Var *f = lookup_var(f_id, 1);
    byte_size_per_type(f->value);
}


char * return_temp_type(char *temp){
    char *index_string = temp + 1;
    int index = atoi(index_string);
    if(index >= MAX_TEMPS){
        yyerror("allocate more memory to temps in MAX_TEMPS\n");
    }
    return temp_types[index];
}

void insert_temp_type(char *temp, char* temp_type){
    char *index_string = temp + 1;
    int index = atoi(index_string);
    if(index >= MAX_TEMPS){
        yyerror("allocate more memory to temps in MAX_TEMPS\n");
    }
    temp_types[index] = temp_type;
}


char * return_id_type(char *id){
    Var *v = lookup_var(id,1);
    return v->value;
}

int is_var(char *id){
    Var *v = lookup_var(id,1);
    if(strcmp(v->typeVar, "VAR") == 0){
        return 1;
    }
    return 0;
}