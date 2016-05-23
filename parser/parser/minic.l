%{
	#include <stdlib.h>
	#include "minic.h"
	#include "minic.tab.h"

	void yyerror(char *s);
%}

DIGIT 	[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]+)?
ID	[A-Za-z_][A-Za-z0-9_]*

%%

"int" return INT;
"void" return VOID;
"const" return CONST;
"while" return WHILE;
"for" return FOR;
"if" return IF;
"else" return ELSE;
"switch" return SWITCH;
"continue" return CONTINUE;
"break" return BREAK;
"return" return RETURN;
"case" return CASE;
"default" return DEFAULT;
"++" return INC;
"--" return DEC;
"+=" return ADDASSIGN;
"-=" return SUBASSIGN;
"*=" return MULASSIGN;
"%=" return MODASSIGN;
"/=" return DIVASSIGN;
"||" return OR;
"&&" return AND;
">=" return GE;
"<=" return LE;
"==" return EQ;
"!=" return NE;
[\+\-\*/%\(\)<>\[\],;\{\}\.\/=:] {
	
	return yytext[0];
}

"//".* ;
"/*"([^*]|\*+[^*/])*\**"*/" ;

{DIGIT}	{ 
	yylval.iValue = atoi( yytext );
	return INTEGER;
}
{ID}	{
	yylval.string = yytext;
	return IDENTITY;
}

[ \t\n]    ;
.  yyerror("Unknown Character!\n");

%%
