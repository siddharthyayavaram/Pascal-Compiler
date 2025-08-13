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
#line 1 "test.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int typ_ind = 0;
int id_ind = 0;
int if_taken = 0;
int is_array = 0;
int while_taken = 1;
int block_taken;
int while_start;
int while_end;
int for_start;
int for_end;
int counter_variable;
char cv[50];
int counter_variable_index;
int type_err = 0;
int limit = 0; //upper or lower limit of the for loop
int to = 1; // to = 1 means u increment counter after one iteration and to = 0 means u decrement counter
int ff = 0;
int for_diff = 1;
int for_list[2];
extern int yylineno;
int tos = -1;
int is_read = 0;
int is_write= 0;


int asmt_float = 0;

char gtype[50];
char id_names[50][100];

char cur_relop[50];

struct arr_type{
char name[50];
char type[50];
char val[50];
int asnd;
} symbol_table[100];	//This is the symbol table

struct expr_type{
char expr[50];
char type[50];
char val[50];
} expr_typ[100];	//this is the stack

extern FILE* yyin;

void goToFor(){
    int line_num = 1;
    char *line = malloc(1000*sizeof(char));
    fseek(yyin, 0, SEEK_SET);
    while(fgets(line, 1000, yyin)){
        if(line_num == for_start-1) break;
        line_num++;
    }
    line_num++;
    // printf("this is the line number: %d\n",line_num);
    // printf("%s\n", line);
    yyrestart(yyin);
    yylineno = line_num;
}

void goToWhile(){
    printf("enter\n");
    int line_num = 1;
    char *line = malloc(1000*sizeof(char));
    fseek(yyin, 0, SEEK_SET);
    while(fgets(line, 1000, yyin)){
        if(line_num == while_start-1) break;
        line_num++;
    }
    printf("line before: %s\n",line);
    line_num++;
    yyrestart(yyin);
    yylineno = line_num;
}

void print_symbol_table(){
	printf("\nprinting the symbol table.\n");
	for(int i = 0;i<50;i++){
        if(i == 0) printf("Variables\tType\tValue\n");
		if(strcmp(symbol_table[i].name,"") == 0) break;
		printf("%9s\t%4s\t%5s \n",symbol_table[i].name,symbol_table[i].type,symbol_table[i].val);
	}
}

int parseBooleanExpression(char *LHS,char *RHS,char *relop,char *type2, char *type1){
	printf("This is the LHS of BE: %s and this is the RHS of BE: %s\n",LHS,RHS);
	if(strcmp(type1,"integer")==0 && strcmp(type2,"integer")==0){
		int lhs = atoi(LHS);
		int rhs = atoi(RHS);
		printf("the be: %d %s %d\n", lhs, relop, rhs);
		if(strcmp(relop,">")==0){return lhs>rhs;}
		else if(strcmp(relop,"=")==0){return lhs == rhs;}
		else if(strcmp(relop,"<")==0){return lhs<rhs;}
		else if(strcmp(relop,"<>")==0){return lhs!=rhs;}
		else if(strcmp(relop,">=")==0){return lhs>=rhs;}
		else {return lhs<=rhs;}
	}
	else if(strcmp(type1,"real")==0 || strcmp(type2,"real")==0){
		double lhs = atof(LHS);
		double rhs = atof(RHS);
		printf("real %lf %s %lf", lhs, relop, rhs);
		if(strcmp(relop,">")==0){return lhs>rhs;}
		else if(strcmp(relop,"=")==0){
			 if(lhs == rhs) return 1;
			 return 0;
		}
		else if(strcmp(relop,"<")==0){
			printf("result: %d\n",lhs<rhs);
			if(lhs<rhs) return 1;
			return 0;
		}
		else if(strcmp(relop,"<>")==0){
			if(lhs!=rhs) return 1;
			return 0;
		}
		else if(strcmp(relop,">=")==0){
			if(lhs>=rhs) return 1;
			return 0;
		}
		else {
			if(lhs<=rhs)return 1;
			return 0;	
		}
	}
}

int modIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 % num2; // Multiply the integers
}

double divIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
	double dnum1 = num1;
	double dnum2 = num2;
    return dnum1 / dnum2; // Multiply the integers
}

int multiplyIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 * num2; // Multiply the integers
}

int addIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 + num2; // Multiply the integers
}

int subIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 - num2; // Multiply the integers
}

void intToString(int num, char* str) {
    sprintf(str, "%d", num); // Convert integer to string
}

double modFloatInStrings(char* str1, char* str2) {
    int num1 = atof(str1); // Convert string to integer
    int num2 = atof(str2); // Convert string to integer
    return num1 % num2; // Multiply the integers
}

double divFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 / num2; // Multiply the integers
}

double multiplyFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 * num2; // Multiply the integers
}

double addFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 + num2; // Multiply the integers
}

double subFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 - num2; // Subtract the integers
}

