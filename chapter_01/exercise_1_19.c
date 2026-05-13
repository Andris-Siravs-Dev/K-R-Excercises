#include <stdio.h>
#define MAX 1000

int get_line(char line[]);
void reverses(char line[], int lenght);
int main()
{
	int len;
	char line[MAX];

	while ((len = get_line(line)) > 0)
	{
		reverses(line, len);
		printf("%s", line);
	}
	putchar('\n');

	return 0;
}

int get_line(char line[])
{
	int i, c;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;

	if (c == '\n'){
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

void reverses(char line[], int lenght)
{
	int start, end;
	start = 0;
	end = lenght-1;

	if (end >= 0 && line[end] == '\n')
		--end;

	while (end > start){
		char temp = line[start];
		line[start] = line[end];
		line[end] = temp;
		++start;
		--end;
	}
}
