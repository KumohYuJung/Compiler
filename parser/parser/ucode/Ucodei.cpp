/* modified by juyoon, from here... */
/*
#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <locale>

using namespace std;

/* ... to here, to relect new standard of c++ */

const int MAXINSTR  = 2000;
const int MAXLABELS = 500;
const int STACKSIZE = 2000;
const int LABELSIZE = 10;
const int NO_OPCODES    = 47;             // 36 + 5 + 6

ifstream inputFile;
ofstream outputFile;

enum opcode {
	notop,negf,addf,divf,subf,
	multf, ldcf ,neg,   incop, decop, 
	dupl,  swp, add,  sub,   mult, 
	divop,modop, andop, orop,  gt,    
	lt,   ge,  le,   eq,    ne,
	lod,   ldc,   lda,   ldi,   ldp,  
	str, sti,  ujp,   tjp,  fjp,
	call, ret,   retv,  chkh,  chkl, 
	nop, proc, endop, bgn,  sym,
	dump,  none
};

char* opcodeName[NO_OPCODES] = {
	"notop","negf","addf","divf","subf", 
	"multf","ldcf","neg",  "inc", "dec", 
	"dup", "swp", "add",   "sub",   "mult", 
	"div", "mod", "and", "or",  "gt",   
	"lt",    "ge",   "le",  "eq",  "ne", 
   	"lod", "ldc",   "lda",   "ldi",  "ldp",
   	"str", "sti", "ujp", "tjp", "fjp",  
   	"call", "ret", "retv","chkh","chkl","nop", 
	"proc",  "end",  "bgn", "sym", "dump","none"
};

int executable[NO_OPCODES] = {
	/* notop */ 1,/*negf*/1,/*addf*/1,/*divf*/1,/*subf*/1,
	/*multf*/1,/* ldcf */1 , /* neg */  1, /* inc */  1, /* dec */  1, 
	/* dup */  1,  
	/* swp */   1, /* add */  1, /* sub */  1, /* mult */ 1, /* div */  1,
	/* mod */   1, /* and */  1, /* or */   1, /* gt */   1, /* lt */   1,  
	/* ge */    1, /* le */   1, /* eq */   1, /* ne */   1, /* lod */  1,  
	/* ldc */   1, /* lda */  1, /* ldi */  1, /* ldp */  1, /* str */  1, 
	/* sti */   1, /* ujp */  1, /* tjp */  1, /* fjp */  1, /* call */ 1, 
	/* ret */   1, /* retv */ 1, /* chkh */ 1, /* chkl */ 1, /* nop */  0, 
	/* proc */  1, /* end */  0, /* bgn */  0, /* sym */  0, /* dump */ 1,  
	/* none */  0
};

int opcodeCycle[NO_OPCODES] = {
	/* notop */ 5,5,5,5,5,
	5,/*ldcf*/ 5,/* neg */   5, /* inc */  1, /* dec */   1, /* dup */    5,  
	/* swp */  10, /* add */  10, /* sub */ 10, /* mult */ 50, /* div */  100,
	/* mod */ 100, /* and */  10, /* or */  10, /* gt */   20, /* lt */    20, 
	/* ge */   20, /* le */   20, /* eq */  20, /* ne */   20, /* lod */    5,
	/* ldc */   5, /* lda */   5, /* ldi */ 10, /* ldp */  10, /* str */    5, 
	/* sti */  10, /* ujp */  10, /* tjp */ 10, /* fjp */  10, /* call */  30, 
	/* ret */  30, /* retv */ 30, /* chkh */ 5, /* chkl */  5, /* nop */    0, 
	/* proc */ 30, /* end */   0, /* bgn */  0, /* sym */   0, /* dump */ 100,  
	/* none */  0
};

long int dynamicCnt[NO_OPCODES] /* = {
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,
	 1
} */ ;

int staticCnt[NO_OPCODES] /* = {
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,
	 1
} */ ;

