%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int typ_ind = 0;
int id_ind = 0;
int if_taken = 0;
int is_array = 0;
int block_taken;

int type_err = 0;

int tos = -1;
int is_read = 0;
int is_write= 0;

int is_for = 0;
int for_diff = 0;

char gtype[10];
char id_names[50][10];

char cur_relop[10];

struct arr_type{
char name[50];
char type[10];
char val[10];
int asnd;
} symbol_table[50];	//This is the symbol table

int for_list[2];

struct expr_type{
char expr[50];
char type[10];
char val[10];
} expr_typ[50];	//this is the stack

void print_symbol_table(){
	printf("\nprinting the symbol table.\n");
	for(int i = 0;i<50;i++){
		if(symbol_table[i].asnd == 0) continue;
		printf("%s %s %s %d\n",symbol_table[i].name,symbol_table[i].type,symbol_table[i].val,symbol_table[i].asnd);
	}
}

int parseBooleanExpression(char *LHS,char *RHS,char *relop,char *type){
	printf("This is the LHS of BE: %s and this is the RHS of BE: %s\n",LHS,RHS);
	if(strcmp(type,"integer")==0){
		int lhs = atoi(LHS);
		int rhs = atoi(RHS);
		printf("the be: %d %s %d\n", lhs, relop, rhs);
		if(strcmp(relop,">")==0){return lhs>rhs;}
		else if(strcmp(relop,"=")==0){return lhs == rhs;}
		else if(strcmp(relop,"<")==0){return lhs<rhs;}
		else if(strcmp(relop,"<>")==0){return lhs!=rhs;}
		else if(strcmp(relop,">=")==0){return lhs>=rhs;}
		else {return lhs<=rhs;}
	}
	else if(strcmp(type,"real")==0){
		double lhs = atof(LHS);
		double rhs = atof(RHS);
		printf("real %lf %s %lf", lhs, relop, rhs);
		if(strcmp(relop,">")==0){return lhs>rhs;}
		else if(strcmp(relop,"=")==0){
			 if(lhs == rhs) return 1;
			 return 0;
		}
		else if(strcmp(relop,"<")==0){
			printf("result: %d\n",lhs<rhs);
			if(lhs<rhs) return 1;
			return 0;
		}
		else if(strcmp(relop,"<>")==0){
			if(lhs!=rhs) return 1;
			return 0;
		}
		else if(strcmp(relop,">=")==0){
			if(lhs>=rhs) return 1;
			return 0;
		}
		else {
			if(lhs<=rhs)return 1;
			return 0;	
		}
	}
}

int modIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 % num2; // Multiply the integers
}

int divIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 / num2; // Multiply the integers
}

int multiplyIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 * num2; // Multiply the integers
}

int addIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 + num2; // Multiply the integers
}

int subIntegersInStrings(char* str1, char* str2) {
    int num1 = atoi(str1); // Convert string to integer
    int num2 = atoi(str2); // Convert string to integer
    return num1 - num2; // Multiply the integers
}

void intToString(int num, char* str) {
    sprintf(str, "%d", num); // Convert integer to string
}

double modFloatInStrings(char* str1, char* str2) {
    int num1 = atof(str1); // Convert string to integer
    int num2 = atof(str2); // Convert string to integer
    return num1 % num2; // Multiply the integers
}

double divFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 / num2; // Multiply the integers
}

double multiplyFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 * num2; // Multiply the integers
}

double addFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 + num2; // Multiply the integers
}

double subFloatInStrings(char* str1, char* str2) {
    double num1 = atof(str1); // Convert string to integer
    double num2 = atof(str2); // Convert string to integer
    return num1 - num2; // Subtract the integers
}

