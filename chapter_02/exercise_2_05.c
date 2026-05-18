#include <stdio.h>

#define MAX 200

/* Function prototypes */
int get_line(char s[]);
int any(char s1[], char s2[]);

int main(void)
{
        char s1[MAX], s2[MAX];

        /* Continuously process pairs of input lines until EOF or empty input */
        while (get_line(s1) > 0 && get_line(s2) > 0)
        {
                printf("Ergebnis: %i\n", any(s1, s2));
        }

        return 0;
}

/**
 * @brief Reads a line from standard input into the buffer.
 * 
 * Reads characters until a newline character, EOF, or the buffer 
 * limit (MAX - 1) is reached. Ensures proper null-termination.
 * 
 * @param s Character array to store the input line.
 * @return int The length of the string read (excluding the null terminator).
 */
int get_line(char s[])
{
        int c, i;

        /* Read characters until limit, EOF, or newline is encountered */
        for (i = 0; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
        {
                s[i] = c;
        }

        s[i] = '\0'; /* Safely terminate the string */
        return i;
}

/**
 * @brief Finds the first location in string s1 where any character from s2 occurs.
 * 
 * Mimics the standard C library function strpbrk, but returns an index 
 * instead of a pointer.
 * 
 * @param s1 The main string to search through.
 * @param s2 The string containing characters to look for.
 * @return int The index of the first match in s1, or -1 if no match is found.
 */
int any(char s1[], char s2[])
{
        int i, j;

        /* Iterate through each character of the main string s1 */
        for (i = 0; s1[i] != '\0'; i++)
        {
                /* Compare against each character of the search string s2 */
                for (j = 0; s2[j] != '\0'; j++)
                {
                        /* If a matching character is found, return its index in s1 */
                        if (s2[j] == s1[i])
                        {
                                return i;
                        }
                }
        }
        
        return -1; /* Return -1 if no characters match */
}
