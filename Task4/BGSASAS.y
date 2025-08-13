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

char gtype[50];
char id_names[25][50];

int is_read = 0;
int is_write= 0;

struct quadruple{
char operator[5];
char operand1[50];
char operand2[50];
char result[50];
} quad[25];

struct stack{
char c[50]; } stk[25];

struct labels{
char c[50]; } lbl[25];

struct arr_type{
char name[50];
char type[50];
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
    char lowercaseType[50];
    int i = 0;
    while (type[i] != '\0' && type[i] != ' ' && i < 50) {
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

%token Type Begin End Var Prog SC comma Colon Stop Read Write Array If Then Else For While AsmtOp Not RelationalOperator OpenParenthesis CloseParenthesis String
ArrayOpen ArrayClose CharacterLiteral Of DoubleDots Do To DownTo Plus Minus Mul Mod Div Or And NumberLiteral Identifier RealLiteral

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
				 {
					for (int i = 0; i < id_ind; i++) {

						// push the LOWERCASE NAMES 
						// printf("id_names[%d]: %s has type %s\n", i, id_names[i], gtype);
						addTyp(id_names[i],gtype);
					}
					memset(id_names, 0, sizeof(id_names));
    				memset(gtype, 0, sizeof(gtype));
					id_ind = 0;
				 }
	;

RHS : Type 
		{																	
			char c[50]; 
			sprintf(c,"%s",$<cval>1);
			strcpy(gtype, c);
																		
		}
	| Array ArrayOpen NumberLiteral DoubleDots NumberLiteral ArrayClose Of Y
;

Y : Type 
		{
			char c[50]; 
			sprintf(c,"%s",$<cval>1);
			// printf("%s\n",c);
			strcpy(gtype, c);
		}
	;

LHS : Identifier comma 
					{
					char c[50]; 
					sprintf(c,"%s",$<cval>1);
					strcpy(id_names[id_ind++], c);
					}
					
					LHS
	| Identifier
				{
					char c[50]; 
					sprintf(c,"%s",$<cval>1);
					strcpy(id_names[id_ind++], c);
				}
	;

M : Begin B End Stop
	|Begin End Stop
	;

B : S B
	| S
;

/*

remember I is pushing onto stk
need to pop after read / write

*/

S :  I AsmtOp Expression SC 
					{
						char *op1 = pop();
						// printf("op1 is %s\n",op1);
						addQuadruple(op1, NULL, NULL, pop());
						display_Quad();
					}

	| Read OpenParenthesis {is_read = 1; printf("//Read statement here\n");} I {is_read = 0;} CloseParenthesis SC
	| Write OpenParenthesis {is_write = 1;printf("//Write statement here\n");} WriteBody {is_write = 0;} CloseParenthesis SC
	| IfStatement
	| ForLoop
	| WhileLoop
	| Block
;


I: Identifier {char c[50]; sprintf(c,"%s",$<cval>1); 
				if(is_write == 0 && is_read == 0)
					push(c);
				}
 | Identifier ArrayOpen 
 			{
				char c[50]; 
				sprintf(c,"%s",$<cval>1);
				// printf("%s\n",c);
				if(is_write == 0 && is_read == 0)
					push(c);
			}
			ArithmeticExpression ArrayClose
			{
				if(is_write == 0 && is_read == 0){
					char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
					strcat(str1, str);

					char *t0 = pop();
					char *arr_name = pop();

					char * type_temp = getTypeForName(arr_name);
					// printf("type is %s\n",type_temp);

					int sz =getTypeIntegerValue(type_temp);

					printf("%s = %d * %s\n",str1,sz,t0);

					char str2[5], str3[5]="t"; sprintf(str2,"%d", temp_char++);
					strcat(str3, str2);

					printf("%s = &%s\n",str3,arr_name);

					char str4[5], str5[5]="t"; sprintf(str4,"%d", temp_char++);
					strcat(str5, str4);

					printf("%s = %s + %s\n",str5,str1,str3);

					char new_str[6];
					new_str[0] = '*';
					strcpy(new_str + 1, str5);
					push(new_str);
				}
			}
;


Block: Begin B End
	| Begin End
;

WriteBody: I comma WriteBody | I
			| String comma WriteBody | String
;

ForLoop: For I AsmtOp ArithmeticExpression To {char *op1 = pop();
											// printf("op1 is %s\n",op1);
											char *i = pop();
											addQuadruple(op1, NULL, NULL,i);
											display_Quad();
											push(i);}
							
						ArithmeticExpression {char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
												strcat(str1, str);
												lpush(str1);
												printf("%s: ",str1);
												char *sec = pop();
												char *fir = pop();
												push(fir);
												char str3[5], str4[5]="L"; sprintf(str3,"%d", ltemp++);
												strcat(str4, str3); lpush(str4);
												printf("if %s <= %s goto %s\n",fir,sec,str4);
												char str5[5], str6[5]="L"; sprintf(str5,"%d", ltemp++);
												strcat(str6, str5); lpush(str6);
												printf("goto %s: \n",str6);
												printf("%s: ",str4);
											}
						
						Do Block SC      { 
											char *fir = pop();
											printf("%s = %s + 1\n",fir,fir);
											char *l2 = lpop();
											char *l1 = lpop();
											char *l0 = lpop();
											printf("goto %s \n",l0);
											printf("%s: ",l2);
										}

	   | For I AsmtOp ArithmeticExpression DownTo {char *op1 = pop();
											// printf("op1 is %s\n",op1);
											char *i = pop();
											addQuadruple(op1, NULL, NULL,i);
											display_Quad();
											push(i);}
							
						ArithmeticExpression {char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
												strcat(str1, str);
												lpush(str1);
												printf("%s: ",str1);
												char *sec = pop();
												char *fir = pop();
												push(fir);
												char str3[5], str4[5]="L"; sprintf(str3,"%d", ltemp++);
												strcat(str4, str3); lpush(str4);
												printf("if %s >= %s goto %s\n",fir,sec,str4);
												char str5[5], str6[5]="L"; sprintf(str5,"%d", ltemp++);
												strcat(str6, str5); lpush(str6);
												printf("goto %s: \n",str6);
												printf("%s: ",str4);
											}
						
						Do Block SC      { 
											char *fir = pop();
											printf("%s = %s - 1\n",fir,fir);
											char *l2 = lpop();
											char *l1 = lpop();
											char *l0 = lpop();
											printf("goto %s \n",l0);
											printf("%s: ",l2);
										}
;

/* 
left factor if statement
{print skip block label}

IfStatement: If BooleanExpression Then {check if t2 is 1 put labels to skip block if needed} Block {print skip block label} SC
		   | If BooleanExpression Then Block Else Block SC
;

*/

IfStatement: If BooleanExpression Then 
					{
						char *t4 = pop();

						char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
						strcat(str1, str);

						printf("if %s = 0 goto %s\n",t4,str1);
						// str1 is L3

						lpush(str1);
					}
					
					Block 
					
					{
						// char *l3  = lpop();
						// printf("%s: ",l3);
					}

					X
;

X: Else 
		{
			char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
			strcat(str1, str);

			// printf("if %s = 0 goto %s\n",t4,str1);
			// str1 is L3

			printf("goto %s \n",str1);

			char *l3  = lpop();
			printf("%s: ",l3);

			lpush(str1);
		} 
  Block 

  SC  
		{
			char *l4  = lpop();
			printf("%s: ",l4);
		}


| SC

		{
			char *l3  = lpop();
			printf("%s: ",l3);
		}

WhileLoop: While BooleanExpression Do
			{
					char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
					strcat(str1, str);
					
					printf("%s: ",str1);
					lpush(str1);

					char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
					strcat(str3,str2);

					lpush(str3);

					char *t0 = pop();

					printf("if %s = 0 goto %s\n",t0,str3);
			}

			 Block

			 {
				char *l1 = lpop();
				char *l0 = lpop();

				printf("goto %s\n",l0);
				printf("%s: ",l1);
			 }
			 
			 SC
;

Expression: BooleanExpression 
		  | ArithmeticExpression
;

ArithmeticExpression: T 
                    | ArithmeticExpression Plus T 
								{
									if(is_write == 0 && is_read == 0){
										char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
										strcat(str1, str); addQuadruple(pop(), "+", pop(), str1);
										display_Quad(); push(str1);
									}
													
								}
					| ArithmeticExpression Minus T 
								{
									if(is_write == 0 && is_read == 0){
										char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
										strcat(str1, str); addQuadruple(pop(), "-", pop(), str1);
										display_Quad(); push(str1);
									}
								}
;

T : F
  | T Mul F {
			if(is_write == 0 && is_read == 0){
				char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
				strcat(str1, str); addQuadruple(pop(), "*", pop(), str1);
				display_Quad(); push(str1);
			}
			}
  | T Div F {
			if(is_write == 0 && is_read == 0){
				char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
				strcat(str1, str); addQuadruple(pop(), "/", pop(), str1);
				display_Quad(); push(str1);
			}
			}
  | T Mod F {
			if(is_write == 0 && is_read == 0){
				char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
				strcat(str1, str); addQuadruple(pop(), "%", pop(), str1);
				display_Quad(); push(str1);
			}
			}
;

F : NumberLiteral {if(is_write == 0 && is_read == 0){
					char c[10]; sprintf(c,"%s",$<cval>1); push(c);
					}}
  | CharacterLiteral {
	if(is_write == 0 && is_read == 0){
		char c[10]; sprintf(c,"%s",$<cval>1); push(c);
	}}
  | RealLiteral {if(is_write == 0 && is_read == 0){
				char c[10]; sprintf(c,"%s",$<cval>1); push(c);
	}}
  | OpenParenthesis ArithmeticExpression CloseParenthesis 
  | I
;

BooleanExpression: BooleanT
			| BooleanExpression Or BooleanT
				{
					char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
					strcat(str1, str);

					printf("%s = 0\n",str1);   // t4 value of expre with or

					char *t3 = pop();
					char *t2 = pop();

					char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
					strcat(str3, str2);
					// lpush(str3);
					
					printf("if %s = 1 goto %s\n",t2,str3);
					printf("if %s = 1 goto %s\n",t3,str3);

					char str4[5], str5[5]="L"; sprintf(str4,"%d", ltemp++);
					strcat(str5, str4);

					printf("goto %s\n",str5);

					printf("%s: ",str3);	  // i know and condn value at L1
					printf("%s = 1\n",str1);

					printf("%s: ",str5);   //l2

					push(str1);   // t4 is now there in the stack

				}
;

BooleanT: BooleanF
		| BooleanT And BooleanF { //label L0 make , t2 = 0,  if if (2 pops), push t2, t2 = 1, L0 print, and label L0
								char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
								strcat(str1, str);

								printf("%s = 0\n",str1);
								
								char *t1 = pop(); 
								// printf("\nt1 is %s\n",t1);

								char *t0 = pop(); 
								// printf("\nt0 is %s\n",t0);

								// printf("\nt0 is %s\n",t0);

								char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
								strcat(str3, str2);
								// lpush(str3);

								// printf("\nt1 is %s\n",t1);
								// printf("\nt0 is %s\n",t0);
									
								printf("if %s = 0 goto %s\n",t0,str3);
								printf("if %s = 0 goto %s\n",t1,str3);
								printf("%s = 1\n",str1);

								printf("%s: ",str3);	  // i know and condn value at L0
								push(str1);   // t2 is now there in the stack
								}
;

BooleanF: Not BooleanF
			{ 
				char * temp = pop();

				char str[5], str1[5]="L"; sprintf(str,"%d", ltemp++);
				strcat(str1, str);

				printf("if %s = 0 goto %s\n",temp,str1);

				char str2[5], str3[5]="L"; sprintf(str2,"%d", ltemp++);
				strcat(str3, str2);

				printf("%s = 0\n",temp);
				printf("goto %s\n",str3);

				printf("%s: ",str1);
				printf("%s = 1\n",temp);
				printf("%s: \n",str3);

				push(temp);

			}

		| OpenParenthesis BooleanExpression CloseParenthesis

		| ArithmeticExpression RelationalOperator ArithmeticExpression 

		{char str[5], str1[5]="t"; sprintf(str,"%d", temp_char++);
		strcat(str1, str);
		addQuadruple(pop(), $<cval>2, pop(), str1);
		display_Quad(); push(str1);}

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
