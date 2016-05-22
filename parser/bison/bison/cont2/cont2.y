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
		if ($2)
			printf("\tHeater on!\n");
		else
			printf("\tHearter off!\n");
	}
	;
target_set:
	TSET TTEMP TNUMBER
	{
		printf("\tTemperature set %d\n", $3);
	}
	;
get_temperature:
	TGET TTEMP
	{	
		printf("\tGet current temperature\n");
	}
	;
