%{
#include<stdio.h> 
#include<string.h>
int line_num = 1; 
%}

%option caseless
keyword ("program"|"integer"|"real"|"boolean"|"char"|"var"|"to"|"downto"|"if"|"else"|"while"|"for"|"do"|"array"|"begin"|"end"|"read"|"write"|"of"|"writeln"|"then")
digit [0-9]
number ([1-9][0-9]*|0)

character (['][^\']['])

letter [a-zA-Z]

arithmeticOperator ("+"|"-"|"*"|"/"|"%")

relationalOperator ("="|"<>"|"<="|">="|"<"|">")

booleanOperator ("and"|"or"|"not")

variable {letter}+({letter}|{digit}|"_")*

punctuator ("("|")"|","|"."|";"|":"|"["|"]"|"..")

comment " "*"//"[^\n]*

%%
{comment} {printf("%d\t%s\t\t comment \n",line_num, yytext);}
{keyword} {printf("%d\t%s\t\t keyword \n",line_num, yytext);}
{punctuator} {printf("%d\t%s\t\tpunctuator\n", line_num, yytext);}
{number} {printf("%d\t%s\t\tnumber\n", line_num, yytext);}
{relationalOperator} {printf("%d\t%s\t\t Relational Operator\n",line_num, yytext);}
{arithmeticOperator} {printf("%d\t%s\t\tArithmetic Operator\n",line_num, yytext);}
{booleanOperator} {printf("%d\t%s\t\tBoolean Operator\n",line_num, yytext);}
{character} {printf("%d\t%s\t\tcharacter literal\n",line_num, yytext);}
{variable} {printf("%d\t%s\t\tidentifier\n",line_num, yytext);}
":=" {printf("%d\t%s\t\tAssignment Operator\n",line_num, yytext);}
"\n" {line_num++;}
. {;}
%%

// int yywrap(void){}

void main(){
    FILE *f = fopen("input.txt","r");
    yyin = f;
    yylex(); 
}