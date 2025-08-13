%{
#include<stdio.h> 
#include<string.h>
#include "y.tab.h"
int line_num = 1;
%}

%option caseless
digit [0-9]

number " "*([1-9][0-9]*|0)" "*

character (['][^\']['])

letter [a-zA-Z]

relationalOperator " "*("="|"<>"|"<="|">="|"<"|">")" "*

variable {letter}+({letter}|{digit}|"_")*

type " "*("Char"|"Integer"|"Real"|"Boolean")" "*

string (["][^\"]+["]|["]["])

comment " "*"//"[^\n]*

%%
" "*"if"" "* {return If;}
" "*"then"" "* {return Then;}
" "*"else"" "* {return Else;}
" "*"for"" "* {return For;}
" "*"while"" "* {return While;}
" "*"program"" "* {return Prog;}
" "*"do"" "* {return Do;}
" "*"to"" "* {return To;}
" "*"downto"" "* {return DownTo;}
" "*"var"" "* {return Var;}
" "*"not"" "* {return Not;}
" "*"and"" "* {return And;}
" "*"or"" "* {return Or;}
" "*"read"" "* {return Read;}
" "*"write"" "* {return Write;}
" "*"writeln"" "* {return Write;}
" "*"of"" "* {return Of;}
" "*"\("" "* {return OpenParenthesis;}
" "*"\)"" "* {return CloseParenthesis;}
" "*"array"" "* {return Array;}
" "*"begin"" "* {return Begin;}
" "*"end"" "* {return End;}
" "*";"" "* {return SC;}
" "*".."" "* {return DoubleDots;}
"." {return Stop;}
" "*":"" "* {return Colon;}
" "*":="" "* {return AsmtOp;}
" "*","" "* {return comma;}
" "*"\["" "* {return ArrayOpen;}
" "*"\]"" "* {return ArrayClose;}
"\n" {line_num++;}
" "*"+"" "* {return Plus;}
" "*"-"" "* {return Minus;}
" "*"*"" "* {return Mul;}
" "*"/"" "* {return Div;}
" "*"%"" "* {return Mod;}
{number} {return NumberLiteral;}
{relationalOperator} {return RelationalOperator;}
{type} {return Type;}
{comment} {;}
{character} {return CharacterLiteral;}
{string} {return String;}
{variable} {return Identifier;}

" "* {;}

. {printf("Syntax Error at line %d\n",line_num); exit(0);}
%%

int yywrap(void){}