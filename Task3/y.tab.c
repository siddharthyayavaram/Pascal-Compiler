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

int typ_ind = 0;
int id_ind = 0;

int type_err = 0;

int arr = 0;

int tos = -1;
int is_read = 0;
int is_write= 0;

char gtype[10];
char id_names[50][10];

char cur_relop[10];

struct arr_type{
char name[50];
char type[10];
int asnd;
int is_array;
int arr_ind[50];
} typ[50];

struct expr_type{
char expr[50];
char type[10];
} expr_typ[50];

int check_type_compatible(char* type1,char* type2) {
    if (strcmp(type1, type2) == 0) {
        return 1; // Types are identical, so they are compatible
    } else if ((strcmp(type1, "integer") == 0 && strcmp(type2, "real") == 0) ||
               (strcmp(type1, "real") == 0 && strcmp(type2, "integer") == 0)) {
        return 2; // Integer and real types are compatible
    } else {
        return 0; // Types are not compatible
    }
}


char* concat(char* expr1, char* expr2,char* delimiter) {
    size_t len1 = strlen(expr1);
    size_t len2 = strlen(expr2);
    size_t delimLen = strlen(delimiter);
    size_t totalLen = len1 + delimLen + len2 + 1;
    char* result = (char*)malloc(totalLen);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strcpy(result, expr1);
    strcat(result, delimiter);
    strcat(result, expr2);
    return result;
}

void push(char *expr, char * type1){
	// printf("\nc is %s\n",c);
	++tos;

	// printf("|%d| |%s| |%s|\n",tos,expr,type1);
    strcpy(expr_typ[tos].expr, expr);
	strcpy(expr_typ[tos].type, type1);
}

int pop(){
	// printf("tos before pop is %d\n",tos);
	if(tos == -1){
		// printf("here");
		return -1;
	}
    char* c=expr_typ[tos].expr;
    tos=tos-1;
    return tos+1;
}

char* removespace_lower(const char *str) {
    int len = strlen(str);
    char *result = (char *)malloc(len + 1);
    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            result[j++] = tolower(str[i]);
        }
    }
    result[j] = '\0';
    return result;
}

int isnameinlist(char *nameToFind) {

	char *l_name = removespace_lower(nameToFind);

    for (int i = 0; i < 50; i++) {
		char * t_name = removespace_lower(typ[i].name);
        if (strcmp(typ[i].name, nameToFind) == 0) {
            return i;
        }
    }

	printf("undeclared variable '%s'\n",nameToFind);
    return -1;
}

int asndornot(int ind){
	if(typ[ind].asnd == 0){
		printf("variable '%s' used before value assigned\n",typ[ind].name);
		return 0;
	}
	return 1;
}


char* getTypeForName(char name[]){
    for (int i = 0; i < 50; i++) {
        if (strcmp(typ[i].name, name) == 0) {
            return typ[i].type;
        }
    }
    return NULL;
}

