%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minic_ast.h"

extern FILE *yyin;

int yylex(void);
void yyerror(char *s);
Node *root;
%}

%union{
	char* string;
	struct nodeType *nPtr;
}
/* Terminial */
%token <string> TINTEGER
%token <string> TIDENTITY
%token TINT TVOID						/* qualifier */
%token TCONST						/* specifier */
%token TWHILE TFOR					/* 반복문 */
%token TIF TSWITCH					/* 조건문 */
%token TCONTINUE TBREAK TRETURN		/* 흐름문 */
%token TCASE TDEFAULT					/* TCASE문 */
%token TINC TDEC						/* ++, -- */
%token TADDASSIGN TSUBASSIGN TMULASSIGN TMODASSIGN TDIVASSIGN /* +=, -=, *=, %=, /= */
%token TOR TAND						/* ||, && */
%nonassoc TIFX
%nonassoc TELSE					
%left TGE TLE TEQ TNE '>' '<'			/* >= <= == != */
%left '+' '-'
%left '*' '/'
%nonassoc TUMINUS
/* NonTerminal */
%type <nPtr> translation_unit external_dcl function_def function_header dcl_spec dcl_specifiers
	dcl_specifier type_qualifier type_specifier function_name formal_param opt_formal_param
	formal_param_list param_dcl compound_st opt_dcl_list declaration_list declaration init_dcl_list
	init_declarator declarator opt_number opt_stat_list statement_list statement expression_st 
	opt_expression if_st while_st return_st for_st for_dcl for_dcl_list for_exp for_inc for_inc_list
	continue_st break_st switch_st switch_case_list switch_case loop_st condition_st flow_st expression
	assignment_exp logical_or_exp logical_and_exp equality_exp relational_exp additive_exp
	multiplicative_exp unary_exp postfix_exp opt_actual_param actual_param_list actual_param primary_exp

%%
mini_c:
	translation_unit	{ 
		root = buildTree(PROGRAM, $1);
	}
	;
translation_unit:
	external_dcl{
		$$ = $1;
	}
	| translation_unit external_dcl	{
		appendBrother($1,$2);
		$$ = $1;
	}
	;
external_dcl:
	function_def{
		$$ = $1;
	}
	| declaration{
		$$ = $1;
	}
	;
function_def:
	function_header compound_st	{
		appendBrother($1, $2);
		$$ = buildTree(FUNC_DEF, $1);
	}
	;
function_header:
	dcl_spec function_name formal_param {
		appendBrother($1, $2);
		appendBrother($2, $3);
		$$ = buildTree(FUNC_HEAD, $1);

	}
	;
dcl_spec:
	dcl_specifiers	{
		$$ = buildTree(DCL_SPEC,$1);
	}
	;
dcl_specifiers:
	 dcl_specifier {
		$$ = $1;
	}
	| dcl_specifiers dcl_specifier {
		appendBrother($1, $2);
		$$ = $1;
	}
	;
dcl_specifier:
	type_qualifier	{ $$ = $1; }
	| type_specifier	{ $$ = $1; }
	;
type_qualifier:
	TCONST {
		$$ = buildTree(CONST_TYPE, NULL);
	}
	;
type_specifier:
	TINT{
		$$ = buildTree(INT_TYPE, NULL);
	}
	| TVOID{
		$$ = buildTree(VOID_TYPE, NULL);
	}
	;
function_name:
	TIDENTITY{
		$$ = buildNode(IDENT,$1);
	}
	;
formal_param:
	'(' opt_formal_param ')'{
		$$ = buildTree(FORMAL_PARA, $2);
	}
	;
opt_formal_param:
	formal_param_list { $$ = $1; }
	| { $$ = NULL; } 
	;
formal_param_list:
	param_dcl { $$ = $1; }
	| formal_param_list ',' param_dcl {
		appendBrother($1, $3);
		$$ = $1;
	}
	;
param_dcl:
	dcl_spec declarator {
		appendBrother($1, $2);
		$$ = buildTree(PARAM_DCL, $1);
	}
	;
compound_st:
	'{' opt_dcl_list opt_stat_list '}' {
		appendBrother($2, $3);
		$$ = buildTree(COMPOUND_ST, $2);
	}
	;
opt_dcl_list:
	declaration_list { $$ = buildTree(DCL_LIST, $1); }
	| { $$ = buildTree(DCL_LIST,NULL); }
	;
declaration_list:
	declaration { $$ = $1; }
	| declaration_list declaration { 
		appendBrother($1, $2);
		$$ = $1;
	}
	;
declaration:
	dcl_spec init_dcl_list ';' {
		appendBrother($1, $2);
		$$ = buildTree(DCL, $1);
	}
	;
init_dcl_list:
	init_declarator { $$ = $1; }
	| init_dcl_list ',' init_declarator { 
		appendBrother($1, $3);
		$$ = $1;
	}
	;
init_declarator:
	declarator { $$ = $1; }
	| declarator '=' TINTEGER {
		appendBrother($1->son, buildNode(NUMBER, $3)); 
	}
	;
