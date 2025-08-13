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
#line 1 "BGSASAS.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count=0;
int qind=0;
int tos=-1;
int temp_char=0;
int ltos = -1;
int ltemp = 0;
int typ_ind = 0;
int id_ind = 0;

char gtype[50];
char id_names[25][50];

int is_read = 0;
int is_write= 0;

struct quadruple{
char operator[5];
char operand1[50];
char operand2[50];
char result[50];
} quad[25];

struct stack{
char c[50]; } stk[25];

struct labels{
char c[50]; } lbl[25];

struct arr_type{
char name[50];
char type[50];
} typ[25];


char* getTypeForName(char name[]) {
    for (int i = 0; i < 25; i++) {
        if (strcmp(typ[i].name, name) == 0) {
            return typ[i].type;
        }
    }
    return NULL;
}

int getTypeIntegerValue(char type[]) {
    char lowercaseType[50];
    int i = 0;
    while (type[i] != '\0' && type[i] != ' ' && i < 50) {
        lowercaseType[i] = tolower(type[i]);
        i++;
    }
    lowercaseType[i] = '\0';

	// printf("lowercase type is |%s|\n",lowercaseType);

    if (strcmp(lowercaseType, "integer") == 0) {
        return 2;
    } else if (strcmp(lowercaseType, "real") == 0) {
        return 4;
    } else if (strcmp(lowercaseType, "boolean") == 0 || strcmp(lowercaseType, "char") == 0) {
        return 1;
    } else {
        return -1;
    }
}

void addTyp(char name[], char type[]) {
        strcpy(typ[typ_ind].name, name);
        strcpy(typ[typ_ind].type, type);
        typ_ind++;
}

void addQuadruple(char op1[], char op[], char op2[], char result[]){
    strcpy(quad[qind].operator, op ? op : "");
    strcpy(quad[qind].operand1, op1 ? op1 : "");
    strcpy(quad[qind].operand2, op2 ? op2 : "");
    strcpy(quad[qind].result, result);
    qind++;
}

void display_Quad(){
    printf("%s ", quad[qind-1].result);
    printf("= ");
    printf("%s ", quad[qind-1].operand1);
    if (strlen(quad[qind-1].operator) > 0) {
        printf("%s ", quad[qind-1].operator);
    }
    if (strlen(quad[qind-1].operand2) > 0) {
        printf("%s ", quad[qind-1].operand2);
    }
    printf("\n");
}

void push(char *c){
	// printf("\nc is %s\n",c);
    strcpy(stk[++tos].c, c);
}

char* pop(){
    char* c=stk[tos].c;
    tos=tos-1;
    return c;
}

void lpush(char *c){
    strcpy(lbl[++ltos].c, c);
}

char* lpop(){
    char* c=lbl[ltos].c;
    ltos=ltos-1;
    return c;
}

extern FILE* yyin;
extern int line_num;
void yyerror(const char *msg);


