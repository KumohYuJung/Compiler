#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NO_SYMBOLS 40
#define NO_KEYWORDS 7
#define ID_LENGTH 12
enum tsymbol {
  tnull = -1, tnot, tnotequ, tmod, tmodAssign, tident, tnumber,
  tand, tlparen, trparen, tmul, tmulAssign, tplus,
  tinc, taddAssign, tcomma, tminus, tdec, tsubAssign,
  tdiv, tdivAssign, tsemicolon, tless, tlesse,tassign,
  tequal, tgreat, tgreate, tlbracket, trbracket, teof,
  tconst, telse, tif, tint, treturn , tvoid,
  twhile, tlbrace, tor, trbrace
};

struct tokenType 
{
	int number;
	union {
		char id[ID_LENGTH];
		int num;
	}value;
};

char * keyword[NO_KEYWORDS] = {
	"const", "else", "if", "int", "return", "void", "while"
};

enum tsymbol tnum[NO_KEYWORDS] = 
{
	tconst, telse, tif, tint, treturn, tvoid, twhile
};

void lexicalError(int n)
{
	printf(" *** Lexical Error : ");
	switch(n)
	{
		case 1: 
			printf("an identifier length must be less than 12.\n");
			break;
		case 2:
			printf("next character must be &.\n");
			break;
		case 3:
			printf("next character must be |.\n");
			break;
		case 4:
			printf("invalid character!!!\n");
			break;
	}
}
int hexValue(char ch)
{
	switch(ch)
	{
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':
			return (ch - '0');
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
			return (ch -'A' + 10);
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			return (ch - 'a' + 10);
		default :
			return -1;
	}
}
int getIntNum(char firstCharacter)
{
	int num = 0;
	int value;
	char ch;

	if (firstCharacter != '0')
	{
		ch = firstCharacter;
		do {
			num = 10 * num + (int)(ch - '0');
			ch = getchar();
		}while(isdigit(ch));
	}
	else
	{
		ch = getchar();
		if((ch >= '0' && ch <= '7'))
		{
			do{
				num = 8* num + (int)(ch - '0');
				ch = getchar();
			}while ((ch >= '0') || (ch <= '7'));
		}
		else if((ch == 'x') || (ch == 'X'))
		{
			while((value = hexValue(ch = getchar())) != -1)
				num = 16 * num + value;
		}
		else num = 0;
	}
	ungetc(ch, stdin);
	return num;
}
int superLetter(char ch)
{
	if(isalpha(ch) || ch =='_') return 1;
	else return 0;
	
}
int superLetterOrDigit(char ch)
{
	if(isalnum(ch) || ch =='_')
		return 1;
	else return 0;
}
struct tokenType scanner()
{
	struct tokenType token;
	int i, index;
	char ch, id[ID_LENGTH];

	token.number = tnull;