declarator:
	TIDENTITY {
		Node* ptr = buildTree(SIMPLE_VAR, buildNode(IDENT, $1));
		$$ = buildTree(DCL_ITEM,ptr);
	}
	| TIDENTITY '[' opt_number ']' {
		Node* ptr = buildNode(IDENT, $1);
		appendBrother(ptr,$3);
		$$ = buildTree(DCL_ITEM, buildTree(ARRAY_VAR, ptr));
	}
	;
opt_number:
	TINTEGER { $$ = buildNode(NUMBER, $1); }
	| { $$ = NULL; }
	;
opt_stat_list:
	statement_list { $$ = buildTree(STAT_LIST, $1); }
	| { $$ = NULL; } 
	;
statement_list:
	statement { $$ = $1; }
	| statement_list statement { 
		appendBrother($1, $2);
		$$ = $1; 
	}
	;
for_st:
	TFOR '(' for_dcl ';' for_exp ';' for_inc')' statement {
		appendBrother($3, $5);
		appendBrother($5, $7);
		appendBrother($7, $9);
		$$ = buildTree(FOR_ST,$3);
	}
	;
for_dcl:
	for_dcl_list {
		$$ = buildTree(FOR_DCL, $1);
	}
	| { $$ = buildTree(FOR_DCL,NULL); } 
	;
for_dcl_list:
	for_dcl_list ',' init_declarator {
		appendBrother($1, $3);
		$$ = $1;	
	}
	| init_declarator{
		$$ = $1;
	}
	;
for_exp:
	logical_or_exp {
		$$ = buildTree(FOR_EXP, $1);
	}
	| { $$ = buildTree(FOR_EXP, NULL); }
	;
for_inc:
	for_inc_list {
		$$ = buildTree(FOR_INC, $1);
	}
	| { $$ = buildTree(FOR_INC,NULL); } 
	;
for_inc_list:
	assignment_exp { $$ = $1; }
	| for_inc_list ',' assignment_exp{
		appendBrother($1, $3);
		$$ = $1;
	}
continue_st:
	TCONTINUE ';' {
		$$ = buildTree(CONTINUE_ST,NULL);
	}
	;
break_st:
	TBREAK ';' {
		$$ = buildTree(BREAK_ST, NULL);
	}
	;
switch_st:
	TSWITCH '(' declarator ')' '{' switch_case_list'}' {
		appendBrother($3, $6);	
		$$ = buildTree(SWITCH_ST, $3);
	}
	;
switch_case_list:
	switch_case_list switch_case {
		appendBrother($1, $2);
		$$ = $1;
	}
	| switch_case {
		$$ = $1;
	}
	;
switch_case:
	TCASE TINTEGER ':' statement_list {
		Node *son = buildNode(NUMBER, $2);
		appendBrother(son, $4);
		$$ = buildTree(CASE_ST, son);		
	}
	| TCASE TINTEGER ':' {
		Node * son = buildNode(NUMBER, $2);
		$$ = buildTree(CASE_ST, son);		
	}
	| TDEFAULT ':' statement_list {
		$$ = buildTree(DEFAULT_ST, $3);
	} 
	| TDEFAULT ':'{
		$$ = buildTree(DEFAULT_ST, NULL);
	}
	;
statement:
	compound_st { $$ = $1; }
	| expression_st { $$ = $1; }
	| condition_st { $$ = $1; }
	| loop_st { $$ = $1; }
	| flow_st { $$ = $1; }
	;
loop_st:
	for_st { $$ = $1; }
	| while_st { $$ = $1; }
	;
condition_st:
	if_st { $$ = $1; }
	| switch_st { $$ = $1; }
	;
flow_st:
	return_st { $$ = $1; }
	| continue_st { $$ = $1; }
	| break_st { $$ = $1; }
	;
expression_st:
	opt_expression ';' { 
		$$ = buildTree(EXP_ST, $1);
	}
	;
opt_expression:
	expression { $$ = $1; }
	| { $$ = NULL; }
	;
if_st:
	 TIF '(' expression ')' statement %prec TIFX {
		appendBrother($3, $5);
		$$ = buildTree(IF_ST, $3);
	}
	| TIF '(' expression ')' statement TELSE statement {
		appendBrother($3, $5);
		appendBrother($5, $7);
		$$ = buildTree(IF_ELSE_ST, $3);
	}
	;
while_st:
	TWHILE '(' expression ')' statement {
		appendBrother($3, $5);
		$$ = buildTree(WHILE_ST, $3);
	}
	;
return_st:
	TRETURN opt_expression ';' { 
		$$ = buildTree(RETURN_ST, $2);
	}
	;
expression:
	assignment_exp { $$ = $1; }
	;
