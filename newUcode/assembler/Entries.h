#ifndef __ENTRIES_H
#define __ENTRIES_H
#include <string>
#include <list>
using namespace std;

class LabelEntry {
public:
	string labelName;
	int address;
	list<int>* instrList;
	LabelEntry(){
		labelName="";
		address = 0;
		instrList = NULL;
	}
};
#endif