void floatToString(double num, char* str) {
    sprintf(str, "%lf", num); // Convert integer to string
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

void push(char *expr, char * type1, char * val){
	// printf("\nc is %s\n",c);
	++tos;

	// printf("%d %s %s %s\n",tos,expr,type1,val);
    strcpy(expr_typ[tos].expr, expr);
	strcpy(expr_typ[tos].type, type1);
	strcpy(expr_typ[tos].val, val);
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

char *removeFirstLastChar(char *string){
	int len = strlen(string);
    char *result = (char *)malloc(len);
	int j = 0;
	if (len <= 2){
		string[0] = '\0';
	} else {
		for (int i = 1; i < len - 1; i ++){
			result[j++] = string[i];
		}
	}
	result[j] = '\0';

	return result;

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
	// printf("this is the name to find: %s\n",l_name);
    for (int i = 0; i < 50; i++) {
		char * t_name = removespace_lower(symbol_table[i].name);
        if (strcmp(symbol_table[i].name, nameToFind) == 0) {
            return i;
        }
    }

	printf("undeclared variable '%s'\n",nameToFind);
    return -1;
}

int asndornot(int ind){
	if(symbol_table[ind].asnd == 0){
		printf("variable '%s' used before value assigned\n",symbol_table[ind].name);
		return 0;
	}
	return 1;
}

char* getTypeForName(char name[]){
    for (int i = 0; i < 50; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type;
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

void addTyp(char name[], char type[]) {		//adding to symbol table

		char * l_name = removespace_lower(name);

		for (int i = 0; i < 50; i++) {

			char * t_name = removespace_lower(symbol_table[i].name);

			if (strcmp(t_name, l_name) == 0) {
				printf("multiple declarations of the variable '%s'\n",name);
				return;
			}
    	}

		char * type_act = removespace_lower(type);
		// printf("type actual %s\n",type_act);
        strcpy(symbol_table[typ_ind].name, name);
        strcpy(symbol_table[typ_ind].type, type_act);
        typ_ind++;

		// printf("typ_ind is %d\n",typ_ind);
}

void type_check(char* op){

	int op2_ind = -1;
	int op1_ind = -1;

	if(strcmp("new",expr_typ[tos].type)==0){
		printf("IGNORE\n");
		return;
	}
	else{
		op2_ind = pop();
	}

	if(strcmp("new",expr_typ[tos].type)!=0){
		op1_ind = pop();
	}

	if(op1_ind==-1){
		printf("IGNoring rest of the expression\n");
		return;
	}

	char * expr1 = expr_typ[op1_ind].expr;
	char * expr2 = expr_typ[op2_ind].expr;

	char * type1 = expr_typ[op1_ind].type;
	char * type2 = expr_typ[op2_ind].type;

	// printf("op2_ind: '%d'\n", op2_ind);
	// printf("op1_ind: '%d'\n", op1_ind);
	// printf("expr1: %s\n", expr1);
	// printf("expr2: %s\n", expr2);
	// printf("type1: %s\n", type1);
	// printf("type2: %s\n", type2);

	if(strcmp(type1,type2)==0){
		// push(concat(expr1,expr2,op), type1);
	}
	else{
		printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);

		// int nom = pop();
		char * type = expr_typ[tos].type;

		while(strcmp(type,"new")!=0){
			int nom = pop();

			printf("pop with tos = %d and name %s\n",nom,expr_typ[nom].expr);

			strcpy(type,expr_typ[nom].type);
		}

		if(strcmp("new",expr_typ[tos].type)!=0){
			// push("newexp1","new");
		}

		printf("ignoring rest of the expression\n");

	}
}



extern int line_num;
void yyerror(const char *msg);


#line 492 "y.tab.c"

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
#line 422 "test.y"
char *cval;int ival;

#line 634 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

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
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_Y = 54,                         /* Y  */
  YYSYMBOL_LHS = 55,                       /* LHS  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_M = 57,                         /* M  */
  YYSYMBOL_B = 58,                         /* B  */
  YYSYMBOL_S = 59,                         /* S  */
  YYSYMBOL_60_5 = 60,                      /* $@5  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_I = 66,                         /* I  */
  YYSYMBOL_67_11 = 67,                     /* $@11  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_LI = 69,                        /* LI  */
  YYSYMBOL_70_13 = 70,                     /* $@13  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_Block = 72,                     /* Block  */
  YYSYMBOL_WriteBody = 73,                 /* WriteBody  */
  YYSYMBOL_74_15 = 74,                     /* $@15  */
  YYSYMBOL_75_16 = 75,                     /* $@16  */
  YYSYMBOL_76_17 = 76,                     /* $@17  */
  YYSYMBOL_ForLoop = 77,                   /* ForLoop  */
  YYSYMBOL_78_18 = 78,                     /* $@18  */
  YYSYMBOL_A = 79,                         /* A  */
  YYSYMBOL_80_19 = 80,                     /* $@19  */
  YYSYMBOL_81_20 = 81,                     /* $@20  */
  YYSYMBOL_IfStatement = 82,               /* IfStatement  */
  YYSYMBOL_83_21 = 83,                     /* $@21  */
  YYSYMBOL_84_22 = 84,                     /* $@22  */
  YYSYMBOL_X = 85,                         /* X  */
  YYSYMBOL_86_23 = 86,                     /* $@23  */
  YYSYMBOL_WhileLoop = 87,                 /* WhileLoop  */
  YYSYMBOL_88_24 = 88,                     /* $@24  */
  YYSYMBOL_Expression = 89,                /* Expression  */
  YYSYMBOL_ArithmeticExpression = 90,      /* ArithmeticExpression  */
  YYSYMBOL_T = 91,                         /* T  */
  YYSYMBOL_F = 92,                         /* F  */
  YYSYMBOL_BooleanExpression = 93,         /* BooleanExpression  */
  YYSYMBOL_BooleanT = 94,                  /* BooleanT  */
  YYSYMBOL_BooleanF = 95                   /* BooleanF  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

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
       0,   428,   428,   438,   441,   444,   445,   448,   491,   497,
     497,   497,   497,   500,   510,   509,   517,   526,   527,   530,
     531,   535,   536,   535,   571,   571,   571,   572,   572,   572,
     573,   574,   575,   576,   579,   597,   605,   596,   621,   669,
     686,   668,   730,   731,   734,   734,   743,   752,   752,   752,
     752,   755,   755,   795,   795,   843,   843,   894,   899,   894,
     902,   902,   903,   905,   905,   912,   913,   919,   920,   952,
     985,   986,  1018,  1059,  1085,  1096,  1107,  1118,  1119,  1122,
    1123,  1126,  1127,  1130,  1132,  1134
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
  "V", "LS", "L", "RHS", "$@1", "$@2", "$@3", "Y", "LHS", "$@4", "M", "B",
  "S", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "I", "$@11", "$@12",
  "LI", "$@13", "$@14", "Block", "WriteBody", "$@15", "$@16", "$@17",
  "ForLoop", "$@18", "A", "$@19", "$@20", "IfStatement", "$@21", "$@22",
  "X", "$@23", "WhileLoop", "$@24", "Expression", "ArithmeticExpression",
  "T", "F", "BooleanExpression", "BooleanT", "BooleanF", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,   -38,    36,    43,    49,  -102,    28,    73,  -102,    75,
    -102,    28,    85,     6,  -102,  -102,  -102,    -1,    50,    87,
      78,    88,    17,    68,    17,    86,   108,    60,    94,  -102,
    -102,  -102,  -102,    28,  -102,  -102,   107,  -102,   111,  -102,
    -102,  -102,    17,    17,  -102,  -102,    91,  -102,  -102,    65,
      -3,  -102,    79,    80,  -102,    99,    79,  -102,   110,  -102,
    -102,  -102,    96,  -102,  -102,    68,   -11,  -102,    72,   -17,
    -102,    48,    48,    48,    48,    48,    48,    17,   109,    17,
      48,    92,    48,  -102,    17,    83,  -102,    48,   117,  -102,
      -8,  -102,  -102,    48,   -26,    -3,    -3,  -102,  -102,  -102,
      80,  -102,  -102,   -26,   123,   -26,  -102,    65,    79,  -102,
     104,    32,   120,   106,   122,   -26,   123,    76,   124,   112,
     125,   105,   126,  -102,   128,   -11,   113,    66,    48,    48,
    -102,  -102,  -102,  -102,    97,  -102,   -11,  -102,  -102,  -102,
    -102,  -102,  -102,   -26,   -26,  -102,  -102,   123,   114,   115,
     116,   129,   123,   123,   118,  -102,   133,   134,   141,  -102,
    -102,  -102,  -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     3,    16,
       4,     6,     0,     0,     2,    14,     5,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,    20,     0,    33,
      31,    30,    32,     0,     8,     9,     0,    43,     0,    18,
      24,    27,     0,     0,    76,    74,    34,    75,    78,     0,
      67,    70,    57,    79,    81,     0,    63,    39,     0,    19,
      21,    15,     0,     7,    42,     0,     0,    83,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    25,     0,    47,    28,
      44,    77,    84,     0,    85,    68,    69,    71,    73,    72,
      80,    58,    82,    51,     0,    40,    22,    66,    65,    10,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
      52,    64,    41,    23,     0,    26,     0,    29,    45,    37,
      62,    60,    59,    53,    55,    11,    50,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,    54,
      56,    13,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,  -102,   137,  -102,  -102,  -102,  -102,  -102,
    -102,   119,  -102,  -102,    70,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,   -18,  -102,  -102,  -101,   -83,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,   -43,     8,    29,   -23,
      74,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,    10,    11,    36,    62,   121,   150,
     162,    12,    33,    14,    26,    27,    84,   120,    65,   110,
      66,   113,    48,    93,   126,    28,    82,   119,    29,    89,
     114,   112,   136,    30,   117,   130,   148,   149,    31,    78,
     116,   142,   147,    32,    81,   106,    49,    50,    51,    52,
      53,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    56,    34,   118,     4,    55,    67,    92,    72,    73,
      18,    19,    87,    35,    88,   127,   -46,    44,    20,    21,
      69,    22,    77,    90,    23,    24,    72,    73,    94,     1,
      45,    46,    47,    74,    75,    76,     5,   103,    42,   105,
      43,   107,   138,   102,   111,    44,   151,    86,    25,     6,
     115,   156,   157,   146,    18,    37,    91,     8,    45,    46,
      47,   108,    20,    21,    18,    22,    72,    73,    23,    24,
       9,    87,    20,    21,   140,    22,    44,    13,    23,    24,
      95,    96,    90,   141,    15,   143,   144,    71,    38,    45,
      46,    47,    25,    90,    71,    17,    91,    59,    39,    72,
      73,    40,    25,    97,    98,    99,    72,    73,   128,   129,
      25,    41,    57,    58,    60,    63,    64,    70,    77,    80,
      79,    83,    85,   104,   109,   101,   -48,    18,   122,   123,
     124,   125,   131,   133,   135,   134,   137,   155,   145,   132,
     139,   159,   160,   154,   161,   152,   153,   158,    16,     0,
       0,   100,    61
};

static const yytype_int16 yycheck[] =
{
      43,    24,     3,   104,    42,    23,    42,    24,    34,    35,
       4,     5,    23,    14,    25,   116,    24,    28,    12,    13,
      43,    15,    39,    66,    18,    19,    34,    35,    71,     7,
      41,    42,    43,    36,    37,    38,     0,    80,    21,    82,
      23,    84,   125,    79,    87,    28,   147,    65,    42,     6,
      93,   152,   153,   136,     4,     5,    24,     8,    41,    42,
      43,    84,    12,    13,     4,    15,    34,    35,    18,    19,
      42,    23,    12,    13,     8,    15,    28,     4,    18,    19,
      72,    73,   125,    17,     9,   128,   129,    22,    18,    41,
      42,    43,    42,   136,    22,    10,    24,    27,    11,    34,
      35,    23,    42,    74,    75,    76,    34,    35,    32,    33,
      42,    23,    26,     5,    20,     8,     5,    26,    39,    20,
      40,    11,    26,    31,    41,    16,     9,     4,    24,     9,
      24,     9,     8,     8,     8,    30,     8,     8,    41,    27,
      27,     8,     8,    27,     3,    31,    31,    29,    11,    -1,
      -1,    77,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    45,    46,    42,     0,     6,    47,     8,    42,
      48,    49,    55,     4,    57,     9,    48,    10,     4,     5,
      12,    13,    15,    18,    19,    42,    58,    59,    69,    72,
      77,    82,    87,    56,     3,    14,    50,     5,    58,    11,
      23,    23,    21,    23,    28,    41,    42,    43,    66,    90,
      91,    92,    93,    94,    95,    69,    93,    26,     5,    58,
      20,    55,    51,     8,     5,    62,    64,    95,    90,    93,
      26,    22,    34,    35,    36,    37,    38,    39,    83,    40,
      20,    88,    70,    11,    60,    26,    69,    23,    25,    73,
      90,    24,    24,    67,    90,    91,    91,    92,    92,    92,
      94,    16,    95,    90,    31,    90,    89,    90,    93,    41,
      63,    90,    75,    65,    74,    90,    84,    78,    72,    71,
      61,    52,    24,     9,    24,     9,    68,    72,    32,    33,
      79,     8,    27,     8,    30,     8,    76,     8,    73,    27,
       8,    17,    85,    90,    90,    41,    73,    86,    80,    81,
      53,    72,    31,    31,    27,     8,    72,    72,    29,     8,
       8,     3,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    47,    48,    48,    49,    50,    51,
      52,    53,    50,    54,    56,    55,    55,    57,    57,    58,
      58,    60,    61,    59,    62,    63,    59,    64,    65,    59,
      59,    59,    59,    59,    66,    67,    68,    66,    69,    70,
      71,    69,    72,    72,    74,    73,    73,    73,    75,    76,
      73,    78,    77,    80,    79,    81,    79,    83,    84,    82,
      86,    85,    85,    88,    87,    89,    89,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     4,     1,     0,
       0,     0,    11,     1,     0,     4,     1,     4,     3,     2,
       1,     0,     0,     6,     0,     0,     7,     0,     0,     7,
       1,     1,     1,     1,     1,     0,     0,     6,     1,     0,
       0,     6,     3,     2,     0,     4,     1,     1,     0,     0,
       5,     0,     6,     0,     6,     0,     6,     0,     0,     7,
       0,     4,     1,     0,     6,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     3,     1,     1,
       3,     1,     3,     2,     3,     3
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* sentence: P V M  */
#line 428 "test.y"
                 { printf("\nValid Syntax\n");
					while(tos>=0){
					printf("top of stack is %d %s %s\n",tos,expr_typ[tos].expr,expr_typ[tos].val);
					tos--;
					}
					print_symbol_table();
					return 1; 
				}
#line 1958 "y.tab.c"
    break;

  case 7: /* L: LHS Colon RHS SC  */
#line 449 "test.y"
                                 {
					for (int i = 0; i < id_ind; i++) {
						// push the LOWERCASE NAMES 
						if(is_array == 1){
							char *base = id_names[i];
							printf("this is the base before new: %s\n",base);
							int u = pop();
							// printf("hi");
							u = atoi(expr_typ[u].val);
							int l = pop();
							l = atoi(expr_typ[l].val);
							printf("l: %d, u: %d\n",l, u);
							for(int j= l;j<=u;j++){
								char *new_id_name = malloc((strlen(base)+5));
								char *ind_string = malloc(5);
								strcpy(new_id_name,base);
								// printf("thisis garbage test: %s\n",new_id_name);
								strcat(new_id_name,"[");

								// itoa(j,ind_string,50);

								sprintf(ind_string,"%d",j);

								strcat(new_id_name,ind_string);
								strcat(new_id_name,"]");
								// printf("this is the new_id_name: %s",new_id_name);
								printf("%s: has type %s\n", new_id_name, gtype);
								addTyp(new_id_name,gtype);
							}
							is_array = 0;
						}
						else{
							printf("id_names[%d]: %s has type %s\n", i, id_names[i], gtype);
							addTyp(id_names[i],gtype);
						}
					}
					memset(id_names, 0, sizeof(id_names));
    				memset(gtype, 0, sizeof(gtype));
					id_ind = 0;
				 }
#line 2003 "y.tab.c"
    break;

  case 8: /* RHS: Type  */
#line 492 "test.y"
                {
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			strcpy(gtype, c);
		}
#line 2013 "y.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 497 "test.y"
                {is_array = 1;}
#line 2019 "y.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 497 "test.y"
                                                       {printf("pushing");push((yyvsp[0].cval),"integer",(yyvsp[0].cval));}
#line 2025 "y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 497 "test.y"
                                                                                                                                       {push((yyvsp[0].cval),"integer",(yyvsp[0].cval));}
#line 2031 "y.tab.c"
    break;

  case 13: /* Y: Type  */
#line 501 "test.y"
                {
			char c[50]; 
			sprintf(c,"%s",(yyvsp[0].cval));
			// printf("%s\n",c);
			strcpy(gtype, c);
		}
#line 2042 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 510 "test.y"
                                        {
					char c[50]; 
					sprintf(c,"%s",(yyvsp[-1].cval));
					strcpy(id_names[id_ind++], c);
					}
#line 2052 "y.tab.c"
    break;

  case 16: /* LHS: Identifier  */
#line 518 "test.y"
                                {
					char c[50]; 
					sprintf(c,"%s",(yyvsp[0].cval));
					strcpy(id_names[id_ind++], c);
					// printf("this is the base in LHS: %s\n",id_names[id_ind-1]);
				}
#line 2063 "y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 535 "test.y"
               {asmt_float = 1;}
#line 2069 "y.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 536 "test.y"
                                        {
						if(if_taken == block_taken && for_diff>0 && while_taken == 1){
                            printf("hello  in assign\n");
							int ind1 = pop();
							int ind2 = pop();
							
							char* val1 = expr_typ[ind1].val;
							// printf("this is val1: %s\n",val1);
							int ind = isnameinlist(expr_typ[ind2].expr);
							if(ind != -1){
								symbol_table[ind].asnd = 1;
								strcpy(symbol_table[ind].val,val1); 
							}
							// char* val2 = expr_typ[ind2].val;

							char * expr1 = expr_typ[ind1].expr;
							char * expr2 = expr_typ[ind2].expr;

							char * type = expr_typ[ind1].type;

							// int result = multiplyIntegersInStrings(val1, val2);
							
							// char resultStr[50];
							// intToString(result, resultStr);

							push(concat(expr2,"",""), type, val1);
						}
						// printf("CHECKING ASSIGNOP\n");

						asmt_float =0;

					}
#line 2106 "y.tab.c"
    break;

  case 24: /* $@7: %empty  */
#line 571 "test.y"
                               {is_read = 1;}
#line 2112 "y.tab.c"
    break;

  case 25: /* $@8: %empty  */
#line 571 "test.y"
                                                 {is_read = 0;}
#line 2118 "y.tab.c"
    break;

  case 27: /* $@9: %empty  */
#line 572 "test.y"
                                {is_write = 1;}
#line 2124 "y.tab.c"
    break;

  case 28: /* $@10: %empty  */
#line 572 "test.y"
                                                          {is_write = 0;}
#line 2130 "y.tab.c"
    break;

  case 34: /* I: Identifier  */
#line 580 "test.y"
                        {
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					char c[50]; sprintf(c,"%s",(yyvsp[0].cval));
					int ind = isnameinlist(c);
					if(ind != -1){
						int a = asndornot(ind);
						// printf("assigned: %d\n",a);
						if(a==1){
							char *type = getTypeForName(c);
							int index = isnameinlist(symbol_table[ind].name);
							push(symbol_table[ind].name,type,symbol_table[index].val);
						}
					}
				}
			}
#line 2150 "y.tab.c"
    break;

  case 35: /* $@11: %empty  */
#line 597 "test.y"
                        {
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					char c[50]; sprintf(c,"%s",(yyvsp[-1].cval));
					strcat(c,"[");
					push(c,"",c);
				}
			}
#line 2162 "y.tab.c"
    break;

  case 36: /* $@12: %empty  */
#line 605 "test.y"
                                            {
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					int ind = pop();
					char *index = expr_typ[ind].val;
					ind = pop();
					char *base = expr_typ[ind].val;
					strcat(base,index);
					strcat(base,"]");
					ind = isnameinlist(base);
					push(base,getTypeForName(base),symbol_table[ind].val);
				}
			}
