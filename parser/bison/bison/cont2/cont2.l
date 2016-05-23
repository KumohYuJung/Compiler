%{
#include <stdio.h>
#include "cont2.tab.h"
%}
%%
[0-9]+		yylval=atoi(yytext); return TNUMBER;
heat		return THEAT;
\?		return TASK;
on|off		yylval=!strcmp(yytext, "on"); return TSWITCH;
set		return TSET;
get		return TGET;
temperature	return TTEMP;
[ \n\t]+	;
.		printf("Unrecognized character!\n");
%%
