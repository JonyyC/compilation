/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "part3.y"

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

#line 250 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BOOL_TOK = 258,                /* BOOL_TOK  */
    CHAR_TOK = 259,                /* CHAR_TOK  */
    INT_TOK = 260,                 /* INT_TOK  */
    REAL_TOK = 261,                /* REAL_TOK  */
    STRING_TOK = 262,              /* STRING_TOK  */
    INT_PTR = 263,                 /* INT_PTR  */
    CHAR_PTR = 264,                /* CHAR_PTR  */
    REAL_PTR = 265,                /* REAL_PTR  */
    PAR = 266,                     /* PAR  */
    BOOL = 267,                    /* BOOL  */
    CHAR = 268,                    /* CHAR  */
    INT = 269,                     /* INT  */
    REAL = 270,                    /* REAL  */
    STRING = 271,                  /* STRING  */
    VOID = 272,                    /* VOID  */
    ID = 273,                      /* ID  */
    IF = 274,                      /* IF  */
    ELIF = 275,                    /* ELIF  */
    ELSE = 276,                    /* ELSE  */
    WHILE = 277,                   /* WHILE  */
    FOR = 278,                     /* FOR  */
    DO = 279,                      /* DO  */
    VAR = 280,                     /* VAR  */
    BEG = 281,                     /* BEG  */
    END = 282,                     /* END  */
    DEF = 283,                     /* DEF  */
    CALL = 284,                    /* CALL  */
    NULL_TOK = 285,                /* NULL_TOK  */
    RETURN = 286,                  /* RETURN  */
    RETURNS = 287,                 /* RETURNS  */
    MAIN = 288,                    /* MAIN  */
    type = 289,                    /* type  */
    AND = 290,                     /* AND  */
    NOT = 291,                     /* NOT  */
    OR = 292,                      /* OR  */
    EQ = 293,                      /* EQ  */
    GE = 294,                      /* GE  */
    LE = 295,                      /* LE  */
    NE = 296,                      /* NE  */
    LOWER_THAN_ELSE = 297,         /* LOWER_THAN_ELSE  */
    UMINUS = 298                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL_TOK 258
