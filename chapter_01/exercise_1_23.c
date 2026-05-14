#include <stdio.h>

#define MAX 400
int in_comment = 0;

int get_line(char line[]);
int edit(char line[], char out[]);

int main()
{
	char line[MAX];
	char out[MAX];
	int i, len;

	while((len = get_line(line)) > 0)
	{
		edit(line, out);
		printf("%s", out);
	}
	return 0;

}

int get_line(char line[]) // Man zeieht sich Zeilen in Form von Arrays raus
{
	int i, c;

	for (i = 0; (c = getchar()) != EOF && c != '\n' && i <= MAX - 2; ++i)

		line[i] = c;

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

int  edit(char line[], char out[])
{
	int i, o, j;
	o = i = j = 0;

	while(line[i] != '\0') // Soll durch das Array durchgehen, und ihn nur unter einer bestimmten Bedingung hinzufügen
	{
		// Prüfung ob ich in einem Boxkommentar bin
		if (in_comment) {
			if (line[i] == '*' && line[i+1] == '/') {
        			in_comment = 0;
        			i += 2;
    			}
			else
			{
        			i++;
    			}
   		 	continue;
		}



		if (line[i] == '/' && line[i] != '\0' && line[i+1] != '\0' && (line[i+1] == '/' || line[i+1] ==  '*')) // bei einem kommentar // muss nichts passieren, i muss nur an das ende der zeile bis '\n' kommen
		{

			for (j = i; line[j] != '\n' && line[j] != '\0'; ++j)
				;

			if (line[j] == '\n' ||line[j] == '\0')
			{
				i = j;
				out[o] = line[i];
				++i;
				++o;
			}

			else if (line[j] == '*' && line[j+1] == '/') 	/* Ende boxkommentar, wenn box kommentar angefangen hat, soll nichts passieren... also automatisch, aber wenn ich eine neue zeile habe, weiß die ja gar nicht,
									 dass sie drinnen ist, dass muss ich also auch überprüfen... am Anfang */
			{
				in_comment = 0;
				j = j+2;
				i = j;
				out[o] = line[i];
				++o;
			}
			else
				++i;
		}

		else
		{

			out[o] = line[i];
			++i;
			++o;
		}
	}

	out[o] = '\0';
	return in_comment;
}