#line 2179 "y.tab.c"
    break;

  case 38: /* LI: Identifier  */
#line 622 "test.y"
                        {
                // printf("for difff: %d\n",for_diff);
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					if(is_read == 1){
						char *theVariable = (yyvsp[0].cval);
						int ind = isnameinlist(theVariable);
						char *type = symbol_table[ind].type;
						if(strcmp(type,"integer") == 0){
							int temp;
							scanf("%d",&temp);
							// itoa(temp, symbol_table[ind].val, 50);

							sprintf(symbol_table[ind].val,"%d",temp);

							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "real") == 0){
							double temp;
							scanf("%lf",&temp);
							sprintf(symbol_table[ind].val, "%lf", temp);
							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "char") == 0){
							char temp;
							char buffer;
							scanf("%c%c", &temp, &buffer);
							sprintf(symbol_table[ind].val, "%c", temp);
							symbol_table[ind].asnd = 1;
						}
					}
					else{
						char c[50]; sprintf(c,"%s",(yyvsp[0].cval));
                        if(ff == 0) strcpy(cv,c);
						char * type = getTypeForName(c);
						push(c,type,"");
					}
				// int ind = isnameinlist(c);

				// if(ind != -1 && is_read ==0){
				// 	symbol_table[ind].asnd = 1;
				// 	char * type = getTypeForName(c);
				// 	push(c,type);
				// }
				}
			}
