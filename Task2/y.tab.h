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
    Identifier = 258,              /* Identifier  */
    Type = 259,                    /* Type  */
    Begin = 260,                   /* Begin  */
    End = 261,                     /* End  */
    Var = 262,                     /* Var  */
    Prog = 263,                    /* Prog  */
    SC = 264,                      /* SC  */
    comma = 265,                   /* comma  */
    Colon = 266,                   /* Colon  */
    Stop = 267,                    /* Stop  */
    Read = 268,                    /* Read  */
    Write = 269,                   /* Write  */
    Array = 270,                   /* Array  */
    If = 271,                      /* If  */
    Then = 272,                    /* Then  */
    Else = 273,                    /* Else  */
    For = 274,                     /* For  */
    While = 275,                   /* While  */
    AsmtOp = 276,                  /* AsmtOp  */
    Not = 277,                     /* Not  */
    RelationalOperator = 278,      /* RelationalOperator  */
    OpenParenthesis = 279,         /* OpenParenthesis  */
    CloseParenthesis = 280,        /* CloseParenthesis  */
    String = 281,                  /* String  */
    ArrayOpen = 282,               /* ArrayOpen  */
    ArrayClose = 283,              /* ArrayClose  */
    NumberLiteral = 284,           /* NumberLiteral  */
    CharacterLiteral = 285,        /* CharacterLiteral  */
    Of = 286,                      /* Of  */
    DoubleDots = 287,              /* DoubleDots  */
    Do = 288,                      /* Do  */
    To = 289,                      /* To  */
    DownTo = 290,                  /* DownTo  */
    Plus = 291,                    /* Plus  */
    Minus = 292,                   /* Minus  */
    Mul = 293,                     /* Mul  */
    Mod = 294,                     /* Mod  */
    Div = 295,                     /* Div  */
    Or = 296,                      /* Or  */
    And = 297                      /* And  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define Identifier 258
#define Type 259
#define Begin 260
#define End 261
#define Var 262
#define Prog 263
#define SC 264
#define comma 265
#define Colon 266
#define Stop 267
#define Read 268
#define Write 269
#define Array 270
#define If 271
#define Then 272
#define Else 273
#define For 274
#define While 275
#define AsmtOp 276
#define Not 277
#define RelationalOperator 278
#define OpenParenthesis 279
#define CloseParenthesis 280
#define String 281
#define ArrayOpen 282
#define ArrayClose 283
#define NumberLiteral 284
#define CharacterLiteral 285
#define Of 286
#define DoubleDots 287
#define Do 288
#define To 289
#define DownTo 290
#define Plus 291
#define Minus 292
#define Mul 293
#define Mod 294
#define Div 295
#define Or 296
#define And 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