#line 197 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    Type = 258,                    /* Type  */
    Begin = 259,                   /* Begin  */
    End = 260,                     /* End  */
    Var = 261,                     /* Var  */
    Prog = 262,                    /* Prog  */
    SC = 263,                      /* SC  */
    comma = 264,                   /* comma  */
    Colon = 265,                   /* Colon  */
    Stop = 266,                    /* Stop  */
    Read = 267,                    /* Read  */
    Write = 268,                   /* Write  */
    Array = 269,                   /* Array  */
    If = 270,                      /* If  */
    Then = 271,                    /* Then  */
    Else = 272,                    /* Else  */
    For = 273,                     /* For  */
    While = 274,                   /* While  */
    AsmtOp = 275,                  /* AsmtOp  */
    Not = 276,                     /* Not  */
    RelationalOperator = 277,      /* RelationalOperator  */
    OpenParenthesis = 278,         /* OpenParenthesis  */
    CloseParenthesis = 279,        /* CloseParenthesis  */
    String = 280,                  /* String  */
    ArrayOpen = 281,               /* ArrayOpen  */
    ArrayClose = 282,              /* ArrayClose  */
    CharacterLiteral = 283,        /* CharacterLiteral  */
    Of = 284,                      /* Of  */
    DoubleDots = 285,              /* DoubleDots  */
    Do = 286,                      /* Do  */
    To = 287,                      /* To  */
    DownTo = 288,                  /* DownTo  */
    Plus = 289,                    /* Plus  */
    Minus = 290,                   /* Minus  */
    Mul = 291,                     /* Mul  */
    Mod = 292,                     /* Mod  */
    Div = 293,                     /* Div  */
    Or = 294,                      /* Or  */
    And = 295,                     /* And  */
    NumberLiteral = 296,           /* NumberLiteral  */
    Identifier = 297,              /* Identifier  */
    RealLiteral = 298              /* RealLiteral  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define Type 258
#define Begin 259
#define End 260
#define Var 261
#define Prog 262
#define SC 263
#define comma 264
#define Colon 265
#define Stop 266
#define Read 267
#define Write 268
#define Array 269
#define If 270
#define Then 271
#define Else 272
#define For 273
#define While 274
#define AsmtOp 275
#define Not 276
#define RelationalOperator 277
#define OpenParenthesis 278
#define CloseParenthesis 279
#define String 280
#define ArrayOpen 281
#define ArrayClose 282
#define CharacterLiteral 283
#define Of 284
#define DoubleDots 285
#define Do 286
#define To 287
#define DownTo 288
#define Plus 289
#define Minus 290
#define Mul 291
#define Mod 292
#define Div 293
#define Or 294
#define And 295
#define NumberLiteral 296
#define Identifier 297
#define RealLiteral 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 127 "BGSASAS.y"
char *cval;int ival;

#line 339 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Type = 3,                       /* Type  */
  YYSYMBOL_Begin = 4,                      /* Begin  */
  YYSYMBOL_End = 5,                        /* End  */
  YYSYMBOL_Var = 6,                        /* Var  */
  YYSYMBOL_Prog = 7,                       /* Prog  */
  YYSYMBOL_SC = 8,                         /* SC  */
  YYSYMBOL_comma = 9,                      /* comma  */
  YYSYMBOL_Colon = 10,                     /* Colon  */
  YYSYMBOL_Stop = 11,                      /* Stop  */
  YYSYMBOL_Read = 12,                      /* Read  */
  YYSYMBOL_Write = 13,                     /* Write  */
  YYSYMBOL_Array = 14,                     /* Array  */
  YYSYMBOL_If = 15,                        /* If  */
  YYSYMBOL_Then = 16,                      /* Then  */
  YYSYMBOL_Else = 17,                      /* Else  */
  YYSYMBOL_For = 18,                       /* For  */
  YYSYMBOL_While = 19,                     /* While  */
  YYSYMBOL_AsmtOp = 20,                    /* AsmtOp  */
  YYSYMBOL_Not = 21,                       /* Not  */
  YYSYMBOL_RelationalOperator = 22,        /* RelationalOperator  */
  YYSYMBOL_OpenParenthesis = 23,           /* OpenParenthesis  */
  YYSYMBOL_CloseParenthesis = 24,          /* CloseParenthesis  */
  YYSYMBOL_String = 25,                    /* String  */
  YYSYMBOL_ArrayOpen = 26,                 /* ArrayOpen  */
  YYSYMBOL_ArrayClose = 27,                /* ArrayClose  */
  YYSYMBOL_CharacterLiteral = 28,          /* CharacterLiteral  */
  YYSYMBOL_Of = 29,                        /* Of  */
  YYSYMBOL_DoubleDots = 30,                /* DoubleDots  */
  YYSYMBOL_Do = 31,                        /* Do  */
  YYSYMBOL_To = 32,                        /* To  */
  YYSYMBOL_DownTo = 33,                    /* DownTo  */
  YYSYMBOL_Plus = 34,                      /* Plus  */
  YYSYMBOL_Minus = 35,                     /* Minus  */
  YYSYMBOL_Mul = 36,                       /* Mul  */
  YYSYMBOL_Mod = 37,                       /* Mod  */
  YYSYMBOL_Div = 38,                       /* Div  */
  YYSYMBOL_Or = 39,                        /* Or  */
  YYSYMBOL_And = 40,                       /* And  */
  YYSYMBOL_NumberLiteral = 41,             /* NumberLiteral  */
  YYSYMBOL_Identifier = 42,                /* Identifier  */
  YYSYMBOL_RealLiteral = 43,               /* RealLiteral  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_sentence = 45,                  /* sentence  */
  YYSYMBOL_P = 46,                         /* P  */
  YYSYMBOL_V = 47,                         /* V  */
  YYSYMBOL_LS = 48,                        /* LS  */
  YYSYMBOL_L = 49,                         /* L  */
  YYSYMBOL_RHS = 50,                       /* RHS  */
  YYSYMBOL_Y = 51,                         /* Y  */
  YYSYMBOL_LHS = 52,                       /* LHS  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_M = 54,                         /* M  */
  YYSYMBOL_B = 55,                         /* B  */
  YYSYMBOL_S = 56,                         /* S  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_60_5 = 60,                      /* $@5  */
  YYSYMBOL_I = 61,                         /* I  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_Block = 63,                     /* Block  */
  YYSYMBOL_WriteBody = 64,                 /* WriteBody  */
  YYSYMBOL_ForLoop = 65,                   /* ForLoop  */
  YYSYMBOL_66_7 = 66,                      /* $@7  */
  YYSYMBOL_67_8 = 67,                      /* $@8  */
  YYSYMBOL_68_9 = 68,                      /* $@9  */
  YYSYMBOL_69_10 = 69,                     /* $@10  */
  YYSYMBOL_IfStatement = 70,               /* IfStatement  */
  YYSYMBOL_71_11 = 71,                     /* $@11  */
  YYSYMBOL_72_12 = 72,                     /* $@12  */
  YYSYMBOL_X = 73,                         /* X  */
  YYSYMBOL_74_13 = 74,                     /* $@13  */
  YYSYMBOL_WhileLoop = 75,                 /* WhileLoop  */
  YYSYMBOL_76_14 = 76,                     /* $@14  */
  YYSYMBOL_77_15 = 77,                     /* $@15  */
  YYSYMBOL_Expression = 78,                /* Expression  */
  YYSYMBOL_ArithmeticExpression = 79,      /* ArithmeticExpression  */
  YYSYMBOL_T = 80,                         /* T  */
  YYSYMBOL_F = 81,                         /* F  */
  YYSYMBOL_BooleanExpression = 82,         /* BooleanExpression  */
  YYSYMBOL_BooleanT = 83,                  /* BooleanT  */
  YYSYMBOL_BooleanF = 84                   /* BooleanF  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   136,   139,   142,   143,   146,   160,   167,
     170,   180,   179,   187,   195,   196,   199,   200,   210,   218,
     218,   218,   219,   219,   219,   220,   221,   222,   223,   227,
     232,   231,   274,   275,   278,   278,   279,   279,   282,   289,
     282,   315,   322,   315,   360,   374,   359,   383,   382,   406,
     414,   433,   413,   444,   445,   448,   449,   458,   468,   469,
     476,   483,   492,   495,   499,   502,   503,   506,   507,   539,
     540,   570,   593,   595,   602
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
  "\"end of file\"", "error", "\"invalid token\"", "Type", "Begin", "End",
  "Var", "Prog", "SC", "comma", "Colon", "Stop", "Read", "Write", "Array",
  "If", "Then", "Else", "For", "While", "AsmtOp", "Not",
  "RelationalOperator", "OpenParenthesis", "CloseParenthesis", "String",
  "ArrayOpen", "ArrayClose", "CharacterLiteral", "Of", "DoubleDots", "Do",
  "To", "DownTo", "Plus", "Minus", "Mul", "Mod", "Div", "Or", "And",
  "NumberLiteral", "Identifier", "RealLiteral", "$accept", "sentence", "P",
  "V", "LS", "L", "RHS", "Y", "LHS", "$@1", "M", "B", "S", "$@2", "$@3",
  "$@4", "$@5", "I", "$@6", "Block", "WriteBody", "ForLoop", "$@7", "$@8",
  "$@9", "$@10", "IfStatement", "$@11", "$@12", "X", "$@13", "WhileLoop",
  "$@14", "$@15", "Expression", "ArithmeticExpression", "T", "F",
  "BooleanExpression", "BooleanT", "BooleanF", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -39,    56,    54,    59,   -97,    44,    88,   -97,    90,
     -97,    44,    94,    53,   -97,   -97,   -97,    39,    72,    95,
     102,   103,    77,    86,    77,    87,   122,     3,   109,   -97,
     -97,   -97,   -97,    44,   -97,   104,   123,   -97,   127,   -97,
     -97,   -97,    77,    77,   -97,   -97,   -97,    62,   -10,    37,
     -97,    10,    93,   -97,   114,     1,   -97,   124,   -97,    77,
     -97,    96,   -97,   -97,    86,   -19,   -97,     9,   -11,    66,
      66,    66,    66,    66,    66,   -97,    77,    77,    66,   -97,
      66,   -97,   128,   -10,    99,   110,   -97,   130,   132,   -97,
     -97,   -97,    66,   -97,     0,    37,    37,   -97,   -97,   -97,
     138,    93,   -97,    89,   138,    27,   -97,   105,   119,   -19,
     -19,   120,    35,   -97,   -97,   -97,   -97,   -97,   118,   139,
     -97,   -97,   140,    71,    66,    66,   141,   121,   -97,   -97,
     -97,   -97,   -97,     0,     0,   -97,   148,   138,   125,   126,
     -97,   -97,   144,   138,   138,   -97,   145,   146,   -97,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     3,    13,
       4,     6,     0,     0,     2,    11,     5,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,    17,     0,    28,
      26,    25,    27,     0,     8,     0,     0,    33,     0,    15,
      19,    22,     0,     0,    63,    62,    64,    66,     0,    55,
      58,     0,    67,    69,     0,     0,    30,     0,    16,     0,
      12,     0,     7,    32,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,     0,    50,
       0,    14,     0,    54,    53,     0,    20,    37,    35,    23,
      65,    72,     0,    66,    73,    56,    57,    59,    61,    60,
       0,    68,    70,     0,     0,     0,    18,     0,     0,     0,
       0,     0,     0,    45,    38,    41,    51,    31,     0,     0,
      36,    34,     0,     0,     0,     0,     0,     0,    21,    24,
      49,    47,    46,    39,    42,    52,     0,     0,     0,     0,
      10,     9,     0,     0,     0,    48,     0,     0,    40,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   -97,   -97,   147,   -97,   -97,   -97,   129,   -97,
     -97,    85,   -97,   -97,   -97,   -97,   -97,   -13,   -97,   -96,
     -29,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -42,    40,    43,    -4,    79,
     -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,    10,    11,    36,   141,    12,    33,
      14,    26,    27,    64,   108,    65,   111,    93,    80,    29,
      89,    30,   124,   138,   125,   139,    31,   100,   123,   132,
     137,    32,   104,   126,    82,    48,    49,    50,    51,    52,
      53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    67,    66,     4,   113,    28,    87,    18,   116,    47,
      54,    47,    69,    91,    28,    20,    21,    83,    22,     1,
      55,    23,    24,    25,    70,    71,    75,    94,    76,    47,
      47,    69,    79,    90,    70,    71,   103,   102,   105,    68,
      76,   142,    34,    70,    71,    25,    47,   146,   147,    76,
     112,    86,    88,    35,   117,    84,     5,    18,    19,    90,
       6,    70,    71,    47,    47,    20,    21,     8,    22,    70,
      71,    23,    24,    72,    73,    74,    18,    37,   -74,   130,
     120,   121,   133,   134,    20,    21,     9,    22,   131,    92,
      23,    24,    13,   -74,    44,    25,    88,    88,    42,    15,
      43,   -74,   -74,    38,    17,    44,    39,    45,    25,    46,
      95,    96,    58,    56,    25,    97,    98,    99,    45,    25,
      46,   114,   115,    70,    71,    40,    41,    57,    25,    59,
      61,    62,    63,    77,    78,    81,   106,    85,    76,   109,
     107,   110,    18,   119,   122,   127,   118,   128,   129,   135,
     136,   140,   145,   148,   149,   101,   143,   144,    16,     0,
       0,     0,    60
};

static const yytype_int16 yycheck[] =
{
      13,    43,    42,    42,   100,    18,    25,     4,   104,    22,
      23,    24,    22,    24,    27,    12,    13,    59,    15,     7,
      24,    18,    19,    42,    34,    35,    16,    69,    39,    42,
      43,    22,    31,    24,    34,    35,    78,    77,    80,    43,
      39,   137,     3,    34,    35,    42,    59,   143,   144,    39,
      92,    64,    65,    14,    27,    59,     0,     4,     5,    24,
       6,    34,    35,    76,    77,    12,    13,     8,    15,    34,
      35,    18,    19,    36,    37,    38,     4,     5,    16,     8,
     109,   110,   124,   125,    12,    13,    42,    15,    17,    23,
      18,    19,     4,    31,    28,    42,   109,   110,    21,     9,
      23,    39,    40,    18,    10,    28,    11,    41,    42,    43,
      70,    71,    27,    26,    42,    72,    73,    74,    41,    42,
      43,    32,    33,    34,    35,    23,    23,     5,    42,    20,
      26,     8,     5,    40,    20,    11,     8,    41,    39,     9,
      30,     9,     4,    24,    24,    27,    41,     8,     8,     8,
      29,     3,     8,     8,     8,    76,    31,    31,    11,    -1,
      -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    45,    46,    42,     0,     6,    47,     8,    42,
      48,    49,    52,     4,    54,     9,    48,    10,     4,     5,
      12,    13,    15,    18,    19,    42,    55,    56,    61,    63,
      65,    70,    75,    53,     3,    14,    50,     5,    55,    11,
      23,    23,    21,    23,    28,    41,    43,    61,    79,    80,
      81,    82,    83,    84,    61,    82,    26,     5,    55,    20,
      52,    26,     8,     5,    57,    59,    84,    79,    82,    22,
      34,    35,    36,    37,    38,    16,    39,    40,    20,    31,
      62,    11,    78,    79,    82,    41,    61,    25,    61,    64,
      24,    24,    23,    61,    79,    80,    80,    81,    81,    81,
      71,    83,    84,    79,    76,    79,     8,    30,    58,     9,
       9,    60,    79,    63,    32,    33,    63,    27,    41,    24,
      64,    64,    24,    72,    66,    68,    77,    27,     8,     8,
       8,    17,    73,    79,    79,     8,    29,    74,    67,    69,
       3,    51,    63,    31,    31,     8,    63,    63,     8,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    48,    48,    49,    50,    50,
      51,    53,    52,    52,    54,    54,    55,    55,    56,    57,
      58,    56,    59,    60,    56,    56,    56,    56,    56,    61,
      62,    61,    63,    63,    64,    64,    64,    64,    66,    67,
      65,    68,    69,    65,    71,    72,    70,    74,    73,    73,
      76,    77,    75,    78,    78,    79,    79,    79,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     4,     1,     8,
       1,     0,     4,     1,     4,     3,     2,     1,     4,     0,
       0,     7,     0,     0,     7,     1,     1,     1,     1,     1,
       0,     5,     3,     2,     3,     1,     3,     1,     0,     0,
      11,     0,     0,    11,     0,     0,     7,     0,     4,     1,
       0,     0,     7,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     2,     3,     3,     1
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
  case 2: /* sentence: P V M  */