#define CHAR_TOK 259
#define INT_TOK 260
#define REAL_TOK 261
#define STRING_TOK 262
#define INT_PTR 263
#define CHAR_PTR 264
#define REAL_PTR 265
#define PAR 266
#define BOOL 267
#define CHAR 268
#define INT 269
#define REAL 270
#define STRING 271
#define VOID 272
#define ID 273
#define IF 274
#define ELIF 275
#define ELSE 276
#define WHILE 277
#define FOR 278
#define DO 279
#define VAR 280
#define BEG 281
#define END 282
#define DEF 283
#define CALL 284
#define NULL_TOK 285
#define RETURN 286
#define RETURNS 287
#define MAIN 288
#define type 289
#define AND 290
#define NOT 291
#define OR 292
#define EQ 293
#define GE 294
#define LE 295
#define NE 296
#define LOWER_THAN_ELSE 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOL_TOK = 3,                   /* BOOL_TOK  */
  YYSYMBOL_CHAR_TOK = 4,                   /* CHAR_TOK  */
  YYSYMBOL_INT_TOK = 5,                    /* INT_TOK  */
  YYSYMBOL_REAL_TOK = 6,                   /* REAL_TOK  */
  YYSYMBOL_STRING_TOK = 7,                 /* STRING_TOK  */
  YYSYMBOL_INT_PTR = 8,                    /* INT_PTR  */
  YYSYMBOL_CHAR_PTR = 9,                   /* CHAR_PTR  */
  YYSYMBOL_REAL_PTR = 10,                  /* REAL_PTR  */
  YYSYMBOL_PAR = 11,                       /* PAR  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_REAL = 15,                      /* REAL  */
  YYSYMBOL_STRING = 16,                    /* STRING  */
  YYSYMBOL_VOID = 17,                      /* VOID  */
  YYSYMBOL_ID = 18,                        /* ID  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELIF = 20,                      /* ELIF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_VAR = 25,                       /* VAR  */
  YYSYMBOL_BEG = 26,                       /* BEG  */
  YYSYMBOL_END = 27,                       /* END  */
  YYSYMBOL_DEF = 28,                       /* DEF  */
  YYSYMBOL_CALL = 29,                      /* CALL  */
  YYSYMBOL_NULL_TOK = 30,                  /* NULL_TOK  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_RETURNS = 32,                   /* RETURNS  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_type = 34,                      /* type  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_EQ = 38,                        /* EQ  */
  YYSYMBOL_GE = 39,                        /* GE  */
  YYSYMBOL_LE = 40,                        /* LE  */
  YYSYMBOL_NE = 41,                        /* NE  */
  YYSYMBOL_LOWER_THAN_ELSE = 42,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* '|'  */
  YYSYMBOL_59_ = 59,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_funcs = 62,                     /* funcs  */
  YYSYMBOL_func = 63,                      /* func  */
  YYSYMBOL_parameter_list = 64,            /* parameter_list  */
  YYSYMBOL_ret_type = 65,                  /* ret_type  */
  YYSYMBOL_TYPE_TOK = 66,                  /* TYPE_TOK  */
  YYSYMBOL_TYPE_VALUE = 67,                /* TYPE_VALUE  */
  YYSYMBOL_func_body = 68,                 /* func_body  */
  YYSYMBOL_ret = 69,                       /* ret  */
  YYSYMBOL_declaration = 70,               /* declaration  */
  YYSYMBOL_declarations = 71,              /* declarations  */
  YYSYMBOL_IDS = 72,                       /* IDS  */
  YYSYMBOL_IDS_S = 73,                     /* IDS_S  */
  YYSYMBOL_code_body = 74,                 /* code_body  */
  YYSYMBOL_statements = 75,                /* statements  */
  YYSYMBOL_statement = 76,                 /* statement  */
  YYSYMBOL_elifs = 77,                     /* elifs  */
  YYSYMBOL_block = 78,                     /* block  */
  YYSYMBOL_init = 79,                      /* init  */
  YYSYMBOL_update = 80,                    /* update  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_function_call = 82,             /* function_call  */
  YYSYMBOL_args = 83,                      /* args  */
  YYSYMBOL_argument_list = 84              /* argument_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      50,    51,    47,    45,    54,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    53,
      44,    57,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   207,   207,   208,   209,   211,   213,   214,   215,   217,
     218,   220,   220,   220,   220,   221,   221,   221,   223,   223,
     223,   223,   223,   223,   225,   226,   228,   229,   232,   233,
     236,   237,   239,   240,   241,   242,   244,   245,   246,   247,
     249,   251,   252,   254,   255,   256,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   270,   271,   273,   274,
     276,   277,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   297,   298,
     299,   300,   301,   302,   304,   306,   307,   310,   312,   313,
     315,   316
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BOOL_TOK", "CHAR_TOK",
  "INT_TOK", "REAL_TOK", "STRING_TOK", "INT_PTR", "CHAR_PTR", "REAL_PTR",
  "PAR", "BOOL", "CHAR", "INT", "REAL", "STRING", "VOID", "ID", "IF",
  "ELIF", "ELSE", "WHILE", "FOR", "DO", "VAR", "BEG", "END", "DEF", "CALL",
  "NULL_TOK", "RETURN", "RETURNS", "MAIN", "type", "AND", "NOT", "OR",
  "EQ", "GE", "LE", "NE", "LOWER_THAN_ELSE", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "'('", "')'", "':'", "';'", "','", "'['", "']'",
  "'='", "'|'", "'&'", "$accept", "program", "funcs", "func",
  "parameter_list", "ret_type", "TYPE_TOK", "TYPE_VALUE", "func_body",
  "ret", "declaration", "declarations", "IDS", "IDS_S", "code_body",
  "statements", "statement", "elifs", "block", "init", "update",
  "expression", "function_call", "args", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,    19,    30,  -196,    -5,     4,  -196,  -196,    62,   461,
      27,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    33,    46,
      90,    72,    56,   461,    57,    62,  -196,    78,    68,  -196,
    -196,   453,    78,    92,   -44,    87,    87,    63,    67,    78,
      68,   102,   103,  -196,    91,  -196,    68,  -196,    71,    80,
      83,  -196,    68,    87,    87,  -196,  -196,  -196,  -196,  -196,
      75,  -196,    87,    87,    -8,    87,   120,   121,  -196,   289,
    -196,   305,   122,    68,   115,    91,    93,   105,    87,   117,
    -196,  -196,   129,   131,    91,   113,   187,    87,   407,  -196,
    -196,   145,   337,   106,   110,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    68,    68,   116,
     114,   148,    68,   147,    87,    87,   204,  -196,   136,   119,
     -11,   124,   178,   118,  -196,   141,   -19,  -196,  -196,    87,
     407,   396,    12,     1,     1,    12,     1,     1,    41,    41,
    -196,  -196,    86,  -196,    87,    87,   166,    91,  -196,   169,
     168,  -196,   221,  -196,   206,  -196,    20,   131,  -196,  -196,
      87,  -196,    87,    87,   155,    87,   177,   200,   382,   238,
      87,   209,    87,  -196,  -196,   181,   184,  -196,   255,   352,
     367,  -196,   321,    68,   194,   235,   272,  -196,  -196,    22,
     131,  -196,  -196,  -196,    68,  -196,    68,   197,   212,  -196,
     239,   129,  -196,   250,  -196,    87,   219,   218,  -196,  -196,
     382,    68,   129,  -196,  -196
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     1,     3,     8,     0,
       0,    11,    12,    13,    14,    15,    16,    17,     0,     0,
       0,    10,     7,     0,     0,     8,     9,    30,    42,     5,
       6,     0,    30,     0,     0,     0,     0,     0,     0,    30,
      42,     0,     0,    54,    27,    40,    42,    55,     0,     0,
       0,    31,    42,     0,     0,    18,    19,    20,    21,    22,
      85,    23,     0,     0,     0,     0,     0,     0,    86,     0,
      84,     0,     0,     0,     0,    27,     0,     0,     0,     0,
      41,    46,     0,     0,    27,     0,     0,     0,    76,    64,
      78,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    89,     0,     0,    25,     0,     0,
      35,     0,     0,     0,    43,     0,     0,    62,    77,     0,
      74,    75,    70,    71,    72,    73,    68,    69,    63,    65,
      66,    67,    47,    51,     0,     0,     0,    27,    59,    91,
       0,    88,     0,    26,     0,    29,     0,     0,    28,    24,
       0,    83,     0,     0,     0,     0,     0,    49,    60,     0,
       0,     0,     0,    87,    45,     0,    33,    34,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    58,    90,    39,
       0,    44,    79,    80,     0,    48,     0,     0,     0,    52,
       0,     0,    32,    56,    50,     0,     0,    37,    38,    57,
      61,     0,     0,    53,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   276,    21,   262,  -196,   -15,   132,  -196,   -70,
    -196,   -17,  -150,  -195,   237,   -37,   -69,    94,  -196,  -196,
    -196,   -34,   -28,  -196,   133
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    43,    10,    24,    18,    68,    29,    79,
      32,    33,   121,   119,    44,    45,    46,   167,    47,   110,
     198,   149,    70,   150,   151
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    69,    71,    75,   111,   113,   208,   177,    26,    80,
      90,    53,    48,    54,   122,    51,    50,   214,    48,    85,
      86,     4,    74,     1,    48,     4,   162,   163,    88,    89,
       6,    92,    55,    56,    57,    58,    59,     5,   142,   143,
     202,   156,    91,   157,   116,    48,   103,   104,   105,   106,
      61,    98,    99,   125,     8,   101,   102,   103,   104,   105,
     106,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     9,   200,   147,   201,   171,    19,    48,
      48,   152,    27,    28,    48,    20,    34,    35,   105,   106,
      36,    37,    38,    39,    40,   164,     1,    41,    21,    55,
      56,    57,    58,    59,    23,    60,   165,   166,    22,    25,
     168,   169,    31,    72,   195,    42,    41,    61,    52,    73,
      76,    77,    78,    62,    81,   203,   178,   204,   179,   180,
      87,   182,    82,    63,    64,    83,   186,    65,    93,    94,
     109,   112,   213,   114,   117,    66,    67,   118,    95,   120,
      96,    97,    98,    99,   100,    48,   101,   102,   103,   104,
     105,   106,   115,   126,   128,   129,    48,   145,    48,   123,
     146,   210,   155,   144,   148,   160,    95,   158,    96,    97,
      98,    99,   100,    48,   101,   102,   103,   104,   105,   106,
      95,   154,    96,    97,    98,    99,   100,   161,   101,   102,
     103,   104,   105,   106,    95,   159,    96,    97,    98,    99,
     100,   181,   101,   102,   103,   104,   105,   106,   170,   173,
     175,   184,    95,   172,    96,    97,    98,    99,   100,   183,
     101,   102,   103,   104,   105,   106,   187,   189,   190,    95,
     124,    96,    97,    98,    99,   100,   196,   101,   102,   103,
     104,   105,   106,   197,   205,   207,    95,   153,    96,    97,
      98,    99,   100,   206,   101,   102,   103,   104,   105,   106,
     165,   211,   212,    95,   174,    96,    97,    98,    99,   100,
       7,   101,   102,   103,   104,   105,   106,    30,   176,    84,
      95,   185,    96,    97,    98,    99,   100,   209,   101,   102,
     103,   104,   105,   106,     0,   188,     0,    95,   191,    96,
      97,    98,    99,   100,     0,   101,   102,   103,   104,   105,
     106,     0,     0,     0,    95,   199,    96,    97,    98,    99,
     100,     0,   101,   102,   103,   104,   105,   106,     0,     0,
      95,   107,    96,    97,    98,    99,   100,     0,   101,   102,
     103,   104,   105,   106,     0,     0,    95,   108,    96,    97,
      98,    99,   100,     0,   101,   102,   103,   104,   105,   106,
       0,     0,    95,   194,    96,    97,    98,    99,   100,     0,
     101,   102,   103,   104,   105,   106,     0,    95,   127,    96,
      97,    98,    99,   100,     0,   101,   102,   103,   104,   105,
     106,     0,    95,   192,    96,    97,    98,    99,   100,     0,
     101,   102,   103,   104,   105,   106,     0,    95,   193,    96,
      97,    98,    99,   100,     0,   101,   102,   103,   104,   105,
     106,    95,     0,     0,    97,    98,    99,   100,     0,   101,
     102,   103,   104,   105,   106,    97,    98,    99,   100,     0,
     101,   102,   103,   104,   105,   106,    11,    12,    13,    14,
      49,    15,    16,    17,    11,    12,    13,    14,     0,    15,
      16,    17
};

static const yytype_int16 yycheck[] =
{
      28,    35,    36,    40,    73,    75,   201,   157,    23,    46,
      18,    55,    40,    57,    84,    32,    31,   212,    46,    53,
      54,     0,    39,    28,    52,     4,    45,    46,    62,    63,
       0,    65,    12,    13,    14,    15,    16,    18,   107,   108,
     190,    52,    50,    54,    78,    73,    45,    46,    47,    48,
      30,    39,    40,    87,    50,    43,    44,    45,    46,    47,
      48,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    11,    52,   112,    54,   147,    51,   107,
     108,   115,    25,    26,   112,    52,    18,    19,    47,    48,
      22,    23,    24,    25,    26,   129,    28,    29,    52,    12,
      13,    14,    15,    16,    32,    18,    20,    21,    18,    53,
     144,   145,    34,    50,   183,    47,    29,    30,    26,    52,
      18,    18,    31,    36,    53,   194,   160,   196,   162,   163,
      55,   165,    52,    46,    47,    52,   170,    50,    18,    18,
      18,    26,   211,    50,    27,    58,    59,    18,    35,    18,
      37,    38,    39,    40,    41,   183,    43,    44,    45,    46,
      47,    48,    57,    18,    58,    55,   194,    53,   196,    56,
      22,   205,    53,    57,    27,    57,    35,    53,    37,    38,
      39,    40,    41,   211,    43,    44,    45,    46,    47,    48,
      35,    55,    37,    38,    39,    40,    41,    56,    43,    44,
      45,    46,    47,    48,    35,    27,    37,    38,    39,    40,
      41,    56,    43,    44,    45,    46,    47,    48,    52,    51,
      14,    21,    35,    54,    37,    38,    39,    40,    41,    52,
      43,    44,    45,    46,    47,    48,    27,    56,    54,    35,
      53,    37,    38,    39,    40,    41,    52,    43,    44,    45,
      46,    47,    48,    18,    57,    16,    35,    53,    37,    38,
      39,    40,    41,    51,    43,    44,    45,    46,    47,    48,
      20,    52,    54,    35,    53,    37,    38,    39,    40,    41,
       4,    43,    44,    45,    46,    47,    48,    25,   156,    52,
      35,    53,    37,    38,    39,    40,    41,   203,    43,    44,
      45,    46,    47,    48,    -1,   172,    -1,    35,    53,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    35,    53,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      35,    52,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,    35,    52,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,    -1,    35,    52,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    -1,    35,    51,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    -1,    35,    51,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    -1,    35,    51,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    35,    -1,    -1,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,     3,     4,     5,     6,
       7,     8,     9,    10,     3,     4,     5,     6,    -1,     8,
       9,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    61,    62,    63,    18,     0,    62,    50,    11,
      64,     3,     4,     5,     6,     8,     9,    10,    66,    51,
      52,    52,    18,    32,    65,    53,    66,    25,    26,    68,
      64,    34,    70,    71,    18,    19,    22,    23,    24,    25,
      26,    29,    47,    63,    74,    75,    76,    78,    82,     7,
      66,    71,    26,    55,    57,    12,    13,    14,    15,    16,
      18,    30,    36,    46,    47,    50,    58,    59,    67,    81,
      82,    81,    50,    52,    71,    75,    18,    18,    31,    69,
      75,    53,    52,    52,    74,    81,    81,    55,    81,    81,
      18,    50,    81,    18,    18,    35,    37,    38,    39,    40,
      41,    43,    44,    45,    46,    47,    48,    52,    52,    18,
      79,    76,    26,    69,    50,    57,    81,    27,    18,    73,
      18,    72,    69,    56,    53,    81,    18,    51,    58,    55,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    76,    76,    57,    53,    22,    75,    27,    81,
      83,    84,    81,    53,    55,    53,    52,    54,    53,    27,
      57,    56,    45,    46,    81,    20,    21,    77,    81,    81,
      52,    69,    54,    51,    53,    14,    67,    72,    81,    81,
      81,    56,    81,    52,    21,    53,    81,    27,    84,    56,
      54,    53,    51,    51,    52,    76,    52,    18,    80,    53,
      52,    54,    72,    76,    76,    57,    51,    16,    73,    77,
      81,    52,    54,    76,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    64,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    83,    83,
      84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     8,     6,     4,     0,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     4,     3,     0,     5,     5,
       0,     2,     5,     3,     3,     1,     8,     6,     6,     4,
       1,     2,     0,     4,     7,     5,     2,     4,     7,     5,
       8,     4,     7,    10,     1,     1,     4,     5,     6,     4,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     6,
       6,     2,     5,     4,     1,     1,     1,     5,     1,     0,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: funcs  */
