#include <iostream>
#include "../assembler/Label.h"
using namespace std;

int main(int argc, char** args){
	vector<Instruction> instr; 
	Label label(instr);
	label.insertLabel("gggg",10);	
	label.insertLabel("kkkk",20);
	label.findLabel("gggg",30);
	label.findLabel("$22",25);
	return 0;
}
