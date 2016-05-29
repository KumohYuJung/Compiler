#include <stdio.h>
#include <stdlib.h>
#include "minic_ast.h"

char *nodeName[] =
{
		"ACTUAL_PARAM",	"ADD",			"ADD_ASSIGN",	"ARRAY_VAR",	"ASSIGN_OP",
		"BREAK_ST",		"CALL",			"CASE_ST",		"COMPOUND_ST",	"CONST_TYPE",
		"CONTINUE_ST",	"DCL",			"DCL_ITEM",		"DCL_LIST",		"DCL_SPEC",		
		"DEFAULT_ST",	"DIV",			"DIV_ASSIGN",	"EQ",			"ERROR",		
		"EXP_ST",		"FORMAL_PARA",	"FOR_DCL",		"FOR_EXP",		"FOR_INC",		
		"FOR_ST",		"FUNC_DEF",		"FUNC_HEAD",	"GE",			"GT",			
		"IDENT",		"IF_ELSE_ST",	"IF_ST",		"INDEX",		"INT_TYPE",		
		"LE",			"LOGICAL_AND",	"LOGICAL_NOT",	"LOGICAL_OR",	"LT",			
		"MOD_ASSIGN",	"MUL",			"MUL_ASSIGN",	"NE",			"NUMBER",		
		"PARAM_DCL",	"POST_DEC",		"POST_INC",		"PRE_DEC",		"PRE_INC",		
		"PROGRAM",		"REMAINDER",	"RETURN_ST",	"SIMPLE_VAR",	"STAT_LIST",	
		"SUB",			"SUB_ASSIGN",	"SWITCH_ST",	"UNARY_MINUS",	"VOID_TYPE",	
		"WHILE_ST", 
};

Node* buildNode(int tokenNumber, char* tokenValue)
{
	Node *ptr;
	ptr = (Node *)malloc(sizeof(Node));
	if(!ptr)
	{
		printf("malloc error in buildNode()\n");
		exit(1);
	}
	ptr->token.number = tokenNumber;
	ptr->token.value = tokenValue;
	ptr->noderep = TERMINAL;
	ptr->son = ptr->brother = NULL;
	return ptr;
}
Node* buildTree(int tokenNumber, Node* son)
{
	Node *ptr;
	ptr = (Node*) malloc(sizeof(Node));
	if(!ptr)
	{
		printf("malloc error in buildTree()\n");
		exit(1);
	}
	ptr->token.number = tokenNumber;
	ptr->token.value = NULL;
	ptr->noderep = NONTERM;
	ptr->son = son;
	ptr->brother = NULL;

	return ptr;
}
void appendBrother(Node* me, Node* brother)
{
	if (me == NULL)
	{
		me = brother;
	}
	else 
	{
		while(me->brother != NULL) me = me->brother;
		me->brother = brother;
	}
}

void printTree(Node *ptr, int indent, FILE *output)
{
	while(ptr != NULL)
	{
		printNode(ptr,indent,output);
		if(ptr->noderep == NONTERM) 
			printTree(ptr->son, indent+INDENT_SIZE,output);
		ptr = ptr->brother;
	}
}

void printNode(Node *ptr, int indent, FILE *output)
{
	int i;
	for(i = 1; i <= indent; i++)
		fprintf(output," ");
	if(ptr->noderep == TERMINAL)
		fprintf(output," Terminal: %s\n", ptr->token.value);
	else
		fprintf(output," Nontermianl: %s\n", nodeName[ptr->token.number]);
}
