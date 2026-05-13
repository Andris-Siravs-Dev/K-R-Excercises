#include <stdio.h>
#define TAB 8
#define MAX 1000

int get_line(char line[]);
void entab(char line[], char clean_line[]);
int main()
{
	char line[MAX];
	char clean_line[MAX];
	int len;
	while ((len = get_line(line)) > 0)
	{
		entab(line, clean_line);
		printf("%s", clean_line);
	}
}

int get_line(char line[])
{
	int i, c;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

void entab(char line[], char clean_line[])
{
	int i, n, k;
	for (i = 0, k = 0; line[i] != EOF && line[i] != '\n'; ++i)
	{
		if (line[i] != '\t')
		{
			clean_line[k] = line[i];
			++k;
		}
		else
		{
			n = TAB - (i % TAB);
			for (int j = 0; j <  n; j++)
			{
				clean_line[k] = ' ';
				++k;
			}
		}
	}
	clean_line[k] = '\0';

}
