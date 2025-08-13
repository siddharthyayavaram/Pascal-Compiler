%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

extern FILE* yyin;
extern FILE *yyout;
extern int line_num;
void yyerror(const char *msg);

%}

%union{char *cval;int ival;float fval;}

%token Type Begin End Var Prog SC comma Colon Stop Read Write Array If Then Else For While AsmtOp Not RelationalOperator OpenParenthesis CloseParenthesis String
ArrayOpen ArrayClose CharacterLiteral Of DoubleDots Do To DownTo Plus Minus Mul Mod Div Or And NumberLiteral Identifier RealLiteral

%%
sentence : {fprintf(yyout, "[sentence[P");} P {fprintf(yyout, "][V");} V {fprintf(yyout, "][M");}M {fprintf(yyout, "]]");printf(" Valid Sentence\n") ; return 1; }
	; 

P  : Prog{fprintf(yyout, "[prog:{program}]");} Identifier{fprintf(yyout, "[var:{%s}]",$<cval>3);} SC {fprintf(yyout, "[SC:{;}]");}
	;

V : Var {fprintf(yyout, "[var:{var}][LS");} LS {fprintf(yyout, "]");}
	;

LS : {fprintf(yyout, "[L");}L {fprintf(yyout, "][O");} O {fprintf(yyout, "]");}
	;

O: {fprintf(yyout, "[LS");}LS {fprintf(yyout, "]");} | /*epsilon*/

L : {fprintf(yyout, "[LHS");} LHS {fprintf(yyout, "]");} Colon {fprintf(yyout, "[Colon:{:}]");fprintf(yyout, "[RHS");}RHS {fprintf(yyout, "]");} SC{fprintf(yyout, "[SC:{;}]");}
	;

RHS : Type {fprintf(yyout, "[type:{%s}]",$<cval>1);}
	| Array {fprintf(yyout, "[array:{array}]");} ArrayOpen {fprintf(yyout, "[array_open:{[}]");} NumberLiteral {fprintf(yyout, "[num_literal:{%d}]",$<ival>5);} DoubleDots {fprintf(yyout, "[double_dots:{..}]");} NumberLiteral {fprintf(yyout, "[num_literal:{%d}]",$<ival>9);} ArrayClose {fprintf(yyout, "[array_close:{]}]");} Of {fprintf(yyout, "[of:{of}]");} {fprintf(yyout, "[Y");}Y {fprintf(yyout, "]");}
;

Y : Type {fprintf(yyout, "[type:{%s}]",$<cval>1);}
	;

LHS : Identifier{fprintf(yyout, "[var:{%s}]",$<cval>1);fprintf(yyout, "[H");}H{fprintf(yyout, "]");}
	;

H: comma{fprintf(yyout, "[comma:{,}][LHS");}LHS{fprintf(yyout, "]");} 
	| /*epsilon*/ ;


M : Begin {fprintf(yyout, "[begin:{begin}][J");} J {fprintf(yyout, "]");}
	;

J: {fprintf(yyout, "[B");}B{fprintf(yyout, "]");} End {fprintf(yyout, "[end:{end}]");} Stop {fprintf(yyout, "[stop:{.}]");} 
	| End Stop {fprintf(yyout, "[end:{end}][stop:{.}]");}

B : {fprintf(yyout, "[S");}S{fprintf(yyout, "]");fprintf(yyout, "[K");}K{fprintf(yyout, "]");} 
;

K: {fprintf(yyout, "[B");}B{fprintf(yyout, "]");} | /*epsilon*/

S :  I {fprintf(yyout, "]");}AsmtOp{fprintf(yyout, "[asmt_op:{:=}][Expression");} Expression {fprintf(yyout, "]");}SC{fprintf(yyout, "[SC:{;}]");} 
	| Read{fprintf(yyout, "[read:{read}]");}OpenParenthesis{fprintf(yyout, "[open_parenthesis:{(}]");} I{fprintf(yyout, "]");} CloseParenthesis{fprintf(yyout, "[close_parenthesis:{)}]");} SC {fprintf(yyout, "[SC:{;}]");}
	| Write {fprintf(yyout, "[write:{write}]");} OpenParenthesis {fprintf(yyout, "[open_parenthesis:{(}][WriteBody");} WriteBody {fprintf(yyout, "]");} CloseParenthesis {fprintf(yyout, "[close_parenthesis:{)}]");} SC {fprintf(yyout, "[SC:{;}]");}
	| IfStatement {fprintf(yyout, "]");}
	| ForLoop {fprintf(yyout, "]");}
	| WhileLoop {fprintf(yyout, "]");}
	| Block {fprintf(yyout, "]");}
;


I: {fprintf(yyout, "[I");}Identifier {fprintf(yyout, "[var:{%s}][G",$<cval>2);} G {fprintf(yyout, "]");}
;

G: ArrayOpen {fprintf(yyout, "[array_open:{[}][ArithmeticExpression");}ArithmeticExpression {fprintf(yyout, "]");} ArrayClose {fprintf(yyout, "[array_close:{]}]");} 
    | /*epsilon*/

Block: Begin {fprintf(yyout, "[begin:{begin}]");fprintf(yyout, "[A");}A {fprintf(yyout, "]");}
;

A: {fprintf(yyout, "[B");}B {fprintf(yyout, "]");} End {fprintf(yyout, "[end:{end}]");} | End {fprintf(yyout, "[end:{end}]");}

WriteBody:  I {fprintf(yyout, "][C");}C{fprintf(yyout, "]");}
			| String{fprintf(yyout, "[string:{%s}][D",$<cval>1);} D {fprintf(yyout, "]");}