	do {
		while (isspace(ch = getchar()));
		if(superLetter(ch)) {
			i = 0;
			do{
				if(i < ID_LENGTH) id[i++] = ch;
				ch = getchar();
			
			}while(superLetterOrDigit(ch));
			if(i >= ID_LENGTH) lexicalError(1);
			id[i] = '\0';
			ungetc(ch, stdin);

			for(index = 0; index < NO_KEYWORDS; index++)
				if(!strcmp(id, keyword[index])) break;
			if( index < NO_KEYWORDS ){
				token.number = tnum[index];
				printf("%s\t",keyword[index]);
			}
			else
			{
				token.number = tident;
				strcpy(token.value.id, id);
				printf("%s\t",token.value.id);
			}
		}
		else if( isdigit(ch) )
		{
			token.number = tnumber;
			token.value.num = getIntNum(ch);
			printf("number\t");
		}
		else
		{
			switch(ch)
			{
				case '/':
					ch = getchar();
					if(ch == '*')
					{
						do{
							while( ch != '*' ) ch = getchar();
							ch = getchar();
						}while(ch != '/');
					}
					else if( ch == '/' )
						while (getchar() != '\n');
					else if( ch == '=' )
					{
						token.number = tdivAssign;
						printf("/=\t");
					}
					else
					{
						token.number = tdiv;
						printf("/\t");
						ungetc(ch, stdin);
					}
					break;
				case '!':
					ch = getchar();
					if(ch == '='){
						token.number = tnotequ;
						printf("!=\t");
					}
					else
					{
						token.number = tnot;
						printf("!\t");
						ungetc(ch, stdin);
					}
					break;
				case '%':
					ch = getchar();
					if(ch == '=')
					{
						token.number = tmodAssign;
						printf("%=\t");
					}
					else
					{
						printf("%\t");
						token.number = tmod;
						ungetc(ch, stdin);
					}
					break;
				case '&':
					ch = getchar();
					if( ch == '&' ){
						token.number = tand;
						printf("&&\t");
					}
					else
					{
						lexicalError(2);
						ungetc(ch, stdin);
					}
					break;
				case '*':
					ch = getchar();
					if(ch == '='){
						printf("*=\t");
						token.number = tmulAssign;
					}
					else
					{
						token.number = tmul;
						printf("*\t");
						ungetc(ch,stdin);
					}
					break;
				case '+':
					ch = getchar();
					if(ch == '+'){
						token.number = tinc;
						printf("++\t");
					}
					else if(ch == '='){
						token.number = taddAssign;
						printf("+=\t");
					}
					else
					{
						printf("+\t");
						token.number = tplus;
						ungetc(ch, stdin);
					}
					break;
				case '-':
					ch = getchar();
					if(ch == '-'){
						printf("--\t");
						token.number = tdec;
					}
					else if( ch == '=' )
					{
						printf("-=\t");
						token.number = tsubAssign;
					}
					else
					{
						printf("-\t");
						token.number = tminus;
						ungetc(ch, stdin);
					}
					break;
				case '<':
					ch = getchar();
					if(ch == '='){
						token.number = tlesse;
						printf("<=\t");
					}
					else 
					{
						token.number = tless;
						printf("<\t");
						ungetc(ch, stdin);
					}
					break;
				case '=':
					ch = getchar();
					if(ch == '='){
						printf("==\t");
						token.number = tequal;
					}
					else
					{
						token.number = tassign;
						printf("-\t");
						ungetc(ch, stdin);
					}
					break;
				case '>':
					ch = getchar();
					if(ch == '=') {
						printf(">=\t");
						token.number = tgreate;
					}
					else
					{
						printf(">\t");
						token.number = tgreat;
						ungetc(ch, stdin);
					}
					break;
				case '|':
					ch = getchar();
					if(ch == '|') {
						printf("||\t");
						token.number = tor;
					}
					else
					{
						lexicalError(3);
						ungetc(ch, stdin);
					}
					break;
				case '(': token.number = tlparen; printf("(\t");break;
				case ')': token.number = trparen;printf(")\t"); break;
				case ',': token.number = tcomma; printf(",\t");break;
				case ';': token.number = tsemicolon;printf(";\t"); break;
				case '[': token.number = tlbracket; printf("[\t");break;
				case ']': token.number = trbracket; printf("]\t");break;
				case '{': token.number = tlbrace; printf("{\t");break;
				case '}': token.number = trbrace; printf("}\t");break;
				case EOF: token.number = teof;  break;
				default:
					printf("Current character : %c", ch);
					lexicalError(4);
					break;
			}
			
		}
	}while (token.number == tnull);
	return token;
}

int main(int argc, char * argv[])
{
	if (argc != 2) printf("wrong number of arguments\n");

	freopen(argv[1], "r", stdin);
	struct tokenType token;
	while ((token=scanner()).number != teof)
	{
		if(token.number != 4)
			printf("%d\t%d\n", token.number,token.value.num);
		else
			printf("%d\t%s\n", token.number,token.value.id);

	}
	return 0;
}