#line 2229 "y.tab.c"
    break;

  case 39: /* $@13: %empty  */
#line 669 "test.y"
                        {
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					char c[50]; sprintf(c,"%s",(yyvsp[-1].cval));
					strcat(c,"[");
					// int ind = isnameinlist(c);

					// if(ind != -1 && is_read ==0){
					// 	symbol_table[ind].asnd = 1;
					// 	char * type = getTypeForName(c);
					// 	push(c,type);
					// }
					// char * type = getTypeForName(c);
					// printf("%s",type);
					push(c,"",c);
				}
			}
#line 2250 "y.tab.c"
    break;

  case 40: /* $@14: %empty  */
#line 686 "test.y"
                                            {
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					int ind = pop();
					char *index = expr_typ[ind].val;
					ind = pop();
					char *base = expr_typ[ind].val;
					strcat(base,index);
					strcat(base,"]");
					// printf("this is the base: %s\n",base);
					if(is_read == 1){
						int ind = isnameinlist(base);
						char *type = symbol_table[ind].type;
						if(strcmp(type,"integer") == 0){
							int temp;
							scanf("%d",&temp);
							// itoa(temp, symbol_table[ind].val, 50);

							sprintf(symbol_table[ind].val,"%d",temp);
							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "real") == 0){
							double temp;
							scanf("%lf",&temp);
							sprintf(symbol_table[ind].val, "%lf", temp);
							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "char") == 0){
							char temp;
							char buffer;
							scanf("%c%c", &temp, &buffer);
							sprintf(symbol_table[ind].val, "%c", temp);
							symbol_table[ind].asnd = 1;
						}
					}
					else{
						push(base, getTypeForName(base), "");
					}
					// printf("this is the index: %d\n",index);
				}
			}
