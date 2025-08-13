%{
#include<stdio.h> 
#include<string.h>
#include "y.tab.h"
int line_num = 1;
char *fn(char *text){
    char *result = malloc(strlen(text)*sizeof(char));
    int i = 0;
    int j = 0;
    while(text[i] == ' ') i++;
    while(text[i] != ' ') result[j++] = text[i++];
    result[j] = '\0';
    return result;
}
%}

%option caseless
digit [0-9]
number " "*([1-9][0-9]*|0)" "*

character (['][^\']['])
prog " "*("program")" "*
letter [a-zA-Z]

relationalOperator " "*("="|"<>"|"<="|">="|"<"|">")" "*

variable {letter}+({letter}|{digit}|"_")*

type " "*("Char"|"Integer"|"Real"|"Boolean")" "*

string (["][^\"]+["]|["]["])

comment " "*"//"[^\n]*

%%
" "+ {;}
"var" {yylval.cval=strdup(yytext); return Var;}
"program" {yylval.cval = strdup(yytext); return Prog;}
{variable} {yylval.cval = strdup(yytext); return Identifier;}
";" {yylval.cval= strdup(yytext);return SC;}
. {printf("Syntax Error at line %d\n",line_num); exit(0);}
%%

int yywrap(void){}