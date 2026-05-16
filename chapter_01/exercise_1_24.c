#include <stdio.h>

#define MAX 5000
#define IN 1
#define OUT 0

void check(char code[]);
int get_array(char code[]);

int main()
{
	char code[MAX];

	int len;

	while ((len = get_array(code)) > 0)
	{
		check(code);
	}
	return 0;
}

int get_array(char code[])
{
	int i, c;

	for (i = 0; (c = getchar()) != EOF && i < MAX-1; ++i)

		code[i] = c;

	code[i] = '\0';

	return i;
}

void check(char code[])
{
	int i, fehler, j, state_string, string_count, state_comment;
	int nl = 1;
	char bracket[MAX];
	int oben = fehler = state_string = state_comment = string_count = OUT;


	// Start der Syntaxüberprüfung:
	for (i = 0; code[i] != '\0'; ++i)
	{
		if (code[i] == '\n')
		{
                        ++nl; //muss noch die states ändern!
                        state_comment = OUT;
                        if (state_string == IN && (string_count % 2 != 0))
                        {
                                printf("String in Zeile %i wurde nicht geschlossen!\n", nl-1);
                                        state_string = OUT;
                        }
                }


		else if ((code[i] == '"' || code[i] == '\'') && code[i-1] != '\\' && state_comment != IN)
		{
			state_string = !state_string;
			++string_count;
		}

		else if (code[i] == '/' && code[i+1] == '/')
		{
			state_comment = IN;
			++i; // es werden ja 2 zeichen geprüft
		}

		else if (code[i] == '/' && code[i+1] == '*')
		{
			for (j = i; code[j] != '\0' && code[j] != '*' && code[j+1] != '/'; ++j)
				;
			if (code[j] == '*' && code[j+1] == '/')
			{
				i = j+1; // ['*'; '/'; ziel], aber es wird in der for-schleife einmal erhöht, darum nicht j+2 sondern j+1
			}
		}

		else
		{
			if ((code[i] == ')' || code[i] == ']' || code[i] == '}') && state_comment != IN && state_string != IN)
			{
				if (oben > 0)
				{
					if ((bracket[oben-1] == '(' && code[i] == ')') || (bracket[oben-1] == '{' && code[i] == '}') || (bracket[oben-1] == '[' && code[i] == ']'))
					{
    						--oben;
					}


					else
					{
						if (fehler == 0)
							fehler = nl;

						printf("Klammern falsch gesetzt in Zeile %i!\n", nl);
					}
				}
			}
			else if ((code[i] == '(' || code[i] == '[' || code[i] == '{') && state_comment != IN && state_string != IN)
                	{
                        	bracket[oben] = code[i];
                        	++oben;
                	}

		}
	}
	if (oben > 0 || oben < 0)
		printf("Klammersyntax fehlerhaft ab %i\n.", fehler);
}