int getTypeIntegerValue(char type[]) {
    char lowercaseType[10];
    int i = 0;
    while (type[i] != '\0' && type[i] != ' ' && i < 10) {
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

void addTyp(char name[], char type[], int arr) {

		char * l_name = removespace_lower(name);

		for (int i = 0; i < 50; i++) {

			char * t_name = removespace_lower(typ[i].name);

			if (strcmp(t_name, l_name) == 0) {
				printf("multiple declarations of the variable '%s'\n",name);
				return;
			}
    	}

		char * type_act = removespace_lower(type);
		// printf("type actual %s\n",type_act);

        strcpy(typ[typ_ind].name, name);
        strcpy(typ[typ_ind].type, type_act);

		typ[typ_ind].is_array = arr;
        typ_ind++;

		// printf("typ_ind is %d\n",typ_ind);
}

void type_check(char* op){

	int op2_ind = -1;
	int op1_ind = -1;

	if(strcmp("new",expr_typ[tos].type)==0){
		// printf("IGNORE\n");
		return;
	}
	else{
		op2_ind = pop();
	}

	if(strcmp("new",expr_typ[tos].type)!=0){
		op1_ind = pop();
	}

	if(op1_ind==-1){
		// printf("IGNoring rest of the expression\n");
		return;
	}

	char * expr1 = expr_typ[op1_ind].expr;
	char * expr2 = expr_typ[op2_ind].expr;

	char * type1 = expr_typ[op1_ind].type;
	char * type2 = expr_typ[op2_ind].type;

	if(strcmp(op," % ")==0){
		if(!strcmp(type1,"integer")==0 || !strcmp(type2,"integer")==0){
			printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);
			return;
		}
	}

	if(strcmp(op," / ")==0){
		if(strcmp(type1,"integer")==0 && strcmp(type2,"integer")==0){
			strcpy(type1,"real");
		}
	}

	if(strcmp(op," := ")==0){
		// printf("HHIIIII %s %s\n",type1,type2);
		if(strcmp(type1,"integer")==0 && strcmp(type2,"real")==0){
			printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);
			return;
		}
	}

	// printf("op2_ind: '%d'\n", op2_ind);
	// printf("op1_ind: '%d'\n", op1_ind);
	// printf("expr1: %s\n", expr1);
	// printf("expr2: %s\n", expr2);
	// printf("type1: %s\n", type1);
	// printf("type2: %s\n", type2);

	if(check_type_compatible(type1,type2)==2){
		push(concat(expr1,expr2,op), "real");
	}

	else if(check_type_compatible(type1,type2)==1 && strcmp(op," relop ")==0){
		push(concat(expr1,expr2,op), "boolean");
	}

	else if(strcmp("boolean",type1)==0 && strcmp(type2,"boolean")==0 && strcmp(op," relop ")!=0 && strcmp(op," := ")!=0){
		printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);
	}

	else if(check_type_compatible(type1,type2)==1){
		push(concat(expr1,expr2,op), type1);
	}

	else{
		printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);

		// int nom = pop();
		char * type = expr_typ[tos].type;

		while(strcmp(type,"new")!=0){
			int nom = pop();

			// printf("pop with tos = %d and name %s\n",nom,expr_typ[nom].expr);

			strcpy(type,expr_typ[nom].type);
		}

		if(strcmp("new",expr_typ[tos].type)!=0){
			push("newexp1","new");
		}

		// printf("ignoring rest of the expression\n");

	}
}


extern FILE* yyin;
extern int line_num;
void yyerror(const char *msg);


#line 356 "y.tab.c"

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
#line 286 "BGSASAS.y"
char *cval;int ival;