#line 133 "BGSASAS.y"
                 { printf("Valid Sentence\n") ; return 1; }
#line 1505 "y.tab.c"
    break;

  case 7: /* L: LHS Colon RHS SC  */
#line 147 "BGSASAS.y"
                                 {
					for (int i = 0; i < id_ind; i++) {

						// push the LOWERCASE NAMES 
						// printf("id_names[%d]: %s has type %s\n", i, id_names[i], gtype);
						addTyp(id_names[i],gtype);
					}
					memset(id_names, 0, sizeof(id_names));
    				memset(gtype, 0, sizeof(gtype));
					id_ind = 0;
				 }
#line 1521 "y.tab.c"
    break;

  case 8: /* RHS: Type  */
#line 161 "BGSASAS.y"
                {																	
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			strcpy(gtype, c);
																		
		}
#line 1532 "y.tab.c"
    break;

  case 10: /* Y: Type  */
#line 171 "BGSASAS.y"
                {
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			// printf("%s\n",c);
			strcpy(gtype, c);
		}
#line 1543 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 180 "BGSASAS.y"
                                        {
					char c[50]; 
					sprintf(c,"%s",(yyvsp[-1].cval));
					strcpy(id_names[id_ind++], c);
					}
#line 1553 "y.tab.c"
    break;

  case 13: /* LHS: Identifier  */