enum {FALSE, TRUE};
enum procIndex {READPROC = -1, WRITEPROC = -2, LFPROC = -3, FWRITEPROC = -4,
				UNDEFINED = -1000 };

typedef struct {
     int opcode;
     int value1;
     int value2;
     int value3;
} Instruction;

Instruction instrBuf[MAXINSTR];
void doubleToInteger(double input, int& hi, int& low){
	hi = (int)input;
	low = (int)((input-hi)*10000000);
	//cout<<hi<<" "<<low<<endl;
}
double integerToDouble(int hi, int low){
	//cout<<"integer : "<< (double)hi+(low/10000000.0)<<endl;
	return (double)hi + (low/10000000.0);
}
void errmsg(char* s, char* s2 = "")
{
     cerr << "error !!!  " << s << ":  " << s2 << "\n";
     exit(1);
}

class UcodeiStack {
     int size;
     int sp;
     int* stackArray;
public:
     void push(int) ;
     int pop() ;
     int top() { return sp; }
     void spSet(int n) {sp = n;}
	 void dump();
     int& operator[](int);
     UcodeiStack(int) ; 
     ~UcodeiStack() { delete[] stackArray; }
}; 

class Label {
     struct fixUpList {
         int instrAddress;
         struct fixUpList* next;
     };
     struct labelEntry {
         char labelName[LABELSIZE];
         int address;
         struct fixUpList* instrList;
     };
     struct labelEntry labelTable[MAXLABELS];
     int labelCnt;
     void addFix(struct fixUpList*, int);
public:
     void insertLabel(char [], int);
     void findLabel(char [], int);
	 void checkUndefinedLabel();
     Label();
     virtual ~Label() { }
};

class Assemble {
     int instrCnt;
     char lineBuffer[80];
     int bufIndex;
     Label labelProcess;
     char label[LABELSIZE];
     void getLabel();
     int getOpcode();
     int getOperand();
	 void getOperandf(int& hi, int &low);
     void instrWrite();
public:
     void assemble();
     int startAddr;
     Assemble() {
        instrCnt = 0;
     }

};

class Interpret {
     UcodeiStack stack;
     int arBase;
     long int tcycle;
     long int exeCount;
     void predefinedProc(int);
     int findAddr(int);
     void statistic();
public:
     void execute(int);
     Interpret();
     virtual ~Interpret() { }
};

UcodeiStack::UcodeiStack(int size)
{
     stackArray = new int[size]; //size만큼 만드는데..
     sp = -1; //아무것도 없으니 top 인덱스는 -1 이다.
     push(-1); push(-1); push(-1); push(0); //이건 왜 해주는 걸까?
     push(0);   push(0); push(-1); push(1);
}

void UcodeiStack::push(int value)
{
     if (sp == STACKSIZE) errmsg("push()", "Stack Overflow...");
     stackArray[++sp] = value;
}

int UcodeiStack::pop()
{
     if (sp == 0) errmsg("pop()", "Stack Underflow...");
     return stackArray[sp--]; 
}

void UcodeiStack::dump()
{ // top-10 ~ top 까지 스택이 어떤 것이 쌓였는지 출력해보는 함수다.
	int i;

	cout << "stack dump (address : value)\n";
	for ( i = sp-10; i <=sp; ++i)
		cout << ' ' << i << " : " << stackArray[i] << "\n";
	cout << '\n'; 
}

int& UcodeiStack::operator[](int index)
{
     return stackArray[index];
}

Label::Label()
{
	int index;

	//기본 함수를 정의하고 있다.
    labelCnt = 3;
    strcpy(labelTable[0].labelName, "read"); 
    labelTable[0].address = READPROC;
    labelTable[0].instrList = NULL;
    strcpy(labelTable[1].labelName, "write"); /* modified by juyoon */
    labelTable[1].address = WRITEPROC;
    labelTable[1].instrList = NULL;
    strcpy(labelTable[2].labelName, "lf");
    labelTable[2].address = LFPROC;
    labelTable[2].instrList = NULL;
	strcpy(labelTable[3].labelName,"fwrite");
	labelTable[3].address =FWRITEPROC;
	labelTable[3].instrList = NULL;
	for (index = 4; index < MAXLABELS; index++)
		labelTable[index].address = UNDEFINED;
}

