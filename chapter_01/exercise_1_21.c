#include <stdio.h>
#define TAB 8
#define MAX 1000

int get_line(char line[]);
void detab(char line[], char clean_line[]);

int main()
{
	char line[MAX];
	char clean_line[MAX];

	int len;

	while ((len = get_line(line)) > 0)
	{
		detab(line, clean_line);
		printf("%s", clean_line);
	}
	return 0;
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

void detab(char line[], char clean_line[])
{
	int i, k, count, j, n;
	count = k = 0;

	for (i = 0; line[i] != '\n' && line[i] != EOF; ++i)
	{
		if (line[i] != ' ')
		{
			for (int l = 0; l < count; ++l)
			{
				clean_line[k] = ' ';
				++k;
			}

			count = 0;
			clean_line[k] = line[i];
			++k;
		}
		else
		{
			++count;
			if (count >= TAB)
			{
				clean_line[k] = '\t';
				count = count - TAB;
				++k;
			}

		}
	}

	if (line[i] == '\n')
	{
		clean_line[k] = line[i];
		++k;

	}

	for (int f = 0; f < count; ++f)
                {
                        clean_line[k] = ' ';
                        ++k;
		}
	clean_line[k] = '\0';
}
