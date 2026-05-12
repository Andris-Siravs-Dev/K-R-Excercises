#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c, state;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			putchar('\n');
			putchar(c);
		}
		else
			putchar(c);
	}
	putchar('\n');

}
