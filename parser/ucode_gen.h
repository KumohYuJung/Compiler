#ifndef __UCODE_GEN_
#define __UCODE_GEN_

#include "minic_ast.h"

#define LABEL_LEN		8
#define SYM_TABLE_SIZE  512

typedef enum{
	NONE_SPEC, VOID_SPEC, INT_SPEC
} Specifier;

typedef enum{
	NONE_QUAL, CONST_QUAL, VAR_QUAL, FUNC_QUAL
} Qualifier;

typedef struct _symbolInfo{
	char *id;
	Qualifier qual;
	Specifier spec;
	int width;
	//int base;
	int offset;
	int initialValue;	
} SymbolInfo;

typedef struct _symbolTable{
	int count;  // symbol count
	int offset; // table offset
	int base;   // table base
	SymbolInfo symbols[SYM_TABLE_SIZE];
	struct _symbolTable *parent; //parent table
} SymbolTable;

/** symbolTable **/
SymbolTable* makeSymbolTable(SymbolTable *parent, int base);
SymbolTable* initSymbolTable();
/* 찾을 findID를 넣고 기준 SymbolTable를 넣으면 SymbolTable과
 * 어디에 위치하는지 index를 리턴합니다.*/
void lookupSymbol(char* findId, SymbolTable** foundTable, int* findIdx);
/* Symbol을 table에 넣는다. 성공 시 -1 리턴, 실패 시 어디에 위치하는지
 * 인덱스를 리턴한다. */
int insertSymbol(SymbolTable* table, Qualifier qual, Specifier spec, 
		char* id, int width, int initialValue);

void emit0(char *opcode);
void emit1(char *opcode, int operand);
void emit2(char *opcode, int operand1, int operand2);
void emitJump(char *opcode, char *operand);
void emitSym(char *opcode, int operand1, int operand2, int operand3);
void emitProc(char *label, int operand1, int operand2, int operand3);
void emitLabel(char *label);

void rv_emit(SymbolTable *table, Node *ptr);
void processSimpleVariable(SymbolTable *table, Node *ptr, 
		Specifier spec, Qualifier qual);
void processArrayVariable(SymbolTable *table, Node *ptr,
		Specifier spec, Qualifier qual);
void processDeclaration(SymbolTable *table, Node *ptr);
//void processFuncHeader(SymbolTable *table, Node *ptr);
void processOperator(SymbolTable *table, Node *ptr);
void processStatement(SymbolTable *table, Node *ptr);
void processCondition(SymbolTable *table, Node *ptr);

void processFunction(SymbolTable *table, Node *ptr);
int checkPredefined(SymbolTable *table, Node *ptr);

void genLabel(char *label);
void codeGen(Node *root, FILE *ucoFile);


#endif
