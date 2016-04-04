#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H
#include <string>
using namespace std;

struct Instruction{

	int opcode;
	int value1;
	int value2;
	int value3;
};

const int NO_OPCODES    = 41;

enum opcode{
	notop, neg,   incop, decop, dupl,  swp, add,  sub,   mult, divop,
	modop, andop, orop,  gt,    lt,   ge,  le,   eq,    ne,
	lod,   ldc,   lda,   ldi,   ldp,  str, sti,  ujp,   tjp,  fjp,
	call, ret,   retv,  chkh,  chkl, nop, proc, endop, bgn,  sym,
	dump,  none
};

string opcodeName[NO_OPCODES] = {
	"notop", "neg",  "inc", "dec", "dup", "swp", "add",   
	"sub",   "mult", "div", "mod", "and", "or",  "gt",   
	"lt",    "ge",   "le",  "eq",  "ne",  "lod", "ldc",   
	"lda",   "ldi",  "ldp", "str", "sti", "ujp", "tjp", 
	"fjp",   "call", "ret", "retv","chkh","chkl","nop", 
	"proc",  "end",  "bgn", "sym", "dump","none"

};
#endif
