%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "minic.h"



int yylex(void);
void yyerror(char *s);

%}

%union{
	int iValue;
	char* string;
	nodeType *nPtr;
}

%token <iValue> INTEGER
%token <string> IDENTITY
%token INT VOID						/* qualifier */
%token CONST						/* specifier */
%token WHILE FOR					/* 반복문 */
%token IF SWITCH					/* 조건문 */
%token CONTINUE BREAK RETURN		/* 흐름문 */
%token CASE DEFAULT					/* CASE문 */
%token INC DEC						/* ++, -- */
%token ADDASSIGN SUBASSIGN MULASSIGN MODASSIGN DIVASSIGN /* +=, -=, *=, %=, /= */
%token OR AND						/* ||, && */
%nonassoc IFX
%nonassoc CASEX
%nonassoc ELSE					
%left GE LE EQ NE '>' '<'			/* >= <= == != */
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%type <nPtr> translation_unit external_dcl function_def function_header dcl_spec dcl_specifiers
	dcl_specifier type_qualifier type_specifier function_name formal_param opt_formal_param
	formal_param_list param_dcl compound_st opt_dcl_list declaration_list declaration init_dcl_list
	init_declarator declarator opt_number opt_stat_list statement_list statement expression_st 
	opt_expression if_st while_st return_st for_st for_dcl for_exp for_inc continue_st break_st
	switch_st switch_case_list switch_case switch_default loop_st condition_st flow_st expression
	assignment_exp logical_or_exp logical_and_exp equality_exp relational_exp additive_exp
	multiplicative_exp unary_exp postfix_exp opt_actual_param actual_param_list primary_exp

%%
mini_c:
	translation_unit	{ exit(0); }
	;
translation_unit:
	external_dcl					{}
	| translation_unit external_dcl	{}
	;
external_dcl:
	function_def		{}
	| declaration			{}
	;
function_def:
	function_header compound_st		{}
	;
function_header:
	dcl_spec function_name formal_param {}
	;
dcl_spec:
	dcl_specifiers	{}
	;
dcl_specifiers:
	dcl_specifier {}
	| dcl_specifiers dcl_specifier
	;
dcl_specifier:
	type_qualifier	{}
	| type_specifier	{}
	;
type_qualifier:
	CONST {}
	;
type_specifier:
	INT		{}
	| VOID	{}
	;
function_name:
	IDENTITY	{}
	;
formal_param:
	'(' opt_formal_param ')' {}
	;
opt_formal_param:
	formal_param_list {}
	| {} 
	;
formal_param_list:
	param_dcl {}
	| formal_param_list ',' param_dcl {}
	;
param_dcl:
	dcl_spec declarator {}
	;
compound_st:
	'{' opt_dcl_list opt_stat_list '}' {}
	;
opt_dcl_list:
	declaration_list {}
	| {}
	;
declaration_list:
	declaration {}
	| declaration_list declaration {}
	;
declaration:
	dcl_spec init_dcl_list ';' {}
	;
init_dcl_list:
	init_declarator {}
	| init_dcl_list ',' init_declarator {}
	;
init_declarator:
	declarator {}
	| declarator '=' INTEGER {}
	;
declarator:
	IDENTITY {}
	| IDENTITY '[' opt_number ']' {}
	;
opt_number:
	INTEGER {}
	| {}
	;
opt_stat_list:
	statement_list {}
	| {} 
	;
statement_list:
	statement {}
	| statement_list statement {}
	;
for_st:
	FOR '(' for_dcl ';' for_exp ';' for_inc')' statement {}
	;
for_dcl:
	dcl_spec init_dcl_list {}
	| {} 
	;
for_exp:
	expression {}
	| {}
	;
for_inc:
	assignment_exp {}
	| {} 
	;
continue_st:
	CONTINUE ';' {}
	;
break_st:
	BREAK ';' {}
	;
switch_st:
	SWITCH '(' declarator ')' '{' switch_case_list'}' {}
	;
switch_case_list:
	switch_case_list switch_case {}
	| switch_case_list switch_default {}
	| {} 
	;
switch_case:
	CASE INTEGER ':' statement_list {}
	| CASE INTEGER ':' %prec CASEX {} 
	;
switch_default:
	DEFAULT ':' statement_list {}
	| DEFAULT ':' %prec CASEX{}
	;
statement:
	compound_st {}
	| expression_st {}
	| condition_st {}
	| loop_st {}
	| flow_st {}
	;
loop_st:
	for_st {}
	| while_st {}
	;
condition_st:
	if_st {}
	| switch_st {}
	;
flow_st:
	return_st {}
	| continue_st {}
	| break_st {}
	;
expression_st:
	opt_expression ';' {}
	;
opt_expression:
	expression {}
	| {}
	;
if_st:
	IF '(' expression ')' statement %prec IFX {}
	| IF '(' expression ')' statement ELSE statement {}
	;
while_st:
	WHILE '(' expression ')' statement {}
	;
return_st:
	RETURN opt_expression ';' {}
	;
expression:
	assignment_exp {}
	;
assignment_exp:
	logical_or_exp {}
	| unary_exp '=' assignment_exp {}
	| unary_exp ADDASSIGN assignment_exp {}
	| unary_exp SUBASSIGN assignment_exp {}
	| unary_exp MULASSIGN assignment_exp {}
	| unary_exp DIVASSIGN assignment_exp {}
	| unary_exp MODASSIGN assignment_exp {}
	;
logical_or_exp:
	logical_and_exp {}
	| logical_or_exp OR logical_and_exp {}
	;
logical_and_exp:
	equality_exp {}
	| logical_and_exp AND equality_exp {}
	;
equality_exp:
	relational_exp {}
	| equality_exp EQ relational_exp {}
	| equality_exp NE relational_exp {}
	;
relational_exp:
	additive_exp {}
	| relational_exp '>' additive_exp {}
	| relational_exp '<' additive_exp {}
	| relational_exp GE additive_exp  {}
	| relational_exp LE additive_exp  {}
	;
additive_exp:
	multiplicative_exp {}
	| additive_exp '+' multiplicative_exp {}
	| additive_exp '-' multiplicative_exp {}
	;
multiplicative_exp:
	unary_exp {}
	| multiplicative_exp '*' unary_exp {}
	| multiplicative_exp '/' unary_exp {}
	| multiplicative_exp '%' unary_exp {}
	;
unary_exp:
	postfix_exp {}
	| '-' unary_exp {}
	| '!' unary_exp {}
	| INC unary_exp {}
	| DEC unary_exp {}
	;
postfix_exp:
	primary_exp {}
	| postfix_exp '[' expression ']' {}
	| postfix_exp '(' opt_actual_param ')' {}
	| postfix_exp INC {}
	| postfix_exp DEC {}
	;
opt_actual_param:
	actual_param {}
	| {} 
	;
actual_param:
	actual_param_list {}
	;
actual_param_list:
	assignment_exp {}
	| actual_param_list ',' assignment_exp {}
	;
primary_exp:
	IDENTITY {}
	| INTEGER {}
	| '(' expression ')' {} 
	;

%%

void yyerror(char *s){
	fprintf(stdout, "%s\n", s);
}
int main(void){
	yyparse();
	return 0;
}