#line 498 "y.tab.c"

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
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_I = 62,                         /* I  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_LI = 65,                        /* LI  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_67_10 = 67,                     /* $@10  */
  YYSYMBOL_Block = 68,                     /* Block  */
  YYSYMBOL_WriteBody = 69,                 /* WriteBody  */
  YYSYMBOL_ForLoop = 70,                   /* ForLoop  */
  YYSYMBOL_71_11 = 71,                     /* $@11  */
  YYSYMBOL_A = 72,                         /* A  */
  YYSYMBOL_73_12 = 73,                     /* $@12  */
  YYSYMBOL_74_13 = 74,                     /* $@13  */
  YYSYMBOL_IfStatement = 75,               /* IfStatement  */
  YYSYMBOL_X = 76,                         /* X  */
  YYSYMBOL_WhileLoop = 77,                 /* WhileLoop  */
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
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

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
       0,   292,   292,   297,   300,   303,   304,   307,   322,   329,
     332,   343,   342,   350,   358,   359,   362,   363,   368,   367,
     381,   381,   381,   382,   382,   382,   383,   384,   385,   386,
     389,   406,   425,   405,   439,   452,   469,   451,   481,   482,
     485,   485,   486,   486,   490,   489,   510,   509,   520,   520,
     532,   539,   540,   542,   549,   557,   567,   568,   574,   581,
     582,   587,   592,   600,   607,   614,   621,   622,   625,   626,
     633,   634,   641,   643,   645,   664
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
  "$@4", "$@5", "$@6", "I", "$@7", "$@8", "LI", "$@9", "$@10", "Block",
  "WriteBody", "ForLoop", "$@11", "A", "$@12", "$@13", "IfStatement", "X",
  "WhileLoop", "Expression", "ArithmeticExpression", "T", "F",
  "BooleanExpression", "BooleanT", "BooleanF", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -26,    38,    58,    63,   -75,    33,    82,   -75,    86,
     -75,    33,    87,    14,   -75,   -75,   -75,     7,    36,    89,
     102,   103,    73,    68,    73,   101,   123,    64,   109,   -75,
     -75,   -75,   -75,    33,   -75,   104,   124,   -75,   126,   -75,
     -75,   -75,    73,    73,   -75,   -75,   107,   -75,    53,   -20,
      75,   -75,    -3,    94,   -75,   115,    60,   -75,   125,   -75,
      73,   -75,    96,   -75,   -75,    68,    62,   -75,    28,   -19,
     -75,    79,    79,    79,    79,    79,    79,   134,    73,    73,
      79,   134,    79,   -75,   -75,   -20,   100,   110,   -75,    79,
     132,   -75,   -75,     0,   -75,   -75,    79,    24,    75,    75,
     -75,   -75,   -75,    49,    94,   -75,    24,   135,    24,   136,
     105,   118,    74,    62,   121,    62,    24,   -75,   134,   -75,
      48,   -75,   120,   -75,   122,   140,   -75,   142,   -75,   127,
     143,    79,    79,   -75,   -75,   128,   -75,   -75,   -75,   -75,
      24,    24,   149,   129,   130,   -75,   -75,   134,   134,   145,
     147,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     3,    13,
       4,     6,     0,     0,     2,    11,     5,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,    17,     0,    29,
      27,    26,    28,     0,     8,     0,     0,    39,     0,    15,
      20,    23,     0,     0,    65,    63,    30,    64,    67,     0,
      56,    59,     0,    68,    70,     0,     0,    35,     0,    16,
       0,    12,     0,     7,    38,     0,     0,    72,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    18,    55,    54,     0,    21,     0,
      43,    67,    24,    41,    66,    73,     0,    74,    57,    58,
      60,    62,    61,     0,    69,    71,    44,     0,    36,     0,
       0,     0,     0,     0,     0,     0,    32,    52,     0,    50,
       0,    53,     0,    19,     0,     0,    42,     0,    40,     0,
       0,     0,     0,    45,    37,     0,    22,    25,    33,    51,
      46,    48,     0,     0,     0,    10,     9,     0,     0,     0,
       0,    47,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -75,   148,   -75,   -75,   -75,   131,   -75,
     -75,     4,   -75,   -75,   -75,   -75,   -75,   -75,   -18,   -75,
     -75,   -22,   -75,   -75,   -74,   -48,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -43,    51,    43,   -13,    78,
     -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,    10,    11,    36,   146,    12,    33,
      14,    26,    27,   109,    65,   111,    66,   114,    91,    96,
     129,    28,    82,   122,    29,    92,    30,   120,   133,   143,
     144,    31,   119,    32,    84,    49,    50,    51,    52,    53,
      54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    55,    71,   103,    48,    95,    48,   107,    67,   115,
      34,    56,     1,    77,    72,    73,     4,    85,    18,    19,
      78,    35,    38,    93,    48,    48,    20,    21,    97,    22,
      69,    59,    23,    24,    72,    73,    78,   106,     5,   108,
      18,    37,    48,    88,   130,   105,   112,    86,    20,    21,
      71,    22,    94,   116,    23,    24,    25,   117,    72,    73,
      48,    48,    72,    73,     6,   126,   118,   128,    18,   -75,
      93,     8,    93,   149,   150,     9,    20,    21,    25,    22,
     131,   132,    23,    24,   -75,    89,    13,    90,   140,   141,
      44,    81,   -75,   -75,    42,    15,    43,    17,    94,    78,
      39,    44,    89,    45,    46,    47,    25,    44,    72,    73,
      25,    74,    75,    76,    45,    46,    47,   100,   101,   102,
      45,    46,    47,    98,    99,    40,    41,    57,    58,    60,
      62,    64,    63,    70,    79,    80,    83,    87,    18,    78,
     110,   113,   125,   121,   123,   127,   124,   134,   136,   135,
     137,   139,   145,   151,   138,   152,   104,   142,     0,    16,
     147,   148,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
      43,    23,    22,    77,    22,    24,    24,    81,    42,     9,
       3,    24,     7,    16,    34,    35,    42,    60,     4,     5,
      39,    14,    18,    66,    42,    43,    12,    13,    71,    15,
      43,    27,    18,    19,    34,    35,    39,    80,     0,    82,
       4,     5,    60,    65,   118,    79,    89,    60,    12,    13,
      22,    15,    24,    96,    18,    19,    42,     8,    34,    35,
      78,    79,    34,    35,     6,   113,    17,   115,     4,    16,
     113,     8,   115,   147,   148,    42,    12,    13,    42,    15,
      32,    33,    18,    19,    31,    23,     4,    25,   131,   132,
      28,    31,    39,    40,    21,     9,    23,    10,    24,    39,
      11,    28,    23,    41,    42,    43,    42,    28,    34,    35,
      42,    36,    37,    38,    41,    42,    43,    74,    75,    76,
      41,    42,    43,    72,    73,    23,    23,    26,     5,    20,
      26,     5,     8,    26,    40,    20,    11,    41,     4,    39,
      30,     9,    24,     8,     8,    24,    41,    27,     8,    27,
       8,     8,     3,     8,    27,     8,    78,    29,    -1,    11,
      31,    31,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    45,    46,    42,     0,     6,    47,     8,    42,
      48,    49,    52,     4,    54,     9,    48,    10,     4,     5,
      12,    13,    15,    18,    19,    42,    55,    56,    65,    68,
      70,    75,    77,    53,     3,    14,    50,     5,    55,    11,
      23,    23,    21,    23,    28,    41,    42,    43,    62,    79,
      80,    81,    82,    83,    84,    65,    82,    26,     5,    55,
      20,    52,    26,     8,     5,    58,    60,    84,    79,    82,
      26,    22,    34,    35,    36,    37,    38,    16,    39,    40,
      20,    31,    66,    11,    78,    79,    82,    41,    65,    23,
      25,    62,    69,    79,    24,    24,    63,    79,    80,    80,
      81,    81,    81,    68,    83,    84,    79,    68,    79,    57,
      30,    59,    79,     9,    61,     9,    79,     8,    17,    76,
      71,     8,    67,     8,    41,    24,    69,    24,    69,    64,
      68,    32,    33,    72,    27,    27,     8,     8,    27,     8,
      79,    79,    29,    73,    74,     3,    51,    31,    31,    68,
      68,     8,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    48,    48,    49,    50,    50,
      51,    53,    52,    52,    54,    54,    55,    55,    57,    56,
      58,    59,    56,    60,    61,    56,    56,    56,    56,    56,
      62,    63,    64,    62,    65,    66,    67,    65,    68,    68,
      69,    69,    69,    69,    71,    70,    73,    72,    74,    72,
      75,    76,    76,    77,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     4,     1,     8,
       1,     0,     4,     1,     4,     3,     2,     1,     0,     5,
       0,     0,     7,     0,     0,     7,     1,     1,     1,     1,
       1,     0,     0,     6,     1,     0,     0,     6,     3,     2,
       3,     1,     3,     1,     0,     6,     0,     6,     0,     6,
       5,     3,     1,     5,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     1,     3,     1,     1,     3,
       1,     3,     2,     3,     3,     1
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
#line 292 "BGSASAS.y"
                 { printf("Valid Syntax\n");
					return 1; 
				}
