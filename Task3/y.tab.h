/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
