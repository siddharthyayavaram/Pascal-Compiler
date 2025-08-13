
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 15 "BGSASAS.y"
char *cval;int ival;float fval;


/* Line 1676 of yacc.c  */
#line 142 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


