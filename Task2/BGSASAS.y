%{
#include <stdio.h>
#include <stdlib.h>
extern FILE* yyin;
extern int line_num;
void yyerror(const char *msg);
%}

%token Identifier Type Begin End Var Prog SC comma Colon Stop Read Write Array If Then Else For While AsmtOp Not RelationalOperator OpenParenthesis CloseParenthesis String
ArrayOpen ArrayClose NumberLiteral CharacterLiteral Of DoubleDots Do To DownTo Plus Minus Mul Mod Div Or And

%%
sentence : P V M { printf("Valid Sentence\n") ; return 1; }
	; 

P : Prog Identifier SC
	;

V : Var LS
	;

LS : L LS
	| L
	;

L : LHS Colon RHS SC
	;

RHS : Type
	| Array ArrayOpen NumberLiteral DoubleDots NumberLiteral ArrayClose Of Type
	;

LHS : Identifier comma LHS
	| Identifier
	;

M : Begin B End Stop
	|Begin End Stop
	;

B : S B
	| S
;

S :  I AsmtOp Expression SC
	| Read OpenParenthesis I CloseParenthesis SC
	| Write OpenParenthesis WriteBody CloseParenthesis SC
	| IfStatement
	| ForLoop
	| WhileLoop
	| Block
;

I: Identifier
 | Identifier ArrayOpen ArithmeticExpression ArrayClose
; 

Block: Begin B End
	| Begin End
;

WriteBody: I comma WriteBody | I
			| String comma WriteBody | String
;

ForLoop: For I AsmtOp ArithmeticExpression To ArithmeticExpression Do Block SC
	   | For I AsmtOp ArithmeticExpression DownTo ArithmeticExpression Do Block SC
;

IfStatement: If BooleanExpression Then Block SC
		   | If BooleanExpression Then Block Else Block SC
;

WhileLoop: While BooleanExpression Do Block SC
;

Expression: BooleanExpression 
		  | ArithmeticExpression
;

ArithmeticExpression: T | ArithmeticExpression Plus T | ArithmeticExpression Minus T
;

T : F | T Mul F | T Div F | T Mod F
;

F : NumberLiteral | CharacterLiteral | OpenParenthesis ArithmeticExpression CloseParenthesis |  I
;

BooleanExpression: BooleanT
			| BooleanExpression Or BooleanT
;

BooleanT: BooleanF
		| BooleanT And BooleanF
;

BooleanF: Not BooleanF 
		| OpenParenthesis BooleanExpression CloseParenthesis
		| ArithmeticExpression RelationalOperator ArithmeticExpression
		| I
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
