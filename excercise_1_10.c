#include <stdio.h>

int main()
{
	int c, t /* Tabulator */, b /* backspace */, bs /*\*/;

	while ((c = getchar()) != EOF){
		if (c  == '\t'){
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b'){
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\'){
			putchar('\\');
			putchar('\\');
		}
		else{
			putchar(c);
		}
	}
}