;

C: comma {fprintf(yyout, "[comma:{,}][WriteBody");} WriteBody {fprintf(yyout, "]");} | /*epsilon*/

D: comma {fprintf(yyout, "[comma:{,}][WriteBody");} WriteBody {fprintf(yyout, "]");}| /*epsilon*/

ForLoop: {fprintf(yyout, "[ForLoop");}For{fprintf(yyout, "[for:{for}]");} I {fprintf(yyout, "]");} AsmtOp{fprintf(yyout, "[asmt_op:{:=}][ArithmeticExpression");} ArithmeticExpression {fprintf(yyout, "][E");} E {fprintf(yyout, "][ArithmeticExpression");} ArithmeticExpression {fprintf(yyout, "]");} Do{fprintf(yyout, "[Do:{do}][Block");} Block {fprintf(yyout, "]");} SC {fprintf(yyout, "[SC:{;}]");}
;

E: To {fprintf(yyout, "[To:{to}]");}| DownTo {fprintf(yyout, "[DownTo: {down_to}]");}

IfStatement: {fprintf(yyout, "[IfStatement");}If {fprintf(yyout, "[if:{if}]");}BooleanExpression{fprintf(yyout, "]");} Then {fprintf(yyout, "[then:{then}][Block");} Block {fprintf(yyout, "][X");} X {fprintf(yyout, "]");}
;

X: Else {fprintf(yyout, "[else:{else}][Block");} Block{fprintf(yyout, "]");} SC {fprintf(yyout, "[SC:{;]}");} 
	| SC {fprintf(yyout, "[SC:{;}]");}

WhileLoop: {fprintf(yyout, "[WhileLoop");}While {fprintf(yyout, "[While:{while}]");}BooleanExpression {fprintf(yyout, "]");}Do{fprintf(yyout, "[Do:{do}][Block");} Block{fprintf(yyout, "]");} SC {fprintf(yyout, "[SC:{;}]");}
;

Expression: BooleanExpression {fprintf(yyout, "]");}
		  | {fprintf(yyout, "[ArithmeticExpression");} ArithmeticExpression {fprintf(yyout, "]");}
;

ArithmeticExpression: {fprintf(yyout, "[T");}T{fprintf(yyout, "][A1");} A1{fprintf(yyout, "]");}
;

A1: {fprintf(yyout, "[OP");}OP{fprintf(yyout, "][T");}T {fprintf(yyout, "][A1");} A1 {fprintf(yyout, "]");} | /*epsilon*/

OP: Plus {fprintf(yyout, "[plus:{+}]");}| Minus {fprintf(yyout, "[minus:{-}]");}

T : {fprintf(yyout, "[F");}F{fprintf(yyout, "]");} {fprintf(yyout, "[T1");}T1 {fprintf(yyout, "]");}
;

T1: {fprintf(yyout, "[PO");}PO {fprintf(yyout, "][F");} F {fprintf(yyout, "]");} {fprintf(yyout, "[T1");}T1{fprintf(yyout, "]");} | /*epsilon*/

PO: Mul{fprintf(yyout, "[mul:{*}]");} | Div{fprintf(yyout, "[div:{/}]");} | Mod{fprintf(yyout, "[mod:{%}]");}

F : NumberLiteral {fprintf(yyout, "[number_literal:{%d}]",$<ival>1);}
  | CharacterLiteral {fprintf(yyout, "[character_literal:{%s}]",$<cval>1);}
  | RealLiteral {fprintf(yyout, "[real_literal:{%lf}]",$<fval>1);}
  | OpenParenthesis {fprintf(yyout, "[open_parenthesis:{(}][ArithmeticExpression");} ArithmeticExpression {fprintf(yyout, "]");} CloseParenthesis {fprintf(yyout, "[close_parenthesis:)]");} 
  | I{fprintf(yyout, "]");}
;

BooleanExpression: {fprintf(yyout, "[BooleanExpression[BooleanT");}BooleanT{fprintf(yyout, "][BooleanExpression1");} BooleanExpression1 {fprintf(yyout, "]");}
;

BooleanExpression1: Or {fprintf(yyout, "[or:{or}][BooleanT");}BooleanT{fprintf(yyout, "][BooleanExpression1");} BooleanExpression1 {fprintf(yyout, "]");} | /*epsilon*/

BooleanT: BooleanF {fprintf(yyout, "][BooleanT1");} BooleanT1 {fprintf(yyout, "]");}
;

BooleanT1: And {fprintf(yyout, "[and:{and}][BooleanT1");} BooleanF BooleanT1 {fprintf(yyout, "]");} | /*epsilon*/

BooleanF: Not{fprintf(yyout, "[BooleanF[Not:{not}]");} BooleanF{fprintf(yyout, "]");}
		| OpenParenthesis{fprintf(yyout, "[BooleanF[open_parenthesis:{(}]");}BooleanExpression{fprintf(yyout, "]");} CloseParenthesis{fprintf(yyout, "[close_parenthesis:{)}]");}
		| {fprintf(yyout, "[BooleanF[ArithmeticExpression");}ArithmeticExpression {fprintf(yyout, "][X1");} X1 {fprintf(yyout, "]");} 
;

X1: RelationalOperator{fprintf(yyout, "[relational_operator:{%s}][ArithmeticExpression",$<cval>1);} ArithmeticExpression {fprintf(yyout, "]");} | /*epsilon*/ 

%%

void main(){
	FILE *f = fopen("input.txt","r");
    yyin = f;
	FILE *g = fopen("syntaxtree.txt","w");
	yyout = g;
    yyparse();
	fclose(g);
    exit(0);
    }


void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