#line 2295 "y.tab.c"
    break;

  case 44: /* $@15: %empty  */
#line 734 "test.y"
                               {
	if(if_taken == block_taken && for_diff>0 && while_taken == 1){
		int ind = pop();
		char *type = expr_typ[ind].type;
		printf("this is the result of the arithmetic operation: %s and this is the expression: %s\n",expr_typ[ind].val, expr_typ[ind].expr);
		if(strcmp(type,"integer") == 0 || strcmp(type,"boolean") == 0) printf("%d",atoi(expr_typ[ind].val));
		else if(strcmp(type,"real") == 0) printf("%lf", atof(expr_typ[ind].val));
		else if(strcmp(type,"char") == 0) printf("%c",expr_typ[ind].val[0]);
	}
}
#line 2310 "y.tab.c"
    break;

  case 46: /* WriteBody: ArithmeticExpression  */
#line 743 "test.y"
                                         {
	if(if_taken == block_taken && for_diff>0 && while_taken == 1){
		int ind = pop();
		char *type = expr_typ[ind].type;
		printf("this is the result of the arithmetic operation: %s and this is the expression: %s\n",expr_typ[ind].val, expr_typ[ind].expr);
		printf("TYPE type : %s\n",type);
		printf("hi%shi",expr_typ[ind].val);
	}
	}