void Label::insertLabel(char label[], int value)
{
     struct fixUpList* ptr;
     int index;

     for (index = 0; (index <= labelCnt) 
             && strcmp(labelTable[index].labelName, label); index++);
			 //LabelName 같은 것이 없을 때 까지 index를 증가시킨다.
     labelTable[index].address = value; // address 값은 lineNumber! 
     if (index > labelCnt) { // 처음 라벨을 등록할 경우
                  strcpy(labelTable[index].labelName, label);// 라벨 이름을 등록하고
                  labelCnt = index; // 라벨 카운터를 인덱스로 준다.
                  labelTable[index].instrList = NULL; // 명령List는 NULL을 준다
     } else { //전에 등록한 라벨인 경우(findLabel에서 등록을 함)
                  ptr = labelTable[index].instrList; // 명령List => ptr
                  labelTable[index].instrList = NULL; //현재 명령list에 null을 준다.
                  while (ptr) {  // backpatching //ptr이 NULL이 나올때 까지 돌린다.
                       instrBuf[ptr->instrAddress].value1 = value; //모든 라인을 첫번째 값을 현재 라인 번호를 넣는다.
					   // 왜? findLabel 구문은 보통 점프 구문! -> 해당 라벨이 어디 있는지 등록하기 위해 쓰인다
                       ptr = ptr->next; 
                  }
     }
}

void Label::findLabel(char label[], int instr)
{
     struct fixUpList* ptr; 
     int index;

     for (index=0; (index <= labelCnt) &&
          strcmp(label, labelTable[index].labelName); index++); //labelTable에 등록된 label이 있는 지 확인한다.
     if (index > labelCnt) { // not found
          strcpy(labelTable[index].labelName, label); //label 내용을 labelName에 복사한다.
          labelCnt = index; // label count를 1 증가 시킨다.
          ptr = new fixUpList; // fixUpList를 새로 만든다.
          if (ptr == NULL) errmsg("findLabel()", "Out of memory -- new"); // 메모리가 없어서 리스트가 만들어 지지 않을 경우 애러
          labelTable[index].instrList= ptr; //instList 에 새로운 ptr을 추가시키고 
          ptr->instrAddress = instr; //instrAddress는 현제 라인을 등록한다.
          ptr->next = NULL; //다음 수행해야할 것이 아직 정해지지 않았으므로 NULL을 입력한다. 
     } else {                // found
          ptr = labelTable[index].instrList; 
          if (ptr) addFix(ptr, instr); // findLabel실행이 처음이 아닌 경우 instrList에 링크드 리스트 형태로 추가한다. 
          else instrBuf[instr].value1=labelTable[index].address; // insertLabel로 등록 후 처음 findLabel이 실행될 때 해당 로직이 실행됨. 해당 라벨이 어디있는지 등록하는 모습이다. 이 함수는 jump명령어에서 쓰일테니
     }
}

void Label::addFix(struct fixUpList* prev, int instr)
{
     struct fixUpList* succ;

     while (prev->next) prev = prev->next; //linked list 끝까지 간다.
     succ = new fixUpList; // 하나를 생성해서
     if (succ == NULL) errmsg("addFix()", "Out of memory");
     succ-> instrAddress = instr; // instrAddress에는 자신의 line number를 넣는다.
     succ-> next = NULL;
     prev-> next = succ;  // linkedList 추가.
//   delete succ;
}

void Label::checkUndefinedLabel()
{
	int index;
	
	for (index = 0; index <= labelCnt; index++)
		if (labelTable[index].address == UNDEFINED)
			errmsg("undefined label", labelTable[index].labelName);
}

