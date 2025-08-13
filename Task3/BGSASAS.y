%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int typ_ind = 0;
int id_ind = 0;

int type_err = 0;

int arr = 0;

int tos = -1;
int is_read = 0;
int is_write= 0;

char gtype[10];
char id_names[50][10];

char cur_relop[10];

struct arr_type{
char name[50];
char type[10];
int asnd;
int is_array;
int arr_ind[50];
} typ[50];

struct expr_type{
char expr[50];
char type[10];
} expr_typ[50];

int check_type_compatible(char* type1,char* type2) {
    if (strcmp(type1, type2) == 0) {
        return 1; // Types are identical, so they are compatible
    } else if ((strcmp(type1, "integer") == 0 && strcmp(type2, "real") == 0) ||
               (strcmp(type1, "real") == 0 && strcmp(type2, "integer") == 0)) {
        return 2; // Integer and real types are compatible
    } else {
        return 0; // Types are not compatible
    }
}


char* concat(char* expr1, char* expr2,char* delimiter) {
    size_t len1 = strlen(expr1);
    size_t len2 = strlen(expr2);
    size_t delimLen = strlen(delimiter);
    size_t totalLen = len1 + delimLen + len2 + 1;
    char* result = (char*)malloc(totalLen);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strcpy(result, expr1);
    strcat(result, delimiter);
    strcat(result, expr2);
    return result;
}

void push(char *expr, char * type1){
	// printf("\nc is %s\n",c);
	++tos;

	// printf("|%d| |%s| |%s|\n",tos,expr,type1);
    strcpy(expr_typ[tos].expr, expr);
	strcpy(expr_typ[tos].type, type1);
}

int pop(){
	// printf("tos before pop is %d\n",tos);
	if(tos == -1){
		// printf("here");
		return -1;
	}
    char* c=expr_typ[tos].expr;
    tos=tos-1;
    return tos+1;
}

char* removespace_lower(const char *str) {
    int len = strlen(str);
    char *result = (char *)malloc(len + 1);
    if (result == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            result[j++] = tolower(str[i]);
        }
    }
    result[j] = '\0';
    return result;
}

int isnameinlist(char *nameToFind) {

	char *l_name = removespace_lower(nameToFind);

    for (int i = 0; i < 50; i++) {
		char * t_name = removespace_lower(typ[i].name);
        if (strcmp(typ[i].name, nameToFind) == 0) {
            return i;
        }
    }

	printf("undeclared variable '%s'\n",nameToFind);
    return -1;
}

int asndornot(int ind){
	if(typ[ind].asnd == 0){
		printf("variable '%s' used before value assigned\n",typ[ind].name);
		return 0;
	}
	return 1;
}


char* getTypeForName(char name[]){
    for (int i = 0; i < 50; i++) {
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

void addTyp(char name[], char type[], int arr) {

		char * l_name = removespace_lower(name);

		for (int i = 0; i < 50; i++) {

			char * t_name = removespace_lower(typ[i].name);

			if (strcmp(t_name, l_name) == 0) {
				printf("multiple declarations of the variable '%s'\n",name);
				return;
			}
    	}

		char * type_act = removespace_lower(type);
		// printf("type actual %s\n",type_act);

        strcpy(typ[typ_ind].name, name);
        strcpy(typ[typ_ind].type, type_act);

		typ[typ_ind].is_array = arr;
        typ_ind++;

		// printf("typ_ind is %d\n",typ_ind);
}

void type_check(char* op){

	int op2_ind = -1;
	int op1_ind = -1;

	if(strcmp("new",expr_typ[tos].type)==0){
		// printf("IGNORE\n");
		return;
	}
	else{
		op2_ind = pop();
	}

	if(strcmp("new",expr_typ[tos].type)!=0){
		op1_ind = pop();
	}

	if(op1_ind==-1){
		// printf("IGNoring rest of the expression\n");
		return;
	}

	char * expr1 = expr_typ[op1_ind].expr;
	char * expr2 = expr_typ[op2_ind].expr;

	char * type1 = expr_typ[op1_ind].type;
	char * type2 = expr_typ[op2_ind].type;

	if(strcmp(op," % ")==0){
		if(!strcmp(type1,"integer")==0 || !strcmp(type2,"integer")==0){
			printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);
			return;
		}
	}

	if(strcmp(op," / ")==0){
		if(strcmp(type1,"integer")==0 && strcmp(type2,"integer")==0){
			strcpy(type1,"real");
		}
	}

	if(strcmp(op," := ")==0){
		// printf("HHIIIII %s %s\n",type1,type2);
		if(strcmp(type1,"integer")==0 && strcmp(type2,"real")==0){
			printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);
			return;
		}
	}

	// printf("op2_ind: '%d'\n", op2_ind);
	// printf("op1_ind: '%d'\n", op1_ind);
	// printf("expr1: %s\n", expr1);
	// printf("expr2: %s\n", expr2);
	// printf("type1: %s\n", type1);
	// printf("type2: %s\n", type2);

	if(check_type_compatible(type1,type2)==2){
		push(concat(expr1,expr2,op), "real");
	}

	else if(check_type_compatible(type1,type2)==1 && strcmp(op," relop ")==0){
		push(concat(expr1,expr2,op), "boolean");
	}

	else if(strcmp("boolean",type1)==0 && strcmp(type2,"boolean")==0 && strcmp(op," relop ")!=0 && strcmp(op," := ")!=0){
		printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);
	}

	else if(check_type_compatible(type1,type2)==1){
		push(concat(expr1,expr2,op), type1);
	}

	else{
		printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);

		// int nom = pop();
		char * type = expr_typ[tos].type;

		while(strcmp(type,"new")!=0){
			int nom = pop();

			// printf("pop with tos = %d and name %s\n",nom,expr_typ[nom].expr);

			strcpy(type,expr_typ[nom].type);
		}

		if(strcmp("new",expr_typ[tos].type)!=0){
			push("newexp1","new");
		}

		// printf("ignoring rest of the expression\n");

	}
}


