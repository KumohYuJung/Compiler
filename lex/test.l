%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber {TEOF, TIDEN, TNUM, TASSIGN, TADD, TSEMI, TDOT, TBEGIN, TEND, TERROR};
%}
letter	[a-zA-Z]
digit		[0-9]
%%
begin													return(TBEGIN);
end														return(TEND);
{letter}({letter}|digit)*			return(TIDEN);
":="													return(TASSIGN);
"+"														return(TADD);
{digit}+											return(TNUM);
";"														return(TSEMI);
\.														return(TDOT);
[ \t\n]												;
.															return(TERROR);
%%
int main()
{
	enum tnumber tn; /* token number */
	printf(" Start of Lex\n");
	while((tn=yylex()) != TEOF) {
		switch(tn){
			case TBEGIN : printf("Begin\n"); break;
			case TEND : printf("End\n"); break;
			case TIDEN : printf("Identifier: %s\n", yytext); break;
			case TASSIGN : printf("Assignment_op\n"); break;
			case TADD : printf("Add_op\n"); break;
			case TNUM : printf("Number: %d\n", atoi(yytext)); break;
			case TSEMI : printf("Semicolon\n"); break;
			case TDOT : printf("Dot\n"); break;
			case TERROR : printf("Error: %c\n", yytext[0]); break;
		}
	}
	return 0;
}
int yywrap()
{
	printf(" End of Lex\n");
	return 1;
}