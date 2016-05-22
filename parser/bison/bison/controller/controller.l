%{
#include <stdio.h>
#include "controller.tab.h"
%}
%%
[0-9]+		return TNUMBER;
heat		return THEAT;
\?		return TASK;
on|off		return TSWITCH;
set		return TSET;
get		return TGET;
temperature	return TTEMP;
[ \n\t]+	;
.		printf("Unrecognized character!\n");
%%