void Assemble::getLabel()
{
     int i;

     while (isspace(lineBuffer[bufIndex])) bufIndex++;
     for (i=0; i<=LABELSIZE && !isspace(label[i]=lineBuffer[bufIndex]);
          bufIndex++, i++);
     label[i] = '\0'; //text 추출! label에다가 저장한다.
}

int Assemble::getOpcode()
{
     char mnemonic[5];
     int index;

	 // always start at 12-th column

     bufIndex = 11;
     index = 0;
     while (index < 5 && !isspace(lineBuffer[bufIndex])) {
          mnemonic[index++] = lineBuffer[bufIndex++]; 
     }// 5자 이내 또는 공백이 나올때 까지
     mnemonic[index] = '\0';

     for(index=notop; index < none; index++) // 모든 명령어를 루프 돌아서 이게 어떤 명령어인지 확인한다.
		 if (!strcmp(mnemonic, opcodeName[index])) break;

     if (index == none) errmsg("Illegal opcode", mnemonic);
     return index;
}

int Assemble::getOperand()
{
     int result;

     while (isspace(lineBuffer[bufIndex])) bufIndex++;
     result= 0;
     while (isdigit(lineBuffer[bufIndex]) && lineBuffer[bufIndex] != '\n')
          result= 10*result + (lineBuffer[bufIndex++]-'0');
     return result; // 걍 숫자를 가져오네
}
void Assemble::getOperandf(int &hi, int &low)
{
	/*
	bufIndex = 0;
	lineBuffer[0] = '1';
	lineBuffer[1] = '.';
	lineBuffer[2] = '0';
	lineBuffer[3] = '1';
	lineBuffer[4] = '3';
	lineBuffer[5] = '8';
	lineBuffer[6] = '1';
	lineBuffer[7] = '9';
	lineBuffer[8] = '0';
	lineBuffer[9] = '4';
*/

	// 총 6자리 이며 나누기 10만하면 소수점 부분을 찾을 수 있음
	double result = 0;
	//cout<<"test : "<<lineBuffer+bufIndex<<endl;
	while( isspace(lineBuffer[bufIndex])) bufIndex++;
	while(isdigit(lineBuffer[bufIndex]) && lineBuffer[bufIndex] != '\n')
		result = 10*result+(lineBuffer[bufIndex++]-'0');
	bufIndex++;
	double result2 = 0;
	int count = 0;
	while(isdigit(lineBuffer[bufIndex]) && lineBuffer[bufIndex] != '\n')
	{
		count ++;
		if(count == 7)
			break;
		result2 = 10*result2 +(lineBuffer[bufIndex++]-'0');
	}
	for(;count < 7; count++)
		result2 *= 10;
	//cout<<"------"<<endl;
	//cout<<result<<endl;
	//cout<<result2<<endl;
	hi = result;
	low = result2;
}
void Assemble::instrWrite()
{
	//명령어 결과를 lst파일에다가 저장하는 함수
     int i, j;
     char ch;

     inputFile.seekg(0, ios::beg);

     outputFile << "\n line       object           ucode  source program\n\n";
     for (i=1; i<=instrCnt; i++) 
     {    outputFile.width(4);
          outputFile << i << "    (";
          outputFile.width(2);
          outputFile << instrBuf[i].opcode; //opcode  출력
          j = instrBuf[i].opcode; 
          if (j == chkl || j == chkh || j==ldc   || j == bgn ||
              j == ujp  || j == call  || j == fjp || j == tjp) { //operand가 하나이 ㄴ아이
               outputFile.width(5);
               outputFile << instrBuf[i].value1 << "     ";
          } else if (j==lod || j==str || j==lda || j==sym || j==proc) { // operand가2,3 개인 아이
               outputFile.width(5);
               outputFile << instrBuf[i].value1 ;
               outputFile.width(5);
               outputFile << instrBuf[i].value2 ;
          } else outputFile << "          "; 
          outputFile << ")     ";
          while ((ch=inputFile.get()) != '\n')  // copy input to output
             outputFile.put(ch); //ucode파일 그대로 한줄 출력 
          outputFile.put('\n');
     }
     outputFile << "\n\n\n   ****    Result    ****\n\n\n";
}

