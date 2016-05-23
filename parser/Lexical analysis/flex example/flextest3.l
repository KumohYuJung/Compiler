/* scanner for a toy Pascal-like language */

%{
/* need this for the call to atof() below */
#include <math.h>
%}

DIGIT 	[0-9]
ID	[a-z][a-z0-9]*

%%

{DIGIT}+	{ 
		printf ("An integer: %s (%d) \n", yytext, atoi(yytext)); }
{DIGIT}+"."{DIGIT}*	{
		printf("A float: %s (%g)\n", yytext, atof(yytext)); }
if|then|begin|end|procedure|function	{
		printf("A keyword: %s\n", yytext); }
{ID}		printf("An identifier: %s\n", yytext);
"+"|"-"|"*"|"/"	printf("An operator: %s\n", yytext);
"{"[^}\n]"}"	/* eat up one-line comments */
[ \t\n]+	/* eat up whitespaces */
.		printf("Unrecognized charater: %s\n", yytext);
%%

int main (argc, argv)
int argc;
char **argv;
{
	++argv, --argc;
	if (argc > 0)
		yyin = fopen (argv[0], "r");
	else
		yyin = stdin;
	yylex();
}
