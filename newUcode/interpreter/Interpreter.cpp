#include "Interpreter.h"

Interpreter::Interpreter(vector<Instruction> & instrBuf):instrBuf(instruBuf)
{
	arBase=0;
}
void Interpret::predefinedProc(int procIndex)
{
	static ifstream dataFile;
	static bool readFirst = true;
	
	int data, temp;

	if(procIndex == READPROC)
	{
		cin>>data;
		temp.
	}
}

void Interpreter::execute(int pc)
{
	int params, tmp, tmp2;
	int memory;
	cout<<" == Executing ...    =="<<endl
		<<" == Result           =="<<endl;
	while(pc >= 0)
	{
		switch(instrBuf[pc].opcode)
		{
			case notop :
				stack.push(!stack.pop());
				break;
			case neg:
				stack.push(-stack.pop());
				break;
			case add:
				stack.push(stack.pop()+stack.pop());
				break;
			case divop:
				tmp = stack.pop();
				if(tmp == 0) cout<<"execute() Divide by zero...");
				stack.push(stack.pop()/tmp);
				break;
			case sub:
				tmp = stack.pop();
				stack.push(stack.pop()-tmp);
				break;
			case mult :
				stack.push(stack.pop()* stack.pop());
				break;
			case modop:
				tmp = stack.pop();
				stack.push(stack.pop()%tmp);
				break;
			case andop :
				stack.push(stack.pop() & stack.pop());
				break;
			case orop:
				stack.push(stack.pop() | stack.pop());
				break;
			case gt:
				tmp = stack.pop();
				stack.push(stack.pop() >tmp );
				break;
			case lt :
				tmp = stack.pop();
				stack.push(stack.pop() < tmp);
				break;
			case ge:
				tmp = stack.pop();
				stack.push(stack.pop() >= tmp);
				break;
			case le:
				tmp = stack.pop();
				stack.push(stack.pop() <= tmp);
				break;
			case eq :
				tmp = stack.pop();
				stack.push(stack.pop() == tmp);
				break;
			case ne:
				tmp = stack.pop();
				stack.push(stack.pop() != tmp);
				break;
			case swp:
				tmp = stack.pop();
				tmp2 = stack.pop();
				stack.push(tmp);
				stack.push(tmp2);
				break;
			case lod:
				stack.push(getMemory(instrBuf[pc].value1,instrBuf[pc].value2));
				break;
			case ldc:
				stack.push(instrBuf[pc].value1);
				break;
			case lda:
				//stack.push(getMemoryAddr(instrBuf[pc].value1, instrBuf[pc].value2));
				memory = instrBuf[pc].value1;
				stack.push(instrBuf[pc].value2);
				break;
			case str:
				insertMemory(instrBuf[pc].value1, instrBuf[pc].value2, stack.pop());
				break;
			case ldi:
				stack.push(getMemory(memory,stack.pop()));
				break;
			case sti:
				tmp = stack.pop();
				insertMemory(memory,stack.pop(), value);
				break;
			case ujp:
				pc = instrBuf[pc].value1 - 1;
				break;
			case tjp:
				if(stack.pop()) pc = instrBuf[pc].value1 - 1;
				break;
			case fjp:
				if(!stack.pop()) pc = instrBuf[pc].value1 - 1;
				break;
			case ldp:
				params = stack.top() +1;
				stack.spSet(stack.top()+4);
				break;
			case call:
				if((tmp=instrBuf[pc].value1) < 0) predefinedProc(tmp);
				else
				{
					stack[params+2] = pc + 1;
					stack[params+1] = arBase;
					arBase = params;
					pc = instrBuf[pc].value1 - 1;
					
				}
				break;
			case retv:
				temp = stack.pop();
				csae ret:
					stack.spSet(arBase-1);
				if(instrBuf[pc].opcode == retv)
					stack.push(tmp);
				pc = stack[arBase+2]-1;
				arBase = stack[arBase+1];
				break;
			case proc:
				stack.spSet(arBase + instrBuf[pc].value1 + 3);
				stack[arBase+3] = instrBuf[pc].value2;
				for(tmp = stack[arBase+1]; stack[tmp+3] != instrBuf[])
					

		}
	}
}
/*
int Interpreter::findAddr(int n){
	
}
*/
int Interpreter::clearMemory(int m)
{
	if(memory.size() <= m)
	{
		int s = memory.size();
		memory.resize(m*2);
		for(int i = s ; i < m*2; i++)
			memory[i] = NULL;
	}
	if(memory[m] != NULL)
		delete memory[m];
	memory[m] = new vector<int>(5);
}
int Interpreter::getMemory(int m, int n)
{
	return *(memory[m]+n);
}
void Interpreter::insertMemory(int m, int n, int value)
{
	if(memory.size() <= m)
		clearMemory(m);
	if(memory[m]->size() <= n)
	{
		int s = memory[m]->size();
		memory.resize(m*2);
	}
	
	*(memory[m]+n) = value;
}

