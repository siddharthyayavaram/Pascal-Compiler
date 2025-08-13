%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

extern FILE* yyin;
extern int line_num;
void yyerror(const char *msg);

%}

%union{char *cval;int ival;}

%token Type Begin End Var Prog SC comma Colon Stop Read Write Array If Then Else For While AsmtOp Not RelationalOperator OpenParenthesis CloseParenthesis String
ArrayOpen ArrayClose CharacterLiteral Of DoubleDots Do To DownTo Plus Minus Mul Mod Div Or And NumberLiteral Identifier

%%
sentence : P V M {printf(" Valid Sentence\n") ; return 1; }
	; 

P  : Prog Identifier SC ;

V : Var LS
	;

LS : L  O 
	;

O: LS  | /*epsilon*/

L :  LHS  Colon RHS SC
	;

RHS : Type 
	| Array  ArrayOpen NumberLiteral DoubleDots NumberLiteral ArrayClose Of Y 
;

Y : Type
	;

LHS : Identifier H
	;

H: comma LHS | /*epsilon*/ ;
M : Begin J 
	;

J:B End Stop  | End Stop 

B : S K
;

K: B | /*epsilon*/

S :  I AsmtOp Expression SC
	| Read OpenParenthesis I CloseParenthesis SC
	| Write  OpenParenthesis WriteBody CloseParenthesis SC
	| IfStatement
	| ForLoop
	| WhileLoop
	| Block
;

I: Identifier G
;

G: ArrayOpen ArithmeticExpression ArrayClose 
    | /*epsilon*/

Block: Begin A
;

A: B End | End

WriteBody:  I C
			| String D
;

C: comma WriteBody | /*epsilon*/

D: comma WriteBody | /*epsilon*/

ForLoop: For I AsmtOp ArithmeticExpression E ArithmeticExpression Do Block SC
;

E: To | DownTo

IfStatement: If BooleanExpression Then Block X
;

X: Else Block SC 
	| SC

WhileLoop: While BooleanExpression Do Block SC
;

Expression: BooleanExpression 
		  | ArithmeticExpression 
;

ArithmeticExpression: T A1
;

A1: OP T A1 | /*epsilon*/

OP: Plus | Minus

T : F T1
;

T1: PO F T1 | /*epsilon*/

PO: Mul | Div | Mod

F : NumberLiteral
  | CharacterLiteral
  | OpenParenthesis ArithmeticExpression CloseParenthesis
  | I
;

BooleanExpression: BooleanT BooleanExpression1
;

BooleanExpression1: Or BooleanT BooleanExpression1 | /*epsilon*/

BooleanT: BooleanF BooleanT1
;

BooleanT1: And BooleanF BooleanT1 | /*epsilon*/

PrintStmt : /*epsilon*/
	;

BooleanF: Not{printf("[BooleanF[Not:{not}]");} BooleanF{printf("]");}
         | OpenParenthesis{printf("[BooleanF[open_parenthesis:{(}]");}BooleanExpression{printf("]");} CloseParenthesis{printf("[close_parenthesis:{)}]");}
         | PrintStmt ArithmeticExpression {printf("]");} RelationalOperator{printf("[relational_operator:{%s}][ArithmeticExpression",$<cval>1);} ArithmeticExpression {printf("]");}
         | Identifier PrintStmt {printf("[var:{%s}][G",$<cval>1);} G {printf("]");}
;

%%

void main(){
	FILE *f = fopen("input.txt","r");
    yyin = f;
    yyparse();
    exit(0);
    }


void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
