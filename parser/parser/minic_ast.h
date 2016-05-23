#ifndef _MINIC_AST_
#define _MINIC_AST_

#define NODE_NUM	58
#define STACK_SIZE	512

#define ID_LENGTH	128

typedef struct tokenType {
	int tokenNumber;
	char *tokenValue;
} Token;

typedef struct nodeType {
	Token token;
	enum {TERMINAL, NONTERM} noderep;
	struct nodeType *son;
	struct nodeType *brother;
} Node;
enum nodeNumber {
	ACTUAL_PARAM,   ADD,            ADD_ASSIGN,     ARRAY_VAR,      ASSIGN_OP,
	CALL,           COMPOUND_ST,    CONST_NODE,     DCL,            DCL_ITEM,
	DCL_LIST,       DCL_SPEC,       DIV,            DIV_ASSIGN,     EQ,
	ERROR_NODE,     EXP_ST,         FORMAL_PARA,    FUNC_DEF,       FUNC_HEAD,
	GE,             GT,             IDENT,          IF_ELSE_ST,     IF_ST,
	INDEX,          INT_NODE,       LE,             LOGICAL_AND,    LOGICAL_NOT,
	LOGICAL_OR,     LT,             MOD,            MOD_ASSIGN,     MUL,
	MUL_ASSIGN,     NE,             NUMBER,         PARAM_DCL,      POST_DEC,
	POST_INC,       PRE_DEC,        PRE_INC,        PROGRAM,        RETURN_ST,
	SIMPLE_VAR,     STAT_LIST,      SUB,            SUB_ASSIGN,     UNARY_MINUS,
	VOID_NODE,      WHILE_ST,		CONTINUE_ST,	BREAK_ST,		FOR_ST,
	SWITCH_ST,		SCH_CASE_ST,	SCH_DEF_ST, //58개 
};

#endif
