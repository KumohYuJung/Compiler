#ifndef __LABEL_H
#define __LABEL_H
#include <vector>
#include <string>
#include "../common/Instruction.h"
#include "Entries.h"
using namespace std;
class Label{
private:
	vector<LabelEntry> labelTable;
	vector<Instruction>& instrBuf;
public:
	void insertLabel(string, int);
	void findLabel(string, int);
	Label(vector<Instruction>& );
	virtual ~Label(){}
};
#endif