#line 188 "BGSASAS.y"
                                {
					char c[50]; 
					sprintf(c,"%s",(yyvsp[0].cval));
					strcpy(id_names[id_ind++], c);
				}
#line 1563 "y.tab.c"
    break;

  case 18: /* S: I AsmtOp Expression SC  */
#line 211 "BGSASAS.y"
                                        {
						char *op1 = pop();
						// printf("op1 is %s\n",op1);
						addQuadruple(op1, NULL, NULL, pop());
						display_Quad();
					}
#line 1574 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 218 "BGSASAS.y"
                               {is_read = 1; printf("//Read statement here\n");}
#line 1580 "y.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 218 "BGSASAS.y"
                                                                                   {is_read = 0;}
#line 1586 "y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 219 "BGSASAS.y"
                                {is_write = 1;printf("//Write statement here\n");}
#line 1592 "y.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 219 "BGSASAS.y"
                                                                                             {is_write = 0;}
#line 1598 "y.tab.c"
    break;

  case 29: /* I: Identifier  */
#line 227 "BGSASAS.y"
              {char c[50]; sprintf(c,"%s",(yyvsp[0].cval)); 
				if(is_write == 0 && is_read == 0)
					push(c);
				}
#line 1607 "y.tab.c"
    break;

  case 30: /* $@6: %empty  */
