#include "Label.h"
#include <iostream>
using namespace std;

Label::Label(vector<Instruction> &instrBuf):instrBuf(instrBuf)
{
}

void Label::insertLabel(string label, int lineNum)
{

	for(auto itr = labelTable.begin(); itr != labelTable.end(); itr++)
	{	
		if(itr->labelName  == label)
		{
			itr->address = lineNum;
			list<int>* ptr = itr->instrList;
			itr->instrList = NULL;

			if(ptr != NULL)
			{
				for(auto instrAddress : *ptr)
				{
					instrBuf[instrAddress].value1 = lineNum;
				}
			}
		}
		else if(itr == labelTable.end())
		{
			LabelEntry entry;
			entry.address = lineNum;
			entry.labelName = label;
			entry.instrList = NULL;
			labelTable.push_back(entry);
		}
	}
}
void Label::findLabel(string label, int lineNum)
{
	//FixUpList* ptr;	
	
	for(auto itr = labelTable.begin(); itr != labelTable.end(); itr++)
	{
		if(itr->labelName == label)
		{
			list<int>* ptr = itr->instrList;
			if(ptr) ptr->push_back(lineNum);
			else instrBuf[lineNum].value1 = itr->address;
		}
		else if(itr == labelTable.end()){
			list<int>* ptr = new list<int>;
			if(ptr == NULL) cout<<"findLabel()"<<" "<<"Out of memory -- new";
			ptr->push_back(lineNum);

			LabelEntry entry;
			entry.labelName = label;
			entry.instrList = ptr;
			labelTable.push_back(entry);
		}
	}
}

