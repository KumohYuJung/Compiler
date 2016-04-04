#include "Assembler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
Assembler::Assembler(vector<Instruction>& instrBuf):instrBuf(instrBuf)
{
}
void Assembler::split(const string& data, vector<string>& buffer)
{
	auto i = 0;
	auto pos = data.find(' ');
	while (pos != string::npos) {
		buffer.push_back(data.substr(i, pos-i));
		i = ++pos;
		pos = data.find(' ', pos);
		if (pos == string::npos)
			buffer.push_back(data.substr(i, data.length()));							    
	}
}
int Assembler::getOpcode(const string& opstr)
{
	for(int i = notop ; i < none; i++)
		if(opcodeName[i] == opstr) return i;

	return -1;
}
void Assembler::assemble()
{
	ifstream inputFile;
	string bufferLine;
	vector<string> buffers;
	Label label(instrBuf);
	bool done;
	bool end;
	int instrCnt = 0;

	cout <<" == Assembling ... =="<<endl;
	while(!inputFile.eof() && !inputFile.fail() && !end)
	{
		//inputFile.getline(bufferLine);
		getline(inputFile,bufferLine);
		split(bufferLine,buffers);
		if(buffers.empty())
			continue;
		instrBuf[instrCnt].opcode = getOpcode(buffers[0]);
		if( instrBuf[instrCnt].opcode == -1 && buffers.size() == 1 )
			continue;
		if( instrBuf[instrCnt].opcode == -1 )
			label.insertLabel( buffers[0], instrCnt );
		
		switch(instrBuf[instrCnt].opcode)
		{
		case chkl:
		case chkh:
		case ldc:
			instrBuf[instrCnt].value1 = stoi(buffers[1]);
			break;
		case lod:
		case str:
		case lda:
		case sym:
			instrBuf[instrCnt].value1 = stoi(buffers[1]);
			instrBuf[instrCnt].value2 = stoi(buffers[2]);
			break;
		case proc:
			instrBuf[instrCnt].value1 = stoi(buffers[1]);
			instrBuf[instrCnt].value2 = stoi(buffers[2]);
			instrBuf[instrCnt].value3 = stoi(buffers[3]);
			break;
		case bgn:
			instrBuf[instrCnt].value1 = stoi(buffers[1]);
			startAddr = instrCnt;
			done = true;
			break;
		case ujp:
		case call:
		case fjp:
		case tjp:
			label.findLabel(buffers[1], instrCnt);
			break;
		case endop:
			if(done) end = true;
		}
		instrCnt++;
		buffers.clear();	
	}
}