#line 2324 "y.tab.c"
    break;

  case 47: /* WriteBody: String  */
#line 752 "test.y"
                               {if(if_taken == block_taken && for_diff>0 && while_taken == 1)printf("%s",removeFirstLastChar((yyvsp[0].cval)));}
#line 2330 "y.tab.c"
    break;

  case 48: /* $@16: %empty  */
#line 752 "test.y"
                                                                                                                                                   {if(if_taken == block_taken && for_diff>0 && while_taken == 1) printf("%s",removeFirstLastChar((yyvsp[0].cval)));}
#line 2336 "y.tab.c"
    break;

  case 49: /* $@17: %empty  */
#line 752 "test.y"
                                                                                                                                                                                                                                                                     {printf("string comma writebody part \n");}
#line 2342 "y.tab.c"
    break;

  case 51: /* $@18: %empty  */
#line 755 "test.y"
                                           {
                        printf("For startning at line %d\n", (yylsp[-3]).first_line);for_start = (yylsp[-3]).first_line;
                        if(if_taken == block_taken && for_diff>0 && while_taken == 1){
							int ind1 = pop();
							int ind2 = pop();
							
							char* val1 = expr_typ[ind1].val;
							// printf("this is val1: %s\n",val1);
							int ind = isnameinlist(expr_typ[ind2].expr);
							if(ind != -1){
                                if(ff == 0){
                                    symbol_table[ind].asnd = 1;
								    strcpy(symbol_table[ind].val,val1);
                                } 
							}
							char* val2 = expr_typ[ind2].val;

							char * expr1 = expr_typ[ind1].expr;
							char * expr2 = expr_typ[ind2].expr;

							char * type = expr_typ[ind1].type;

							// int result = multiplyIntegersInStrings(val1, val2);
							
							// char resultS`tr[50];
							// intToString(result, resultStr);

            

							printf("inside first part loop %s %s %s\n",expr2,val1,type);

							for_list[0] = atoi(val1);

							push(concat(expr2,"",""), type, val1);
						}
}
#line 2383 "y.tab.c"
    break;

  case 53: /* $@19: %empty  */
#line 795 "test.y"
                           {
                            if(if_taken == block_taken && for_diff>0 && while_taken == 1){
                                int ind1 = pop();
                                char* val1 = expr_typ[ind1].val;
                                char * expr1 = expr_typ[ind1].expr;
                                char * type = expr_typ[ind1].type;
                                // int ind2 = pop();
                                // char *expr2 = expr_typ[ind2].expr;
                                // char *val2 = expr_typ[ind2].val;
                                printf("this is expr1 %s\n",expr1);
                                // printf("this is expr2 %s\n",expr2);
                                printf("inside for loop %s %s %s\n",expr1,val1,type);

                                for_list[1] = atoi(val1);
                                if(ff == 0){
                                    for_diff = for_list[1] - for_list[0] + 1;
                                    // counter_variable = atoi(val2);
                                    // printf("COUNTER EXPR: %s\n", expr2);
                                    // counter_variable_index = isnameinlist(expr2);
                                    ff = 1;
                                } 

                                // push(concat(expr2,"",""), type, val1);
						    }
						}
#line 2413 "y.tab.c"
    break;

  case 54: /* A: To ArithmeticExpression $@19 Do Block SC  */
#line 821 "test.y"
                                                            {
                            printf("ending at line %d\n", (yylsp[-1]).last_line);
                            for_end = (yylsp[-1]).last_line;
                            if(for_diff-- > 0){
                                printf("thisis the cv: %s\n", cv);
                                sprintf(symbol_table[isnameinlist(cv)].val, "%d", atoi(symbol_table[isnameinlist(cv)].val)+1);
                                // counter_variable++;
                                // printf("COUNTER: %d\n", counter_variable);
                                printf("after updating this is value of counter variable: %s\n",symbol_table[isnameinlist(cv)].val);
                                
                                printf("this is for diff: %d\n",for_diff);
                                goToFor();
                            }
                            else{
                                // printf("Final counter variable: %d\n", counter_variable);
                                sprintf(symbol_table[isnameinlist(cv)].val, "%d", atoi(symbol_table[isnameinlist(cv)].val)-1);
                                for_diff = 1;
                                ff = 0;
                            }
                        }
#line 2438 "y.tab.c"
    break;

  case 55: /* $@20: %empty  */
#line 843 "test.y"
                                    {
                            if(if_taken == block_taken && for_diff>0 && while_taken == 1){
                                int ind1 = pop();
                                char* val1 = expr_typ[ind1].val;
                                char * expr1 = expr_typ[ind1].expr;
                                char * type = expr_typ[ind1].type;
                                // int ind2 = pop();
                                // char *expr2 = expr_typ[ind2].expr;
                                // char *val2 = expr_typ[ind2].val;
                                printf("this is expr1 %s\n",expr1);
                                // printf("this is expr2 %s\n",expr2);
                                printf("inside for loop %s %s %s\n",expr1,val1,type);

                                for_list[1] = atoi(val1);
                                if(ff == 0){
                                    for_diff = for_list[0] - for_list[1] + 1;
                                    // counter_variable = atoi(val2);
                                    // printf("COUNTER EXPR: %s\n", expr2);
                                    // counter_variable_index = isnameinlist(expr2);
                                    ff = 1;
                                } 

                                // push(concat(expr2,"",""), type, val1);
						    }
						}
