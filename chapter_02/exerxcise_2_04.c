#include <stdio.h>
#define MAX 1000

/* Function prototypes */
int get_input(char s[]);
void squeeze(char s1[], char s2[], char s[]);

int main()
{
        char s1[MAX], s2[MAX], s[MAX];

        /* Continuously process pairs of inputs until one of them is empty */
        while (get_input(s1) > 0 && get_input(s2) > 0)
        {
                squeeze(s1, s2, s);
                printf("%s\n", s);
        }
}

/* Reads a line of input from standard input (stdin) 
   and returns the length of the string */
int get_input(char s[])
{
        int i, c;

        /* Read characters until EOF, a newline ('\n'), or array limit is reached */
        for (i=0; (c=getchar()) != EOF && c != '\n' && i < MAX-1; i++)
        {
                s[i] = c;
        }

        s[i] = '\0'; /* Null-terminate the string */
        return i;    /* Return string length to control the main loop */
}

/* Removes all characters from s1 that match any character in s2,
   and stores the filtered result in s */
void squeeze(char s1[], char s2[], char s[])
{
        int i, j, k, gefunden;
        i = k = 0; /* Initialize indices for s1 (i) and destination s (k) */

        /* Loop through each character of the source string s1 */
        for (; s1[i] != '\0'; i++)
        {
                gefunden = 0; /* Reset flag for each new character in s1 */
                j = 0;        /* Always reset s2 index to scan from the beginning */

                /* Check if the current character s1[i] exists anywhere in s2 */
                for (; s2[j] != '\0'; j++)
                {
                        if (s1[i] == s2[j])
                        {
                                gefunden = 1; /* Match found, character should be removed */
                                break;        /* Exit inner loop early to save time */
                        }
                }

                /* If the character was not found in s2, keep it and copy to s */
                if (gefunden == 0)
                        s[k++] = s1[i];

        }
        s[k] = '\0'; /* Null-terminate the output string to prevent memory corruption */
}

