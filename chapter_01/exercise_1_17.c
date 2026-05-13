
#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int get_line(char line[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line)) > 0)
		if (len > 80)
			for (int i = 0; line[i] != '\0' && i < MAXLINE; ++i)
				putchar(line[i]);
	return 0;
}

int get_line(char line[])
{
	int c, i;

        for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
       	        line[i] = c;

 	if (c == '\n'){
               	line[i] = c;
               	++i;
       	}

       	line[i] = '\0';

       	return i;
}