extern FILE* yyin;
extern int line_num;
void yyerror(const char *msg);

%}

%union{char *cval;int ival;}

%token Type Begin End Var Prog SC comma Colon Stop Read Write Array If Then Else For While AsmtOp Not RelationalOperator OpenParenthesis CloseParenthesis String
ArrayOpen ArrayClose CharacterLiteral Of DoubleDots Do To DownTo Plus Minus Mul Mod Div Or And NumberLiteral Identifier RealLiteral

%%
sentence : P V M { printf("Valid Syntax\n");
					return 1; 
				}
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
						// printf("array ? %d\n",arr);
						addTyp(id_names[i],gtype,arr);
					}
					memset(id_names, 0, sizeof(id_names));
    				memset(gtype, 0, sizeof(gtype));
					id_ind = 0;
					arr = 0;
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
			arr = 1;
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


S :  LI AsmtOp Expression
					{
						// printf("CHECKING ASSIGNOP\n");
						if(strcmp("newexp",expr_typ[tos].expr)==0){
							int x =pop();
							// printf("%d\n",x);
							type_check(" := ");
						}
						
						push("newexp","new");	
					}
						
						SC 

	| Read OpenParenthesis {is_read = 1;} LI {is_read = 0;} CloseParenthesis SC
	| Write OpenParenthesis {is_write = 1;} WriteBody {is_write = 0;} CloseParenthesis SC
	| IfStatement
	| ForLoop
	| WhileLoop
	| Block
;

I: Identifier
			{
				char c[50]; sprintf(c,"%s",$<cval>1);
				int ind = isnameinlist(c);

				if(ind != -1){
					int a = asndornot(ind);

					if(a==1 && is_write ==0){
						char * type = getTypeForName(c);
						push(c,type);
					}
				}
			}


 | Identifier ArrayOpen 
			{
				char c[50]; sprintf(c,"%s",$<cval>1);
				int ind = isnameinlist(c);

				if(ind != -1 && typ[ind].is_array==1){
					int a = asndornot(ind);

					if(a==1 && is_write ==0){
						char * type = getTypeForName(c);
						push(c,type);
					}
				}

				if(typ[ind].is_array==0){
					printf("Cannot index non-array variables\n");
				}
			}

			ArithmeticExpression
			{
				if(is_write==0){
					int ind = pop();
					// printf("result of index of array is %s with type %s\n",expr_typ[ind].expr,expr_typ[ind].type);

					if(strcmp(expr_typ[ind].type,"integer") != 0){
						printf("Type error, Array index expression not of integer type\n");
					}
				}
			} ArrayClose

;


