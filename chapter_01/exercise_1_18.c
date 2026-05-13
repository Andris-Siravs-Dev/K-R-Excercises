
#include <stdio.h>

#define  SIZE 1000
#define IN 1
#define OUT 0

int len;
int get_line(char line[]);
int main()
{
	int c;
	char line[SIZE];

	while ((len = get_line(line)) > 0){
		printf("%s", line);
	}
}

int get_line(char line[])
{
	int state = IN;
	int c, i;

	for (i = 0; i < (SIZE - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

       	while (i > 0 && (line[i-1] == ' ' || line[i-1] == '\t')) {
        	--i;
    	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return  i;
}