#line 232 "BGSASAS.y"
                        {
				char c[50]; 
				sprintf(c,"%s",(yyvsp[-1].cval));
				// printf("%s\n",c);
				if(is_write == 0 && is_read == 0)
					push(c);
			}
#line 1619 "y.tab.c"
    break;

  case 31: /* I: Identifier ArrayOpen $@6 ArithmeticExpression ArrayClose  */
#line 240 "BGSASAS.y"
                        {
				if(is_write == 0 && is_read == 0){
					char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
					strcat(str1, str);

					char *t0 = pop();
					char *arr_name = pop();

					char * type_temp = getTypeForName(arr_name);
					// printf("type is %s\n",type_temp);

					int sz =getTypeIntegerValue(type_temp);

					printf("%s = %d * %s\n",str1,sz,t0);

					char str2[5], str3[5]="t"; sprintf(str2,"%d", temp_char++);
					strcat(str3, str2);

					printf("%s = &%s\n",str3,arr_name);

					char str4[5], str5[5]="t"; sprintf(str4,"%d", temp_char++);
					strcat(str5, str4);

					printf("%s = %s + %s\n",str5,str1,str3);

					char new_str[6];
					new_str[0] = '*';
					strcpy(new_str + 1, str5);
					push(new_str);
				}
			}
