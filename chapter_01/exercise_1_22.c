#include <stdio.h>

#define BORDER 20
#define MAX 1000

int get_line(char line[]);
void formate(char line[], int len);

int main()
{
	int len = 0;
	char line[MAX];

	while ((len = get_line(line)) > 0)
	{
		formate(line, len);
		printf("%s", line);
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

void formate(char line[], int len)
{
	int i, highest;
	highest = 0;

	while ((len - highest) > BORDER)
	{
		int last_highest = highest;

		for (i = 0 + last_highest; line[i] != '\0' && i < MAX - 2; ++i)
		{
			if (line[i] == ' ' || line[i] == '\t')

				if (i <= last_highest +  BORDER)
					highest = i;
		}
		if (highest == last_highest)
                        highest = last_highest + BORDER;
		line[highest] = '\n';
	}
}