#line 1669 "y.tab.c"
    break;

  case 7: /* L: LHS Colon RHS SC  */
#line 308 "BGSASAS.y"
                                 {
					for (int i = 0; i < id_ind; i++) {
						// push the LOWERCASE NAMES 
						// printf("id_names[%d]: %s has type %s\n", i, id_names[i], gtype);
						// printf("array ? %d\n",arr);
						addTyp(id_names[i],gtype,arr);
					}
					memset(id_names, 0, sizeof(id_names));
    				memset(gtype, 0, sizeof(gtype));
					id_ind = 0;
					arr = 0;
				 }
#line 1686 "y.tab.c"
    break;

  case 8: /* RHS: Type  */
#line 323 "BGSASAS.y"
                {																	
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			strcpy(gtype, c);
																		
		}
#line 1697 "y.tab.c"
    break;

  case 10: /* Y: Type  */
#line 333 "BGSASAS.y"
                {
			arr = 1;
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			// printf("%s\n",c);
			strcpy(gtype, c);
		}
#line 1709 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 343 "BGSASAS.y"
                                        {
					char c[50]; 
					sprintf(c,"%s",(yyvsp[-1].cval));
					strcpy(id_names[id_ind++], c);
					}
#line 1719 "y.tab.c"
    break;

  case 13: /* LHS: Identifier  */