void Assemble::assemble()
{
	 //char test[10] = "12.467";
     int done = FALSE;
     int end = FALSE;
     int n;
	 //getOperandf(done,end);
     cout << " == Assembling ... ==" << '\n';
     while (!inputFile.eof() && !inputFile.fail() && !end) {
          instrCnt++; bufIndex = 0;
          inputFile.getline(lineBuffer, sizeof(lineBuffer));
          if (!isspace(lineBuffer[0])) { //첫번째 칸이 공백이 아니라면 
                  getLabel(); // label을 가져옴 (11칸)
                  labelProcess.insertLabel(label, instrCnt); // 그리고 집어넣음 instrCnt는 lineNumber임 
          }
          instrBuf[instrCnt].opcode = n = getOpcode();//명령어 인덱스를 가져오고
          staticCnt[n]++; // static계수를 1 증가시킴
          switch (n) {
          case chkl:
          case chkh:
          case ldc :
                  instrBuf[instrCnt].value1 = getOperand(); // 1항 연산자들
                  break;
		  case ldcf:
				  getOperandf(instrBuf[instrCnt].value1, instrBuf[instrCnt].value2);
				  break;	  
          case lod:
          case str:
          case lda:
          case sym:
                  instrBuf[instrCnt].value1 = getOperand();
                  instrBuf[instrCnt].value2 = getOperand(); //2 항 연산자들
                  break;
          case proc:
                  instrBuf[instrCnt].value1 = getOperand();
                  instrBuf[instrCnt].value2 = getOperand();
                  instrBuf[instrCnt].value3 = getOperand(); //3항 연산자들
                  break;
          case bgn:
                  instrBuf[instrCnt].value1 = getOperand(); // 1항 연산자인데 특수한 행동을 함
                  startAddr = instrCnt;
                  done = TRUE;
                  break;
          case ujp:
          case call:
          case fjp:
          case tjp:
                  getLabel(); //11칸을 읽음 
                  labelProcess.findLabel(label, instrCnt); // label이 필요한 경우
                  break;
          case endop:
                  if (done) end = TRUE; // 
          }
     }
     instrWrite();
}

Interpret::Interpret()
        : stack(STACKSIZE)
{
     arBase = 4; // 처음엔 4로 설정
     tcycle = 0;
     exeCount = 0 ;
}

int Interpret::findAddr(int n)
{
     int temp ;

     if (!instrBuf[n].value1) //1번째 값이 있는지 확인 
         errmsg("findAddr()", "Lexical level is zero ...");
     else if (instrBuf[n].value2 < 1) // 2번째 값이 음수인지 확인
         errmsg("findAddr()", "Negative offset ...");
     for (temp=arBase; instrBuf[n].value1!=stack[temp+3]; temp=stack[temp]) {
         if ((temp > STACKSIZE) || (temp < 0 ))
            cout << "Lexical level :  " << instrBuf[n].value1 << ' ' 
                 << "Offset        :  " << instrBuf[n].value2 << '\n';
     }

     return (temp+instrBuf[n].value2+3);
}

void Interpret::predefinedProc(int procIndex)
{
	//사전에 정의된 함수들을 실행할 때 쓰인다.
     static ifstream dataFile;
     static int readFirst = TRUE;

//     char dataFileName[20];
     int data, temp;

     if (procIndex == READPROC)           // read
     {                              
		 /*
          if (readFirst) {
               cout << "\nEnter Data File Name : ";
               cin >> dataFileName;
               dataFile.open(dataFileName, ios::in);
               if (dataFileName == NULL)
                     errmsg("checkPredefined()", "Data file open error ...");
               readFirst = FALSE;
          }
          dataFile >> data;
		  */
		 cin >> data;
          temp = stack.pop();
          stack[temp] = data;
          stack.spSet(stack.top()-4);
     }
     else if (procIndex == WRITEPROC) {   // write
          temp = stack.pop();
          cout << ' ' << temp;
          outputFile << ' ' << temp ;
          stack.spSet(stack.top()-4);
     } else if (procIndex == LFPROC) {    // lf : line feed
          outputFile.put('\n');
          cout << "\n";
     } else if (procIndex == FWRITEPROC)
	 {
		 temp =stack.pop();
		 double a = integerToDouble(stack.pop(),temp);
		 //cout<< ' '<<a;
		 printf("%f ",a);
		 outputFile<<' '<<a;
		 stack.spSet(stack.top()-4); // 조심
	 } 
}