assignment_exp:
	logical_or_exp { $$ = $1; }
	| unary_exp '=' assignment_exp { 
		appendBrother($1, $3);
		$$ = buildTree(ASSIGN_OP, $1);
	}
	| unary_exp TADDASSIGN assignment_exp {
		appendBrother($1, $3);
		$$ = buildTree(ADD_ASSIGN, $1);
	}
	| unary_exp TSUBASSIGN assignment_exp {
		appendBrother($1, $3);
		$$ = buildTree(SUB_ASSIGN, $1);
	}
	| unary_exp TMULASSIGN assignment_exp {
		appendBrother($1, $3);
		$$ = buildTree(MUL_ASSIGN, $1);
	}
	| unary_exp TDIVASSIGN assignment_exp {
		appendBrother($1, $3);
		$$ = buildTree(DIV_ASSIGN, $1);
	}
	| unary_exp TMODASSIGN assignment_exp {
		appendBrother($1, $3);
		$$ = buildTree(MOD_ASSIGN, $1);
	}
	;
logical_or_exp:
	logical_and_exp { $$ = $1; }
	| logical_or_exp TOR logical_and_exp {
		appendBrother($1, $3);
		$$ = buildTree(LOGICAL_OR, $1);
	}
	;
logical_and_exp:
	equality_exp { $$ = $1; }
	| logical_and_exp TAND equality_exp {
		appendBrother($1,$3);
		$$ = buildTree(LOGICAL_AND, $1);
	}
	;
equality_exp:
	relational_exp { $$ = $1; }
	| equality_exp TEQ relational_exp {
		appendBrother($1, $3);
		$$ = buildTree(EQ, $1);
	}
	| equality_exp TNE relational_exp {
		appendBrother($1, $3);
		$$ = buildTree(NE, $1);
	}
	;
relational_exp:
	additive_exp { $$ = $1; }
	| relational_exp '>' additive_exp {
		appendBrother($1, $3);
		$$ = buildTree(GT, $1);
	}
	| relational_exp '<' additive_exp {
		appendBrother($1, $3);
		$$ = buildTree(LT, $1);
	}
	| relational_exp TGE additive_exp  {
		appendBrother($1, $3);
		$$ = buildTree(GE, $1);
	}
	| relational_exp TLE additive_exp  {
		appendBrother($1, $3);
		$$ = buildTree(LE, $1);
	}
	;
additive_exp:
	multiplicative_exp { $$ = $1; }
	| additive_exp '+' multiplicative_exp {
		appendBrother($1, $3);
		$$ = buildTree(ADD, $1);
	}
	| additive_exp '-' multiplicative_exp {
		appendBrother($1, $3);
		$$ = buildTree(SUB, $1);
	}
	;
multiplicative_exp:
	unary_exp { $$ = $1; }
	| multiplicative_exp '*' unary_exp {
		appendBrother($1, $3);
		$$ = buildTree(MUL, $1);
	}
	| multiplicative_exp '/' unary_exp {
		appendBrother($1, $3);
		$$ = buildTree(DIV, $1);
	}
	| multiplicative_exp '%' unary_exp {
		appendBrother($1, $3);
		$$ = buildTree(REMAINDER, $1);
	}
	;
unary_exp:
	postfix_exp { $$ = $1; }
	| '-' unary_exp {
		$$ = buildTree(UNARY_MINUS, $2);
	}
	| '!' unary_exp {
		$$ = buildTree(LOGICAL_NOT, $2);
	}
	| TINC unary_exp {
		$$ = buildTree(PRE_INC, $2);
	}
	| TDEC unary_exp {
		$$ = buildTree(PRE_DEC, $2);
	}
	;
postfix_exp:
	primary_exp { $$ = $1; }
	| postfix_exp '[' expression ']' {
		appendBrother($1, $3);
		$$ = buildTree(INDEX, $1);
	}
	| postfix_exp '(' opt_actual_param ')' {
		appendBrother($1, $3);
		$$ = buildTree(CALL, $1);
	}
	| postfix_exp TINC {
		$$ = buildTree(POST_INC, $1);
	}
	| postfix_exp TDEC {
		$$ = buildTree(POST_DEC, $1);
	}
	;
opt_actual_param:
	actual_param { $$ = $1; }
	| { $$ = NULL; } 
	;
actual_param:
	actual_param_list {
		$$ = buildTree(ACTUAL_PARAM, $1);	
	}
	;
actual_param_list:
	assignment_exp { $$ = $1; }
	| actual_param_list ',' assignment_exp { 
		appendBrother($1, $3);
		$$ = $1;
	}
	;
primary_exp:
	TIDENTITY { $$ = buildNode(IDENT, $1); }
	| TINTEGER { $$ = buildNode(NUMBER, $1); }
	| '(' expression ')' { $$ = $2; } 
	;

%%
char *toString(char *string)
{
	char *str;
	int len = strlen(string);
	str = (char *)malloc(len+1);
	strcpy(str,string);
	str[len] = '\0';
	return str;
}

void parse(FILE *cFile)
{

	yyin = cFile;
	do{
		yyparse();
	}while(!feof(yyin));
}
int main(int argc, char *argv[]){
	FILE *cFile, *astFile;
	char fileName[256];
	if(argc != 2){
		fprintf(stderr, "arguments not valid.");
		return -1;
	}
	strcpy(fileName, argv[1]);
	cFile = fopen(fileName, "r");
	astFile = fopen(strcat(strtok(fileName,"."),".ast"),"w");
	parse(cFile);
	printTree(root,0,astFile);
	return 0;
}