#line 1655 "y.tab.c"
    break;

  case 38: /* $@7: %empty  */
#line 282 "BGSASAS.y"
                                              {char *op1 = pop();
											// printf("op1 is %s\n",op1);
											char *i = pop();
											addQuadruple(op1, NULL, NULL,i);
											display_Quad();
											push(i);}
#line 1666 "y.tab.c"
    break;

  case 39: /* $@8: %empty  */
#line 289 "BGSASAS.y"
                                                                     {char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
												strcat(str1, str);
												lpush(str1);
												printf("%s: ",str1);
												char *sec = pop();
												char *fir = pop();
												push(fir);
												char str3[5], str4[5]="L"; sprintf(str3,"%d", ltemp++);
												strcat(str4, str3); lpush(str4);
												printf("if %s <= %s goto %s\n",fir,sec,str4);
												char str5[5], str6[5]="L"; sprintf(str5,"%d", ltemp++);
												strcat(str6, str5); lpush(str6);
												printf("goto %s: \n",str6);
												printf("%s: ",str4);
											}
#line 1686 "y.tab.c"
    break;

  case 40: /* ForLoop: For I AsmtOp ArithmeticExpression To $@7 ArithmeticExpression $@8 Do Block SC  */
#line 305 "BGSASAS.y"
                                                                 { 
											char *fir = pop();
											printf("%s = %s + 1\n",fir,fir);
											char *l2 = lpop();
											char *l1 = lpop();
											char *l0 = lpop();
											printf("goto %s \n",l0);
											printf("%s: ",l2);
										}
#line 1700 "y.tab.c"
    break;

  case 41: /* $@9: %empty  */
#line 315 "BGSASAS.y"
                                                      {char *op1 = pop();
											// printf("op1 is %s\n",op1);
											char *i = pop();
											addQuadruple(op1, NULL, NULL,i);
											display_Quad();
											push(i);}
#line 1711 "y.tab.c"
    break;

  case 42: /* $@10: %empty  */