void Interpret::statistic()
{
     int i, opcode;
	
     outputFile << "\n\n   **********************\n\n";
     outputFile << "\n\n\n                 " << "#### Statistics ####\n";
     outputFile << "\n\n    ****  Static Instruction Counts  ****\n\n\n";
     for (i=0, opcode = notop ; opcode <= none; opcode++) {
          if ( staticCnt[opcode] != 0) {
               outputFile.width(5);
               outputFile.setf(ios::left, ios::adjustfield);
               outputFile << opcodeName[opcode] <<  "  =  " ;
               outputFile.width(5);
               outputFile.setf(ios::left, ios::adjustfield);
               outputFile <<  staticCnt[opcode] << "   ";
               i++;
               if (i % 4 == 0) outputFile.put('\n');
          }
     } 
     outputFile << "\n\n\n  ****  Dynamic instruction counts  ****\n\n\n";
     for (i=0, opcode = notop ; opcode <= none; opcode++) {
          if (dynamicCnt[opcode] != 0) {
               outputFile.width(5);
               outputFile.setf(ios::left, ios::adjustfield);
               outputFile << opcodeName[opcode] << "  =  " ;
               outputFile.width(8);
               outputFile.setf(ios::left, ios::adjustfield);
               outputFile << dynamicCnt[opcode] << "  " ;
               i++;
               if ( i % 4 == 0) outputFile << "\n";
          }
     }
     outputFile << "\n\n Executable instruction count  =   " << exeCount;
     outputFile << "\n\n Total execution cycle         =   " << tcycle;
     outputFile << "\n";
}


