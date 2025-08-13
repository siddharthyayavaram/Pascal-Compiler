%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count=0;
int qind=0;
int tos=-1;
int temp_char=0;
int ltos = -1;
int ltemp = 0;
int typ_ind = 0;
int id_ind = 0;

char gtype[10];
char id_names[25][10];

struct quadruple{
char operator[5];
char operand1[10];
char operand2[10];
char result[10];
} quad[25];

struct stack{
char c[10]; } stk[25];

struct labels{
char c[10]; } lbl[25];

struct arr_type{
char name[10];
char type[10];
} typ[25];


char* getTypeForName(char name[]) {
    for (int i = 0; i < 25; i++) {
        if (strcmp(typ[i].name, name) == 0) {
            return typ[i].type;
        }
    }
    return NULL;
}

int getTypeIntegerValue(char type[]) {
    char lowercaseType[10];
    int i = 0;
    while (type[i] != '\0' && type[i] != ' ' && i < 10) {
        lowercaseType[i] = tolower(type[i]);
        i++;
    }
    lowercaseType[i] = '\0';

	// printf("lowercase type is |%s|\n",lowercaseType);

    if (strcmp(lowercaseType, "integer") == 0) {
        return 2;
    } else if (strcmp(lowercaseType, "real") == 0) {
        return 4;
    } else if (strcmp(lowercaseType, "boolean") == 0 || strcmp(lowercaseType, "char") == 0) {
        return 1;
    } else {
        return -1;
    }
}

void addTyp(char name[], char type[]) {
        strcpy(typ[typ_ind].name, name);
        strcpy(typ[typ_ind].type, type);
        typ_ind++;
}

void addQuadruple(char op1[], char op[], char op2[], char result[]){
    strcpy(quad[qind].operator, op ? op : "");
    strcpy(quad[qind].operand1, op1 ? op1 : "");
    strcpy(quad[qind].operand2, op2 ? op2 : "");
    strcpy(quad[qind].result, result);
    qind++;
}

void display_Quad(){
    printf("%s ", quad[qind-1].result);
    printf("= ");
    printf("%s ", quad[qind-1].operand1);
    if (strlen(quad[qind-1].operator) > 0) {
        printf("%s ", quad[qind-1].operator);
    }
    if (strlen(quad[qind-1].operand2) > 0) {
        printf("%s ", quad[qind-1].operand2);
    }
    printf("\n");
}

void push(char *c){
	// printf("\nc is %s\n",c);
    strcpy(stk[++tos].c, c);
}

char* pop(){
    char* c=stk[tos].c;
    tos=tos-1;
    return c;
}

void lpush(char *c){
    strcpy(lbl[++ltos].c, c);
}

char* lpop(){
    char* c=lbl[ltos].c;
    ltos=ltos-1;
    return c;
}

extern FILE* yyin;
extern int line_num;
void yyerror(const char *msg);

%}

%union{char *cval;int ival;}

%token  Prog SC Identifier Var
%%
sentence : {printf("[sentence[");printf("P[");} P {printf("]][V[");} V {printf("]][M[");}M {printf("]]");printf("]"); printf(" Valid Sentence\n") ; return 1; }
	; 

P  : Prog Identifier SC {printf("prog:{%s}][var:{%s}][SC:{%s}]",$<cval>1, $<cval>2, $<cval>3);}
	;

V : Var {printf("[var:{%s}]LS[]",$<cval>1);} LS {printf("]]");}

LS : L LS
	| L
	;
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