#line 2468 "y.tab.c"
    break;

  case 56: /* A: DownTo ArithmeticExpression $@20 Do Block SC  */
#line 869 "test.y"
                                                            {
                            printf("ending at line %d\n", (yylsp[-1]).last_line);
                            for_end = (yylsp[-1]).last_line;
                            if(for_diff-- > 0){
                                if(ff == 0){}
                                printf("thisis the cv: %s\n", cv);
                                sprintf(symbol_table[isnameinlist(cv)].val, "%d", atoi(symbol_table[isnameinlist(cv)].val)-1);
                                // counter_variable++;
                                // printf("COUNTER: %d\n", counter_variable);
                                printf("after updating this is value of counter variable: %s\n",symbol_table[isnameinlist(cv)].val);
                                
                                printf("this is for diff: %d\n",for_diff);
                                goToFor();
                            }
                            else{
                                // printf("Final counter variable: %d\n", counter_variable);
                                sprintf(symbol_table[isnameinlist(cv)].val, "%d", atoi(symbol_table[isnameinlist(cv)].val)+1);
                                for_diff = 1;
                                ff = 0;
                            }
                        }
#line 2494 "y.tab.c"
    break;

  case 57: /* $@21: %empty  */
#line 894 "test.y"
                                  {
	if(if_taken == block_taken && for_diff>0 && while_taken == 1 && while_taken == 1){
		int ind = pop();
		if_taken = atoi(expr_typ[ind].val);
	}
}
#line 2505 "y.tab.c"
    break;

  case 58: /* $@22: %empty  */
#line 899 "test.y"
       {block_taken = 1;}
#line 2511 "y.tab.c"
    break;

  case 60: /* $@23: %empty  */
#line 902 "test.y"
        {block_taken = 0;}
#line 2517 "y.tab.c"
    break;

  case 61: /* X: Else $@23 Block SC  */
#line 902 "test.y"
                                   {block_taken = if_taken;}
#line 2523 "y.tab.c"
    break;

  case 62: /* X: SC  */
#line 903 "test.y"
             {block_taken = if_taken;}
#line 2529 "y.tab.c"
    break;

  case 63: /* $@24: %empty  */
#line 905 "test.y"
                                  {
                                    printf("While starting at line %d\n", (yylsp[-1]).first_line);while_start = (yylsp[-1]).first_line;while_taken = atoi(expr_typ[pop()].val);
                                    printf("this is BE: %d\n", while_taken);
                                  }
#line 2538 "y.tab.c"
    break;

  case 64: /* WhileLoop: While BooleanExpression $@24 Do Block SC  */
#line 908 "test.y"
                                               {printf("ending at line %d\n", (yylsp[-1]).last_line);
                            while_end = (yylsp[-1]).last_line;if(while_taken == 1){goToWhile();}while_taken = 1;}
#line 2545 "y.tab.c"
    break;

  case 66: /* Expression: ArithmeticExpression  */
#line 914 "test.y"
                            {
						// printf("OOOOOOO\n");
					}
#line 2553 "y.tab.c"
    break;

  case 68: /* ArithmeticExpression: ArithmeticExpression Plus T  */
#line 921 "test.y"
                                                {
							if(if_taken == block_taken && for_diff>0 && while_taken == 1){
								//printf("CHECKING +\n");
								// type_check(" * ");
								int ind1 = pop();
								int ind2 = pop();
								
								char* val1 = expr_typ[ind1].val;
								char* val2 = expr_typ[ind2].val;	

								char * expr1 = expr_typ[ind1].expr;
								char * expr2 = expr_typ[ind2].expr;

								char * type = expr_typ[ind1].type;
								char resultStr[50];
								if(strcmp(type,"integer") == 0){
									int result = addIntegersInStrings(val2, val1);
									intToString(result, resultStr);
								}
								else if(strcmp(type,"real") == 0){
									double result = addFloatInStrings(val2, val1);
									floatToString(result,resultStr);
								}
								push(concat(expr2,expr1,"+"), type, resultStr);

								// if (is_write){
								// 	printf("_%s_", resultStr);
								// }
							}

						}
#line 2589 "y.tab.c"
    break;

  case 69: /* ArithmeticExpression: ArithmeticExpression Minus T  */
#line 953 "test.y"
                                                {
							if(if_taken == block_taken && for_diff>0 && while_taken == 1){
								// printf("CHECKING -\n");				
								// type_check(" * ");
								int ind1 = pop();
								int ind2 = pop();
								
								char* val1 = expr_typ[ind1].val;
								char* val2 = expr_typ[ind2].val;	

								char * expr1 = expr_typ[ind1].expr;
								char * expr2 = expr_typ[ind2].expr;

								char * type = expr_typ[ind1].type;
								char resultStr[50];
								if(strcmp(type,"integer") == 0){
									int result = subIntegersInStrings(val2, val1);
									intToString(result, resultStr);
								}
								else if(strcmp(type,"real") == 0){
									double result = subFloatInStrings(val2, val1);
									floatToString(result, resultStr);
								}
								push(concat(expr2,expr1,"-"), type, resultStr);

								// if (is_write){
								// 	printf("_%s_", resultStr);
								// }
							}
						}
#line 2624 "y.tab.c"
    break;

  case 71: /* T: T Mul F  */
