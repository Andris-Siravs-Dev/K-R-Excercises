# include <stdio.h>

int main()
{
	int c, l[256] = {0};

	while ((c = getchar()) != EOF)
	{
		++l[c];
	}

	for (int i = 0; i < 256; i++)
	{
	    if (l[i] != 0)
	    {
	        // 1. Namen/Zeichen ausgeben
	        if (i == 32) printf("Leerzeichen\t| ");
	        else if (i == 10) printf("Enter\t| ");
	        else printf("'%c'\t| ", i);

	        // 2. Die Anzahl als Sterne ausgeben
	        for (int j = 0; j < l[i]; j++)
	        {
	            putchar('*');
	        }

	        // 3. Zeilenumbruch für das nächste Zeichen
	        putchar('\n');
	    }
	}

	putchar('\n');
	return 0;
}

