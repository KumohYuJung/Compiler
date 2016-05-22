%{
#define NO_KEYWORDS 7
enum tsymbol {
  tnull = -1, tnot, tnotequ, tmod, tmodAssign, tident, tnumber, //7
  tand, tlparen, trparen, tmul, tmulAssign, tplus, // 6
  tinc, taddAssign, tcomma, tminus, tdec, tsubAssign, //6
  tdiv, tdivAssign, tsemicolon, tless, tlesse,tassign, 
  tequal, tgreat, tgreate, tlbracket, trbracket, teof,
  tconst, telse, tif, tint, treturn , tvoid,
  twhile, tlbrace, tor, trbrace, tfor, tswitch, tcase, tdefault, tbreak, tcontinue // 10
};
%}

DIGIT 	[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]+)?
ID	[A-Za-z_][A-Za-z0-9_]*

%%
"for"	printf ("%s\t%d\t0\n",yytext,tfor);
"switch"	printf ("%s\t%d\t0\n",yytext,tswitch);
"case"	printf ("%s\t%d\t0\n",yytext,tcase);
"default"	printf ("%s\t%d\t0\n",yytext,tdefault);
"break" printf ("%s\t%d\t0\n",yytext,tbreak);
"continue"	printf ("%s\t%d\t0\n",yytext,tcontinue);  	
"const"   printf ("%s\t%d\t0\n",yytext,tconst);
"else"   printf ("%s\t%d\t0\n",yytext,telse);
"if"   printf ("%s\t%d\t0\n",yytext,tif);
"int"   printf ("%s\t%d\t0\n",yytext,tint);
"return"   printf ("%s\t%d\t0\n",yytext,treturn);
"void"   printf ("%s\t%d\t0\n",yytext,tvoid);
"while"   printf ("%s\t%d\t0\n",yytext,twhile);
"("   printf ("%s\t%d\t0\n",yytext,tlparen);
")"   printf ("%s\t%d\t0\n",yytext,trparen);
","   printf ("%s\t%d\t0\n",yytext,tcomma);
";"   printf ("%s\t%d\t0\n",yytext,tsemicolon);
"["   printf ("%s\t%d\t0\n",yytext,tlbracket);
"]"   printf ("%s\t%d\t0\n",yytext,trbracket);
"{"   printf ("%s\t%d\t0\n",yytext,tlbrace);
"}"   printf ("%s\t%d\t0\n",yytext,trbrace);
"!="   printf ("%s\t%d\t0\n",yytext,tnotequ);
"!"   printf ("%s\t%d\t0\n",yytext,tnot);
"%="   printf ("%s\t%d\t0\n",yytext,tmodAssign);
"%"   printf ("%s\t%d\t0\n",yytext,tmod);
"&&"   printf ("%s\t%d\t0\n",yytext,tand);
"*="   printf ("%s\t%d\t0\n",yytext,tmulAssign);
"*"   printf ("%s\t%d\t0\n",yytext,tmul);
"+="   printf ("%s\t%d\t0\n",yytext,taddAssign);
"++"   printf ("%s\t%d\t0\n",yytext,tinc);
"+"   printf ("%s\t%d\t0\n",yytext,tplus);
"-="   printf ("%s\t%d\t0\n",yytext,tdec);
"--"   printf ("%s\t%d\t0\n",yytext,tsubAssign);
"-"   printf ("%s\t%d\t0\n",yytext,tminus);
"<="   printf ("%s\t%d\t0\n",yytext,tlesse);
"<"   printf ("%s\t%d\t0\n",yytext,tless);
"=="   printf ("%s\t%d\t0\n",yytext,tequal);
"="   printf ("%s\t%d\t0\n",yytext,tassign);
">="   printf ("%s\t%d\t0\n",yytext,tgreate);
">"   printf ("%s\t%d\t0\n",yytext,tgreat);
"||"   printf ("%s\t%d\t0\n",yytext,tor);

"//".*	printf("line commnet\n");
"/*"([^*]|\*+[^*/])*\**"*/" printf("multi-line comment\n");

{DIGIT}	{ 
		printf ("number\t%d\t%d\n",tnumber,atoi(yytext)); }
{ID}		printf("%s\t%d\t%s\n", yytext, tident, yytext);

[ \t\n]    ;
. printf("Unrecognized character: %s\n",yytext);

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
