#include <stdio.h>
#define MAX 1000

int get_line(char line[]);

int main()
{
	int len;
	char line[MAX];

	while ((len = get_line(line)) > 0)
	{
		printf("%s", reverses(line, len));
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

char reverses(char alt[], int lenght)
{
	int i, j;
	char reversed[lenght];

	for (i = 0; (lenght-(i+2)) > 1; ++i)
	{						// 				    0 1  2  3
		if (alt[lenght-(i+2)] != '\n')		//lenght - 3 -> wenn ich ein array [0,1,\n,\0] habe, und es umdrehen möchte, dann möchte ich mit dem zeichen auf index 1 beginnen, die länge ist 4, also rechne ich 4 - 2, dann 4 - 3,
			reversed[i] = alt[lenght-(i+2);//-> also doch lenght - 2 bis ich bei der 1 bin, da höre ich auf, also für lenght > 1, dann am anfang habe ich i = 2, und dann habe ich ++i, aber ich muss erst prüfen ob \n üerhaupt
		else					// existent ist
			reversed[i] = '\n';		// if alt[lenght - 2] != '\n' do ++lenght.
	}
	reversed[i+1] = '\0';

	return reversed[i];
}