void Interpret::execute(int startAddr)
{
     int parms;
     int temp, temp1,temp2, temp3;
	 double temp4, temp5;
     int pc;
//	 int returnAddress;

     pc = startAddr;
     cout << " == Executing ...  ==\n";
     cout << " == Result         ==\n";
     while (pc >= 0) 
     {
          dynamicCnt[instrBuf[pc].opcode]++;
          if (executable[instrBuf[pc].opcode]) exeCount++;
          tcycle += opcodeCycle[instrBuf[pc].opcode];
          switch(instrBuf[pc].opcode) //instBuf내 opcode에 따라 .. 
          {
			  case ldcf://소수점 부분이 먼저 들어감
				  //cout<<"ldcf : "<<instrBuf[pc].value2<<" " <<instrBuf[pc].value1<<endl;
				  stack.push(instrBuf[pc].value2);
				  stack.push(instrBuf[pc].value1);
				  break;
			  case negf:
				  temp = stack.pop();
				  stack.push(-stack.pop());
				  stack.push(-temp);
				  break;
			  case addf:
				  temp4 = integerToDouble(stack.pop(),stack.pop());
				  temp5 = integerToDouble(stack.pop(),stack.pop());
				  doubleToInteger(temp4+temp5, temp, temp1);
				  stack.push(temp1);
				  stack.push(temp);
				  break;
			  case divf:
				  temp4 = integerToDouble(stack.pop(), stack.pop());
				  temp5 = integerToDouble(stack.pop(), stack.pop());
				  doubleToInteger(temp5/temp4,temp,temp1);
				  stack.push(temp1);
				  stack.push(temp);
				  break;
			  case subf:
				  temp4 = integerToDouble(stack.pop(),stack.pop());
				  temp5 = integerToDouble(stack.pop(),stack.pop());
				  doubleToInteger(temp5 - temp4, temp, temp1);
				  stack.push(temp1);
				  stack.push(temp);
				  break;
			  case multf:
				  temp4 = integerToDouble(stack.pop(), stack.pop());
				  temp5 = integerToDouble(stack.pop(), stack.pop());
				  doubleToInteger(temp4*temp5, temp,temp1);
				  stack.push(temp1);
				  stack.push(temp);
				  break;
          case notop :
                  stack.push(!stack.pop()); // pop top, push !top
                  break;
          case neg:
                  stack.push(-stack.pop()); // pop top, push -top
                  break;
          case add :
                  stack.push(stack.pop()+stack.pop()); // pop two tops, push add tops
                  break;
          case divop :
                  temp = stack.pop(); //
                  if (temp == 0) errmsg("execute()", "Divide by Zero ...");
                  stack.push(stack.pop()/temp);
                  break;
          case sub :
                  temp = stack.pop();
                  stack.push(stack.pop()-temp);
                  break;
          case mult :
                  stack.push(stack.pop()*stack.pop());
                  break;
          case modop:
                  temp = stack.pop();
                  stack.push(stack.pop()%temp);
                  break;
          case andop :
                  stack.push(stack.pop() & stack.pop()); // add 연산 비교 x
                  break;
          case orop:
                  stack.push(stack.pop() | stack.pop()); // or 연산 비교 x
                  break;
          case gt :
                  temp = stack.pop();
                  stack.push(stack.pop()>temp);
                  break;
          case lt :
                  temp = stack.pop();
                  stack.push(stack.pop()<temp);
                  break;
          case ge :
                  temp = stack.pop();
                  stack.push(stack.pop()>=temp);
                  break;
          case le :
                  temp = stack.pop();
                  stack.push(stack.pop()<=temp);
                  break;
          case eq:
                  temp = stack.pop();
                  stack.push(stack.pop()==temp);
                  break;
          case ne:
                  temp = stack.pop();
                  stack.push(stack.pop()!=temp);
                  break;
          case swp:
                  temp = stack.pop();
                  temp1 = stack.pop();
                  stack.push(temp);
                  stack.push(temp1); // 바꾸기
                  break;
		  case lod:
				  stack.push(stack[findAddr(pc)]); //이따가  
				  break;
          case ldc:
                  stack.push(instrBuf[pc].value1); //상수 넣기
                  break;
          case lda:
                  stack.push(findAddr(pc)); //이따가
                  break;
          case str:
                  stack[findAddr(pc)] = stack.pop();// 이따가 
                  break;
          case ldi:
                  if ((stack.top() <= 0) || (stack.top() > STACKSIZE))
                       errmsg("execute()", "Illegal ldi instruction ...");
                  temp = stack.pop(); // top에 있는 걸 가져와서 
                  stack.push(temp); // 다시 스택에 넣고 
                  stack[stack.top()] = stack[temp]; //stack.top이 temp인데 같은거 아니야? 이상함.. -> 아 여기서 top은 인덱스임.. ㅡㅡ..
                  break;
          case sti:
                  temp = stack.pop(); // 스택에 잇는걸 팝하고
                  stack[stack.pop()] = temp; // 또 팝하여 값을 넣는다.
                  break;
          case ujp:
                  pc = instrBuf[pc].value1 - 1; // 인덱스는 0 부터 시작되기 때문에 1을 뺀 값을 다음 program counter로 준다.
                  break;
          case tjp:
                  if (stack.pop()) pc = instrBuf[pc].value1 - 1; // 
                  break;
          case fjp:
                  if (!stack.pop()) pc = instrBuf[pc].value1 - 1;
                  break;
          case chkh:
                  temp = stack.pop();
                  if (temp > instrBuf[pc].value1) //값을 꺼내 비교해 보고 다시 스택에 넣음
                      errmsg("execute()", "High check failed...");
                  stack.push(temp);
                  break;
          case chkl:
                  temp = stack.pop();
                  if (temp < instrBuf[pc].value1)
                       errmsg("execute()", "Low check failed...");
                  stack.push(temp);
                  break;
          case ldp:
                  parms = stack.top() + 1;		// save sp
                  stack.spSet(stack.top()+4);   // set a frame //왜 스택보다 4 위치 큰 곳에 위치를 잡지?
                  break;
          case call:
                  if ((temp=instrBuf[pc].value1) < 0) predefinedProc(temp); //사전에 등록된 함수는 아무리 찾아봐도 나오질 않지.
                    else {
							// parms는 ldp에서 설정이 된다.
                           stack[parms+2] = pc + 1 ;//돌아올 주소 저장하기
                           stack[parms+1] = arBase; //원래 arBase를 저장한다.
                           arBase = parms;  // 
                           pc = instrBuf[pc].value1 - 1;//해당 함수의 line번호-1 으로 설정함으로서 다음에 line번호 부터 실행이 될 수 있도록 한다.
                         }
                  break;
		  case retv:
				  temp = stack.pop(); // temp에 최상값을 넣는다. 밑에 break문이 없다는 것을 유념하라.
		  case ret:
				  stack.spSet(arBase - 1);  //top 포인트를 현재 arBase보다 -1 로 둔다. (스택 해제)
				  if (instrBuf[pc].opcode == retv) // 현재 명령이 retv로 인하여 실행 되었다면.. 
					  stack.push(temp);  //꺼냇던 값을 다시 넣는다.(arBase - 1에 들어가게 됨)
				  pc = stack[arBase+2] - 1;  // 돌아올 주소로 pc로 바꿈
				  arBase = stack[arBase+1]; // 함수호출전 arBase로 돌아옴
				  break;
				  /*
          case stp:
                  returnAddress = stack[arBase+2] - 1;
                  stack.spSet(arBase - 1);
                  arBase = stack[arBase + 1];
                  break;
          case ret:
                  pc = returnAddress;
                  break;
				  */
          case proc:
				  // value 1: (size of paras + size of local vars)
				  // value 2: block number(base)
				  // value 3: static level => lexical level (static chain)
                  stack.spSet( arBase + instrBuf[pc].value1 + 3); // arBase에 parameter Size와 local value Size를 더하고 거기에 3을 또 더한다 왜?
                  stack[arBase+3] = instrBuf[pc].value2; // 3을 더한 자리에 블락 넘버를 넣는다. 1또는 2를 넣는데 왜?
                  for (temp = stack[arBase+1]; stack[temp+3] !=       // 무슨말이지?
                       instrBuf[pc].value3 -1; temp = stack[temp]);
                       stack[arBase] = temp;
                  break;
          case endop:
                  pc = -2;
                  break;
          case bgn:
                  stack.spSet(stack.top() + instrBuf[pc].value1);
                  break;
		  /*
		  case ones:
                  temp = stack.pop();
                  stack.push(~temp);
                  break;
		  */
          case nop:
          case sym:
                  break;
		  /* augmented operation code */
		  case incop:
                  temp = stack.pop();
                  stack.push(++temp);
                  break;
		  case decop:
                  temp = stack.pop();
                  stack.push(--temp);
                  break;
		  case dupl:
                  temp = stack.pop();
                  stack.push(temp);
                  stack.push(temp);
                  break;
		  case dump:
				  stack.dump();
				  break;
          }
          pc++;
     }
     cout << '\n';
     statistic();
}

int main(int argc, char* argv[])
{

     Assemble sourceProgram;
     Interpret binaryProgram;

     if (argc != 2) errmsg("main()", "Wrong number of arguments");

     inputFile.open(argv[1], ios::in);
     if (!inputFile) errmsg("cannot open input file", argv[1]);

     outputFile.open(strcat(strtok(argv[1], "."), ".lst"), ios::out);
     // if (!outputFile) errmsg("cannot open output file", argv[2]) ;

     sourceProgram.assemble();
     binaryProgram.execute(sourceProgram.startAddr);

     inputFile.close();
     outputFile.close();

	 return 0;
}
