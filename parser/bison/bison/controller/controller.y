%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
	fprintf(stderr, "error: %s\n", str);
}

int yywrap()
{
	return 1;
}

main()
{
	yyparse();
}
%}

%token TNUMBER THEAT TASK TTEMP TSWITCH TSET TGET
%%

commands: 
	| commands command
	;

command:
	ask_state
	|
	heat_switch
	|
	target_set
	|
	get_temperature
	;

ask_state:
	THEAT TASK
	{
		printf("\tHeater status report\n");
	}
	;
heat_switch:
	THEAT TSWITCH
	{
		printf("\tHeater switch on or off\n");
	}
	;
target_set:
	TSET TTEMP TNUMBER
	{
		printf("\tTemperature set\n");
	}
	;
get_temperature:
	TGET TTEMP
	{	
		printf("\tGet current temperature\n");
	}
	;