#line 351 "BGSASAS.y"
                                {
					char c[50]; 
					sprintf(c,"%s",(yyvsp[0].cval));
					strcpy(id_names[id_ind++], c);
				}
#line 1729 "y.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 368 "BGSASAS.y"
                                        {
						// printf("CHECKING ASSIGNOP\n");
						if(strcmp("newexp",expr_typ[tos].expr)==0){
							int x =pop();
							// printf("%d\n",x);
							type_check(" := ");
						}
						
						push("newexp","new");	
					}
#line 1744 "y.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 381 "BGSASAS.y"
                               {is_read = 1;}
#line 1750 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 381 "BGSASAS.y"
                                                 {is_read = 0;}
#line 1756 "y.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 382 "BGSASAS.y"
                                {is_write = 1;}
#line 1762 "y.tab.c"
    break;

  case 24: /* $@6: %empty  */
#line 382 "BGSASAS.y"
                                                          {is_write = 0;}
#line 1768 "y.tab.c"
    break;

  case 30: /* I: Identifier  */
#line 390 "BGSASAS.y"
                        {
				char c[50]; sprintf(c,"%s",(yyvsp[0].cval));
				int ind = isnameinlist(c);

				if(ind != -1){
					int a = asndornot(ind);

					if(a==1 && is_write ==0){
						char * type = getTypeForName(c);
						push(c,type);
					}
				}
			}
#line 1786 "y.tab.c"
    break;

  case 31: /* $@7: %empty  */
#line 406 "BGSASAS.y"
                        {
				char c[50]; sprintf(c,"%s",(yyvsp[-1].cval));
				int ind = isnameinlist(c);

				if(ind != -1 && typ[ind].is_array==1){
					int a = asndornot(ind);

					if(a==1 && is_write ==0){
						char * type = getTypeForName(c);
						push(c,type);
					}
				}

				if(typ[ind].is_array==0){
					printf("Cannot index non-array variables\n");
				}
			}
#line 1808 "y.tab.c"
    break;

  case 32: /* $@8: %empty  */
#line 425 "BGSASAS.y"
                        {
				if(is_write==0){
					int ind = pop();
					// printf("result of index of array is %s with type %s\n",expr_typ[ind].expr,expr_typ[ind].type);

					if(strcmp(expr_typ[ind].type,"integer") != 0){
						printf("Type error, Array index expression not of integer type\n");
					}
				}
			}
#line 1823 "y.tab.c"
    break;

  case 34: /* LI: Identifier  */
#line 440 "BGSASAS.y"
                        {
				char c[50]; sprintf(c,"%s",(yyvsp[0].cval));
				int ind = isnameinlist(c);

				if(ind != -1 && is_read ==0){
					typ[ind].asnd = 1;
					char * type = getTypeForName(c);
					push(c,type);
				}
			}
#line 1838 "y.tab.c"
    break;

  case 35: /* $@9: %empty  */
#line 452 "BGSASAS.y"
                        {
				char c[50]; sprintf(c,"%s",(yyvsp[-1].cval));
				int ind = isnameinlist(c);

				if(ind != -1 && typ[ind].is_array==1 && is_read ==0){
					typ[ind].asnd = 1;
					char * type = getTypeForName(c);
					push(c,type);
				}

				if(typ[ind].is_array==0){
					printf("Cannot index non-array variables\n");
				}

			}
#line 1858 "y.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 469 "BGSASAS.y"
                        {
				int ind = pop();
				// printf("result of index of array is %s with type %s\n",expr_typ[ind].expr,expr_typ[ind].type);

				if(strcmp(expr_typ[ind].type,"integer") != 0){
					printf("Type error, Array index expression not of integer type\n");
				}
			}
#line 1871 "y.tab.c"
    break;

  case 44: /* $@11: %empty  */
