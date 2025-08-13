
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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



/* Line 189 of yacc.c  */
#line 88 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Type = 258,
     Begin = 259,
     End = 260,
     Var = 261,
     Prog = 262,
     SC = 263,
     comma = 264,
     Colon = 265,
     Stop = 266,
     Read = 267,
     Write = 268,
     Array = 269,
     If = 270,
     Then = 271,
     Else = 272,
     For = 273,
     While = 274,
     AsmtOp = 275,
     Not = 276,
     RelationalOperator = 277,
     OpenParenthesis = 278,
     CloseParenthesis = 279,
     String = 280,
     ArrayOpen = 281,
     ArrayClose = 282,
     CharacterLiteral = 283,
     Of = 284,
     DoubleDots = 285,
     Do = 286,
     To = 287,
     DownTo = 288,
     Plus = 289,
     Minus = 290,
     Mul = 291,
     Mod = 292,
     Div = 293,
     Or = 294,
     And = 295,
     NumberLiteral = 296,
     Identifier = 297,
     RealLiteral = 298
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "BGSASAS.y"
char *cval;int ival;float fval;


/* Line 214 of yacc.c  */
#line 214 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 226 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  142
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNRULES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    13,    14,    15,    21,
      22,    26,    27,    28,    33,    34,    37,    38,    39,    40,
      41,    42,    51,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    78,    80,    81,    85,    86,    90,    91,    92,
      96,    97,    98,    99,   106,   109,   110,   111,   116,   117,
     120,   121,   122,   123,   124,   132,   133,   134,   135,   136,
     146,   147,   148,   149,   150,   160,   162,   164,   166,   168,
     169,   170,   175,   176,   177,   183,   184,   185,   189,   190,
     191,   196,   198,   199,   203,   204,   208,   209,   213,   214,
     215,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   248,   250,   252,   253,   254,   255,   256,   257,
     268,   269,   270,   276,   278,   279,   280,   281,   282,   283,
     294,   296,   297,   300,   301,   302,   307,   308,   309,   310,
     317,   318,   320,   322,   323,   324,   325,   331,   332,   333,
     334,   335,   343,   344,   346,   348,   350,   352,   354,   356,
     357,   358,   364,   366,   367,   368,   373,   374,   375,   381,
     382,   383,   387,   388,   393,   394,   395,   399,   400,   401,
     407,   408,   409,   414,   415,   419
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      45,     0,    -1,    -1,    -1,    -1,    46,    49,    47,    52,
      48,    78,    -1,    -1,    -1,     7,    50,    42,    51,     8,
      -1,    -1,     6,    53,    54,    -1,    -1,    -1,    55,    59,
      56,    57,    -1,    -1,    58,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    74,    61,    10,    62,    64,    63,     8,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    65,    26,    66,    41,    67,    30,    68,    41,
      69,    27,    70,    29,    71,    72,    73,    -1,     3,    -1,
      -1,    42,    75,    76,    -1,    -1,     9,    77,    74,    -1,
      -1,    -1,     4,    79,    80,    -1,    -1,    -1,    -1,    81,
      84,    82,     5,    83,    11,    -1,     5,    11,    -1,    -1,
      -1,    85,    89,    86,    87,    -1,    -1,    88,    84,    -1,
      -1,    -1,    -1,    -1,   101,    90,    20,    91,   145,    92,
       8,    -1,    -1,    -1,    -1,    -1,    12,    93,    23,    94,
     101,    95,    24,    96,     8,    -1,    -1,    -1,    -1,    -1,
      13,    97,    23,    98,   112,    99,    24,   100,     8,    -1,
     130,    -1,   119,    -1,   139,    -1,   107,    -1,    -1,    -1,
     102,    42,   103,   104,    -1,    -1,    -1,    26,   105,   147,
     106,    27,    -1,    -1,    -1,     4,   108,   109,    -1,    -1,
      -1,   110,    84,   111,     5,    -1,     5,    -1,    -1,   101,
     113,   115,    -1,    -1,    25,   114,   117,    -1,    -1,     9,
     116,   112,    -1,    -1,    -1,     9,   118,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      18,   121,   101,   122,    20,   123,   147,   124,   129,   125,
     147,   126,    31,   127,   107,   128,     8,    -1,    32,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,   131,    15,   132,
     168,   133,    16,   134,   107,   135,   136,    -1,    -1,    -1,
      17,   137,   107,   138,     8,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    19,   141,   168,   142,    31,   143,
     107,   144,     8,    -1,   168,    -1,    -1,   146,   147,    -1,
      -1,    -1,   148,   155,   149,   150,    -1,    -1,    -1,    -1,
     151,   154,   152,   155,   153,   150,    -1,    -1,    34,    -1,
      35,    -1,    -1,    -1,    -1,   156,   165,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,   160,   164,   161,   165,   162,
     163,   159,    -1,    -1,    36,    -1,    38,    -1,    37,    -1,
      41,    -1,    28,    -1,    43,    -1,    -1,    -1,    23,   166,
     147,   167,    24,    -1,   101,    -1,    -1,    -1,   169,   174,
     170,   171,    -1,    -1,    -1,    39,   172,   174,   173,   171,
      -1,    -1,    -1,   178,   175,   176,    -1,    -1,    40,   177,
     178,   176,    -1,    -1,    -1,    21,   179,   178,    -1,    -1,
      -1,    23,   180,   168,   181,    24,    -1,    -1,    -1,   182,
     147,   183,   184,    -1,    -1,    22,   185,   147,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    21,    21,    21,    21,    21,    24,    24,    24,    27,
      27,    30,    30,    30,    33,    33,    33,    35,    35,    35,
      35,    35,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    42,    45,    45,    48,    48,    49,    52,    52,
      55,    55,    55,    55,    56,    58,    58,    58,    61,    61,
      61,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    67,    68,    69,    73,
      73,    73,    76,    76,    76,    77,    79,    79,    82,    82,
      82,    82,    84,    84,    85,    85,    88,    88,    88,    90,
      90,    90,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    95,    95,    97,    97,    97,    97,    97,    97,
     100,   100,   100,   101,   103,   103,   103,   103,   103,   103,
     106,   107,   107,   110,   110,   110,   113,   113,   113,   113,
     113,   115,   115,   117,   117,   117,   117,   120,   120,   120,
     120,   120,   120,   122,   122,   122,   124,   125,   126,   127,
     127,   127,   128,   131,   131,   131,   134,   134,   134,   134,
     136,   136,   139,   139,   139,   141,   141,   142,   142,   142,
     143,   143,   143,   146,   146,   146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Type", "Begin", "End", "Var", "Prog",
  "SC", "comma", "Colon", "Stop", "Read", "Write", "Array", "If", "Then",
  "Else", "For", "While", "AsmtOp", "Not", "RelationalOperator",
  "OpenParenthesis", "CloseParenthesis", "String", "ArrayOpen",
  "ArrayClose", "CharacterLiteral", "Of", "DoubleDots", "Do", "To",
  "DownTo", "Plus", "Minus", "Mul", "Mod", "Div", "Or", "And",
  "NumberLiteral", "Identifier", "RealLiteral", "$accept", "sentence",
  "$@1", "$@2", "$@3", "P", "$@4", "$@5", "V", "$@6", "LS", "$@7", "$@8",
  "O", "$@9", "L", "$@10", "$@11", "$@12", "$@13", "RHS", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "Y", "LHS", "$@22", "H",
  "$@23", "M", "$@24", "J", "$@25", "$@26", "$@27", "B", "$@28", "$@29",
  "K", "$@30", "S", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "$@37",
  "$@38", "$@39", "$@40", "$@41", "I", "$@42", "$@43", "G", "$@44", "$@45",
  "Block", "$@46", "A", "$@47", "$@48", "WriteBody", "$@49", "$@50", "C",
  "$@51", "D", "$@52", "ForLoop", "$@53", "$@54", "$@55", "$@56", "$@57",
  "$@58", "$@59", "$@60", "$@61", "E", "IfStatement", "$@62", "$@63",
  "$@64", "$@65", "$@66", "X", "$@67", "$@68", "WhileLoop", "$@69", "$@70",
  "$@71", "$@72", "$@73", "Expression", "$@74", "ArithmeticExpression",
  "$@75", "$@76", "A1", "$@77", "$@78", "$@79", "OP", "T", "$@80", "$@81",
  "$@82", "T1", "$@83", "$@84", "$@85", "$@86", "PO", "F", "$@87", "$@88",
  "BooleanExpression", "$@89", "$@90", "BooleanExpression1", "$@91",
  "$@92", "BooleanT", "$@93", "BooleanT1", "$@94", "BooleanF", "$@95",
  "$@96", "$@97", "$@98", "$@99", "X1", "$@100", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    47,    48,    45,    50,    51,    49,    53,
      52,    55,    56,    54,    58,    57,    57,    60,    61,    62,
      63,    59,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    64,    73,    75,    74,    77,    76,    76,    79,    78,
      81,    82,    83,    80,    80,    85,    86,    84,    88,    87,
      87,    90,    91,    92,    89,    93,    94,    95,    96,    89,
      97,    98,    99,   100,    89,    89,    89,    89,    89,   102,
     103,   101,   105,   106,   104,   104,   108,   107,   110,   111,
     109,   109,   113,   112,   114,   112,   116,   115,   115,   118,
     117,   117,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   119,   129,   129,   131,   132,   133,   134,   135,   130,
     137,   138,   136,   136,   140,   141,   142,   143,   144,   139,
     145,   146,   145,   148,   149,   147,   151,   152,   153,   150,
     150,   154,   154,   156,   157,   158,   155,   160,   161,   162,
     163,   159,   159,   164,   164,   164,   165,   165,   165,   166,
     167,   165,   165,   169,   170,   168,   172,   173,   171,   171,
     175,   174,   177,   176,   176,   179,   178,   180,   181,   178,
     182,   183,   178,   185,   184,   184
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     6,     0,     0,     5,     0,
       3,     0,     0,     4,     0,     2,     0,     0,     0,     0,
       0,     8,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     1,     0,     3,     0,     3,     0,     0,     3,
       0,     0,     0,     6,     2,     0,     0,     4,     0,     2,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     9,     1,     1,     1,     1,     0,
       0,     4,     0,     0,     5,     0,     0,     3,     0,     0,
       4,     1,     0,     3,     0,     3,     0,     3,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     1,     1,     0,     0,     0,     0,     0,    10,
       0,     0,     5,     1,     0,     0,     0,     0,     0,    10,
       1,     0,     2,     0,     0,     4,     0,     0,     0,     6,
       0,     1,     1,     0,     0,     0,     5,     0,     0,     0,
       0,     7,     0,     1,     1,     1,     1,     1,     1,     0,
       0,     5,     1,     0,     0,     4,     0,     0,     5,     0,
       0,     3,     0,     4,     0,     0,     3,     0,     0,     5,
       0,     0,     4,     0,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     6,     3,     0,     0,     7,     9,
       4,     0,    11,     0,     8,    10,    17,    38,     5,    12,
       0,    40,    14,    33,    18,     0,    39,    45,    13,    11,
      37,     0,    44,    41,    69,    15,    35,    34,    19,     0,
      76,    55,    60,    46,    51,     0,    68,    66,     0,    65,
       0,    67,     0,     0,     0,    42,    78,     0,     0,    48,
       0,    70,    93,   105,   115,    36,    22,    23,    20,     0,
      81,    77,    45,    56,    61,    47,    45,    52,    75,    69,
     153,   153,     0,     0,    43,    79,    69,    69,    49,   121,
      72,    71,    94,   106,   170,   116,    24,    21,     0,    57,
      84,    82,    62,    53,   123,   120,   123,     0,     0,   165,
     167,   154,   160,   123,     0,     0,    80,     0,    91,    88,
       0,     0,   122,   133,    73,    95,   107,   170,   153,   159,
     164,   171,   117,    25,    58,    89,    85,    86,    83,    63,
      54,   124,    69,     0,   123,     0,   166,   168,   156,   155,
     162,   161,   175,     0,     0,     0,    69,    69,     0,   130,
     149,   147,   146,   148,   152,   134,    74,    96,   108,     0,
     170,   170,   173,   172,   118,    26,    59,    90,    87,    64,
     125,     0,   123,   135,     0,     0,   169,   157,   164,   123,
       0,     0,   131,   132,   127,   150,   142,   102,   103,    97,
     113,   110,   109,   159,   163,   174,   119,    27,   133,     0,
     136,     0,   123,     0,   158,     0,   128,   151,   143,   145,
     144,   138,    98,   111,    28,   130,    69,     0,     0,     0,
     129,   139,    99,   112,    29,   140,     0,    30,   142,   100,
       0,   141,     0,    32,    31,   101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    13,     5,     6,    11,    10,    12,
      15,    16,    22,    28,    29,    19,    20,    31,    54,    83,
      68,    82,   115,   154,   191,   215,   229,   237,   240,   244,
      24,    30,    37,    53,    18,    21,    26,    27,    39,    69,
      33,    34,    59,    75,    76,    43,    60,    89,   121,    57,
      86,   117,   155,    58,    87,   120,   158,   101,    45,    78,
      91,   106,   143,    46,    56,    71,    72,    98,   102,   119,
     118,   138,   157,   136,   156,    47,    48,    79,   107,   144,
     184,   212,   227,   236,   242,   199,    49,    50,    80,   108,
     145,   185,   202,   213,   228,    51,    52,    81,   114,   153,
     190,   103,   104,   122,   123,   159,   180,   181,   208,   225,
     194,   141,   142,   183,   196,   210,   211,   226,   235,   238,
     221,   165,   182,   209,    93,    94,   129,   149,   170,   203,
     111,   130,   151,   171,   112,   127,   128,   169,   113,   152,
     173,   189
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
    -144,     9,    19,  -144,  -144,  -144,    -4,    38,  -144,  -144,
    -144,    39,  -144,    42,  -144,  -144,  -144,  -144,  -144,  -144,
      11,    44,    47,  -144,  -144,    43,  -144,  -144,  -144,  -144,
      46,    48,  -144,  -144,     1,  -144,  -144,  -144,  -144,    51,
    -144,  -144,  -144,  -144,  -144,    15,  -144,  -144,    41,  -144,
      45,  -144,    49,    11,     3,  -144,    56,    40,    50,    57,
      52,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,    53,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,    54,  -144,
    -144,  -144,    55,    58,  -144,  -144,  -144,    60,  -144,    61,
    -144,  -144,  -144,  -144,     0,  -144,  -144,  -144,    62,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,    59,    67,  -144,
    -144,  -144,  -144,  -144,    34,    28,  -144,    63,    65,    66,
      64,    68,  -144,  -144,  -144,  -144,  -144,     0,  -144,    32,
      69,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   -16,    70,  -144,    74,  -144,  -144,  -144,  -144,
    -144,  -144,    72,    74,    71,    78,    60,    60,    81,     2,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,    75,
       0,     0,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,     6,  -144,  -144,    10,     7,  -144,  -144,    69,  -144,
      82,    73,  -144,  -144,  -144,  -144,    -8,  -144,  -144,  -144,
    -144,  -144,  -144,    32,  -144,  -144,  -144,  -144,  -144,    76,
    -144,    -5,  -144,    74,  -144,    77,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,     2,   -16,    79,    83,    84,
    -144,  -144,  -144,  -144,  -144,  -144,    74,  -144,    -8,  -144,
      89,  -144,    87,  -144,  -144,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      86,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      80,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
     -54,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,   -34,  -144,  -144,
    -144,  -144,  -144,  -143,  -144,  -144,  -144,  -144,  -122,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -105,  -144,  -144,  -129,  -144,  -144,  -144,
    -144,  -110,  -144,  -144,  -144,  -136,  -144,  -144,  -144,  -144,
    -144,  -121,  -144,  -144,   -78,  -144,  -144,  -100,  -144,  -144,
     -64,  -144,   -77,  -144,  -123,  -144,  -144,  -144,  -144,  -144,
    -144,  -144
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -154
static const yytype_int16 yytable[] =
{
      44,   124,   168,    95,   146,    40,    66,   160,   131,     3,
     174,   105,   161,    41,    42,   200,  -104,    67,    85,   -92,
    -114,   109,    88,   110,   201,   162,     4,   163,  -137,  -137,
    -137,   218,   219,   220,   177,   178,  -126,  -126,     8,   167,
     192,   193,   197,   198,     9,    92,    17,    14,   188,    25,
     147,   -16,    99,    23,    32,    36,    55,    61,    38,    62,
      63,    70,   -50,    73,    84,   132,    97,   116,    64,   133,
     223,   148,    77,    74,   135,   137,   140,   195,    40,   125,
      90,    96,  -153,   126,   205,   100,   176,   134,   139,   179,
     206,   233,   243,   239,   172,   245,   230,   166,   216,   186,
     217,   175,   241,   214,   224,   231,   187,   222,   164,   150,
     232,   204,     0,   234,   207,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164
};

