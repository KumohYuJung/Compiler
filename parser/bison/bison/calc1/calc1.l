%{
#include <stdlib.h>
void yyerror(char *);
#include "calc1.tab.h"
%}

%%

[0-9]+ { yylval = atoi(yytext);
	 return INTEGER;
	}

[-+\n]	return *yytext;
[ \t]	;

.	yyerror("invalid character");
%%

