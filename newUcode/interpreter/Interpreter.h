#ifndef __INTERPRETER_H
#define __INTERPRETER_H
#include "../common/Instruction.h"
#include <vector>
using namespace std;


class Interpreter
{
private:
	UStack<int> stack;
	vector<Instruction> &instrBuf;
	vector<vector<int>*> memory;
	int arBase;
	void predefineddProc(int);
	//int findAddr(int);
	void clearMemory(int);
	int getMemory(int, int);
	//int* getMemoryAddr(int, int);
	void insertMemory(int,int,int);
public:
	void execute(int);
	Interpreter(vector<Instruction> &);
	virtual ~Interpreter();

};

#endif