void floatToString(double num, char* str) {
    sprintf(str, "%lf", num); // Convert integer to string
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

void push(char *expr, char * type1, char * val){
	// printf("\nc is %s\n",c);
	++tos;

	printf("%d %s %s %s\n",tos,expr,type1,val);
    strcpy(expr_typ[tos].expr, expr);
	strcpy(expr_typ[tos].type, type1);
	strcpy(expr_typ[tos].val, val);
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

char *removeFirstLastChar(char *string){
	int len = strlen(string);
    char *result = (char *)malloc(len);
	int j = 0;
	if (len <= 2){
		string[0] = '\0';
	} else {
		for (int i = 1; i < len - 1; i ++){
			result[j++] = string[i];
		}
	}
	result[j] = '\0';

	return result;

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
	// printf("this is the name to find: %s\n",l_name);
    for (int i = 0; i < 50; i++) {
		char * t_name = removespace_lower(symbol_table[i].name);
        if (strcmp(symbol_table[i].name, nameToFind) == 0) {
            return i;
        }
    }

	printf("undeclared variable '%s'\n",nameToFind);
    return -1;
}

int asndornot(int ind){
	if(symbol_table[ind].asnd == 0){
		printf("variable '%s' used before value assigned\n",symbol_table[ind].name);
		return 0;
	}
	return 1;
}

char* getTypeForName(char name[]){
    for (int i = 0; i < 50; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type;
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

void addTyp(char name[], char type[]) {		//adding to symbol table

		char * l_name = removespace_lower(name);

		for (int i = 0; i < 50; i++) {

			char * t_name = removespace_lower(symbol_table[i].name);

			if (strcmp(t_name, l_name) == 0) {
				printf("multiple declarations of the variable '%s'\n",name);
				return;
			}
    	}

		char * type_act = removespace_lower(type);
		// printf("type actual %s\n",type_act);
        strcpy(symbol_table[typ_ind].name, name);
        strcpy(symbol_table[typ_ind].type, type_act);
        typ_ind++;

		// printf("typ_ind is %d\n",typ_ind);
}

void type_check(char* op){

	int op2_ind = -1;
	int op1_ind = -1;

	if(strcmp("new",expr_typ[tos].type)==0){
		printf("IGNORE\n");
		return;
	}
	else{
		op2_ind = pop();
	}

	if(strcmp("new",expr_typ[tos].type)!=0){
		op1_ind = pop();
	}

	if(op1_ind==-1){
		printf("IGNoring rest of the expression\n");
		return;
	}

	char * expr1 = expr_typ[op1_ind].expr;
	char * expr2 = expr_typ[op2_ind].expr;

	char * type1 = expr_typ[op1_ind].type;
	char * type2 = expr_typ[op2_ind].type;

	// printf("op2_ind: '%d'\n", op2_ind);
	// printf("op1_ind: '%d'\n", op1_ind);
	// printf("expr1: %s\n", expr1);
	// printf("expr2: %s\n", expr2);
	// printf("type1: %s\n", type1);
	// printf("type2: %s\n", type2);

	if(strcmp(type1,type2)==0){
		// push(concat(expr1,expr2,op), type1);
	}
	else{
		printf("Type error, incorrect operation '%s' attempted between '%s' and '%s'\n",op,type1,type2);

		// int nom = pop();
		char * type = expr_typ[tos].type;

		while(strcmp(type,"new")!=0){
			int nom = pop();

			printf("pop with tos = %d and name %s\n",nom,expr_typ[nom].expr);

			strcpy(type,expr_typ[nom].type);
		}

		if(strcmp("new",expr_typ[tos].type)!=0){
			// push("newexp1","new");
		}

		printf("ignoring rest of the expression\n");

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
					while(tos>=0){
					printf("top of stack is %d %s %s\n",tos,expr_typ[tos].expr,expr_typ[tos].val);
					tos--;
					}
					print_symbol_table();
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
						if(is_array == 1){
							char *base = id_names[i];
							printf("this is the base before new: %s\n",base);
							int u = pop();
							// printf("hi");
							u = atoi(expr_typ[u].val);
							int l = pop();
							l = atoi(expr_typ[l].val);
							printf("l: %d, u: %d\n",l, u);
							for(int j= l;j<=u;j++){
								char *new_id_name = malloc((strlen(base)+5));
								char *ind_string = malloc(5);
								strcpy(new_id_name,base);
								// printf("thisis garbage test: %s\n",new_id_name);
								strcat(new_id_name,"[");

								// itoa(j,ind_string,10);

								sprintf(ind_string,"%d",j);

								strcat(new_id_name,ind_string);
								strcat(new_id_name,"]");
								// printf("this is the new_id_name: %s",new_id_name);
								printf("%s: has type %s\n", new_id_name, gtype);
								addTyp(new_id_name,gtype);
							}
							is_array = 0;
						}
						else{
							printf("id_names[%d]: %s has type %s\n", i, id_names[i], gtype);
							addTyp(id_names[i],gtype);
						}
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
	| Array {is_array = 1;}ArrayOpen NumberLiteral {printf("pushing");push($<cval>4,"integer",$<cval>4);} DoubleDots NumberLiteral {push($<cval>7,"integer",$<cval>7);} ArrayClose Of Y
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
					// printf("this is the base in LHS: %s\n",id_names[id_ind-1]);
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
						if(if_taken == block_taken){
							int ind1 = pop();
							int ind2 = pop();
							
							char* val1 = expr_typ[ind1].val;
							// printf("this is val1: %s\n",val1);
							int ind = isnameinlist(expr_typ[ind2].expr);
							if(ind != -1){
								symbol_table[ind].asnd = 1;
								strcpy(symbol_table[ind].val,val1); 
							}
							// char* val2 = expr_typ[ind2].val;

							char * expr1 = expr_typ[ind1].expr;
							char * expr2 = expr_typ[ind2].expr;

							char * type = expr_typ[ind1].type;

							// int result = multiplyIntegersInStrings(val1, val2);
							
							// char resultStr[10];
							// intToString(result, resultStr);

							push(concat(expr2,"",""), type, val1);
						}
						// printf("CHECKING ASSIGNOP\n");

					}
						
						SC 

	| Read OpenParenthesis {is_read = 1;} LI {is_read = 0;} CloseParenthesis SC
	| Write OpenParenthesis {is_write = 1;} WriteBody {printf("\n");is_write = 0;} CloseParenthesis SC
	| IfStatement
	| ForLoop
	| WhileLoop
	| Block
;

I: Identifier
			{
				if(if_taken == block_taken){
					char c[50]; sprintf(c,"%s",$<cval>1);
					int ind = isnameinlist(c);
					if(ind != -1){
						int a = asndornot(ind);
						// printf("assigned: %d\n",a);
						if(a==1){
							char *type = getTypeForName(c);
							int index = isnameinlist(symbol_table[ind].name);
							push(symbol_table[ind].name,type,symbol_table[index].val);
						}
					}
				}
			}

 | Identifier ArrayOpen 
			{
				if(if_taken == block_taken){
					char c[50]; sprintf(c,"%s",$<cval>1);
					strcat(c,"[");
					push(c,"",c);
				}
			}

			ArithmeticExpression{
				if(if_taken == block_taken){
					int ind = pop();
					char *index = expr_typ[ind].val;
					ind = pop();
					char *base = expr_typ[ind].val;
					strcat(base,index);
					strcat(base,"]");
					ind = isnameinlist(base);
					push(base,getTypeForName(base),symbol_table[ind].val);
				}
			} ArrayClose

;


LI: Identifier
			{
				if(if_taken == block_taken){
					if(is_read == 1){
						char *theVariable = $<cval>1;
						int ind = isnameinlist(theVariable);
						char *type = symbol_table[ind].type;
						if(strcmp(type,"integer") == 0){
							int temp;
							scanf("%d",&temp);
							// itoa(temp, symbol_table[ind].val, 10);

							sprintf(symbol_table[ind].val,"%d",temp);

							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "real") == 0){
							double temp;
							scanf("%lf",&temp);
							sprintf(symbol_table[ind].val, "%lf", temp);
							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "char") == 0){
							char temp;
							char buffer;
							scanf("%c%c", &temp, &buffer);
							sprintf(symbol_table[ind].val, "%c", temp);
							symbol_table[ind].asnd = 1;
						}
					}
					else{
						char c[50]; sprintf(c,"%s",$<cval>1);
						char * type = getTypeForName(c);
						push(c,type,"");
					}
				// int ind = isnameinlist(c);

				// if(ind != -1 && is_read ==0){
				// 	symbol_table[ind].asnd = 1;
				// 	char * type = getTypeForName(c);
				// 	push(c,type);
				// }
				}
			}

 | Identifier ArrayOpen 
			{
				if(if_taken == block_taken){
					char c[50]; sprintf(c,"%s",$<cval>1);
					strcat(c,"[");
					// int ind = isnameinlist(c);

					// if(ind != -1 && is_read ==0){
					// 	symbol_table[ind].asnd = 1;
					// 	char * type = getTypeForName(c);
					// 	push(c,type);
					// }
					// char * type = getTypeForName(c);
					// printf("%s",type);
					push(c,"",c);
				}
			}

			ArithmeticExpression{
				if(if_taken == block_taken){
					int ind = pop();
					char *index = expr_typ[ind].val;
					ind = pop();
					char *base = expr_typ[ind].val;
					strcat(base,index);
					strcat(base,"]");
					// printf("this is the base: %s\n",base);
					if(is_read == 1){
						int ind = isnameinlist(base);
						char *type = symbol_table[ind].type;
						if(strcmp(type,"integer") == 0){
							int temp;
							scanf("%d",&temp);
							// itoa(temp, symbol_table[ind].val, 10);

							sprintf(symbol_table[ind].val,"%d",temp);
							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "real") == 0){
							double temp;
							scanf("%lf",&temp);
							sprintf(symbol_table[ind].val, "%lf", temp);
							symbol_table[ind].asnd = 1;
						}
						else if(strcmp(type, "char") == 0){
							char temp;
							char buffer;
							scanf("%c%c", &temp, &buffer);
							sprintf(symbol_table[ind].val, "%c", temp);
							symbol_table[ind].asnd = 1;
						}
					}
					else{
						push(base, getTypeForName(base), "");
					}
					// printf("this is the index: %d\n",index);
				}
			} ArrayClose

;


Block: Begin B End
	| Begin End
;

WriteBody: ArithmeticExpression{
	if(if_taken == block_taken){
		int ind = pop();
		char *type = expr_typ[ind].type;
		// printf("this is the result of the arithmetic operation: %s and this is the expression: %s\n",expr_typ[ind].val, expr_typ[ind].expr);
		if(strcmp(type,"integer") == 0 || strcmp(type,"boolean") == 0) printf("%d",atoi(expr_typ[ind].val));
		else if(strcmp(type,"real") == 0) printf("%lf", atof(expr_typ[ind].val));
		else if(strcmp(type,"char") == 0) printf("%c",expr_typ[ind].val[0]);
	}
} comma WriteBody | ArithmeticExpression {
	if(if_taken == block_taken){
		int ind = pop();
		char *type = expr_typ[ind].type;
		// printf("this is the result of the arithmetic operation: %s and this is the expression: %s\n",expr_typ[ind].val, expr_typ[ind].expr);
		if(strcmp(type,"integer") == 0 || strcmp(type,"boolean") == 0) printf("%d",atoi(expr_typ[ind].val));
		else if(strcmp(type,"real") == 0) printf("%lf", atof(expr_typ[ind].val));
		else if(strcmp(type,"char") == 0) printf("%c",expr_typ[ind].val[0]);
	}
	} |
			String {if(if_taken == block_taken)printf("%s",removeFirstLastChar($<cval>1));} | String {if(if_taken == block_taken) printf("%s",removeFirstLastChar($<cval>1));} comma WriteBody
;

ForLoop: For LI AsmtOp ArithmeticExpression  
					{
						if(if_taken == block_taken){
							int ind1 = pop();
							int ind2 = pop();
							
							char* val1 = expr_typ[ind1].val;
							// printf("this is val1: %s\n",val1);
							int ind = isnameinlist(expr_typ[ind2].expr);
							if(ind != -1){
								symbol_table[ind].asnd = 1;
								strcpy(symbol_table[ind].val,val1); 
							}
							// char* val2 = expr_typ[ind2].val;

							char * expr1 = expr_typ[ind1].expr;
							char * expr2 = expr_typ[ind2].expr;

							char * type = expr_typ[ind1].type;

							// int result = multiplyIntegersInStrings(val1, val2);
							
							// char resultStr[10];
							// intToString(result, resultStr);

							printf("inside first part loop %s %s %s\n",expr2,val1,type);

							for_list[0] = atoi(val1);

							push(concat(expr2,"",""), type, val1);
						}
						// printf("CHECKING ASSIGNOP\n");
					}

			A
;

A: To ArithmeticExpression 
					{
						if(if_taken == block_taken){
							int ind1 = pop();
							char* val1 = expr_typ[ind1].val;
							char * expr1 = expr_typ[ind1].expr;
							char * type = expr_typ[ind1].type;

							printf("inside for loop %s %s %s\n",expr1,val1,type);

							for_list[1] = atoi(val1);

							// push(concat(expr2,"",""), type, val1);
						}
						// printf("CHECKING ASSIGNOP\n");
					}

					Do
					{
						for(int i=0;i<2;i++){
							printf("for list elem %d \n",for_list[i]);
						}

						for_diff = for_list[1] - for_list[0] + 1;
						
						if(for_diff > 0){
							is_for = 1;
						}
					}

					Block 

					{

					}
					
					SC

	|
	DownTo ArithmeticExpression {//printf("OOOOOOO\n");
						// if(strcmp("new",expr_typ[tos].type)!=0){
						// 	printf("WWWWWWWW\n");
						// 	push("newexp","new");
						// }
						}
						
						Do Block SC

;


IfStatement: If BooleanExpression {
	if(if_taken == block_taken){
		int ind = pop();
		if_taken = atoi(expr_typ[ind].val);
	}
} Then {block_taken = 1;}Block X 
;

X: Else {block_taken = 0;}Block SC {block_taken = if_taken;}
	| SC {block_taken = if_taken;}

WhileLoop: While BooleanExpression Do

			 Block

			 SC
;

Expression: BooleanExpression 
		  | ArithmeticExpression
		            {
						// printf("OOOOOOO\n");
					}
;

ArithmeticExpression: T 
                    | ArithmeticExpression Plus T
						{
							if(if_taken == block_taken){
								//printf("CHECKING +\n");
								// type_check(" * ");
								int ind1 = pop();
								int ind2 = pop();
								
								char* val1 = expr_typ[ind1].val;
								char* val2 = expr_typ[ind2].val;	

								char * expr1 = expr_typ[ind1].expr;
								char * expr2 = expr_typ[ind2].expr;

								char * type = expr_typ[ind1].type;
								char resultStr[10];
								if(strcmp(type,"integer") == 0){
									int result = addIntegersInStrings(val2, val1);
									intToString(result, resultStr);
								}
								else if(strcmp(type,"real") == 0){
									double result = addFloatInStrings(val2, val1);
									floatToString(result,resultStr);
								}
								push(concat(expr2,expr1,"+"), type, resultStr);

								// if (is_write){
								// 	printf("_%s_", resultStr);
								// }
							}

						}
					| ArithmeticExpression Minus T
						{
							if(if_taken == block_taken){
								// printf("CHECKING -\n");				
								// type_check(" * ");
								int ind1 = pop();
								int ind2 = pop();
								
								char* val1 = expr_typ[ind1].val;
								char* val2 = expr_typ[ind2].val;	

								char * expr1 = expr_typ[ind1].expr;
								char * expr2 = expr_typ[ind2].expr;

								char * type = expr_typ[ind1].type;
								char resultStr[10];
								if(strcmp(type,"integer") == 0){
									int result = subIntegersInStrings(val2, val1);
									intToString(result, resultStr);
								}
								else if(strcmp(type,"real") == 0){
									double result = subFloatInStrings(val2, val1);
									floatToString(result, resultStr);
								}
								push(concat(expr2,expr1,"-"), type, resultStr);

								// if (is_write){
								// 	printf("_%s_", resultStr);
								// }
							}
						}
;
T : F
  | T Mul F 
	{
		if(if_taken == block_taken){
			// printf("CHECKING *\n");
			// type_check(" * ");
			int ind1 = pop();
			int ind2 = pop();
			
			char* val1 = expr_typ[ind1].val;
			char* val2 = expr_typ[ind2].val;	

			char * expr1 = expr_typ[ind1].expr;
			char * expr2 = expr_typ[ind2].expr;

			char * type = expr_typ[ind1].type;
			char resultStr[10];
			if(strcmp(type,"integer") == 0){
				int result = multiplyIntegersInStrings(val2, val1);
				intToString(result, resultStr);
			}
			else if(strcmp(type,"real") == 0){
				double result = multiplyFloatInStrings(val2, val1);
				floatToString(result, resultStr);
			}

			push(concat(expr2,expr1,"*"), type, resultStr);

			// if (is_write){
			// 				printf("_%s_", resultStr);
			// 			}
		}
	}
  | T Div F
	{
		if(if_taken == block_taken){
			// printf("CHECKING /\n");
			int ind1 = pop();
			int ind2 = pop();
			
			char* val1 = expr_typ[ind1].val;
			char* val2 = expr_typ[ind2].val;	

			char * expr1 = expr_typ[ind1].expr;
			char * expr2 = expr_typ[ind2].expr;

			char * type = expr_typ[ind1].type;
			char resultStr[10];
			if(strcmp(type,"integer") == 0){
				int result = divIntegersInStrings(val2, val1);
				intToString(result, resultStr);
			}
			else if(strcmp(type,"real") == 0){
				double result = divFloatInStrings(val2, val1);
				floatToString(result, resultStr);
			}
			push(concat(expr2,expr1,"/"), type, resultStr);

			// if (is_write){
			// 				printf("_%s_", resultStr);
			// 			}
		}
	}
  | T Mod F
	{
		if(if_taken == block_taken){
			// printf("CHECKING %\n");
			int ind1 = pop();
			int ind2 = pop();
			
			char* val1 = expr_typ[ind1].val;
			char* val2 = expr_typ[ind2].val;	

			char * expr1 = expr_typ[ind1].expr;
			char * expr2 = expr_typ[ind2].expr;

			char * type = expr_typ[ind1].type;

			int result = modIntegersInStrings(val2, val1);
			
			char resultStr[10];
			intToString(result, resultStr);

			push(concat(expr2,expr1,"%"), type, resultStr);
		}
	}

;

F : NumberLiteral 
		{
			if(if_taken == block_taken){
				char c[50]; 
				sprintf(c,"%s",$<cval>1);
				// printf("numlit is %s\n",c);
				char * d = removespace_lower(c);
				// printf("this is d: %s\n",d);
				push(c,"integer",d);
			}
		}
  | RealLiteral
  		{
			if(if_taken == block_taken){
				char c[50]; 
				sprintf(c,"%s",$<cval>1);
				// printf("realit is %s\n",c);
				// push(c,"real");
				char * d = removespace_lower(c);
				push(c,"real",d);
			}
		}
  | CharacterLiteral
    	{
			if(if_taken == block_taken){
				char c[50]; 
				sprintf(c,"%s",$<cval>1); 
				// printf("charlit is %s\n",c);
				// push(c,"char");
				char * d = removespace_lower(c);
				push(c,"char",d);
			}
		}
  | OpenParenthesis ArithmeticExpression CloseParenthesis 
  | I
;

BooleanExpression: BooleanT
			| BooleanExpression Or BooleanT {
				if(if_taken == block_taken){
					int ind1 = pop();
					int ind2 = pop();
					char* val1 = expr_typ[ind1].val;
					char* val2 = expr_typ[ind2].val;	
					char resultStr[10];
					char * expr1 = expr_typ[ind1].expr;
					char * expr2 = expr_typ[ind2].expr;
					printf("this is val2: %s and this is val1: %s\n",val2,val1);
					char * type = expr_typ[ind1].type;
					int result = atoi(val2) || atoi(val1);
					printf("this is the result of OR: %d\n", result);
					sprintf(resultStr,"%d",result);
					push(concat(expr2,expr1,"OR"), "boolean",resultStr);
				}
			}
;

BooleanT: BooleanF
		| BooleanT And BooleanF {
				if(if_taken == block_taken){
					int ind1 = pop();
					int ind2 = pop();
					char* val1 = expr_typ[ind1].val;
					char* val2 = expr_typ[ind2].val;	
					char resultStr[10];
					char * expr1 = expr_typ[ind1].expr;
					char * expr2 = expr_typ[ind2].expr;
					printf("this is val2: %s and this is val1: %s\n",val2,val1);
					char * type = expr_typ[ind1].type;
					int result = atoi(val2) && atoi(val1);
					printf("this is the result of AND: %d\n", result);
					sprintf(resultStr,"%d",result);
					push(concat(expr2,expr1,"AND"), "boolean",resultStr);
			}
		}
;

BooleanF: Not BooleanF {
	if(if_taken == block_taken){
		int ind = pop();
		char* val = expr_typ[ind].val;
		char resultStr[10];
		char * expr = expr_typ[ind].expr;
		printf("this is val: %s\n",val);
		char * type = expr_typ[ind].type;
		int result = !atoi(val);
		printf("this is the result of NOT: %d\n", result);
		sprintf(resultStr,"%d",result);
		push(expr, "boolean",resultStr);
	}
}

		| OpenParenthesis BooleanExpression CloseParenthesis

		| ArithmeticExpression
			RelationalOperator
			 ArithmeticExpression {
				if(if_taken == block_taken){
					char *relop = $<cval>2;
					printf("this is the relop %s\n",relop);
					int ind1 = pop();
					int ind2 = pop();
					char* val1 = expr_typ[ind1].val;
					char* val2 = expr_typ[ind2].val;	
					char resultStr[10];
					char * expr1 = expr_typ[ind1].expr;
					char * expr2 = expr_typ[ind2].expr;
					printf("this is val2: %s and this is val1: %s\n",val2,val1);
					char * type = expr_typ[ind1].type;
					int result = parseBooleanExpression(val2,val1,relop,type);
					printf("this is the result of be: %d\n", result);
					sprintf(resultStr,"%d",result);
					push(concat(expr2,expr1,relop), "boolean",resultStr);

					// if (is_write){
					// 	printf("_%s_", resultStr);
					// }
				}
			}
;

%%

void main(){
	FILE *f = fopen("input1.txt","r");
    yyin = f;
	for (int i = 0; i < 50; i++) {
        symbol_table[i].asnd = 0;  // Initializing the 'asnd' member to 0
    }
	
    yyparse();
    exit(0);
    }


void yyerror(const char *msg){
	printf("Invalid statement:\n"); 
    printf("Error at line %d: %s\n", line_num, msg);
    exit(1);
}