#line 490 "BGSASAS.y"
                                        {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}
						// printf("CHECKING FORASSIGNOP\n");
						if(strcmp("newexp",expr_typ[tos].expr)==0){
							int x =pop();
							// printf("%d\n",x);
							type_check(" := ");
						}
						
						push("newexp","new");	
					}
#line 1891 "y.tab.c"
    break;

  case 46: /* $@12: %empty  */
#line 510 "BGSASAS.y"
                                        {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}}
#line 1902 "y.tab.c"
    break;

  case 48: /* $@13: %empty  */
#line 520 "BGSASAS.y"
                                    {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}}
#line 1913 "y.tab.c"
    break;

  case 54: /* Expression: BooleanExpression  */
#line 550 "BGSASAS.y"
                                        {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}
					}
#line 1925 "y.tab.c"
    break;

  case 55: /* Expression: ArithmeticExpression  */
#line 558 "BGSASAS.y"
                            {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}
					}
#line 1937 "y.tab.c"
    break;

  case 57: /* ArithmeticExpression: ArithmeticExpression Plus T  */
#line 569 "BGSASAS.y"
                                                {
							// printf("CHECKING +\n");
							type_check(" + ");
						}
#line 1946 "y.tab.c"
    break;

  case 58: /* ArithmeticExpression: ArithmeticExpression Minus T  */
#line 575 "BGSASAS.y"
                                                {
							// printf("CHECKING -\n");
							type_check(" - ");
						}
#line 1955 "y.tab.c"
    break;

  case 60: /* T: T Mul F  */
#line 583 "BGSASAS.y"
        {
		// printf("CHECKING *\n");
		type_check(" * ");
	}
#line 1964 "y.tab.c"
    break;

  case 61: /* T: T Div F  */
#line 588 "BGSASAS.y"
        {
		// printf("CHECKING /\n");
		type_check(" / ");
	}
#line 1973 "y.tab.c"
    break;

  case 62: /* T: T Mod F  */
#line 593 "BGSASAS.y"
        {
		// printf("CHECKING %\n");
		type_check(" % ");
	}
#line 1982 "y.tab.c"
    break;

  case 63: /* F: NumberLiteral  */
#line 601 "BGSASAS.y"
                {
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			// printf("numlit is %s\n",c);
			push(c,"integer");
		}
#line 1993 "y.tab.c"
    break;

  case 64: /* F: RealLiteral  */
#line 608 "BGSASAS.y"
                {
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			// printf("realit is %s\n",c);
			push(c,"real");
		}
#line 2004 "y.tab.c"
    break;

  case 65: /* F: CharacterLiteral  */
#line 615 "BGSASAS.y"
        {
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval)); 
			// printf("charlit is %s\n",c);
			push(c,"char");
		}
#line 2015 "y.tab.c"
    break;

  case 69: /* BooleanExpression: BooleanExpression Or BooleanT  */
#line 627 "BGSASAS.y"
                        {
				// printf("CHECKING AND\n");
				type_check(" relop ");
			}
#line 2024 "y.tab.c"
    break;

  case 71: /* BooleanT: BooleanT And BooleanF  */
#line 635 "BGSASAS.y"
                        {
				// printf("CHECKING AND\n");
				type_check(" relop ");
			}
#line 2033 "y.tab.c"
    break;

  case 74: /* BooleanF: ArithmeticExpression RelationalOperator ArithmeticExpression  */
#line 654 "BGSASAS.y"
                                        {
						// printf("CHECKING RELOP\n");
						type_check(" relop ");
						// printf("OOOOOOO\n");
						// if(strcmp("new",expr_typ[tos].type)!=0){
						// 	printf("WWWWWWWW\n");
						// 	push("newexp","new");
						// }
					}
#line 2047 "y.tab.c"
    break;


#line 2051 "y.tab.c"

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

#line 667 "BGSASAS.y"


int main(int argc, char *argv[]){

    char* filename;

    filename=argv[1];

    printf("\n");

    yyin=fopen(filename, "r");

	for (int i = 0; i < 50; i++) {
        typ[i].asnd = 0;  // Initializing the 'asnd' member to 0
		typ[i].is_array = 0;
		for(int j=0;j<50;j++){
			typ[i].arr_ind[j] = 0;
		}
    }

	push("newexp","new");
    yyparse();

    return 0;

}

void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
