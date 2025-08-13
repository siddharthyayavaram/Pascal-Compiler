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

char* curr_declare_type = NULL;

struct symbol_table{
	char* name;
}vars[50];

struct var_types_table{
	char* type;
}var_types[50];

int vars_ind = 0;
int last_var_ind = 0;

char* for_identifier = NULL;
int for_flag = 0;
%}

%union{char *cval;int ival;}

%token Type Begin End Var Prog SC comma Colon Stop Read Write Array If Then Else For While AsmtOp Not RelationalOperator OpenParenthesis CloseParenthesis String
ArrayOpen ArrayClose CharacterLiteral Of DoubleDots Do To DownTo Plus Minus Mul Mod Div Or And NumberLiteral Identifier

%%
sentence : {printf("#include <stdio.h>\n\nint main(){\n\t");} P V M {printf("\n\treturn 0;\n}\n"); return 1;}
	; 
	
P  : Prog Identifier SC
	;

V : Var LS
	;

LS : L O
	;

O: LS | /*epsilon*/

L : LHS Colon {fprintf(yyout, ":");} RHS SC {\
	for (int i = last_var_ind ; i < vars_ind; i++) {
		printf("%s %s;\n\t", curr_declare_type, vars[i].name);
		}
		last_var_ind = vars_ind;
		}
	;
	

RHS : Type {
	curr_declare_type = strdup($<cval>1);
	fprintf(yyout, "type=%s\n",$<cval>1);}
	| Array {fprintf(yyout, "array:");} ArrayOpen {fprintf(yyout, "");} NumberLiteral {fprintf(yyout, "%d,",$<ival>5);} DoubleDots {fprintf(yyout, "");} NumberLiteral {fprintf(yyout, "%d",$<ival>9);} ArrayClose {fprintf(yyout, "");} Of {fprintf(yyout, "");} {fprintf(yyout, ":");}Y {fprintf(yyout, "");}
;

Y : Type {fprintf(yyout, "type=%s\n",$<cval>1);}
	;

LHS : Identifier{fprintf(yyout, "%s",$<cval>1); vars[vars_ind].name = strdup($<cval>1); vars_ind++;} H
	;

H: comma{fprintf(yyout, ",");} LHS
	| /*epsilon*/ ;


M : Begin {fprintf(yyout, "begin\n");} J
	;

J:  B End {fprintf(yyout, "\nend");} Stop
	| End Stop {fprintf(yyout, "\nend");}

B : S K
;

K: B | /*epsilon*/

S :  I {fprintf(yyout, "");}AsmtOp{printf(" = ");fprintf(yyout, "=");} Expression {fprintf(yyout, "");} SC {printf(";\n\t");fprintf(yyout, "");} 
	| Read{fprintf(yyout, "[read:{read}]");}OpenParenthesis{fprintf(yyout, "[open_parenthesis:{(}]");} I{fprintf(yyout, "]");} CloseParenthesis{fprintf(yyout, "[close_parenthesis:{)}]");} SC {fprintf(yyout, "[SC:{;}]");}
	| Write {fprintf(yyout, "[write:{write}]");} OpenParenthesis {fprintf(yyout, "[open_parenthesis:{(}][WriteBody");} WriteBody {fprintf(yyout, "]");} CloseParenthesis {fprintf(yyout, "[close_parenthesis:{)}]");} SC {fprintf(yyout, "[SC:{;}]");}
	| IfStatement {fprintf(yyout, "]");}
	| ForLoop {fprintf(yyout, "]");}
	| WhileLoop {fprintf(yyout, "]");}
	| Block {fprintf(yyout, "]");}
;


I: {fprintf(yyout, "");}Identifier {printf("%s", $<cval>2); if (for_flag){for_identifier = strdup($<cval>2);} fprintf(yyout, "var:%s",$<cval>2);} G {fprintf(yyout, "");}
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

ForLoop: {fprintf(yyout, "[ForLoop");}For{fprintf(yyout, "[for:{for}]"); for_flag  = 1; printf("for (");} I {fprintf(yyout, "]");} AsmtOp{printf(" = ");fprintf(yyout, "[asmt_op:{:=}][ArithmeticExpression");} ArithmeticExpression {fprintf(yyout, "][E");} E {fprintf(yyout, "][ArithmeticExpression");} ArithmeticExpression {printf("; %s++){\n\t\t", for_identifier);fprintf(yyout, "]");} Do{fprintf(yyout, "[Do:{do}][Block");} Block {fprintf(yyout, "]");} SC {printf("\n\t}");for_identifier = NULL;for_flag = 0;fprintf(yyout, "[SC:{;}]");}
;

E: To {printf("; %s < ", for_identifier); fprintf(yyout, "[To:{to}]");}| DownTo {fprintf(yyout, "[DownTo: {down_to}]");}

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

OP: Plus {printf(" + ");fprintf(yyout, "[plus:{+}]");}| Minus {printf(" - ");fprintf(yyout, "[minus:{-}]");}

T : {fprintf(yyout, "[F");}F{fprintf(yyout, "]");} {fprintf(yyout, "[T1");}T1 {fprintf(yyout, "]");}
;

T1: {fprintf(yyout, "[PO");}PO {fprintf(yyout, "][F");} F {fprintf(yyout, "]");} {fprintf(yyout, "[T1");}T1{fprintf(yyout, "]");} | /*epsilon*/

PO: Mul{printf(" * ");fprintf(yyout, "[mul:{*}]");} | Div{printf(" / ");fprintf(yyout, "[div:{/}]");} | Mod{printf(" % ");fprintf(yyout, "[mod:{%}]");}

F : NumberLiteral {fprintf(yyout, "[number_literal:{%d}]",$<ival>1); printf("%d", $<ival>1);}
  | CharacterLiteral {fprintf(yyout, "[character_literal:{%s}]",$<cval>1);}
  | OpenParenthesis {printf("(");fprintf(yyout, "[open_parenthesis:{(}][ArithmeticExpression");} ArithmeticExpression {fprintf(yyout, "]");} CloseParenthesis {printf(")");fprintf(yyout, "[close_parenthesis:)]");} 
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

X1: RelationalOperator{printf(" %s ", $<cval>1);fprintf(yyout, "[relational_operator:{%s}][ArithmeticExpression",$<cval>1);} ArithmeticExpression {fprintf(yyout, "]");} | /*epsilon*/ 

%%

void main(){
	FILE *f = fopen("input.txt","r");
    yyin = f;
	FILE *g = fopen("op.txt","w");
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
