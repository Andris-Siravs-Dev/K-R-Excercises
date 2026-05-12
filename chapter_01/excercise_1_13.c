#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
	int c, state;
	state = OUT;

	while ((c = getchar()) != EOF){

		if (c != ' ' && c != '\n' && c != '\t' && c != ',' && c != '.' && c != '!' && c != '?')
		{
			state = IN;
			putchar('*');
		}

		else if (state == OUT && (c == ',' || c == '\t' && c != ',' && c != '.' && c != '!' && c != '?'))
			;

		else
			putchar('\n');
	}

	return 0;

}
