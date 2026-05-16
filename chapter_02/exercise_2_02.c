/*Schreiben Sie eine SChleife, die zu der obigen for-Scheife äquivalent ist, ohne die Operatoren && oder || zu verwenden:
  for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;*/

#include <stdio.h>

int main()
{
	int i, c;
	i = 0;
	int lim = 5000;
	char s[lim];

	while (i<lim-1)
	{
		if ((c=getchar()) != '\n')
		{
			if (c != EOF)
			{
				s[i] = c;
				++i;
			}
			else
				i = lim-1;
		}
		else
			i = lim-1;
	}
}
