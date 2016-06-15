#ifndef __UCODE_GEN_
#define __UCODE_GEN_

#include "minic_ast.h"

#define LABEL_LEN		8
#define SYM_TABLE_SIZE  512

typedef enum{
	NONE_SPEC, VOID_SPEC, INT_SPEC
} Specifier;

typedef enum{
	NONE_QUAL, CONST_QUAL, VAR_QUAL, FUNC_QUAL, LOOP_QUAL, SWITCH_QUAL
} Qualifier;

typedef struct _symbolInfo{
	char *id;
	Qualifier qual;
	Specifier spec;
	int width;
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

typedef struct _flowInfo{
	char* startLabel; 
	char* endLabel;
	Qualifier qual;
} FlowInfo;
typedef struct _flowTable{
	int count; // 현재 저장된 흐름 정보 개수
	FlowInfo flows[SYM_TABLE_SIZE];
} FlowTable;

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

/** flowTable **/
FlowTable* initFlowTable();
/* 내가 원하는 Qualifier의 최상단 부터 최하단 까지 검색을 함. 중간에 발견 하면 return */
void lookupFlow(FlowTable* table,Qualifier qual, char** foundStartLabel, char** foundEndLabel);
/* 최상단의 label을 가져옴 */
void topFlow(FlowTable* table, char** foundStartLabel, char** foundEndLabel);
/* label을 입력함 */
void pushFlow(FlowTable* table,Qualifier qual, char* startLabel, char* endLabel);
/* label제거 */
void popFlow(FlowTable* table);

/* 출력 구문들 */
void emit0(char *opcode);
void emit1(char *opcode, int operand);
void emit2(char *opcode, int operand1, int operand2);
void emitJump(char *opcode, char *operand);
void emitSym(char *opcode, int operand1, int operand2, int operand3);
void emitProc(char *label, int operand1, int operand2, int operand3);
void emitLabel(char *label);

/* 상수, 변수에 따라 다르게 출력*/
void rv_emit(SymbolTable *table, Node *ptr);
/* 단 변수 처리 */
void processSimpleVariable(SymbolTable *table, Node *ptr, 
		Specifier spec, Qualifier qual);
/* 복수 변수 (배열) 처리 */
void processArrayVariable(SymbolTable *table, Node *ptr,
		Specifier spec, Qualifier qual);
/* 선언문 처리 */
void processDeclaration(SymbolTable *table, Node *ptr);
/* 함수 헤더 처리 -> SymbolTable에 함수 input*/
void processFuncHeader(SymbolTable *table, Node *ptr);
/* 연산자 처리 */
void processOperator(SymbolTable *table, Node *ptr);
/* 흐름 처리 */
void processStatement(SymbolTable *table, Node *ptr);
/* 조건 값 처리 */
void processCondition(SymbolTable *table, Node *ptr);
/* 함수 U-code 생성 */
void processFunction(SymbolTable *table, Node *ptr);
/* 미리 선언된 함수들 처리 (write, read, lf)*/
int checkPredefined(SymbolTable *table, Node *ptr);
/* label 생성 */
void genLabel(char *label);
/* code 생성 시작 함수 */
void codeGen(Node *root, FILE *ucoFile);


#endif
