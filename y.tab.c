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
#line 1 "part1.y"

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

#line 116 "y.tab.c"

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
    type = 288,                    /* type  */
    AND = 289,                     /* AND  */
    NOT = 290,                     /* NOT  */
    OR = 291,                      /* OR  */
    EQ = 292,                      /* EQ  */
    GE = 293,                      /* GE  */
    LE = 294,                      /* LE  */
    NE = 295                       /* NE  */
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
#define type 288
#define AND 289
#define NOT 290
#define OR 291
#define EQ 292
#define GE 293
#define LE 294
#define NE 295

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
  YYSYMBOL_type = 33,                      /* type  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_EQ = 37,                        /* EQ  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_LE = 39,                        /* LE  */
  YYSYMBOL_NE = 40,                        /* NE  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* '|'  */
  YYSYMBOL_56_ = 56,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_funcs = 59,                     /* funcs  */
  YYSYMBOL_func = 60,                      /* func  */
  YYSYMBOL_parameter_list = 61,            /* parameter_list  */
  YYSYMBOL_ret_type = 62,                  /* ret_type  */
  YYSYMBOL_TYPE_TOK = 63,                  /* TYPE_TOK  */
  YYSYMBOL_TYPE_VALUE = 64,                /* TYPE_VALUE  */
  YYSYMBOL_func_body = 65,                 /* func_body  */
  YYSYMBOL_ret = 66,                       /* ret  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_IDS = 68,                       /* IDS  */
  YYSYMBOL_IDS_S = 69,                     /* IDS_S  */
  YYSYMBOL_code_body = 70,                 /* code_body  */
  YYSYMBOL_statements = 71,                /* statements  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_elifs = 73,                     /* elifs  */
  YYSYMBOL_block = 74,                     /* block  */
  YYSYMBOL_init = 75,                      /* init  */
  YYSYMBOL_update = 76,                    /* update  */
  YYSYMBOL_expression = 77,                /* expression  */
  YYSYMBOL_function_call = 78,             /* function_call  */
  YYSYMBOL_args = 79,                      /* args  */
  YYSYMBOL_argument_list = 80              /* argument_list  */
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
#define YYLAST   473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
      47,    48,    45,    43,    51,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    50,
      42,    54,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    55,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    66,    67,    68,    70,    72,    73,    74,
      76,    77,    79,    79,    79,    79,    79,    80,    80,    80,
      82,    82,    82,    82,    82,    84,    85,    87,    88,    90,
      91,    92,    93,    94,    96,    97,    98,    99,   101,   102,
     103,   104,   106,   108,   109,   110,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     127,   128,   130,   131,   132,   134,   135,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   154,   155,   156,   157,   158,   160,   161,
     162,   165,   167,   168,   170,   171
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
  "NULL_TOK", "RETURN", "RETURNS", "type", "AND", "NOT", "OR", "EQ", "GE",
  "LE", "NE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "':'", "';'", "','", "'['", "']'", "'='", "'|'", "'&'", "$accept",
  "program", "funcs", "func", "parameter_list", "ret_type", "TYPE_TOK",
  "TYPE_VALUE", "func_body", "ret", "declarations", "IDS", "IDS_S",
  "code_body", "statements", "statement", "elifs", "block", "init",
  "update", "expression", "function_call", "args", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    19,    63,  -192,     7,    28,  -192,  -192,    71,   158,
      53,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,    17,
      64,    96,    76,    66,   158,    45,    71,  -192,    84,   128,
    -192,  -192,   463,    93,   -41,   125,   125,    78,    79,   108,
     109,  -192,    98,  -192,   128,    81,    85,    86,   128,   125,
      77,  -192,  -192,  -192,  -192,  -192,    92,  -192,   125,   -11,
     124,   127,  -192,   328,   344,   130,    55,   102,    99,   125,
     131,  -192,  -192,   136,   141,    98,   148,   226,   121,   125,
     406,  -192,   154,   119,   123,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,    55,    55,
     122,   129,    84,   128,  -192,   155,   125,   125,   243,  -192,
     126,   145,    18,   146,   170,   144,  -192,  -192,   168,    44,
    -192,   125,   -13,   406,   419,     3,     3,     3,     3,     3,
       3,    59,    59,   164,   164,    90,  -192,   125,   125,   174,
     189,   166,   208,   169,  -192,   260,  -192,   204,    84,    27,
     141,    84,  -192,    77,  -192,   125,   125,   188,   125,   171,
     198,   406,   277,   128,  -192,   125,   125,  -192,  -192,   182,
    -192,   185,  -192,  -192,   294,   187,   376,   391,  -192,   360,
      55,   190,   220,   213,   311,  -192,    47,   141,  -192,  -192,
    -192,  -192,    55,  -192,    55,   201,   209,  -192,  -192,   240,
     136,  -192,   238,  -192,   125,   224,   223,  -192,  -192,   406,
      55,   136,  -192,  -192
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     2,     3,     0,     1,     4,     9,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,    11,     8,     0,     0,     9,    10,    33,    45,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    28,    42,    44,     0,     0,     0,    45,     0,
       0,    20,    21,    22,    23,    24,    88,    90,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    51,     0,     0,    28,     0,     0,     0,     0,
      80,    83,     0,     0,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    45,    64,     0,    93,     0,     0,    26,
       0,     0,    37,     0,     0,     0,    46,    47,     0,     0,
      82,     0,    77,    79,    78,    73,    74,    75,    76,    71,
      72,    67,    68,    69,    70,    52,    56,     0,     0,     0,
       0,     0,    95,     0,    92,     0,    27,     0,    32,     0,
       0,    30,    25,     0,    81,     0,     0,     0,     0,     0,
      54,    65,     0,    45,    63,     0,     0,    91,    50,     0,
      31,    35,    36,    29,     0,     0,     0,     0,    87,     0,
       0,     0,     0,     0,     0,    94,    41,     0,    48,    49,
      84,    85,     0,    53,     0,     0,     0,    62,    57,     0,
       0,    34,    61,    55,     0,     0,    39,    40,    60,    66,
       0,     0,    58,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,   271,    12,   264,  -192,   -14,   142,  -192,   217,
     -83,  -142,  -191,   259,   -39,   -27,   106,   -95,  -192,  -192,
     -35,   -44,  -192,   143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    41,    10,    25,    19,    62,    30,    70,
      33,   113,   111,    42,    43,   104,   160,   105,   101,   196,
     142,    45,   143,   144
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    64,    44,   135,   136,    71,    78,    81,   172,   207,
      27,    49,     4,    50,    76,    77,     4,    44,    47,   139,
     213,    44,    86,    80,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   108,     1,    82,     5,    86,    51,
      52,    53,    54,    55,   118,   201,    94,    95,    96,    97,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     6,   140,   170,    21,   149,   173,   150,
      28,    29,   145,    34,    35,     8,    44,    36,    37,    38,
     102,   103,     9,     1,    39,   193,   157,   155,   156,    51,
      52,    53,    54,    55,    86,    56,   199,   202,   200,   203,
      40,    20,   161,   162,    96,    97,    39,    57,    24,   175,
     158,   159,    58,    22,    23,   212,    26,    32,   174,    48,
     176,   177,    59,   179,   183,    65,    67,    68,    66,    69,
     184,    72,    60,    61,    73,    74,    44,    51,    52,    53,
      54,    55,    83,    56,    79,    84,    34,    35,   100,   106,
      36,    37,    38,   107,   110,    57,     1,    39,   109,   112,
      58,    11,    12,    13,    14,    15,    16,    17,    18,   209,
      59,   117,   119,    40,   120,   121,   137,   141,   147,   138,
      60,    61,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   148,   151,   152,   153,    86,
     163,   115,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   165,   164,   167,   169,   181,
     180,   154,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   186,   187,   189,   195,   194,
     197,   178,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   204,   206,   205,   158,   166,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   210,   211,     7,   116,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      31,   171,   114,   146,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    75,   208,   185,
     168,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,   182,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,     0,   188,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,   198,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,     0,    98,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,    99,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,   192,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,   190,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,   191,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    85,    86,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    11,    12,    13,    14,
      46,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
      35,    36,    29,    98,    99,    44,    50,    18,   150,   200,
      24,    52,     0,    54,    49,    50,     4,    44,    32,   102,
     211,    48,    35,    58,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    69,    28,    47,    18,    35,    12,
      13,    14,    15,    16,    79,   187,    43,    44,    45,    46,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,   103,   148,    49,    49,   151,    51,
      25,    26,   107,    18,    19,    47,   103,    22,    23,    24,
      25,    26,    11,    28,    29,   180,   121,    43,    44,    12,
      13,    14,    15,    16,    35,    18,    49,   192,    51,   194,
      45,    48,   137,   138,    45,    46,    29,    30,    32,   153,
      20,    21,    35,    49,    18,   210,    50,    33,   153,    26,
     155,   156,    45,   158,   163,    47,    18,    18,    49,    31,
     165,    50,    55,    56,    49,    49,   163,    12,    13,    14,
      15,    16,    18,    18,    52,    18,    18,    19,    18,    47,
      22,    23,    24,    54,    18,    30,    28,    29,    27,    18,
      35,     3,     4,     5,     6,     7,     8,     9,    10,   204,
      45,    50,    18,    45,    55,    52,    54,    22,    52,    50,
      55,    56,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    50,    50,    27,    54,    35,
      26,    53,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    49,    27,    48,    14,    21,
      49,    53,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    53,    51,    50,    18,    49,
      27,    53,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    54,    16,    48,    20,    51,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    49,    51,     4,    50,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      26,   149,    75,    50,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    48,   202,   166,
      50,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    50,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    49,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    49,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     3,     4,     5,     6,
       7,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    58,    59,    60,    18,     0,    59,    47,    11,
      61,     3,     4,     5,     6,     7,     8,     9,    10,    63,
      48,    49,    49,    18,    32,    62,    50,    63,    25,    26,
      65,    61,    33,    67,    18,    19,    22,    23,    24,    29,
      45,    60,    70,    71,    72,    78,     7,    63,    26,    52,
      54,    12,    13,    14,    15,    16,    18,    30,    35,    45,
      55,    56,    64,    77,    77,    47,    49,    18,    18,    31,
      66,    71,    50,    49,    49,    70,    77,    77,    78,    52,
      77,    18,    47,    18,    18,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    49,    49,
      18,    75,    25,    26,    72,    74,    47,    54,    77,    27,
      18,    69,    18,    68,    66,    53,    50,    50,    77,    18,
      55,    52,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    74,    74,    54,    50,    67,
      71,    22,    77,    79,    80,    77,    50,    52,    50,    49,
      51,    50,    27,    54,    53,    43,    44,    77,    20,    21,
      73,    77,    77,    26,    27,    49,    51,    48,    50,    14,
      67,    64,    68,    67,    77,    78,    77,    77,    53,    77,
      49,    21,    50,    71,    77,    80,    53,    51,    50,    50,
      48,    48,    49,    74,    49,    18,    76,    27,    50,    49,
      51,    68,    74,    74,    54,    48,    16,    69,    73,    77,
      49,    51,    74,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    60,    61,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    69,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    74,    75,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     8,     6,     4,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     4,     3,     0,     6,
       5,     6,     5,     0,     5,     3,     3,     1,     8,     6,
       6,     4,     1,     2,     1,     0,     4,     4,     7,     7,
       5,     2,     4,     7,     5,     8,     4,     7,    10,     1,
       5,     4,     5,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     3,     2,     6,     6,     2,     5,     1,     1,
       1,     5,     1,     0,     3,     1
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
#line 65 "part1.y"
               {yyval.node = mknode("PROGRAM",1, yyvsp[0]); print_tree(yyval.node, 0);}