#line 322 "BGSASAS.y"
                                                                     {char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
												strcat(str1, str);
												lpush(str1);
												printf("%s: ",str1);
												char *sec = pop();
												char *fir = pop();
												push(fir);
												char str3[5], str4[5]="L"; sprintf(str3,"%d", ltemp++);
												strcat(str4, str3); lpush(str4);
												printf("if %s >= %s goto %s\n",fir,sec,str4);
												char str5[5], str6[5]="L"; sprintf(str5,"%d", ltemp++);
												strcat(str6, str5); lpush(str6);
												printf("goto %s: \n",str6);
												printf("%s: ",str4);
											}
#line 1731 "y.tab.c"
    break;

  case 43: /* ForLoop: For I AsmtOp ArithmeticExpression DownTo $@9 ArithmeticExpression $@10 Do Block SC  */
#line 338 "BGSASAS.y"
                                                                 { 
											char *fir = pop();
											printf("%s = %s - 1\n",fir,fir);
											char *l2 = lpop();
											char *l1 = lpop();
											char *l0 = lpop();
											printf("goto %s \n",l0);
											printf("%s: ",l2);
										}
#line 1745 "y.tab.c"
    break;

  case 44: /* $@11: %empty  */
#line 360 "BGSASAS.y"
                                        {
						char *t4 = pop();

						char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
						strcat(str1, str);

						printf("if %s = 0 goto %s\n",t4,str1);
						// str1 is L3

						lpush(str1);
					}
#line 1761 "y.tab.c"
    break;

  case 45: /* $@12: %empty  */
#line 374 "BGSASAS.y"
                                        {
						// char *l3  = lpop();
						// printf("%s: ",l3);
					}
#line 1770 "y.tab.c"
    break;

  case 47: /* $@13: %empty  */
#line 383 "BGSASAS.y"
                {
			char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
			strcat(str1, str);

			// printf("if %s = 0 goto %s\n",t4,str1);
			// str1 is L3

			printf("goto %s \n",str1);

			char *l3  = lpop();
			printf("%s: ",l3);

			lpush(str1);
		}
#line 1789 "y.tab.c"
    break;

  case 48: /* X: Else $@13 Block SC  */
#line 400 "BGSASAS.y"
                {
			char *l4  = lpop();
			printf("%s: ",l4);
		}
#line 1798 "y.tab.c"
    break;

  case 49: /* X: SC  */
#line 408 "BGSASAS.y"
                {
			char *l3  = lpop();
			printf("%s: ",l3);
		}
#line 1807 "y.tab.c"
    break;

  case 50: /* $@14: %empty  */
#line 414 "BGSASAS.y"
                        {
					char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
					strcat(str1, str);
					
					printf("%s: ",str1);
					lpush(str1);

					char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
					strcat(str3,str2);

					lpush(str3);

					char *t0 = pop();

					printf("if %s = 0 goto %s\n",t0,str3);
			}
#line 1828 "y.tab.c"
    break;

  case 51: /* $@15: %empty  */
#line 433 "BGSASAS.y"
                         {
				char *l1 = lpop();
				char *l0 = lpop();

				printf("goto %s\n",l0);
				printf("%s: ",l1);
			 }
#line 1840 "y.tab.c"
    break;

  case 56: /* ArithmeticExpression: ArithmeticExpression Plus T  */
#line 450 "BGSASAS.y"
                                                                {
									if(is_write == 0 && is_read == 0){
										char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
										strcat(str1, str); addQuadruple(pop(), "+", pop(), str1);
										display_Quad(); push(str1);
									}
													
								}
#line 1853 "y.tab.c"
    break;

  case 57: /* ArithmeticExpression: ArithmeticExpression Minus T  */
#line 459 "BGSASAS.y"
                                                                {
									if(is_write == 0 && is_read == 0){
										char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
										strcat(str1, str); addQuadruple(pop(), "-", pop(), str1);
										display_Quad(); push(str1);
									}
								}
#line 1865 "y.tab.c"
    break;

  case 59: /* T: T Mul F  */
#line 469 "BGSASAS.y"
            {
			if(is_write == 0 && is_read == 0){
				char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
				strcat(str1, str); addQuadruple(pop(), "*", pop(), str1);
				display_Quad(); push(str1);
			}
			}
#line 1877 "y.tab.c"
    break;

  case 60: /* T: T Div F  */
#line 476 "BGSASAS.y"
            {
			if(is_write == 0 && is_read == 0){
				char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
				strcat(str1, str); addQuadruple(pop(), "/", pop(), str1);
				display_Quad(); push(str1);
			}
			}
