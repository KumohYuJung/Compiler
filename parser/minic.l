%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "minic.tab.h"

	char* toString(char *string);
%}

DIGIT 	[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]+)?
ID	[A-Za-z_][A-Za-z0-9_]*

%%

"int" return TINT;
"void" return TVOID;
"const" return TCONST;
"while" return TWHILE;
"for" return TFOR;
"if" return TIF;
"else" return TELSE;
"switch" return TSWITCH;
"continue" return TCONTINUE;
"break" return TBREAK;
"return" return TRETURN;
"case" return TCASE;
"default" return TDEFAULT;
"++" return TINC;
"--" return TDEC;
"+=" return TADDASSIGN;
"-=" return TSUBASSIGN;
"*=" return TMULASSIGN;
"%=" return TMODASSIGN;
"/=" return TDIVASSIGN;
"||" return TOR;
"&&" return TAND;
">=" return TGE;
"<=" return TLE;
"==" return TEQ;
"!=" return TNE;
[\+\-\*/%\(\)<>\[\],;\{\}\.\/=:] {
	
	return yytext[0];
}

"//".* ;
"/*"([^*]|\*+[^*/])*\**"*/" ;

{DIGIT}	{ 
	yylval.string = toString(yytext);
	return TINTEGER;
}
{ID}	{
	yylval.string = toString(yytext);
	return TIDENTITY;
}

[ \t\n]    ;
.  {
	printf("I don't know what this means : %s.\n",yytext);
}
%%

int yywrap()
{
	return 1;
}