#line 1487 "y.tab.c"
    break;

  case 3: /* funcs: func  */
#line 66 "part1.y"
            {yyval.node  = mknode("",1, yyvsp[0]);}
#line 1493 "y.tab.c"
    break;

  case 4: /* funcs: func funcs  */
#line 67 "part1.y"
                     {yyval.node  = mknode("",2, yyvsp[-1], yyvsp[0]);}
#line 1499 "y.tab.c"
    break;

  case 5: /* funcs: %empty  */
#line 68 "part1.y"
          {yyval.node = mknode("EMPTY-PROGRAM",0);}
#line 1505 "y.tab.c"
    break;

  case 6: /* func: DEF ID '(' parameter_list ')' ':' ret_type func_body  */
#line 70 "part1.y"
                                                           {yyval.node  = mknode("FUNC",4, yyvsp[-6], yyvsp[-4], yyvsp[-1], yyvsp[0]);}
#line 1511 "y.tab.c"
    break;

  case 7: /* parameter_list: PAR TYPE_TOK ':' ID ';' parameter_list  */
#line 72 "part1.y"
                                                       {printf("the ID in the yacc file is : %s and the par is : %s\n", yyvsp[-2].node->token, yyvsp[-5].node->token); yyval.node = mknode("PARS",4, yyvsp[-5], yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1517 "y.tab.c"
    break;

  case 8: /* parameter_list: PAR TYPE_TOK ':' ID  */
#line 73 "part1.y"
                              {yyval.node  = mknode("PARS",4, yyvsp[-3], yyvsp[-2], yyvsp[0], NULL);}
#line 1523 "y.tab.c"
    break;

  case 9: /* parameter_list: %empty  */
#line 74 "part1.y"
          {yyval.node  = mknode("PARS NONE",0);}
#line 1529 "y.tab.c"
    break;

  case 10: /* ret_type: RETURNS TYPE_TOK  */
#line 76 "part1.y"
                           { char *label = (char *)malloc(strlen("RET ") + strlen(yyvsp[0].node->token) + 1); sprintf(label, "RET %s", yyvsp[0].node->token); yyval.node  = mknode(label,0); free(label);}
#line 1535 "y.tab.c"
    break;

  case 11: /* ret_type: %empty  */
#line 77 "part1.y"
          {yyval.node  = mknode("RET_NONE",0);}
#line 1541 "y.tab.c"
    break;

  case 12: /* TYPE_TOK: BOOL_TOK  */
#line 79 "part1.y"
                   {yyval.node = yyvsp[0].node;}
#line 1547 "y.tab.c"
    break;

  case 13: /* TYPE_TOK: CHAR_TOK  */
#line 79 "part1.y"
                                                  {yyval.node = yyvsp[0].node;}
#line 1553 "y.tab.c"
    break;

  case 14: /* TYPE_TOK: INT_TOK  */
#line 79 "part1.y"
                                                                                {yyval.node = yyvsp[0].node;}
#line 1559 "y.tab.c"
    break;

  case 15: /* TYPE_TOK: REAL_TOK  */
#line 79 "part1.y"
                                                                                                               {yyval.node = yyvsp[0].node;}
#line 1565 "y.tab.c"
    break;

  case 16: /* TYPE_TOK: STRING_TOK  */
#line 79 "part1.y"
                                                                                                                                                {yyval.node = yyvsp[0].node;}
#line 1571 "y.tab.c"
    break;

  case 17: /* TYPE_TOK: INT_PTR  */
#line 80 "part1.y"
                  {yyval.node = yyvsp[0].node;}
#line 1577 "y.tab.c"
    break;

  case 18: /* TYPE_TOK: CHAR_PTR  */
#line 80 "part1.y"
                                                 {yyval.node = yyvsp[0].node;}
#line 1583 "y.tab.c"
    break;

  case 19: /* TYPE_TOK: REAL_PTR  */
#line 80 "part1.y"
                                                                                {yyval.node = yyvsp[0].node;}
#line 1589 "y.tab.c"
    break;

  case 20: /* TYPE_VALUE: BOOL  */
#line 82 "part1.y"
                 {yyval.node = yyvsp[0].node;}
#line 1595 "y.tab.c"
    break;

  case 21: /* TYPE_VALUE: CHAR  */
#line 82 "part1.y"
                                            {yyval.node = yyvsp[0].node;}
#line 1601 "y.tab.c"
    break;

  case 22: /* TYPE_VALUE: INT  */
#line 82 "part1.y"
                                                                      {yyval.node = yyvsp[0].node;}
#line 1607 "y.tab.c"
    break;

  case 23: /* TYPE_VALUE: REAL  */
#line 82 "part1.y"
                                                                                                 {yyval.node = yyvsp[0].node;}
#line 1613 "y.tab.c"
    break;

  case 24: /* TYPE_VALUE: STRING  */
#line 82 "part1.y"
                                                                                                                               {yyval.node = yyvsp[0].node;}
#line 1619 "y.tab.c"
    break;

  case 25: /* func_body: VAR declarations BEG code_body ret END  */
#line 84 "part1.y"
                                                  {yyval.node  = mknode("DECL",2, yyvsp[-4], mknode("BODY",2, yyvsp[-2], yyvsp[-1]));}
#line 1625 "y.tab.c"
    break;

  case 26: /* func_body: BEG code_body ret END  */
#line 85 "part1.y"
                                {yyval.node  = mknode("BODY",2, yyvsp[-2], yyvsp[-1]);}
#line 1631 "y.tab.c"
    break;

  case 27: /* ret: RETURN expression ';'  */
#line 87 "part1.y"
                           {yyval.node = mknode("RET ",1, yyvsp[-1]);}
#line 1637 "y.tab.c"
    break;

  case 28: /* ret: %empty  */
#line 88 "part1.y"
          {yyval.node = NULL;}
#line 1643 "y.tab.c"
    break;

  case 29: /* declarations: type TYPE_TOK ':' IDS ';' declarations  */
#line 90 "part1.y"
                                                     {yyval.node = mknode("", 3, yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1649 "y.tab.c"
    break;

  case 30: /* declarations: type TYPE_TOK ':' IDS ';'  */
#line 91 "part1.y"
                                    {yyval.node = mknode("", 3, yyvsp[-3], yyvsp[-1], NULL);}
#line 1655 "y.tab.c"
    break;

  case 31: /* declarations: type STRING_TOK ':' IDS_S ';' declarations  */
#line 92 "part1.y"
                                                     {yyval.node = mknode("string", 3, yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1661 "y.tab.c"
    break;

  case 32: /* declarations: type STRING_TOK ':' IDS_S ';'  */
#line 93 "part1.y"
                                        {yyval.node = mknode("string", 3, yyvsp[-3], yyvsp[-1], NULL);}
#line 1667 "y.tab.c"
    break;

  case 33: /* declarations: %empty  */
#line 94 "part1.y"
          {yyval.node = NULL;}
#line 1673 "y.tab.c"
    break;

  case 34: /* IDS: ID ':' TYPE_VALUE ',' IDS  */
#line 96 "part1.y"
                               {yyval.node = mknode("", 3, yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1679 "y.tab.c"
    break;

  case 35: /* IDS: ID ':' TYPE_VALUE  */
#line 97 "part1.y"
                            {yyval.node = mknode("VAL", 2, yyvsp[-2], yyvsp[0]);}
#line 1685 "y.tab.c"
    break;

  case 36: /* IDS: ID ',' IDS  */
#line 98 "part1.y"
                     {yyval.node = mknode("", 2, yyvsp[-2], yyvsp[0]);}
#line 1691 "y.tab.c"
    break;

  case 37: /* IDS: ID  */
#line 99 "part1.y"
             {yyval.node = yyvsp[0].node;}
#line 1697 "y.tab.c"
    break;

  case 38: /* IDS_S: ID '[' INT ']' ':' STRING ',' IDS_S  */
#line 101 "part1.y"
                                           {yyval.node = mknode("", 4, yyvsp[-7], yyvsp[-5], yyvsp[-2], yyvsp[0]);}
#line 1703 "y.tab.c"
    break;

  case 39: /* IDS_S: ID '[' INT ']' ':' STRING  */
#line 102 "part1.y"
                                    {yyval.node = mknode("VAL", 3, yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1709 "y.tab.c"
    break;

  case 40: /* IDS_S: ID '[' INT ']' ',' IDS_S  */
#line 103 "part1.y"
                                   {yyval.node = mknode("", 3, yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1715 "y.tab.c"
    break;

  case 41: /* IDS_S: ID '[' INT ']'  */
#line 104 "part1.y"
                         {yyval.node = mknode("", 2, yyvsp[-3], yyvsp[-1]);}
#line 1721 "y.tab.c"
    break;

  case 42: /* code_body: statements  */
#line 106 "part1.y"
                      {yyval.node = yyvsp[0].node;}
#line 1727 "y.tab.c"
    break;

  case 43: /* statements: statement statements  */
#line 108 "part1.y"
                                 {yyval.node = mknode("",2, yyvsp[-1], yyvsp[0]);}
#line 1733 "y.tab.c"
    break;

  case 44: /* statements: statement  */
#line 109 "part1.y"
                    {yyval.node = mknode("",2, yyvsp[0], NULL);}
#line 1739 "y.tab.c"
    break;

  case 45: /* statements: %empty  */
#line 110 "part1.y"
          {yyval.node = NULL;}
#line 1745 "y.tab.c"
    break;

  case 46: /* statement: ID '=' expression ';'  */
#line 112 "part1.y"
                                 {yyval.node = mknode("=",2, yyvsp[-3], yyvsp[-1]);}
#line 1751 "y.tab.c"
    break;

  case 47: /* statement: ID '=' function_call ';'  */
#line 113 "part1.y"
                                   {yyval.node = mknode("=",2, yyvsp[-3], yyvsp[-1]);}
#line 1757 "y.tab.c"
    break;

  case 48: /* statement: ID '[' expression ']' '=' expression ';'  */
#line 114 "part1.y"
                                                   {yyval.node = mknode("[]=",3, yyvsp[-6], yyvsp[-4],yyvsp[-1]);}
#line 1763 "y.tab.c"
    break;

  case 49: /* statement: ID '[' expression ']' '=' function_call ';'  */
#line 115 "part1.y"
                                                      {yyval.node = mknode("[]=",3, yyvsp[-6], yyvsp[-4], yyvsp[-1]);}
#line 1769 "y.tab.c"
    break;

  case 50: /* statement: '*' ID '=' expression ';'  */
#line 116 "part1.y"
                                    {yyval.node = mknode("*=", 2, yyvsp[-3], yyvsp[-1]);}
#line 1775 "y.tab.c"
    break;

  case 51: /* statement: function_call ';'  */
#line 117 "part1.y"
                            {yyval.node = yyvsp[-1].node;}
#line 1781 "y.tab.c"
    break;

  case 52: /* statement: IF expression ':' block  */
#line 118 "part1.y"
                                   {yyval.node = mknode("IF",2, yyvsp[-2], yyvsp[0]);}
#line 1787 "y.tab.c"
    break;

  case 53: /* statement: IF expression ':' block ELSE ':' block  */
#line 119 "part1.y"
                                                  {yyval.node = mknode("IF-ELSE",3, yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1793 "y.tab.c"
    break;

  case 54: /* statement: IF expression ':' block elifs  */
#line 120 "part1.y"
                                        {yyval.node = mknode("IF-ELIF",3, yyvsp[-3], yyvsp[-1], yyvsp[0]);}
#line 1799 "y.tab.c"
    break;

  case 55: /* statement: IF expression ':' block elifs ELSE ':' block  */
#line 121 "part1.y"
                                                       {yyval.node = mknode("IF-ELIF-ELSE",4, yyvsp[-6], yyvsp[-4], yyvsp[-3], yyvsp[0]);}
#line 1805 "y.tab.c"
    break;

  case 56: /* statement: WHILE expression ':' block  */
#line 122 "part1.y"
                                     {yyval.node = mknode("WHILE", 2, yyvsp[-2], yyvsp[0]);}
#line 1811 "y.tab.c"
    break;

  case 57: /* statement: DO ':' block WHILE ':' expression ';'  */
#line 123 "part1.y"
                                                {yyval.node = mknode("DO-WHILE", 2, yyvsp[-1], yyvsp[-4]);}
#line 1817 "y.tab.c"
    break;

  case 58: /* statement: FOR '(' init ';' expression ';' update ')' ':' block  */
#line 124 "part1.y"
                                                              {yyval.node = mknode("FOR", 4, yyvsp[-7], yyvsp[-5], yyvsp[-3], yyvsp[0]);}
#line 1823 "y.tab.c"
    break;

  case 59: /* statement: func  */
#line 125 "part1.y"
               {yyval.node = yyvsp[0].node;}
#line 1829 "y.tab.c"
    break;

  case 60: /* elifs: ELIF expression ':' block elifs  */
#line 127 "part1.y"
                                       {yyval.node = mknode("ELIF", 3, yyvsp[-3], yyvsp[-1], yyvsp[0]);}
#line 1835 "y.tab.c"
    break;

  case 61: /* elifs: ELIF expression ':' block  */
#line 128 "part1.y"
                                    {yyval.node = mknode("ELIF", 3, yyvsp[-2], yyvsp[0], NULL);}
#line 1841 "y.tab.c"
    break;

  case 62: /* block: VAR declarations BEG statements END  */
#line 130 "part1.y"
                                           {yyval.node = mknode("BLOCK", 1, mknode("DECL",2, yyvsp[-3], mknode("BODY-BLOCK",1, yyvsp[-1])));}
#line 1847 "y.tab.c"
    break;

  case 63: /* block: BEG statements END  */
#line 131 "part1.y"
                             {yyval.node = mknode("BLOCK", 1, yyvsp[-1]);}
#line 1853 "y.tab.c"
    break;

  case 64: /* block: statement  */
#line 132 "part1.y"
                    {yyval.node = yyvsp[0].node;}
#line 1859 "y.tab.c"
    break;

  case 65: /* init: ID '=' expression  */
#line 134 "part1.y"
                         {yyval.node = mknode("init", 1, mknode("=", 2, yyvsp[-2], yyvsp[0]));}
#line 1865 "y.tab.c"
    break;

  case 66: /* update: ID '=' expression  */
#line 135 "part1.y"
                           {yyval.node = mknode("update", 1, mknode("=", 2, yyvsp[-2], yyvsp[0]));}
#line 1871 "y.tab.c"
    break;

  case 67: /* expression: expression '+' expression  */
#line 137 "part1.y"
                                      {yyval.node = mknode("+", 2, yyvsp[-2], yyvsp[0]);}
#line 1877 "y.tab.c"
    break;

  case 68: /* expression: expression '-' expression  */
#line 138 "part1.y"
                                    {yyval.node = mknode("-", 2, yyvsp[-2], yyvsp[0]);}
#line 1883 "y.tab.c"
    break;

  case 69: /* expression: expression '*' expression  */
#line 139 "part1.y"
                                    {yyval.node = mknode("*", 2, yyvsp[-2], yyvsp[0]);}
#line 1889 "y.tab.c"
    break;

  case 70: /* expression: expression '/' expression  */
#line 140 "part1.y"
                                    {yyval.node = mknode("/", 2, yyvsp[-2], yyvsp[0]);}
#line 1895 "y.tab.c"
    break;

  case 71: /* expression: expression '>' expression  */
#line 141 "part1.y"
                                    {yyval.node = mknode(">", 2, yyvsp[-2], yyvsp[0]);}
#line 1901 "y.tab.c"
    break;

  case 72: /* expression: expression '<' expression  */
#line 142 "part1.y"
                                     {yyval.node = mknode("<", 2, yyvsp[-2], yyvsp[0]);}
#line 1907 "y.tab.c"
    break;

  case 73: /* expression: expression EQ expression  */
#line 143 "part1.y"
                                   {yyval.node = mknode("==", 2, yyvsp[-2], yyvsp[0]);}
#line 1913 "y.tab.c"
    break;

  case 74: /* expression: expression GE expression  */
#line 144 "part1.y"
                                   {yyval.node = mknode(">=", 2, yyvsp[-2], yyvsp[0]);}
#line 1919 "y.tab.c"
    break;

  case 75: /* expression: expression LE expression  */
#line 145 "part1.y"
                                   {yyval.node = mknode("<=", 2, yyvsp[-2], yyvsp[0]);}
#line 1925 "y.tab.c"
    break;

  case 76: /* expression: expression NE expression  */
#line 146 "part1.y"
                                   {yyval.node = mknode("!=", 2, yyvsp[-2], yyvsp[0]);}
#line 1931 "y.tab.c"
    break;

  case 77: /* expression: expression AND expression  */
#line 147 "part1.y"
                                     {yyval.node = mknode("and", 2, yyvsp[-2], yyvsp[0]);}
#line 1937 "y.tab.c"
    break;

  case 78: /* expression: expression OR expression  */
#line 148 "part1.y"
                                   {yyval.node = mknode("or", 2, yyvsp[-2], yyvsp[0]);}
#line 1943 "y.tab.c"
    break;

  case 79: /* expression: expression NOT expression  */
#line 149 "part1.y"
                                    {yyval.node = mknode("not", 2, yyvsp[-2], yyvsp[0]);}
#line 1949 "y.tab.c"
    break;

  case 80: /* expression: NOT expression  */
#line 150 "part1.y"
                         {yyval.node = mknode("not", 2, yyvsp[0], mknode("",0));}
#line 1955 "y.tab.c"
    break;

  case 81: /* expression: ID '[' expression ']'  */
#line 151 "part1.y"
                                {yyval.node = mknode("[]", 2, yyvsp[-3], yyvsp[-1]);}
#line 1961 "y.tab.c"
    break;

  case 82: /* expression: '|' ID '|'  */
#line 152 "part1.y"
                     {yyval.node = mknode("||", 2, yyvsp[-1], mknode("",0));}
#line 1967 "y.tab.c"
    break;

  case 83: /* expression: '*' ID  */
#line 154 "part1.y"
                 {yyval.node = mknode("*id", 2, yyvsp[0], mknode("",0));}
#line 1973 "y.tab.c"
    break;

  case 84: /* expression: '*' '(' ID '+' expression ')'  */
#line 155 "part1.y"
                                       {yyval.node = mknode("*()", 2, mknode("+", 2, yyvsp[-3], yyvsp[-1]), mknode("",0));}
#line 1979 "y.tab.c"
    break;

  case 85: /* expression: '*' '(' ID '-' expression ')'  */
#line 156 "part1.y"
                                       {yyval.node = mknode("*()", 2, mknode("-", 2, yyvsp[-3], yyvsp[-1]), mknode("",0));}
#line 1985 "y.tab.c"
    break;

  case 86: /* expression: '&' ID  */
#line 157 "part1.y"
                 {yyval.node = mknode("&id", 2, yyvsp[0], mknode("",0));}
#line 1991 "y.tab.c"
    break;

  case 87: /* expression: '&' ID '[' expression ']'  */
#line 158 "part1.y"
                                    {yyval.node = mknode("&[]", 2, yyvsp[-3], yyvsp[-1]);}
#line 1997 "y.tab.c"
    break;

  case 88: /* expression: ID  */
#line 160 "part1.y"
             {yyval.node = yyvsp[0].node;}
#line 2003 "y.tab.c"
    break;

  case 89: /* expression: TYPE_VALUE  */
#line 161 "part1.y"
                     {yyval.node = yyvsp[0].node;}
#line 2009 "y.tab.c"
    break;

  case 90: /* expression: NULL_TOK  */
#line 162 "part1.y"
                   {yyval.node = mknode("NULL", 0);}
#line 2015 "y.tab.c"
    break;

  case 91: /* function_call: CALL ID '(' args ')'  */
#line 165 "part1.y"
                                    {yyval.node = mknode("CALL",2, yyvsp[-3], mknode("ARGS", 1, yyvsp[-1]));}
#line 2021 "y.tab.c"
    break;

  case 92: /* args: argument_list  */
#line 167 "part1.y"
                    {yyval.node = yyvsp[0].node;}
#line 2027 "y.tab.c"
    break;

  case 93: /* args: %empty  */
#line 168 "part1.y"
          {yyval.node = mknode("ARGS_NONE", 0);}
#line 2033 "y.tab.c"
    break;

  case 94: /* argument_list: expression ',' argument_list  */
#line 170 "part1.y"
                                            {yyval.node = mknode("",2, yyvsp[-2], yyvsp[0]);}
#line 2039 "y.tab.c"
    break;

  case 95: /* argument_list: expression  */
#line 171 "part1.y"
                     {yyval.node = mknode("",2, yyvsp[0], NULL);}
#line 2045 "y.tab.c"
    break;


#line 2049 "y.tab.c"

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

#line 175 "part1.y"

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
