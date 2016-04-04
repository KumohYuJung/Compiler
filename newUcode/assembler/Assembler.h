#ifndef __ASSEMBLER_H
#define __ASSEMBLER_H
#include "../common/Instruction.h"
#include "Label.h"
#include <vector>
#include <string>
using namespace std;

class Assembler{
private:
	//int instrCnt;
	string lineBuffer;
	//int bufIndex;
	//Label labelProcess;
	//string label;
	//void getLabel();
	int getOpcode(const string&);
	//int getOperand();
	void instrWrite();
	vector<Instruction>& instrBuf;
	void split(const string&, vector<string>&);
public:
	void assemble();
	int startAddr;
	Assembler(vector<Instruction>&);
};
#endif
