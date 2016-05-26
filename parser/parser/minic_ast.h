#ifndef _MINIC_AST_
#define _MINIC_AST_


#define INDENT_SIZE 5

typedef struct tokenType {
	int number;
	char *value;
} Token;

typedef struct nodeType {
	Token token;
	enum {TERMINAL, NONTERM} noderep;
	struct nodeType *son;
	struct nodeType *brother;
} Node;
enum nodeNumber {
		ACTUAL_PARAM,	ADD,			ADD_ASSIGN,		ARRAY_VAR,		ASSIGN_OP,
		BREAK_ST,		CALL,			CASE_ST,		COMPOUND_ST,	CONST_TYPE,
		CONTINUE_ST,	DCL,			DCL_ITEM,		DCL_LIST,		DCL_SPEC,		
		DEFAULT_ST,		DIV,			DIV_ASSIGN,		EQ,				ERROR,			
		EXP_ST,			FORMAL_PARA,	FOR_DCL,		FOR_EXP,		FOR_INC,		
		FOR_ST,			FUNC_DEF,		FUNC_HEAD,		GE,				GT,				
		IDENT,			IF_ELSE_ST,		IF_ST,			INDEX,			INT_TYPE,		
		LE,				LOGICAL_AND,	LOGICAL_NOT,	LOGICAL_OR,		LT,				
		MOD_ASSIGN,		MUL,			MUL_ASSIGN,		NE,				NUMBER,			
		PARAM_DCL,		POST_DEC,		POST_INC,		PRE_DEC,		PRE_INC,		
		PROGRAM,		REMAINDER,		RETURN_ST,		SIMPLE_VAR,		STAT_LIST,		
		SUB,			SUB_ASSIGN,		SWITCH_ST,		UNARY_MINUS,	VOID_TYPE,		
		WHILE_ST, //60개
};

Node* buildNode(int tokenNumber, char* tokenValue);
Node* buildTree(int tokenNumber, Node* son);
void appendBrother(Node* me, Node* brother);

void printTree(Node *ptr, int indent, FILE *output);
void printNode(Node *ptr, int indent, FILE *output);

#endif
