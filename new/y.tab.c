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

extern FILE* yyin;
extern FILE *yyout;
extern int line_num;
void yyerror(const char *msg);


#line 85 "y.tab.c"

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
    Identifier = 297               /* Identifier  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "BGSASAS.y"
char *cval;int ival;

#line 225 "y.tab.c"

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
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_sentence = 44,                  /* sentence  */
  YYSYMBOL_P = 45,                         /* P  */
  YYSYMBOL_V = 46,                         /* V  */
  YYSYMBOL_LS = 47,                        /* LS  */
  YYSYMBOL_O = 48,                         /* O  */
  YYSYMBOL_L = 49,                         /* L  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_RHS = 51,                       /* RHS  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_58_8 = 58,                      /* $@8  */
  YYSYMBOL_59_9 = 59,                      /* $@9  */
  YYSYMBOL_Y = 60,                         /* Y  */
  YYSYMBOL_LHS = 61,                       /* LHS  */
  YYSYMBOL_62_10 = 62,                     /* $@10  */
  YYSYMBOL_H = 63,                         /* H  */
  YYSYMBOL_64_11 = 64,                     /* $@11  */
  YYSYMBOL_M = 65,                         /* M  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_J = 67,                         /* J  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_B = 69,                         /* B  */
  YYSYMBOL_K = 70,                         /* K  */
  YYSYMBOL_S = 71,                         /* S  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_73_15 = 73,                     /* $@15  */
  YYSYMBOL_74_16 = 74,                     /* $@16  */
  YYSYMBOL_75_17 = 75,                     /* $@17  */
  YYSYMBOL_76_18 = 76,                     /* $@18  */
  YYSYMBOL_77_19 = 77,                     /* $@19  */
  YYSYMBOL_78_20 = 78,                     /* $@20  */
  YYSYMBOL_79_21 = 79,                     /* $@21  */
  YYSYMBOL_80_22 = 80,                     /* $@22  */
  YYSYMBOL_81_23 = 81,                     /* $@23  */
  YYSYMBOL_82_24 = 82,                     /* $@24  */
  YYSYMBOL_I = 83,                         /* I  */
  YYSYMBOL_84_25 = 84,                     /* $@25  */
  YYSYMBOL_85_26 = 85,                     /* $@26  */
  YYSYMBOL_G = 86,                         /* G  */
  YYSYMBOL_87_27 = 87,                     /* $@27  */
  YYSYMBOL_88_28 = 88,                     /* $@28  */
  YYSYMBOL_Block = 89,                     /* Block  */
  YYSYMBOL_90_29 = 90,                     /* $@29  */
  YYSYMBOL_A = 91,                         /* A  */
  YYSYMBOL_92_30 = 92,                     /* $@30  */
  YYSYMBOL_93_31 = 93,                     /* $@31  */
  YYSYMBOL_WriteBody = 94,                 /* WriteBody  */
  YYSYMBOL_95_32 = 95,                     /* $@32  */
  YYSYMBOL_96_33 = 96,                     /* $@33  */
  YYSYMBOL_C = 97,                         /* C  */
  YYSYMBOL_98_34 = 98,                     /* $@34  */
  YYSYMBOL_D = 99,                         /* D  */
  YYSYMBOL_100_35 = 100,                   /* $@35  */
  YYSYMBOL_ForLoop = 101,                  /* ForLoop  */
  YYSYMBOL_102_36 = 102,                   /* $@36  */
  YYSYMBOL_103_37 = 103,                   /* $@37  */
  YYSYMBOL_104_38 = 104,                   /* $@38  */
  YYSYMBOL_105_39 = 105,                   /* $@39  */
  YYSYMBOL_106_40 = 106,                   /* $@40  */
  YYSYMBOL_107_41 = 107,                   /* $@41  */
  YYSYMBOL_108_42 = 108,                   /* $@42  */
  YYSYMBOL_109_43 = 109,                   /* $@43  */
  YYSYMBOL_110_44 = 110,                   /* $@44  */
  YYSYMBOL_E = 111,                        /* E  */
  YYSYMBOL_IfStatement = 112,              /* IfStatement  */
  YYSYMBOL_113_45 = 113,                   /* $@45  */
  YYSYMBOL_114_46 = 114,                   /* $@46  */
  YYSYMBOL_115_47 = 115,                   /* $@47  */
  YYSYMBOL_116_48 = 116,                   /* $@48  */
  YYSYMBOL_117_49 = 117,                   /* $@49  */
  YYSYMBOL_X = 118,                        /* X  */
  YYSYMBOL_119_50 = 119,                   /* $@50  */
  YYSYMBOL_120_51 = 120,                   /* $@51  */
  YYSYMBOL_WhileLoop = 121,                /* WhileLoop  */
  YYSYMBOL_122_52 = 122,                   /* $@52  */
  YYSYMBOL_123_53 = 123,                   /* $@53  */
  YYSYMBOL_124_54 = 124,                   /* $@54  */
  YYSYMBOL_125_55 = 125,                   /* $@55  */
  YYSYMBOL_126_56 = 126,                   /* $@56  */
  YYSYMBOL_Expression = 127,               /* Expression  */
  YYSYMBOL_128_57 = 128,                   /* $@57  */
  YYSYMBOL_ArithmeticExpression = 129,     /* ArithmeticExpression  */
  YYSYMBOL_130_58 = 130,                   /* $@58  */
  YYSYMBOL_131_59 = 131,                   /* $@59  */
  YYSYMBOL_A1 = 132,                       /* A1  */
  YYSYMBOL_133_60 = 133,                   /* $@60  */
  YYSYMBOL_134_61 = 134,                   /* $@61  */
  YYSYMBOL_135_62 = 135,                   /* $@62  */
  YYSYMBOL_OP = 136,                       /* OP  */
  YYSYMBOL_T = 137,                        /* T  */
  YYSYMBOL_138_63 = 138,                   /* $@63  */
  YYSYMBOL_139_64 = 139,                   /* $@64  */
  YYSYMBOL_140_65 = 140,                   /* $@65  */
  YYSYMBOL_T1 = 141,                       /* T1  */
  YYSYMBOL_142_66 = 142,                   /* $@66  */
  YYSYMBOL_143_67 = 143,                   /* $@67  */
  YYSYMBOL_144_68 = 144,                   /* $@68  */
  YYSYMBOL_145_69 = 145,                   /* $@69  */
  YYSYMBOL_PO = 146,                       /* PO  */
  YYSYMBOL_F = 147,                        /* F  */
  YYSYMBOL_148_70 = 148,                   /* $@70  */
  YYSYMBOL_149_71 = 149,                   /* $@71  */
  YYSYMBOL_BooleanExpression = 150,        /* BooleanExpression  */
  YYSYMBOL_151_72 = 151,                   /* $@72  */
  YYSYMBOL_152_73 = 152,                   /* $@73  */
  YYSYMBOL_BooleanExpression1 = 153,       /* BooleanExpression1  */
  YYSYMBOL_154_74 = 154,                   /* $@74  */
  YYSYMBOL_155_75 = 155,                   /* $@75  */
  YYSYMBOL_BooleanT = 156,                 /* BooleanT  */
  YYSYMBOL_157_76 = 157,                   /* $@76  */
  YYSYMBOL_BooleanT1 = 158,                /* BooleanT1  */
  YYSYMBOL_159_77 = 159,                   /* $@77  */
  YYSYMBOL_BooleanF = 160,                 /* BooleanF  */
  YYSYMBOL_161_78 = 161,                   /* $@78  */
  YYSYMBOL_162_79 = 162,                   /* $@79  */
  YYSYMBOL_163_80 = 163,                   /* $@80  */
  YYSYMBOL_164_81 = 164,                   /* $@81  */
  YYSYMBOL_165_82 = 165,                   /* $@82  */
  YYSYMBOL_X1 = 166,                       /* X1  */
  YYSYMBOL_167_83 = 167                    /* $@83  */
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
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    21,    21,    24,    27,    30,    33,    33,    35,    35,
      38,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      42,    45,    45,    48,    48,    49,    52,    52,    55,    55,
      56,    58,    61,    61,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    65,    66,    67,
      68,    69,    73,    73,    73,    76,    76,    76,    77,    79,
      79,    82,    82,    82,    82,    84,    84,    85,    85,    88,
      88,    88,    90,    90,    90,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    95,    95,    97,    97,    97,
      97,    97,    97,   100,   100,   100,   101,   103,   103,   103,
     103,   103,   103,   106,   107,   107,   110,   110,   110,   113,
     113,   113,   113,   113,   115,   115,   117,   117,   117,   117,
     120,   120,   120,   120,   120,   120,   122,   122,   122,   124,
     125,   126,   126,   126,   127,   130,   130,   130,   133,   133,
     133,   133,   135,   135,   138,   138,   138,   140,   140,   141,
     141,   141,   142,   142,   142,   145,   145,   145
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
  "NumberLiteral", "Identifier", "$accept", "sentence", "P", "V", "LS",
  "O", "L", "$@1", "RHS", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "Y", "LHS", "$@10", "H", "$@11", "M", "$@12", "J", "$@13", "B",
  "K", "S", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "I", "$@25", "$@26", "G", "$@27", "$@28",
  "Block", "$@29", "A", "$@30", "$@31", "WriteBody", "$@32", "$@33", "C",
  "$@34", "D", "$@35", "ForLoop", "$@36", "$@37", "$@38", "$@39", "$@40",
  "$@41", "$@42", "$@43", "$@44", "E", "IfStatement", "$@45", "$@46",
  "$@47", "$@48", "$@49", "X", "$@50", "$@51", "WhileLoop", "$@52", "$@53",
  "$@54", "$@55", "$@56", "Expression", "$@57", "ArithmeticExpression",
  "$@58", "$@59", "A1", "$@60", "$@61", "$@62", "OP", "T", "$@63", "$@64",
  "$@65", "T1", "$@66", "$@67", "$@68", "$@69", "PO", "F", "$@70", "$@71",
  "BooleanExpression", "$@72", "$@73", "BooleanExpression1", "$@74",
  "$@75", "BooleanT", "$@76", "BooleanT1", "$@77", "BooleanF", "$@78",
  "$@79", "$@80", "$@81", "$@82", "X1", "$@83", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,   -10,    27,    35,    30,  -128,     4,    55,  -128,  -128,
    -128,     4,    56,  -128,  -128,    58,  -128,  -128,  -128,    18,
    -128,  -128,    14,  -128,    57,  -128,  -128,  -128,    65,     0,
    -128,    29,  -128,  -128,    54,  -128,    62,  -128,    59,     4,
    -128,  -128,    71,    68,  -128,    61,    63,  -128,  -128,  -128,
      60,  -128,  -128,  -128,  -128,  -128,    64,  -128,  -128,  -128,
      36,  -128,  -128,    70,  -128,    67,  -128,  -128,  -128,  -128,
    -128,  -128,    66,  -128,    73,  -128,  -128,  -128,  -128,     3,
    -128,    41,    80,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,    69,    72,  -128,  -128,  -128,  -128,  -128,    74,  -128,
    -128,    75,    78,    86,    76,    88,  -128,  -128,  -128,  -128,
    -128,     3,  -128,    77,    79,  -128,  -128,    81,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,   -12,    82,  -128,    93,
    -128,  -128,  -128,  -128,  -128,  -128,    85,    93,  -128,    90,
      66,    66,    94,   -14,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,    84,     3,     3,  -128,  -128,  -128,    83,  -128,
    -128,  -128,  -128,  -128,     9,  -128,  -128,    32,    17,  -128,
    -128,    79,  -128,    95,  -128,  -128,  -128,  -128,  -128,    20,
    -128,  -128,  -128,  -128,  -128,  -128,    77,  -128,  -128,  -128,
      87,  -128,    89,  -128,    25,  -128,    93,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,    91,   -14,   -12,
      92,    96,  -128,  -128,  -128,  -128,  -128,  -128,  -128,    93,
      98,    20,  -128,  -128,  -128,  -128,   102,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     3,    21,
       4,     7,     0,    26,     2,    25,     6,     5,     8,    52,
      23,    22,     0,    59,     0,    38,    43,    27,     0,    33,
      34,     0,    51,    49,     0,    48,     0,    50,     0,     0,
      10,    11,     0,    61,    30,     0,     0,    28,    32,    31,
       0,    53,    76,    88,    98,    24,     0,     9,    64,    60,
      52,    39,    44,     0,    35,    58,    52,   135,   135,    12,
      62,    52,    52,    29,   104,    55,    54,    77,    89,   152,
      99,     0,     0,    40,    67,    65,    45,    36,   106,   103,
     106,     0,     0,   147,   149,   136,   142,   106,     0,    13,
      63,     0,    74,    71,     0,     0,   105,   116,    56,    78,
      90,   152,   135,   141,   146,   153,   100,     0,    41,    72,
      68,    69,    66,    46,    37,   107,    52,     0,   106,     0,
     148,   150,   138,   137,   144,   143,   157,     0,    14,     0,
      52,    52,     0,   113,   131,   130,   129,   134,   117,    57,
      79,    91,     0,   152,   152,   155,   154,   101,     0,    42,
      73,    70,    47,   108,     0,   106,   118,     0,     0,   151,
     139,   146,   106,     0,    15,   114,   115,   110,   132,   125,
      85,    86,    80,    96,    93,    92,   141,   145,   156,   102,
       0,   116,     0,   119,     0,   106,     0,   140,    16,   111,
     133,   126,   128,   127,   121,    81,    94,     0,   113,    52,
       0,     0,    17,   112,   122,    82,    95,    18,   123,     0,
       0,   125,    83,    20,    19,   124,     0,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,   101,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,    97,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,   -15,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
     -66,  -128,  -128,  -128,  -128,  -128,  -127,  -128,  -128,  -128,
    -128,   -88,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,   -89,  -128,  -128,   -93,
    -128,  -128,  -128,  -128,   -74,  -128,  -128,  -128,  -103,  -128,
    -128,  -128,  -128,  -128,   -87,  -128,  -128,   -65,  -128,  -128,
     -61,  -128,  -128,   -32,  -128,   -45,  -128,  -104,  -128,  -128,
    -128,  -128,  -128,  -128,  -128
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,    10,    17,    11,    22,    42,    56,
      81,   117,   158,   190,   207,   217,   220,   224,    12,    15,
      21,    39,    14,    19,    27,    63,    28,    49,    29,    50,
      74,   105,    45,    71,   101,   139,    46,    72,   104,   142,
      30,    31,    65,    76,    90,   127,    32,    43,    59,    60,
      82,    86,   103,   102,   122,   141,   120,   140,    33,    34,
      66,    91,   128,   167,   195,   210,   219,   226,   182,    35,
      36,    67,    92,   129,   168,   185,   196,   211,    37,    38,
      68,    98,   137,   173,    87,    88,   106,   107,   143,   163,
     164,   191,   208,   177,   125,   126,   166,   179,   193,   194,
     209,   218,   221,   204,   148,   165,   192,    78,    79,   113,
     133,   153,   186,    95,   114,   135,   154,    96,   111,   112,
     152,    97,   136,   156,   172
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,   108,   151,    80,    23,    83,    85,   130,   115,    89,
     157,   144,    25,    26,    48,   -87,   145,    40,   -75,   -97,
    -109,  -109,    23,    24,    93,   183,    94,     5,    41,   146,
      25,    26,     4,   -87,   184,     1,   -75,   -97,     8,   150,
      23,     6,   -52,   175,   176,    70,     9,   131,    25,    26,
     171,   -87,   160,   161,   -75,   -97,  -120,  -120,  -120,    13,
     147,   201,   202,   203,   180,   181,    18,    20,    44,   206,
      47,    51,    52,    58,    85,    85,   178,    53,    54,    57,
      64,    73,    99,   188,    61,   100,    62,   119,   110,   109,
      69,    84,   222,    75,  -135,   121,   124,    23,   159,   118,
     123,   223,   162,   189,   216,   116,   205,   155,   169,   149,
     227,   138,    16,   200,   198,   213,   132,   199,   225,   134,
     212,   170,   214,   215,   174,   197,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,   147
};

