%{
#include<stdio.h> 
#include<string.h>
#include "y.tab.h"
int line_num = 1;
%}

%option caseless
digit [0-9]

number ([1-9][0-9]*|0)

real ([1-9][0-9]*|0)"."({digit}+)

character (['][^\']['])

letter [a-zA-Z]

relationalOperator ("="|"<>"|"<="|">="|"<"|">")

variable {letter}+({letter}|{digit}|"_")*

type ("Char"|"Integer"|"Real"|"Boolean")

string (["][^\"]+["]|["]["])

comment " "*"//"[^\n]*

%%
" "+ {;}
"if" {return If;}
"then" {return Then;}
"else" {return Else;}
"for" {return For;}
"while" {return While;}
"program" {return Prog;}
"do" {return Do;}
"to" {return To;}
"downto" {return DownTo;}
"var" {return Var;}
"not" {return Not;}
"and" {return And;}
"or" {return Or;}
"read" {return Read;}
"write" {return Write;}
"writeln" {return Write;}
"of" {return Of;}
"\(" {return OpenParenthesis;}
"\)" {return CloseParenthesis;}
"array" {return Array;}
"begin" {return Begin;}
"end" {return End;}
";" {return SC;}
".." {return DoubleDots;}
"." {return Stop;}
":" {return Colon;}
":=" {return AsmtOp;}
"," {return comma;}
"\[" {return ArrayOpen;}
"\]" {return ArrayClose;}
"\n" {line_num++;}
"+" {return Plus;}
"-" {return Minus;}
"*" {return Mul;}
"/" {return Div;}
"%" {return Mod;}
{number} {yylval.cval= strdup(yytext); return NumberLiteral;}
{real} {yylval.cval= strdup(yytext); return RealLiteral;}
{relationalOperator} {yylval.cval = strdup(yytext); return RelationalOperator;}
{type} {yylval.cval= strdup(yytext); return Type;}
{comment} {;}
{character} {yylval.cval= strdup(yytext); return CharacterLiteral;}
{string} {yylval.cval= strdup(yytext);return String;}
{variable} {yylval.cval = strdup(yytext); return Identifier;}

. {printf("Syntax Error at line %d\n",line_num); exit(0);}
%%

int yywrap(void){}