#line 207 "part3.y"
               {yyval.node = mknode("PROGRAM",1, yyvsp[0]);print_tree(yyval.node, 0); free_tree(yyval.node); }
#line 1632 "y.tab.c"
    break;

  case 3: /* funcs: func funcs  */
#line 208 "part3.y"
                  {yyval.node  = mknode("",2, yyvsp[-1], yyvsp[0]);}
#line 1638 "y.tab.c"
    break;

  case 4: /* funcs: %empty  */
#line 209 "part3.y"
          {yyval.node = NULL;}
#line 1644 "y.tab.c"
    break;

  case 5: /* func: DEF ID '(' parameter_list ')' ':' ret_type func_body  */
#line 211 "part3.y"
                                                           {yyval.node  = mknode("FUNC",4, yyvsp[-6], yyvsp[-4], yyvsp[-1], yyvsp[0]);}
#line 1650 "y.tab.c"
    break;

  case 6: /* parameter_list: PAR TYPE_TOK ':' ID ';' parameter_list  */
#line 213 "part3.y"
                                                       {yyval.node = mknode("PARS",4, yyvsp[-5], yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1656 "y.tab.c"
    break;

  case 7: /* parameter_list: PAR TYPE_TOK ':' ID  */
#line 214 "part3.y"
                              {yyval.node  = mknode("PARS",4, yyvsp[-3], yyvsp[-2], yyvsp[0], NULL);}
#line 1662 "y.tab.c"
    break;

  case 8: /* parameter_list: %empty  */
#line 215 "part3.y"
          {yyval.node  = mknode("PARS NONE",0);}
#line 1668 "y.tab.c"
    break;

  case 9: /* ret_type: RETURNS TYPE_TOK  */
#line 217 "part3.y"
                           {yyval.node = yyvsp[0].node;}
#line 1674 "y.tab.c"
    break;

  case 10: /* ret_type: %empty  */
#line 218 "part3.y"
          {yyval.node  = mknode("RET_NONE",0);}
#line 1680 "y.tab.c"
    break;

  case 11: /* TYPE_TOK: BOOL_TOK  */
#line 220 "part3.y"
                   {yyval.node = yyvsp[0].node;}
#line 1686 "y.tab.c"
    break;

  case 12: /* TYPE_TOK: CHAR_TOK  */
#line 220 "part3.y"
                                                  {yyval.node = yyvsp[0].node;}
#line 1692 "y.tab.c"
    break;

  case 13: /* TYPE_TOK: INT_TOK  */
#line 220 "part3.y"
                                                                                {yyval.node = yyvsp[0].node;}
#line 1698 "y.tab.c"
    break;

  case 14: /* TYPE_TOK: REAL_TOK  */
#line 220 "part3.y"
                                                                                                               {yyval.node = yyvsp[0].node;}
#line 1704 "y.tab.c"
    break;

  case 15: /* TYPE_TOK: INT_PTR  */
#line 221 "part3.y"
                  {yyval.node = yyvsp[0].node;}
#line 1710 "y.tab.c"
    break;

  case 16: /* TYPE_TOK: CHAR_PTR  */
#line 221 "part3.y"
                                                 {yyval.node = yyvsp[0].node;}
#line 1716 "y.tab.c"
    break;

  case 17: /* TYPE_TOK: REAL_PTR  */
#line 221 "part3.y"
                                                                                {yyval.node = yyvsp[0].node;}
#line 1722 "y.tab.c"
    break;

  case 18: /* TYPE_VALUE: BOOL  */
#line 223 "part3.y"
                 {yyval.node = yyvsp[0].node;}
#line 1728 "y.tab.c"
    break;

  case 19: /* TYPE_VALUE: CHAR  */
#line 223 "part3.y"
                                            {yyval.node = yyvsp[0].node;}
#line 1734 "y.tab.c"
    break;

  case 20: /* TYPE_VALUE: INT  */
#line 223 "part3.y"
                                                                      {yyval.node = yyvsp[0].node;}
#line 1740 "y.tab.c"
    break;

  case 21: /* TYPE_VALUE: REAL  */
#line 223 "part3.y"
                                                                                                 {yyval.node = yyvsp[0].node;}
#line 1746 "y.tab.c"
    break;

  case 22: /* TYPE_VALUE: STRING  */
#line 223 "part3.y"
                                                                                                                               {yyval.node = yyvsp[0].node;}
#line 1752 "y.tab.c"
    break;

  case 23: /* TYPE_VALUE: NULL_TOK  */
#line 223 "part3.y"
                                                                                                                                                               {yyval.node = yyvsp[0].node;}
#line 1758 "y.tab.c"
    break;

  case 24: /* func_body: VAR declarations BEG code_body ret END  */
#line 225 "part3.y"
                                                  {yyval.node  = mknode("DECL",2, yyvsp[-4], mknode("BODY",2, yyvsp[-2], yyvsp[-1]));}
#line 1764 "y.tab.c"
    break;

  case 25: /* func_body: BEG code_body ret END  */
#line 226 "part3.y"
                                {yyval.node  = mknode("BODY",2, yyvsp[-2], yyvsp[-1]);}
#line 1770 "y.tab.c"
    break;

  case 26: /* ret: RETURN expression ';'  */
#line 228 "part3.y"
                           {yyval.node = mknode("RET",1, yyvsp[-1]);}
#line 1776 "y.tab.c"
    break;

  case 27: /* ret: %empty  */
#line 229 "part3.y"
          {yyval.node = NULL;}
#line 1782 "y.tab.c"
    break;

  case 28: /* declaration: type TYPE_TOK ':' IDS ';'  */
#line 232 "part3.y"
                                  {yyval.node = mknode("", 3, yyvsp[-3], yyvsp[-1], NULL);}
#line 1788 "y.tab.c"
    break;

  case 29: /* declaration: type STRING_TOK ':' IDS_S ';'  */
#line 233 "part3.y"
                                  {yyval.node = mknode("string", 3, yyvsp[-3], yyvsp[-1], NULL);}
#line 1794 "y.tab.c"
    break;

  case 30: /* declarations: %empty  */
#line 236 "part3.y"
    {yyval.node = NULL;}
#line 1800 "y.tab.c"
    break;

  case 31: /* declarations: declaration declarations  */
#line 237 "part3.y"
                              {yyval.node = mknode(yyvsp[-1].node->token, 3, yyvsp[-1].node->nodes[0], yyvsp[-1].node->nodes[1], yyvsp[0].node);}
#line 1806 "y.tab.c"
    break;

  case 32: /* IDS: ID ':' TYPE_VALUE ',' IDS  */
#line 239 "part3.y"
                               {yyval.node = mknode("", 3, yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1812 "y.tab.c"
    break;

  case 33: /* IDS: ID ':' TYPE_VALUE  */
#line 240 "part3.y"
                            {yyval.node = mknode("VAL", 2, yyvsp[-2], yyvsp[0]);}
#line 1818 "y.tab.c"
    break;

  case 34: /* IDS: ID ',' IDS  */
#line 241 "part3.y"
                     {yyval.node = mknode("", 2, yyvsp[-2], yyvsp[0]);}
#line 1824 "y.tab.c"
    break;

  case 35: /* IDS: ID  */
#line 242 "part3.y"
             {yyval.node = yyvsp[0].node;}
#line 1830 "y.tab.c"
    break;

  case 36: /* IDS_S: ID '[' INT ']' ':' STRING ',' IDS_S  */
#line 244 "part3.y"
                                           {yyval.node = mknode("", 4, yyvsp[-7], yyvsp[-5], yyvsp[-2], yyvsp[0]);}
#line 1836 "y.tab.c"
    break;

  case 37: /* IDS_S: ID '[' INT ']' ':' STRING  */
#line 245 "part3.y"
                                    {yyval.node = mknode("VAL", 3, yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1842 "y.tab.c"
    break;

  case 38: /* IDS_S: ID '[' INT ']' ',' IDS_S  */
#line 246 "part3.y"
                                   {yyval.node = mknode("", 3, yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1848 "y.tab.c"
    break;

  case 39: /* IDS_S: ID '[' INT ']'  */
#line 247 "part3.y"
                         {yyval.node = mknode("", 2, yyvsp[-3], yyvsp[-1]);}
#line 1854 "y.tab.c"
    break;

  case 40: /* code_body: statements  */
#line 249 "part3.y"
                      {yyval.node = yyvsp[0].node;}
#line 1860 "y.tab.c"
    break;

  case 41: /* statements: statement statements  */
#line 251 "part3.y"
                                 {yyval.node = mknode("",2, yyvsp[-1], yyvsp[0]);}
#line 1866 "y.tab.c"
    break;

  case 42: /* statements: %empty  */
#line 252 "part3.y"
          {yyval.node = NULL;}
#line 1872 "y.tab.c"
    break;

  case 43: /* statement: ID '=' expression ';'  */
#line 254 "part3.y"
                                 {yyval.node = mknode("=",2, yyvsp[-3], yyvsp[-1]);}
#line 1878 "y.tab.c"
    break;

  case 44: /* statement: ID '[' expression ']' '=' expression ';'  */
#line 255 "part3.y"
                                                   {yyval.node = mknode("[]=",3, yyvsp[-6], yyvsp[-4],yyvsp[-1]);}
#line 1884 "y.tab.c"
    break;

  case 45: /* statement: '*' ID '=' expression ';'  */
#line 256 "part3.y"
                                    {yyval.node = mknode("*=", 2, yyvsp[-3], yyvsp[-1]);}
#line 1890 "y.tab.c"
    break;

  case 46: /* statement: function_call ';'  */
#line 258 "part3.y"
                            {yyval.node = yyvsp[-1].node;}
#line 1896 "y.tab.c"
    break;

  case 47: /* statement: IF expression ':' statement  */
#line 259 "part3.y"
                                                              {yyval.node = mknode("IF",2, yyvsp[-2], yyvsp[0]);}
#line 1902 "y.tab.c"
    break;

  case 48: /* statement: IF expression ':' statement ELSE ':' statement  */
#line 260 "part3.y"
                                                          {yyval.node = mknode("IF-ELSE",3, yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1908 "y.tab.c"
    break;

  case 49: /* statement: IF expression ':' statement elifs  */
#line 261 "part3.y"
                                                                   {yyval.node = mknode("IF-ELIF",3, yyvsp[-3], yyvsp[-1], yyvsp[0]);}
#line 1914 "y.tab.c"
    break;

  case 50: /* statement: IF expression ':' statement elifs ELSE ':' statement  */
#line 262 "part3.y"
                                                               {yyval.node = mknode("IF-ELIF-ELSE",4, yyvsp[-6], yyvsp[-4], yyvsp[-3], yyvsp[0]);}
#line 1920 "y.tab.c"
    break;

  case 51: /* statement: WHILE expression ':' statement  */
#line 263 "part3.y"
                                         {yyval.node = mknode("WHILE", 2, yyvsp[-2], yyvsp[0]);}
#line 1926 "y.tab.c"
    break;

  case 52: /* statement: DO ':' statement WHILE ':' expression ';'  */
#line 264 "part3.y"
                                                    {yyval.node = mknode("DO-WHILE", 2, yyvsp[-1], yyvsp[-4]);}
#line 1932 "y.tab.c"
    break;

  case 53: /* statement: FOR '(' init ';' expression ';' update ')' ':' statement  */
#line 265 "part3.y"
                                                                  {yyval.node = mknode("FOR", 4, yyvsp[-7], yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1938 "y.tab.c"
    break;

  case 54: /* statement: func  */
#line 266 "part3.y"
               {yyval.node = yyvsp[0].node;}
#line 1944 "y.tab.c"
    break;

  case 55: /* statement: block  */
#line 267 "part3.y"
                {yyval.node = yyvsp[0].node;}
#line 1950 "y.tab.c"
    break;

  case 56: /* elifs: ELIF expression ':' statement  */
#line 270 "part3.y"
                                     {yyval.node = mknode("ELIF", 3, yyvsp[-2], yyvsp[0], NULL);}
#line 1956 "y.tab.c"
    break;

  case 57: /* elifs: ELIF expression ':' statement elifs  */
#line 271 "part3.y"
                                             {yyval.node = mknode("ELIF", 3, yyvsp[-3], yyvsp[-1], yyvsp[0]);}
#line 1962 "y.tab.c"
    break;

  case 58: /* block: VAR declarations BEG statements ret END  */
#line 273 "part3.y"
                                               {yyval.node = mknode("BLOCK", 2, mknode("DECL",2, yyvsp[-4], mknode("BODY",1, yyvsp[-2])), yyvsp[-1]);}
#line 1968 "y.tab.c"
    break;

  case 59: /* block: BEG statements ret END  */
#line 274 "part3.y"
                                 {yyval.node = mknode("BLOCK", 2, yyvsp[-2], yyvsp[-1]);}
#line 1974 "y.tab.c"
    break;

  case 60: /* init: ID '=' expression  */
#line 276 "part3.y"
                         {yyval.node = mknode("init", 1, mknode("=", 2, yyvsp[-2], yyvsp[0]));}
#line 1980 "y.tab.c"
    break;

  case 61: /* update: ID '=' expression  */
#line 277 "part3.y"
                           {yyval.node = mknode("update", 1, mknode("=", 2, yyvsp[-2], yyvsp[0]));}
#line 1986 "y.tab.c"
    break;

  case 62: /* expression: '(' expression ')'  */
#line 280 "part3.y"
                              {yyval.node = yyvsp[-1].node;}
#line 1992 "y.tab.c"
    break;

  case 63: /* expression: expression '+' expression  */
#line 281 "part3.y"
                                    {yyval.node = mknode("+", 2, yyvsp[-2], yyvsp[0]);}
#line 1998 "y.tab.c"
    break;

  case 64: /* expression: '-' expression  */
#line 282 "part3.y"
                                      {yyval.node = mknode("u-", 2, yyvsp[0], mknode("",0));}
#line 2004 "y.tab.c"
    break;

  case 65: /* expression: expression '-' expression  */
#line 283 "part3.y"
                                    {yyval.node = mknode("-", 2, yyvsp[-2], yyvsp[0]);}
#line 2010 "y.tab.c"
    break;

  case 66: /* expression: expression '*' expression  */
#line 284 "part3.y"
                                    {yyval.node = mknode("*", 2, yyvsp[-2], yyvsp[0]);}
#line 2016 "y.tab.c"
    break;

  case 67: /* expression: expression '/' expression  */
#line 285 "part3.y"
                                    {yyval.node = mknode("/", 2, yyvsp[-2], yyvsp[0]);}
#line 2022 "y.tab.c"
    break;

  case 68: /* expression: expression '>' expression  */
#line 286 "part3.y"
                                    {yyval.node = mknode(">", 2, yyvsp[-2], yyvsp[0]);}
#line 2028 "y.tab.c"
    break;

  case 69: /* expression: expression '<' expression  */
#line 287 "part3.y"
                                     {yyval.node = mknode("<", 2, yyvsp[-2], yyvsp[0]);}
#line 2034 "y.tab.c"
    break;

  case 70: /* expression: expression EQ expression  */
#line 288 "part3.y"
                                   {yyval.node = mknode("==", 2, yyvsp[-2], yyvsp[0]);}
#line 2040 "y.tab.c"
    break;

  case 71: /* expression: expression GE expression  */
#line 289 "part3.y"
                                   {yyval.node = mknode(">=", 2, yyvsp[-2], yyvsp[0]);}
#line 2046 "y.tab.c"
    break;

  case 72: /* expression: expression LE expression  */
#line 290 "part3.y"
                                   {yyval.node = mknode("<=", 2, yyvsp[-2], yyvsp[0]);}
#line 2052 "y.tab.c"
    break;

  case 73: /* expression: expression NE expression  */
#line 291 "part3.y"
                                   {yyval.node = mknode("!=", 2, yyvsp[-2], yyvsp[0]);}
#line 2058 "y.tab.c"
    break;

  case 74: /* expression: expression AND expression  */
#line 292 "part3.y"
                                     {yyval.node = mknode("and", 2, yyvsp[-2], yyvsp[0]);}
#line 2064 "y.tab.c"
    break;

  case 75: /* expression: expression OR expression  */
#line 293 "part3.y"
                                   {yyval.node = mknode("or", 2, yyvsp[-2], yyvsp[0]);}
#line 2070 "y.tab.c"
    break;

  case 76: /* expression: NOT expression  */
#line 294 "part3.y"
                         {yyval.node = mknode("not", 2, yyvsp[0], mknode("",0));}
#line 2076 "y.tab.c"
    break;

  case 77: /* expression: '|' ID '|'  */
#line 295 "part3.y"
                     {yyval.node = mknode("||", 2, yyvsp[-1], mknode("",0));}
#line 2082 "y.tab.c"
    break;

  case 78: /* expression: '*' ID  */
#line 297 "part3.y"
                 {yyval.node = mknode("*id", 2, yyvsp[0], mknode("",0));}
#line 2088 "y.tab.c"
    break;

  case 79: /* expression: '*' '(' ID '+' expression ')'  */
#line 298 "part3.y"
                                       {yyval.node = mknode("*()", 2, mknode("+", 2, yyvsp[-3], yyvsp[-1]), mknode("",0));}
#line 2094 "y.tab.c"
    break;

  case 80: /* expression: '*' '(' ID '-' expression ')'  */
#line 299 "part3.y"
                                       {yyval.node = mknode("*()", 2, mknode("-", 2, yyvsp[-3], yyvsp[-1]), mknode("",0));}
#line 2100 "y.tab.c"
    break;

  case 81: /* expression: '&' ID  */
#line 300 "part3.y"
                 {yyval.node = mknode("&id", 2, yyvsp[0], mknode("",0));}
#line 2106 "y.tab.c"
    break;

  case 82: /* expression: '&' ID '[' expression ']'  */
#line 301 "part3.y"
                                    {yyval.node = mknode("&[]", 2, yyvsp[-3], yyvsp[-1]);}
#line 2112 "y.tab.c"
    break;

  case 83: /* expression: ID '[' expression ']'  */
#line 302 "part3.y"
                                {yyval.node = mknode("[]",2, yyvsp[-3], yyvsp[-1]);}
#line 2118 "y.tab.c"
    break;

  case 84: /* expression: function_call  */
#line 304 "part3.y"
                        {yyval.node = yyvsp[0].node;}
#line 2124 "y.tab.c"
    break;

  case 85: /* expression: ID  */
#line 306 "part3.y"
             {yyval.node = yyvsp[0].node;}
#line 2130 "y.tab.c"
    break;

  case 86: /* expression: TYPE_VALUE  */
#line 307 "part3.y"
                     {yyval.node = yyvsp[0].node;}
#line 2136 "y.tab.c"
    break;

  case 87: /* function_call: CALL ID '(' args ')'  */
#line 310 "part3.y"
                                    {yyval.node = mknode("CALL",2, yyvsp[-3], mknode("ARGS", 1, yyvsp[-1]));}
#line 2142 "y.tab.c"
    break;

  case 88: /* args: argument_list  */
#line 312 "part3.y"
                    {yyval.node = yyvsp[0].node;}
#line 2148 "y.tab.c"
    break;

  case 89: /* args: %empty  */
#line 313 "part3.y"
          {yyval.node = mknode("ARGS_NONE", 0);}
#line 2154 "y.tab.c"
    break;

  case 90: /* argument_list: expression ',' argument_list  */
#line 315 "part3.y"
                                            {yyval.node = mknode("",2, yyvsp[-2], yyvsp[0]);}
#line 2160 "y.tab.c"
    break;

  case 91: /* argument_list: expression  */
#line 316 "part3.y"
                     {yyval.node = mknode("",2, yyvsp[0], NULL);}
#line 2166 "y.tab.c"
    break;


#line 2170 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 319 "part3.y"

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