static const yytype_int16 yycheck[] =
{
      66,    90,   129,    68,     4,    71,    72,   111,    97,    74,
     137,    23,    12,    13,    29,    15,    28,     3,    18,    19,
      34,    35,     4,     5,    21,     8,    23,     0,    14,    41,
      12,    13,    42,    15,    17,     7,    18,    19,     8,   128,
       4,     6,    42,    34,    35,    60,    42,   112,    12,    13,
     154,    15,   140,   141,    18,    19,    36,    37,    38,     4,
     126,    36,    37,    38,    32,    33,    10,     9,    11,   196,
       5,    42,    18,     5,   140,   141,   165,    15,    19,     8,
      20,    11,    41,   172,    23,     5,    23,     9,    16,    20,
      26,    25,   219,    26,    21,     9,     8,     4,     8,    24,
      24,     3,     8,     8,     8,    31,   195,    22,    24,    27,
       8,    30,    11,    24,    27,   208,    39,   191,   221,    40,
      29,   153,   209,    31,    41,   186,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,   209
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    44,    45,    42,     0,     6,    46,     8,    42,
      47,    49,    61,     4,    65,    62,    47,    48,    10,    66,
       9,    63,    50,     4,     5,    12,    13,    67,    69,    71,
      83,    84,    89,   101,   102,   112,   113,   121,   122,    64,
       3,    14,    51,    90,    11,    75,    79,     5,    69,    70,
      72,    42,    18,    15,    19,    61,    52,     8,     5,    91,
      92,    23,    23,    68,    20,    85,   103,   114,   123,    26,
      69,    76,    80,    11,    73,    26,    86,    83,   150,   151,
     150,    53,    93,    83,    25,    83,    94,   127,   128,   150,
      87,   104,   115,    21,    23,   156,   160,   164,   124,    41,
       5,    77,    96,    95,    81,    74,   129,   130,   129,    20,
      16,   161,   162,   152,   157,   129,    31,    54,    24,     9,
      99,     9,    97,    24,     8,   137,   138,    88,   105,   116,
     160,   150,    39,   153,    40,   158,   165,   125,    30,    78,
     100,    98,    82,   131,    23,    28,    41,    83,   147,    27,
     129,    89,   163,   154,   159,    22,   166,    89,    55,     8,
      94,    94,     8,   132,   133,   148,   139,   106,   117,    24,
     156,   160,   167,   126,    41,    34,    35,   136,   129,   140,
      32,    33,   111,     8,    17,   118,   155,   158,   129,     8,
      56,   134,   149,   141,   142,   107,   119,   153,    27,   137,
      24,    36,    37,    38,   146,   129,    89,    57,   135,   143,
     108,   120,    29,   132,   147,    31,     8,    58,   144,   109,
      59,   145,    89,     3,    60,   141,   110,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    47,    48,    48,    50,    49,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    51,
      60,    62,    61,    64,    63,    63,    66,    65,    68,    67,
      67,    69,    70,    70,    72,    73,    74,    71,    75,    76,
      77,    78,    71,    79,    80,    81,    82,    71,    71,    71,
      71,    71,    84,    85,    83,    87,    88,    86,    86,    90,
      89,    92,    93,    91,    91,    95,    94,    96,    94,    98,
      97,    97,   100,    99,    99,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   101,   111,   111,   113,   114,   115,
     116,   117,   112,   119,   120,   118,   118,   122,   123,   124,
     125,   126,   121,   127,   128,   127,   130,   131,   129,   133,
     134,   135,   132,   132,   136,   136,   138,   139,   140,   137,
     142,   143,   144,   145,   141,   141,   146,   146,   146,   147,
     147,   148,   149,   147,   147,   151,   152,   150,   154,   155,
     153,   153,   157,   156,   159,   158,   158,   161,   160,   162,
     163,   160,   164,   165,   160,   167,   166,   166
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     0,     0,     5,
       1,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       1,     0,     3,     0,     3,     0,     0,     3,     0,     4,
       2,     2,     1,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     9,     1,     1,
       1,     1,     0,     0,     4,     0,     0,     5,     0,     0,
       3,     0,     0,     4,     1,     0,     3,     0,     3,     0,
       3,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     1,     1,     0,     0,     0,
       0,     0,    10,     0,     0,     5,     1,     0,     0,     0,
       0,     0,    10,     1,     0,     2,     0,     0,     4,     0,
       0,     0,     6,     0,     1,     1,     0,     0,     0,     5,
       0,     0,     0,     0,     7,     0,     1,     1,     1,     1,
       1,     0,     0,     5,     1,     0,     0,     4,     0,     0,
       5,     0,     0,     3,     0,     4,     0,     0,     3,     0,
       0,     5,     0,     0,     4,     0,     3,     0
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
#line 21 "BGSASAS.y"
                 {return 1;}
#line 1543 "y.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 35 "BGSASAS.y"
              {fprintf(yyout, ":");}
#line 1549 "y.tab.c"
    break;

  case 10: /* RHS: Type  */
#line 38 "BGSASAS.y"
           {fprintf(yyout, "type=%s\n",(yyvsp[0].cval));}
#line 1555 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 39 "BGSASAS.y"
                {fprintf(yyout, "array:");}
#line 1561 "y.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 39 "BGSASAS.y"
                                                      {fprintf(yyout, "");}
#line 1567 "y.tab.c"
    break;

  case 13: /* $@4: %empty  */
#line 39 "BGSASAS.y"
                                                                                          {fprintf(yyout, "%d,",(yyvsp[0].ival));}
#line 1573 "y.tab.c"
    break;

  case 14: /* $@5: %empty  */
#line 39 "BGSASAS.y"
                                                                                                                                       {fprintf(yyout, "");}
#line 1579 "y.tab.c"
    break;

  case 15: /* $@6: %empty  */
#line 39 "BGSASAS.y"
                                                                                                                                                                           {fprintf(yyout, "%d",(yyvsp[0].ival));}
#line 1585 "y.tab.c"
    break;

  case 16: /* $@7: %empty  */
#line 39 "BGSASAS.y"
                                                                                                                                                                                                                       {fprintf(yyout, "");}
#line 1591 "y.tab.c"
    break;

  case 17: /* $@8: %empty  */
#line 39 "BGSASAS.y"
                                                                                                                                                                                                                                                {fprintf(yyout, "");}
#line 1597 "y.tab.c"
    break;

  case 18: /* $@9: %empty  */
#line 39 "BGSASAS.y"
                                                                                                                                                                                                                                                                      {fprintf(yyout, ":");}
#line 1603 "y.tab.c"
    break;

  case 19: /* RHS: Array $@2 ArrayOpen $@3 NumberLiteral $@4 DoubleDots $@5 NumberLiteral $@6 ArrayClose $@7 Of $@8 $@9 Y  */
#line 39 "BGSASAS.y"
                                                                                                                                                                                                                                                                                              {fprintf(yyout, "");}
#line 1609 "y.tab.c"
    break;

  case 20: /* Y: Type  */
#line 42 "BGSASAS.y"
         {fprintf(yyout, "type=%s\n",(yyvsp[0].cval));}
#line 1615 "y.tab.c"
    break;

  case 21: /* $@10: %empty  */
#line 45 "BGSASAS.y"
                {fprintf(yyout, "%s",(yyvsp[0].cval));}
#line 1621 "y.tab.c"
    break;

  case 23: /* $@11: %empty  */
#line 48 "BGSASAS.y"
        {fprintf(yyout, ",");}
#line 1627 "y.tab.c"
    break;

  case 26: /* $@12: %empty  */
#line 52 "BGSASAS.y"
          {fprintf(yyout, "begin\n");}
#line 1633 "y.tab.c"
    break;

  case 28: /* $@13: %empty  */
#line 55 "BGSASAS.y"
          {fprintf(yyout, "\nend");}
#line 1639 "y.tab.c"
    break;

  case 30: /* J: End Stop  */
#line 56 "BGSASAS.y"
                   {fprintf(yyout, "\nend");}
#line 1645 "y.tab.c"
    break;

  case 34: /* $@14: %empty  */
#line 63 "BGSASAS.y"
       {fprintf(yyout, "");}
#line 1651 "y.tab.c"
    break;

  case 35: /* $@15: %empty  */
#line 63 "BGSASAS.y"
                                  {fprintf(yyout, "=");}
#line 1657 "y.tab.c"
    break;

  case 36: /* $@16: %empty  */
#line 63 "BGSASAS.y"
                                                                    {fprintf(yyout, "");}
#line 1663 "y.tab.c"
    break;

  case 37: /* S: I $@14 AsmtOp $@15 Expression $@16 SC  */
#line 63 "BGSASAS.y"
                                                                                             {fprintf(yyout, "");}
#line 1669 "y.tab.c"
    break;

  case 38: /* $@17: %empty  */
#line 64 "BGSASAS.y"
              {fprintf(yyout, "[read:{read}]");}
#line 1675 "y.tab.c"
    break;

  case 39: /* $@18: %empty  */
#line 64 "BGSASAS.y"
                                                               {fprintf(yyout, "[open_parenthesis:{(}]");}
#line 1681 "y.tab.c"
    break;

  case 40: /* $@19: %empty  */
#line 64 "BGSASAS.y"
                                                                                                            {fprintf(yyout, "]");}
#line 1687 "y.tab.c"
    break;

  case 41: /* $@20: %empty  */
#line 64 "BGSASAS.y"
                                                                                                                                                   {fprintf(yyout, "[close_parenthesis:{)}]");}
#line 1693 "y.tab.c"
    break;

  case 42: /* S: Read $@17 OpenParenthesis $@18 I $@19 CloseParenthesis $@20 SC  */
#line 64 "BGSASAS.y"
                                                                                                                                                                                                   {fprintf(yyout, "[SC:{;}]");}
#line 1699 "y.tab.c"
    break;

  case 43: /* $@21: %empty  */
#line 65 "BGSASAS.y"
                {fprintf(yyout, "[write:{write}]");}
#line 1705 "y.tab.c"
    break;

  case 44: /* $@22: %empty  */
#line 65 "BGSASAS.y"
                                                                     {fprintf(yyout, "[open_parenthesis:{(}][WriteBody");}
#line 1711 "y.tab.c"
    break;

  case 45: /* $@23: %empty  */
#line 65 "BGSASAS.y"
                                                                                                                                     {fprintf(yyout, "]");}
#line 1717 "y.tab.c"
    break;

  case 46: /* $@24: %empty  */
#line 65 "BGSASAS.y"
                                                                                                                                                                             {fprintf(yyout, "[close_parenthesis:{)}]");}
#line 1723 "y.tab.c"
    break;

  case 47: /* S: Write $@21 OpenParenthesis $@22 WriteBody $@23 CloseParenthesis $@24 SC  */
#line 65 "BGSASAS.y"
                                                                                                                                                                                                                             {fprintf(yyout, "[SC:{;}]");}
#line 1729 "y.tab.c"
    break;

  case 48: /* S: IfStatement  */
#line 66 "BGSASAS.y"
                      {fprintf(yyout, "]");}
#line 1735 "y.tab.c"
    break;

  case 49: /* S: ForLoop  */
#line 67 "BGSASAS.y"
                  {fprintf(yyout, "]");}
#line 1741 "y.tab.c"
    break;

  case 50: /* S: WhileLoop  */
#line 68 "BGSASAS.y"
                    {fprintf(yyout, "]");}
#line 1747 "y.tab.c"
    break;

  case 51: /* S: Block  */
#line 69 "BGSASAS.y"
                {fprintf(yyout, "]");}
#line 1753 "y.tab.c"
    break;

  case 52: /* $@25: %empty  */
#line 73 "BGSASAS.y"
   {fprintf(yyout, "");}
#line 1759 "y.tab.c"
    break;

  case 53: /* $@26: %empty  */
#line 73 "BGSASAS.y"
                                   {fprintf(yyout, "var:%s",(yyvsp[0].cval));}
#line 1765 "y.tab.c"
    break;

  case 54: /* I: $@25 Identifier $@26 G  */
#line 73 "BGSASAS.y"
                                                                          {fprintf(yyout, "");}
#line 1771 "y.tab.c"
    break;

  case 55: /* $@27: %empty  */
#line 76 "BGSASAS.y"
             {fprintf(yyout, "[array_open:{[}][ArithmeticExpression");}
#line 1777 "y.tab.c"
    break;

  case 56: /* $@28: %empty  */
#line 76 "BGSASAS.y"
                                                                                            {fprintf(yyout, "]");}
#line 1783 "y.tab.c"
    break;

  case 57: /* G: ArrayOpen $@27 ArithmeticExpression $@28 ArrayClose  */
#line 76 "BGSASAS.y"
                                                                                                                              {fprintf(yyout, "[array_close:{]}]");}
#line 1789 "y.tab.c"
    break;

  case 59: /* $@29: %empty  */
#line 79 "BGSASAS.y"
             {fprintf(yyout, "[begin:{begin}]");fprintf(yyout, "[A");}
#line 1795 "y.tab.c"
    break;

  case 60: /* Block: Begin $@29 A  */
#line 79 "BGSASAS.y"
                                                                        {fprintf(yyout, "]");}
#line 1801 "y.tab.c"
    break;

  case 61: /* $@30: %empty  */
#line 82 "BGSASAS.y"
   {fprintf(yyout, "[B");}
#line 1807 "y.tab.c"
    break;

  case 62: /* $@31: %empty  */
#line 82 "BGSASAS.y"
                            {fprintf(yyout, "]");}
#line 1813 "y.tab.c"
    break;

  case 63: /* A: $@30 B $@31 End  */
#line 82 "BGSASAS.y"
                                                       {fprintf(yyout, "[end:{end}]");}
#line 1819 "y.tab.c"
    break;

  case 64: /* A: End  */
#line 82 "BGSASAS.y"
                                                                                              {fprintf(yyout, "[end:{end}]");}
#line 1825 "y.tab.c"
    break;

  case 65: /* $@32: %empty  */
#line 84 "BGSASAS.y"
              {fprintf(yyout, "][C");}
#line 1831 "y.tab.c"
    break;

  case 66: /* WriteBody: I $@32 C  */
#line 84 "BGSASAS.y"
                                       {fprintf(yyout, "]");}
#line 1837 "y.tab.c"
    break;

  case 67: /* $@33: %empty  */
#line 85 "BGSASAS.y"
                                {fprintf(yyout, "[string:{%s}][D",(yyvsp[0].cval));}
#line 1843 "y.tab.c"
    break;

  case 68: /* WriteBody: String $@33 D  */
#line 85 "BGSASAS.y"
                                                                                {fprintf(yyout, "]");}
#line 1849 "y.tab.c"
    break;

  case 69: /* $@34: %empty  */
#line 88 "BGSASAS.y"
         {fprintf(yyout, "[comma:{,}][WriteBody");}
#line 1855 "y.tab.c"
    break;

  case 70: /* C: comma $@34 WriteBody  */
#line 88 "BGSASAS.y"
                                                              {fprintf(yyout, "]");}
#line 1861 "y.tab.c"
    break;

  case 72: /* $@35: %empty  */
#line 90 "BGSASAS.y"
         {fprintf(yyout, "[comma:{,}][WriteBody");}
#line 1867 "y.tab.c"
    break;

  case 73: /* D: comma $@35 WriteBody  */
#line 90 "BGSASAS.y"
                                                              {fprintf(yyout, "]");}
#line 1873 "y.tab.c"
    break;

  case 75: /* $@36: %empty  */
#line 92 "BGSASAS.y"
         {fprintf(yyout, "[ForLoop");}
#line 1879 "y.tab.c"
    break;

  case 76: /* $@37: %empty  */
#line 92 "BGSASAS.y"
                                         {fprintf(yyout, "[for:{for}]");}
#line 1885 "y.tab.c"
    break;

  case 77: /* $@38: %empty  */
#line 92 "BGSASAS.y"
                                                                            {fprintf(yyout, "]");}
#line 1891 "y.tab.c"
    break;

  case 78: /* $@39: %empty  */
#line 92 "BGSASAS.y"
                                                                                                         {fprintf(yyout, "[asmt_op:{:=}][ArithmeticExpression");}
#line 1897 "y.tab.c"
    break;

  case 79: /* $@40: %empty  */
#line 92 "BGSASAS.y"
                                                                                                                                                                                       {fprintf(yyout, "][E");}
#line 1903 "y.tab.c"
    break;

  case 80: /* $@41: %empty  */
#line 92 "BGSASAS.y"
                                                                                                                                                                                                                  {fprintf(yyout, "][ArithmeticExpression");}
#line 1909 "y.tab.c"
    break;

  case 81: /* $@42: %empty  */
#line 92 "BGSASAS.y"
                                                                                                                                                                                                                                                                                   {fprintf(yyout, "]");}
#line 1915 "y.tab.c"
    break;

  case 82: /* $@43: %empty  */
#line 92 "BGSASAS.y"
                                                                                                                                                                                                                                                                                                            {fprintf(yyout, "[Do:{do}][Block");}
#line 1921 "y.tab.c"
    break;

  case 83: /* $@44: %empty  */
#line 92 "BGSASAS.y"
                                                                                                                                                                                                                                                                                                                                                       {fprintf(yyout, "]");}
#line 1927 "y.tab.c"
    break;

  case 84: /* ForLoop: $@36 For $@37 I $@38 AsmtOp $@39 ArithmeticExpression $@40 E $@41 ArithmeticExpression $@42 Do $@43 Block $@44 SC  */
#line 92 "BGSASAS.y"
                                                                                                                                                                                                                                                                                                                                                                                 {fprintf(yyout, "[SC:{;}]");}
#line 1933 "y.tab.c"
    break;

  case 85: /* E: To  */
#line 95 "BGSASAS.y"
      {fprintf(yyout, "[To:{to}]");}
#line 1939 "y.tab.c"
    break;

  case 86: /* E: DownTo  */
#line 95 "BGSASAS.y"
                                             {fprintf(yyout, "[DownTo: {down_to}]");}
#line 1945 "y.tab.c"
    break;

  case 87: /* $@45: %empty  */
#line 97 "BGSASAS.y"
             {fprintf(yyout, "[IfStatement");}
#line 1951 "y.tab.c"
    break;

  case 88: /* $@46: %empty  */
#line 97 "BGSASAS.y"
                                                 {fprintf(yyout, "[if:{if}]");}
#line 1957 "y.tab.c"
    break;

  case 89: /* $@47: %empty  */
#line 97 "BGSASAS.y"
                                                                                                {fprintf(yyout, "]");}
#line 1963 "y.tab.c"
    break;

  case 90: /* $@48: %empty  */
#line 97 "BGSASAS.y"
                                                                                                                            {fprintf(yyout, "[then:{then}][Block");}
#line 1969 "y.tab.c"
    break;

  case 91: /* $@49: %empty  */
#line 97 "BGSASAS.y"
                                                                                                                                                                           {fprintf(yyout, "][X");}
#line 1975 "y.tab.c"
    break;

  case 92: /* IfStatement: $@45 If $@46 BooleanExpression $@47 Then $@48 Block $@49 X  */
#line 97 "BGSASAS.y"
                                                                                                                                                                                                      {fprintf(yyout, "]");}
#line 1981 "y.tab.c"
    break;

  case 93: /* $@50: %empty  */
#line 100 "BGSASAS.y"
        {fprintf(yyout, "[else:{else}][Block");}
#line 1987 "y.tab.c"
    break;

  case 94: /* $@51: %empty  */
#line 100 "BGSASAS.y"
                                                      {fprintf(yyout, "]");}
#line 1993 "y.tab.c"
    break;

  case 95: /* X: Else $@50 Block $@51 SC  */
#line 100 "BGSASAS.y"
                                                                                {fprintf(yyout, "[SC:{;]}");}
#line 1999 "y.tab.c"
    break;

  case 96: /* X: SC  */
#line 101 "BGSASAS.y"
             {fprintf(yyout, "[SC:{;}]");}
#line 2005 "y.tab.c"
    break;

  case 97: /* $@52: %empty  */
#line 103 "BGSASAS.y"
           {fprintf(yyout, "[WhileLoop");}
#line 2011 "y.tab.c"
    break;

  case 98: /* $@53: %empty  */
#line 103 "BGSASAS.y"
                                                {fprintf(yyout, "[While:{while}]");}
#line 2017 "y.tab.c"
    break;

  case 99: /* $@54: %empty  */
#line 103 "BGSASAS.y"
                                                                                                      {fprintf(yyout, "]");}
#line 2023 "y.tab.c"
    break;

  case 100: /* $@55: %empty  */
#line 103 "BGSASAS.y"
                                                                                                                              {fprintf(yyout, "[Do:{do}][Block");}
#line 2029 "y.tab.c"
    break;

  case 101: /* $@56: %empty  */
#line 103 "BGSASAS.y"
                                                                                                                                                                        {fprintf(yyout, "]");}
#line 2035 "y.tab.c"
    break;

  case 102: /* WhileLoop: $@52 While $@53 BooleanExpression $@54 Do $@55 Block $@56 SC  */
#line 103 "BGSASAS.y"
                                                                                                                                                                                                  {fprintf(yyout, "[SC:{;}]");}
#line 2041 "y.tab.c"
    break;

  case 103: /* Expression: BooleanExpression  */
#line 106 "BGSASAS.y"
                              {fprintf(yyout, "]");}
#line 2047 "y.tab.c"
    break;

  case 104: /* $@57: %empty  */
#line 107 "BGSASAS.y"
                    {fprintf(yyout, "[ArithmeticExpression");}
#line 2053 "y.tab.c"
    break;

  case 105: /* Expression: $@57 ArithmeticExpression  */
#line 107 "BGSASAS.y"
                                                                                    {fprintf(yyout, "]");}
#line 2059 "y.tab.c"
    break;

  case 106: /* $@58: %empty  */
#line 110 "BGSASAS.y"
                      {fprintf(yyout, "[T");}
#line 2065 "y.tab.c"
    break;

  case 107: /* $@59: %empty  */
#line 110 "BGSASAS.y"
                                              {fprintf(yyout, "][A1");}
#line 2071 "y.tab.c"
    break;

  case 108: /* ArithmeticExpression: $@58 T $@59 A1  */
#line 110 "BGSASAS.y"
                                                                          {fprintf(yyout, "]");}
#line 2077 "y.tab.c"
    break;

  case 109: /* $@60: %empty  */
#line 113 "BGSASAS.y"
    {fprintf(yyout, "[OP");}
#line 2083 "y.tab.c"
    break;

  case 110: /* $@61: %empty  */
#line 113 "BGSASAS.y"
                              {fprintf(yyout, "][T");}
#line 2089 "y.tab.c"
    break;

  case 111: /* $@62: %empty  */
#line 113 "BGSASAS.y"
                                                        {fprintf(yyout, "][A1");}
#line 2095 "y.tab.c"
    break;

  case 112: /* A1: $@60 OP $@61 T $@62 A1  */
#line 113 "BGSASAS.y"
                                                                                     {fprintf(yyout, "]");}
#line 2101 "y.tab.c"
    break;

  case 114: /* OP: Plus  */
#line 115 "BGSASAS.y"
         {fprintf(yyout, "[plus:{+}]");}
#line 2107 "y.tab.c"
    break;

  case 115: /* OP: Minus  */
#line 115 "BGSASAS.y"
                                                {fprintf(yyout, "[minus:{-}]");}
#line 2113 "y.tab.c"
    break;

  case 116: /* $@63: %empty  */
#line 117 "BGSASAS.y"
    {fprintf(yyout, "[F");}
#line 2119 "y.tab.c"
    break;

  case 117: /* $@64: %empty  */
#line 117 "BGSASAS.y"
                            {fprintf(yyout, "]");}
#line 2125 "y.tab.c"
    break;

  case 118: /* $@65: %empty  */
#line 117 "BGSASAS.y"
                                                   {fprintf(yyout, "[T1");}
#line 2131 "y.tab.c"
    break;

  case 119: /* T: $@63 F $@64 $@65 T1  */
#line 117 "BGSASAS.y"
                                                                              {fprintf(yyout, "]");}
#line 2137 "y.tab.c"
    break;

  case 120: /* $@66: %empty  */
#line 120 "BGSASAS.y"
    {fprintf(yyout, "[PO");}
#line 2143 "y.tab.c"
    break;

  case 121: /* $@67: %empty  */
#line 120 "BGSASAS.y"
                               {fprintf(yyout, "][F");}
#line 2149 "y.tab.c"
    break;

  case 122: /* $@68: %empty  */
#line 120 "BGSASAS.y"
                                                          {fprintf(yyout, "]");}
#line 2155 "y.tab.c"
    break;

  case 123: /* $@69: %empty  */
#line 120 "BGSASAS.y"
                                                                                 {fprintf(yyout, "[T1");}
#line 2161 "y.tab.c"
    break;

  case 124: /* T1: $@66 PO $@67 F $@68 $@69 T1  */
#line 120 "BGSASAS.y"
                                                                                                           {fprintf(yyout, "]");}
#line 2167 "y.tab.c"
    break;

  case 126: /* PO: Mul  */
#line 122 "BGSASAS.y"
       {fprintf(yyout, "[mul:{*}]");}
#line 2173 "y.tab.c"
    break;

  case 127: /* PO: Div  */
#line 122 "BGSASAS.y"
                                           {fprintf(yyout, "[div:{/}]");}
#line 2179 "y.tab.c"
    break;

  case 128: /* PO: Mod  */
#line 122 "BGSASAS.y"
                                                                               {fprintf(yyout, "[mod:{%}]");}
#line 2185 "y.tab.c"
    break;

  case 129: /* F: NumberLiteral  */
#line 124 "BGSASAS.y"
                  {fprintf(yyout, "[number_literal:{%d}]",(yyvsp[0].ival));}
#line 2191 "y.tab.c"
    break;

  case 130: /* F: CharacterLiteral  */
#line 125 "BGSASAS.y"
                     {fprintf(yyout, "[character_literal:{%s}]",(yyvsp[0].cval));}
#line 2197 "y.tab.c"
    break;

  case 131: /* $@70: %empty  */
#line 126 "BGSASAS.y"
                    {fprintf(yyout, "[open_parenthesis:{(}][ArithmeticExpression");}
#line 2203 "y.tab.c"
    break;

  case 132: /* $@71: %empty  */
#line 126 "BGSASAS.y"
                                                                                                          {fprintf(yyout, "]");}
#line 2209 "y.tab.c"
    break;

  case 133: /* F: OpenParenthesis $@70 ArithmeticExpression $@71 CloseParenthesis  */
#line 126 "BGSASAS.y"
                                                                                                                                                  {fprintf(yyout, "[close_parenthesis:)]");}
#line 2215 "y.tab.c"
    break;

  case 134: /* F: I  */
#line 127 "BGSASAS.y"
     {fprintf(yyout, "]");}
#line 2221 "y.tab.c"
    break;

  case 135: /* $@72: %empty  */
#line 130 "BGSASAS.y"
                   {fprintf(yyout, "[BooleanExpression[BooleanT");}
#line 2227 "y.tab.c"
    break;

  case 136: /* $@73: %empty  */
#line 130 "BGSASAS.y"
                                                                           {fprintf(yyout, "][BooleanExpression1");}
#line 2233 "y.tab.c"
    break;

  case 137: /* BooleanExpression: $@72 BooleanT $@73 BooleanExpression1  */
#line 130 "BGSASAS.y"
                                                                                                                                        {fprintf(yyout, "]");}
#line 2239 "y.tab.c"
    break;

  case 138: /* $@74: %empty  */
#line 133 "BGSASAS.y"
                       {fprintf(yyout, "[or:{or}][BooleanT");}
#line 2245 "y.tab.c"
    break;

  case 139: /* $@75: %empty  */
#line 133 "BGSASAS.y"
                                                                      {fprintf(yyout, "][BooleanExpression1");}
#line 2251 "y.tab.c"
    break;

  case 140: /* BooleanExpression1: Or $@74 BooleanT $@75 BooleanExpression1  */
#line 133 "BGSASAS.y"
                                                                                                                                   {fprintf(yyout, "]");}
#line 2257 "y.tab.c"
    break;

  case 142: /* $@76: %empty  */
#line 135 "BGSASAS.y"
                   {fprintf(yyout, "][BooleanT1");}
#line 2263 "y.tab.c"
    break;

  case 143: /* BooleanT: BooleanF $@76 BooleanT1  */
#line 135 "BGSASAS.y"
                                                              {fprintf(yyout, "]");}
#line 2269 "y.tab.c"
    break;

  case 144: /* $@77: %empty  */
#line 138 "BGSASAS.y"
               {fprintf(yyout, "[and:{and}][BooleanT1");}
#line 2275 "y.tab.c"
    break;

  case 145: /* BooleanT1: And $@77 BooleanF BooleanT1  */
#line 138 "BGSASAS.y"
                                                                             {fprintf(yyout, "]");}
#line 2281 "y.tab.c"
    break;

  case 147: /* $@78: %empty  */
#line 140 "BGSASAS.y"
             {fprintf(yyout, "[BooleanF[Not:{not}]");}
#line 2287 "y.tab.c"
    break;

  case 148: /* BooleanF: Not $@78 BooleanF  */
#line 140 "BGSASAS.y"
                                                               {fprintf(yyout, "]");}
#line 2293 "y.tab.c"
    break;

  case 149: /* $@79: %empty  */
#line 141 "BGSASAS.y"
                                 {fprintf(yyout, "[BooleanF[open_parenthesis:{(}]");}
#line 2299 "y.tab.c"
    break;

  case 150: /* $@80: %empty  */
#line 141 "BGSASAS.y"
                                                                                                      {fprintf(yyout, "]");}
#line 2305 "y.tab.c"
    break;

  case 151: /* BooleanF: OpenParenthesis $@79 BooleanExpression $@80 CloseParenthesis  */
#line 141 "BGSASAS.y"
                                                                                                                                             {fprintf(yyout, "[close_parenthesis:{)}]");}
#line 2311 "y.tab.c"
    break;

  case 152: /* $@81: %empty  */
#line 142 "BGSASAS.y"
                  {fprintf(yyout, "[BooleanF[ArithmeticExpression");}
#line 2317 "y.tab.c"
    break;

  case 153: /* $@82: %empty  */
#line 142 "BGSASAS.y"
                                                                                          {fprintf(yyout, "][X1");}
#line 2323 "y.tab.c"
    break;

  case 154: /* BooleanF: $@81 ArithmeticExpression $@82 X1  */
#line 142 "BGSASAS.y"
                                                                                                                       {fprintf(yyout, "]");}
#line 2329 "y.tab.c"
    break;

  case 155: /* $@83: %empty  */
#line 145 "BGSASAS.y"
                      {fprintf(yyout, "[relational_operator:{%s}][ArithmeticExpression",(yyvsp[0].cval));}
#line 2335 "y.tab.c"
    break;

  case 156: /* X1: RelationalOperator $@83 ArithmeticExpression  */
#line 145 "BGSASAS.y"
                                                                                                                         {fprintf(yyout, "]");}
#line 2341 "y.tab.c"
    break;


#line 2345 "y.tab.c"

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

#line 147 "BGSASAS.y"


void main(){
	FILE *f = fopen("input.txt","r");
    yyin = f;
	FILE *g = fopen("op.txt","w");
	yyout = g;
    yyparse();
	fclose(g);
    exit(0);
    }


void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
