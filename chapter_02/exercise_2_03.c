#include <stdio.h>

#define MAX 100
int get_string(char string[]);
int convert(char string[]);

int main()
{
	char string[MAX];
	int len;

	 // at first I am asking for input
	printf("Hex-number: ");

	while ((len = get_string(string)) != 0) // and after that I want to get an array of the input, to don't have to use getchar() all the time, and to be able to go backwards in the input
	{
		printf("Result: %i\n", convert(string)); // at the end I output the result of the convert-function, wich purpose is to ...
		printf("Hex-number: ");
	}

}

int get_string(char string[])
{
	int i, c;

	for (i=0; (c=getchar()) != '\n' && c != EOF && i < MAX-1; ++i)
	{
		string[i] = c;
	}
	string[i] = '\0';
	return i;
}

int convert(char string[])
{
	char c;
	int i, output, s;
	output = s = 0;

	if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X'))
		i = 2;
	else
		i = 0;

	for (; string[i] != '\0'; ++i)
	{
		c = string[i];

                // check if the character is a valid digit (0-9)
                if (c >= '0' && c <= '9')
                {
                        output = output * 16 + (c - '0');
                }
                // check for uppercase hex letters (A-F)
                else if (c >= 'A' && c <= 'F')
                {
                        output = output * 16 + (c - 'A' + 10);
                }
                // check for lowercase hex letters (a-f)
                else if (c >= 'a' && c <= 'f')
                {
                        output = output * 16 + (c - 'a' + 10);
                }
                // if it's not a valid hex character, stop the conversion
                else
                {
			printf("Invalid!\n");
                        break;
                }

	}
	return output;
}