LI: Identifier
			{
				char c[50]; sprintf(c,"%s",$<cval>1);
				int ind = isnameinlist(c);

				if(ind != -1 && is_read ==0){
					typ[ind].asnd = 1;
					char * type = getTypeForName(c);
					push(c,type);
				}
			}

 | Identifier ArrayOpen 
			{
				char c[50]; sprintf(c,"%s",$<cval>1);
				int ind = isnameinlist(c);

				if(ind != -1 && typ[ind].is_array==1 && is_read ==0){
					typ[ind].asnd = 1;
					char * type = getTypeForName(c);
					push(c,type);
				}

				if(typ[ind].is_array==0){
					printf("Cannot index non-array variables\n");
				}

			}

			ArithmeticExpression
			{
				int ind = pop();
				// printf("result of index of array is %s with type %s\n",expr_typ[ind].expr,expr_typ[ind].type);

				if(strcmp(expr_typ[ind].type,"integer") != 0){
					printf("Type error, Array index expression not of integer type\n");
				}
			} ArrayClose

;


Block: Begin B End
	| Begin End
;

WriteBody: ArithmeticExpression comma WriteBody | ArithmeticExpression
			| String comma WriteBody | String
;

ForLoop: For LI AsmtOp ArithmeticExpression  
					{
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}
						// printf("CHECKING FORASSIGNOP\n");
						if(strcmp("newexp",expr_typ[tos].expr)==0){
							int x =pop();
							// printf("%d\n",x);
							type_check(" := ");
						}
						
						push("newexp","new");	
					}

			A
;

A: To ArithmeticExpression 
					{
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}}

						Do Block SC

	|
	DownTo ArithmeticExpression {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}}
						
						Do Block SC

;


IfStatement: If BooleanExpression Then 
					
					Block 
					
					X
;

X: Else Block SC 
	| SC

WhileLoop: While BooleanExpression Do

			 Block

			 SC
;

Expression: BooleanExpression 
					{
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}
					}
		  | ArithmeticExpression
		            {
						// printf("OOOOOOO\n");
						if(strcmp("new",expr_typ[tos].type)!=0){
							// printf("WWWWWWWW\n");
							push("newexp","new");
						}
					}
;

ArithmeticExpression: T 
                    | ArithmeticExpression Plus T
						{
							// printf("CHECKING +\n");
							type_check(" + ");
						}

					| ArithmeticExpression Minus T
						{
							// printf("CHECKING -\n");
							type_check(" - ");
						}
;

T : F
  | T Mul F 
	{
		// printf("CHECKING *\n");
		type_check(" * ");
	}
  | T Div F
	{
		// printf("CHECKING /\n");
		type_check(" / ");
	}
  | T Mod F
	{
		// printf("CHECKING %\n");
		type_check(" % ");
	}

;

F : NumberLiteral 
		{
			char c[50]; 
			sprintf(c,"%s",$<cval>1);
			// printf("numlit is %s\n",c);
			push(c,"integer");
		}
  | RealLiteral
  		{
			char c[50]; 
			sprintf(c,"%s",$<cval>1);
			// printf("realit is %s\n",c);
			push(c,"real");
		}
  | CharacterLiteral
    	{
			char c[50]; 
			sprintf(c,"%s",$<cval>1); 
			// printf("charlit is %s\n",c);
			push(c,"char");
		}
  | OpenParenthesis ArithmeticExpression CloseParenthesis 
  | I
;

BooleanExpression: BooleanT
			| BooleanExpression Or BooleanT
			{
				// printf("CHECKING AND\n");
				type_check(" relop ");
			}
;

BooleanT: BooleanF
		| BooleanT And BooleanF
			{
				// printf("CHECKING AND\n");
				type_check(" relop ");
			}
;

BooleanF: Not BooleanF

		| OpenParenthesis BooleanExpression CloseParenthesis

		| ArithmeticExpression
			RelationalOperator
				/* {
					char c[50];
					sprintf(c,"%s",$<cval>1);
					printf("c is %s\n",c);
					strcpy(cur_relop,c);
				} */
			 ArithmeticExpression
			 		{
						// printf("CHECKING RELOP\n");
						type_check(" relop ");
						// printf("OOOOOOO\n");
						// if(strcmp("new",expr_typ[tos].type)!=0){
						// 	printf("WWWWWWWW\n");
						// 	push("newexp","new");
						// }
					}
		
		| I
;

%%

int main(int argc, char *argv[]){

    char* filename;

    filename=argv[1];

    printf("\n");

    yyin=fopen(filename, "r");

	for (int i = 0; i < 50; i++) {
        typ[i].asnd = 0;  // Initializing the 'asnd' member to 0
		typ[i].is_array = 0;
		for(int j=0;j<50;j++){
			typ[i].arr_ind[j] = 0;
		}
    }

	push("newexp","new");
    yyparse();

    return 0;

}

void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