static const yytype_int16 yycheck[] =
{
      34,   106,   145,    81,   127,     4,     3,    23,   113,     0,
     153,    89,    28,    12,    13,     8,    15,    14,    72,    18,
      19,    21,    76,    23,    17,    41,     7,    43,    36,    37,
      38,    36,    37,    38,   156,   157,    34,    35,    42,   144,
      34,    35,    32,    33,     6,    79,     4,     8,   171,     5,
     128,     4,    86,    42,    11,     9,     5,    42,    10,    18,
      15,     5,     5,    23,    11,    31,     8,     5,    19,    41,
     213,    39,    20,    23,     9,     9,     8,   182,     4,    20,
      26,    26,    21,    16,   189,    25,     8,    24,    24,     8,
       8,     8,     3,   236,    22,     8,   225,    27,   208,    24,
      24,    30,   238,   203,    27,   226,   170,   212,   142,    40,
      31,   188,    -1,    29,    41,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     7,    49,    50,    47,    42,     6,
      52,    51,    53,    48,     8,    54,    55,     4,    78,    59,
      60,    79,    56,    42,    74,     5,    80,    81,    57,    58,
      75,    61,    11,    84,    85,    54,     9,    76,    10,    82,
       4,    12,    13,    89,   101,   102,   107,   119,   120,   130,
     131,   139,   140,    77,    62,     5,   108,    93,    97,    86,
      90,    42,    18,    15,    19,    74,     3,    14,    64,    83,
       5,   109,   110,    23,    23,    87,    88,    20,   103,   121,
     132,   141,    65,    63,    11,    84,    94,    98,    84,    91,
      26,   104,   101,   168,   169,   168,    26,     8,   111,   101,
      25,   101,   112,   145,   146,   168,   105,   122,   133,    21,
      23,   174,   178,   182,   142,    66,     5,    95,   114,   113,
      99,    92,   147,   148,   147,    20,    16,   179,   180,   170,
     175,   147,    31,    41,    24,     9,   117,     9,   115,    24,
       8,   155,   156,   106,   123,   134,   178,   168,    39,   171,
      40,   176,   183,   143,    67,    96,   118,   116,   100,   149,
      23,    28,    41,    43,   101,   165,    27,   147,   107,   181,
     172,   177,    22,   184,   107,    30,     8,   112,   112,     8,
     150,   151,   166,   157,   124,   135,    24,   174,   178,   185,
     144,    68,    34,    35,   154,   147,   158,    32,    33,   129,
       8,    17,   136,   173,   176,   147,     8,    41,   152,   167,
     159,   160,   125,   137,   171,    69,   155,    24,    36,    37,
      38,   164,   147,   107,    27,   153,   161,   126,   138,    70,
     150,   165,    31,     8,    29,   162,   127,    71,   163,   107,
      72,   159,   128,     3,    73,     8
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 21 "BGSASAS.y"
    {fprintf(yyout, "[sentence[P");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 21 "BGSASAS.y"
    {fprintf(yyout, "][V");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 21 "BGSASAS.y"
    {fprintf(yyout, "][M");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 21 "BGSASAS.y"
    {fprintf(yyout, "]]");printf(" Valid Sentence\n") ; return 1; }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 24 "BGSASAS.y"
    {fprintf(yyout, "[prog:{program}]");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 24 "BGSASAS.y"
    {fprintf(yyout, "[var:{%s}]",(yyvsp[(3) - (3)].cval));}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 24 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 27 "BGSASAS.y"
    {fprintf(yyout, "[var:{var}][LS");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 27 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 30 "BGSASAS.y"
    {fprintf(yyout, "[L");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 30 "BGSASAS.y"
    {fprintf(yyout, "][O");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 30 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 33 "BGSASAS.y"
    {fprintf(yyout, "[LS");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 33 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 35 "BGSASAS.y"
    {fprintf(yyout, "[LHS");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 35 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 35 "BGSASAS.y"
    {fprintf(yyout, "[Colon:{:}]");fprintf(yyout, "[RHS");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 35 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 35 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 38 "BGSASAS.y"
    {fprintf(yyout, "[type:{%s}]",(yyvsp[(1) - (1)].cval));}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[array:{array}]");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[array_open:{[}]");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[num_literal:{%d}]",(yyvsp[(5) - (5)].ival));}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[double_dots:{..}]");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[num_literal:{%d}]",(yyvsp[(9) - (9)].ival));}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[array_close:{]}]");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[of:{of}]");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "[Y");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 39 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 42 "BGSASAS.y"
    {fprintf(yyout, "[type:{%s}]",(yyvsp[(1) - (1)].cval));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 45 "BGSASAS.y"
    {fprintf(yyout, "[var:{%s}]",(yyvsp[(1) - (1)].cval));fprintf(yyout, "[H");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 45 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 48 "BGSASAS.y"
    {fprintf(yyout, "[comma:{,}][LHS");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 48 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 52 "BGSASAS.y"
    {fprintf(yyout, "[begin:{begin}][J");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 52 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 55 "BGSASAS.y"
    {fprintf(yyout, "[B");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 55 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 55 "BGSASAS.y"
    {fprintf(yyout, "[end:{end}]");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 55 "BGSASAS.y"
    {fprintf(yyout, "[stop:{.}]");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 56 "BGSASAS.y"
    {fprintf(yyout, "[end:{end}][stop:{.}]");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 58 "BGSASAS.y"
    {fprintf(yyout, "[S");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 58 "BGSASAS.y"
    {fprintf(yyout, "]");fprintf(yyout, "[K");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 58 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 61 "BGSASAS.y"
    {fprintf(yyout, "[B");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 61 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 63 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 63 "BGSASAS.y"
    {fprintf(yyout, "[asmt_op:{:=}][Expression");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 63 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 63 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 64 "BGSASAS.y"
    {fprintf(yyout, "[read:{read}]");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 64 "BGSASAS.y"
    {fprintf(yyout, "[open_parenthesis:{(}]");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 64 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 64 "BGSASAS.y"
    {fprintf(yyout, "[close_parenthesis:{)}]");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 64 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 65 "BGSASAS.y"
    {fprintf(yyout, "[write:{write}]");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 65 "BGSASAS.y"
    {fprintf(yyout, "[open_parenthesis:{(}][WriteBody");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 65 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 65 "BGSASAS.y"
    {fprintf(yyout, "[close_parenthesis:{)}]");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 65 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 66 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 67 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 68 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 69 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 73 "BGSASAS.y"
    {fprintf(yyout, "[I");}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 73 "BGSASAS.y"
    {fprintf(yyout, "[var:{%s}][G",(yyvsp[(2) - (2)].cval));}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 73 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 76 "BGSASAS.y"
    {fprintf(yyout, "[array_open:{[}][ArithmeticExpression");}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 76 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 76 "BGSASAS.y"
    {fprintf(yyout, "[array_close:{]}]");}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 79 "BGSASAS.y"
    {fprintf(yyout, "[begin:{begin}]");fprintf(yyout, "[A");}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 79 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 82 "BGSASAS.y"
    {fprintf(yyout, "[B");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 82 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 82 "BGSASAS.y"
    {fprintf(yyout, "[end:{end}]");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 82 "BGSASAS.y"
    {fprintf(yyout, "[end:{end}]");}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 84 "BGSASAS.y"
    {fprintf(yyout, "][C");}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 84 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 85 "BGSASAS.y"
    {fprintf(yyout, "[string:{%s}][D",(yyvsp[(1) - (1)].cval));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 85 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 88 "BGSASAS.y"
    {fprintf(yyout, "[comma:{,}][WriteBody");}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 88 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 90 "BGSASAS.y"
    {fprintf(yyout, "[comma:{,}][WriteBody");}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 90 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "[ForLoop");}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "[for:{for}]");}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "[asmt_op:{:=}][ArithmeticExpression");}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "][E");}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "][ArithmeticExpression");}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "[Do:{do}][Block");}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 92 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 95 "BGSASAS.y"
    {fprintf(yyout, "[To:{to}]");}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 95 "BGSASAS.y"
    {fprintf(yyout, "[DownTo: {down_to}]");}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 97 "BGSASAS.y"
    {fprintf(yyout, "[IfStatement");}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 97 "BGSASAS.y"
    {fprintf(yyout, "[if:{if}]");}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 97 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 97 "BGSASAS.y"
    {fprintf(yyout, "[then:{then}][Block");}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 97 "BGSASAS.y"
    {fprintf(yyout, "][X");}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 97 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 100 "BGSASAS.y"
    {fprintf(yyout, "[else:{else}][Block");}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 100 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 100 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;]}");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 101 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 103 "BGSASAS.y"
    {fprintf(yyout, "[WhileLoop");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 103 "BGSASAS.y"
    {fprintf(yyout, "[While:{while}]");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 103 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 103 "BGSASAS.y"
    {fprintf(yyout, "[Do:{do}][Block");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 103 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 103 "BGSASAS.y"
    {fprintf(yyout, "[SC:{;}]");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 106 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 107 "BGSASAS.y"
    {fprintf(yyout, "[ArithmeticExpression");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 107 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 110 "BGSASAS.y"
    {fprintf(yyout, "[T");}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 110 "BGSASAS.y"
    {fprintf(yyout, "][A1");}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 110 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 113 "BGSASAS.y"
    {fprintf(yyout, "[OP");}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 113 "BGSASAS.y"
    {fprintf(yyout, "][T");}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 113 "BGSASAS.y"
    {fprintf(yyout, "][A1");}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 113 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 115 "BGSASAS.y"
    {fprintf(yyout, "[plus:{+}]");}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 115 "BGSASAS.y"
    {fprintf(yyout, "[minus:{-}]");}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 117 "BGSASAS.y"
    {fprintf(yyout, "[F");}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 117 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 117 "BGSASAS.y"
    {fprintf(yyout, "[T1");}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 117 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 120 "BGSASAS.y"
    {fprintf(yyout, "[PO");}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 120 "BGSASAS.y"
    {fprintf(yyout, "][F");}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 120 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 120 "BGSASAS.y"
    {fprintf(yyout, "[T1");}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 120 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 122 "BGSASAS.y"
    {fprintf(yyout, "[mul:{*}]");}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 122 "BGSASAS.y"
    {fprintf(yyout, "[div:{/}]");}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 122 "BGSASAS.y"
    {fprintf(yyout, "[mod:{%}]");}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 124 "BGSASAS.y"
    {fprintf(yyout, "[number_literal:{%d}]",(yyvsp[(1) - (1)].ival));}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 125 "BGSASAS.y"
    {fprintf(yyout, "[character_literal:{%s}]",(yyvsp[(1) - (1)].cval));}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 126 "BGSASAS.y"
    {fprintf(yyout, "[real_literal:{%lf}]",(yyvsp[(1) - (1)].fval));}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 127 "BGSASAS.y"
    {fprintf(yyout, "[open_parenthesis:{(}][ArithmeticExpression");}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 127 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 127 "BGSASAS.y"
    {fprintf(yyout, "[close_parenthesis:)]");}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 128 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 131 "BGSASAS.y"
    {fprintf(yyout, "[BooleanExpression[BooleanT");}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 131 "BGSASAS.y"
    {fprintf(yyout, "][BooleanExpression1");}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 131 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 134 "BGSASAS.y"
    {fprintf(yyout, "[or:{or}][BooleanT");}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 134 "BGSASAS.y"
    {fprintf(yyout, "][BooleanExpression1");}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 134 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 136 "BGSASAS.y"
    {fprintf(yyout, "][BooleanT1");}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 136 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 139 "BGSASAS.y"
    {fprintf(yyout, "[and:{and}][BooleanT1");}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 139 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 141 "BGSASAS.y"
    {fprintf(yyout, "[BooleanF[Not:{not}]");}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 141 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 142 "BGSASAS.y"
    {fprintf(yyout, "[BooleanF[open_parenthesis:{(}]");}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 142 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 142 "BGSASAS.y"
    {fprintf(yyout, "[close_parenthesis:{)}]");}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 143 "BGSASAS.y"
    {fprintf(yyout, "[BooleanF[ArithmeticExpression");}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 143 "BGSASAS.y"
    {fprintf(yyout, "][X1");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 143 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 146 "BGSASAS.y"
    {fprintf(yyout, "[relational_operator:{%s}][ArithmeticExpression",(yyvsp[(1) - (1)].cval));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 146 "BGSASAS.y"
    {fprintf(yyout, "]");}
    break;



/* Line 1455 of yacc.c  */
#line 2820 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 148 "BGSASAS.y"


void main(){
	FILE *f = fopen("input.txt","r");
    yyin = f;
	FILE *g = fopen("syntaxtree.txt","w");
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