#line 987 "test.y"
        {
		if(if_taken == block_taken && for_diff>0 && while_taken == 1){
			// printf("CHECKING *\n");
			// type_check(" * ");
			int ind1 = pop();
			int ind2 = pop();
			
			char* val1 = expr_typ[ind1].val;
			char* val2 = expr_typ[ind2].val;	

			char * expr1 = expr_typ[ind1].expr;
			char * expr2 = expr_typ[ind2].expr;

			char * type = expr_typ[ind1].type;
			char resultStr[50];
			if(strcmp(type,"integer") == 0){
				int result = multiplyIntegersInStrings(val2, val1);
				intToString(result, resultStr);
			}
			else if(strcmp(type,"real") == 0){
				double result = multiplyFloatInStrings(val2, val1);
				floatToString(result, resultStr);
			}

			push(concat(expr2,expr1,"*"), type, resultStr);

			// if (is_write){
			// 				printf("_%s_", resultStr);
			// 			}
		}
	}
#line 2660 "y.tab.c"
    break;

  case 72: /* T: T Div F  */
#line 1019 "test.y"
        {
		if(if_taken == block_taken && for_diff>0 && while_taken == 1){
			// printf("CHECKING /\n");
			int ind1 = pop();
			int ind2 = pop();
			
			char* val1 = expr_typ[ind1].val;
			char* val2 = expr_typ[ind2].val;

			printf("tos in division --------%s %s\n",expr_typ[tos].expr,expr_typ[tos].type);

			char * expr1 = expr_typ[ind1].expr;
			char * expr2 = expr_typ[ind2].expr;

			printf("EXXXXXXX %s %s\n",expr1,expr2);

			// char * type = expr_typ[ind1].type;
			char resultStr[50];

			double result = divIntegersInStrings(val2, val1);
			printf("\ndjhksjhkd  %lf actual result",result);
			int resultfloor = result;
			printf("\n%d floor of result",resultfloor);
			if((strcmp(expr_typ[tos].type,"integer")==0 && asmt_float ==1)){
				printf("in this case of int on lhs maybe\n");
				intToString(resultfloor,resultStr);
				push(concat(expr2,expr1,"/"), "integer", resultStr);
			}
			else{
				printf("in this case of real on lhs maybe\n");
				floatToString(result, resultStr);
				push(concat(expr2,expr1,"/"), "real", resultStr);
			}

		}

			// if (is_write){
			// 				printf("_%s_", resultStr);
			// 			}
		}
#line 2705 "y.tab.c"
    break;

  case 73: /* T: T Mod F  */
#line 1060 "test.y"
        {
		if(if_taken == block_taken && for_diff>0 && while_taken == 1){
			// printf("CHECKING %\n");
			int ind1 = pop();
			int ind2 = pop();
			
			char* val1 = expr_typ[ind1].val;
			char* val2 = expr_typ[ind2].val;	

			char * expr1 = expr_typ[ind1].expr;
			char * expr2 = expr_typ[ind2].expr;

			char * type = expr_typ[ind1].type;

			int result = modIntegersInStrings(val2, val1);
			
			char resultStr[50];
			intToString(result, resultStr);

			push(concat(expr2,expr1,"%"), type, resultStr);
		}
	}
#line 2732 "y.tab.c"
    break;

  case 74: /* F: NumberLiteral  */
#line 1086 "test.y"
                {
			if(if_taken == block_taken && for_diff>0 && while_taken == 1){
				char c[50]; 
				sprintf(c,"%s",(yyvsp[0].cval));
				// printf("numlit is %s\n",c);
				char * d = removespace_lower(c);
				// printf("this is d: %s\n",d);
				push(c,"integer",d);
			}
		}
#line 2747 "y.tab.c"
    break;

  case 75: /* F: RealLiteral  */
#line 1097 "test.y"
                {
			if(if_taken == block_taken && for_diff>0 && while_taken == 1){
				char c[50]; 
				sprintf(c,"%s",(yyvsp[0].cval));
				// printf("realit is %s\n",c);
				// push(c,"real");
				char * d = removespace_lower(c);
				push(c,"real",d);
			}
		}
#line 2762 "y.tab.c"
    break;

  case 76: /* F: CharacterLiteral  */
#line 1108 "test.y"
        {
			if(if_taken == block_taken && for_diff>0 && while_taken == 1){
				char c[50]; 
				sprintf(c,"%s",(yyvsp[0].cval)); 
				// printf("charlit is %s\n",c);
				// push(c,"char");
				char * d = removespace_lower(c);
				push(c,"char",d);
			}
		}
#line 2777 "y.tab.c"
    break;

  case 85: /* BooleanF: ArithmeticExpression RelationalOperator ArithmeticExpression  */
#line 1136 "test.y"
                                              {
				if(if_taken == block_taken && for_diff>0 && while_taken == 1){
					char *relop = (yyvsp[-1].cval);
					printf("this is the relop %s\n",relop);
					int ind1 = pop();
					int ind2 = pop();
					char* val1 = expr_typ[ind1].val;
					char* val2 = expr_typ[ind2].val;	
					char resultStr[50];
					char * expr1 = expr_typ[ind1].expr;
					char * expr2 = expr_typ[ind2].expr;
					printf("this is val2: %s and this is val1: %s\n",val2,val1);
					printf("THIS IS S IS SI is type2: %s and this is type1: %s\n",expr_typ[ind2].type,expr_typ[ind1].type);
					char * type1 = expr_typ[ind1].type;
					char * type2 = expr_typ[ind2].type;
					int result = parseBooleanExpression(val2,val1,relop,type2,type1);
					printf("this is the result of be: %d\n", result);
					sprintf(resultStr,"%d",result);
					push(concat(expr2,expr1,relop), "boolean",resultStr);

					// if (is_write){
					// 	printf("_%s_", resultStr);
					// }
				}
			}
#line 2807 "y.tab.c"
    break;


#line 2811 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1163 "test.y"


void main(){
	FILE *f = fopen("input1.txt","r");
    yyin = f;
	for (int i = 0; i < 50; i++) {
        symbol_table[i].asnd = 0;  // Initializing the 'asnd' member to 0
    }
	
    yyparse();
    exit(0);
    }


void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