#line 1889 "y.tab.c"
    break;

  case 61: /* T: T Mod F  */
#line 483 "BGSASAS.y"
            {
			if(is_write == 0 && is_read == 0){
				char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
				strcat(str1, str); addQuadruple(pop(), "%", pop(), str1);
				display_Quad(); push(str1);
			}
			}
#line 1901 "y.tab.c"
    break;

  case 62: /* F: NumberLiteral  */
#line 492 "BGSASAS.y"
                  {if(is_write == 0 && is_read == 0){
					char c[10]; sprintf(c,"%s",(yyvsp[0].cval)); push(c);
					}}
#line 1909 "y.tab.c"
    break;

  case 63: /* F: CharacterLiteral  */
#line 495 "BGSASAS.y"
                     {
	if(is_write == 0 && is_read == 0){
		char c[10]; sprintf(c,"%s",(yyvsp[0].cval)); push(c);
	}}
#line 1918 "y.tab.c"
    break;

  case 64: /* F: RealLiteral  */
#line 499 "BGSASAS.y"
                {if(is_write == 0 && is_read == 0){
				char c[10]; sprintf(c,"%s",(yyvsp[0].cval)); push(c);
	}}
#line 1926 "y.tab.c"
    break;

  case 68: /* BooleanExpression: BooleanExpression Or BooleanT  */
#line 508 "BGSASAS.y"
                                {
					char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
					strcat(str1, str);

					printf("%s = 0\n",str1);   // t4 value of expre with or

					char *t3 = pop();
					char *t2 = pop();

					char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
					strcat(str3, str2);
					// lpush(str3);
					
					printf("if %s = 1 goto %s\n",t2,str3);
					printf("if %s = 1 goto %s\n",t3,str3);

					char str4[5], str5[5]="L"; sprintf(str4,"%d", ltemp++);
					strcat(str5, str4);

					printf("goto %s\n",str5);

					printf("%s: ",str3);	  // i know and condn value at L1
					printf("%s = 1\n",str1);

					printf("%s: ",str5);   //l2

					push(str1);   // t4 is now there in the stack

				}
#line 1960 "y.tab.c"
    break;

  case 70: /* BooleanT: BooleanT And BooleanF  */
#line 540 "BGSASAS.y"
                                        { //label L0 make , t2 = 0,  if if (2 pops), push t2, t2 = 1, L0 print, and label L0
								char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
								strcat(str1, str);

								printf("%s = 0\n",str1);
								
								char *t1 = pop(); 
								// printf("\nt1 is %s\n",t1);

								char *t0 = pop(); 
								// printf("\nt0 is %s\n",t0);

								// printf("\nt0 is %s\n",t0);

								char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
								strcat(str3, str2);
								// lpush(str3);

								// printf("\nt1 is %s\n",t1);
								// printf("\nt0 is %s\n",t0);
									
								printf("if %s = 0 goto %s\n",t0,str3);
								printf("if %s = 0 goto %s\n",t1,str3);
								printf("%s = 1\n",str1);

								printf("%s: ",str3);	  // i know and condn value at L0
								push(str1);   // t2 is now there in the stack
								}
#line 1993 "y.tab.c"
    break;

  case 71: /* BooleanF: Not BooleanF  */
#line 571 "BGSASAS.y"
                        { 
				char * temp = pop();

				char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
				strcat(str1, str);

				printf("if %s = 0 goto %s\n",temp,str1);

				char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
				strcat(str3, str2);

				printf("%s = 0\n",temp);
				printf("goto %s\n",str3);

				printf("%s: ",str1);
				printf("%s = 1\n",temp);
				printf("%s: \n",str3);

				push(temp);

			}
#line 2019 "y.tab.c"
    break;

  case 73: /* BooleanF: ArithmeticExpression RelationalOperator ArithmeticExpression  */
#line 597 "BGSASAS.y"
                {char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
		strcat(str1, str);
		addQuadruple(pop(), (yyvsp[-1].cval), pop(), str1);
		display_Quad(); push(str1);}
#line 2028 "y.tab.c"
    break;


#line 2032 "y.tab.c"

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

#line 605 "BGSASAS.y"


void main(){
	FILE *f = fopen("input.txt","r");
    yyin = f;
    yyparse();
    exit(0);
    }


void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
