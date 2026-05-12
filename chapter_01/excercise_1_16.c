#include <stdio.h>
#define MAXLINE 1000 /* Maximale Größe des Speichers */

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max = 0;
    char line[MAXLINE];    // Der Speicher bleibt begrenzt...
    char longest[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;     // ...aber max speichert die ECHTE Länge (z.B. 2000)
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("\nLängste Zeile hatte %d Zeichen.\n", max);
        printf("Anfang der Zeile: %s\n", longest);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    // Wir zählen i immer hoch, aber schreiben nur in s, solange Platz ist
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }

    if (c == '\n') {
        if (i < lim - 1) {
            s[i] = c;
        }
        ++i;
    }

    // Sicherstellen, dass der String korrekt endet
    if (i < lim) {
        s[i] = '\0';
    } else {
        s[lim - 1] = '\0';
    }

    return i; // Gibt die tatsächliche Länge zurück, auch wenn i > MAXLINE
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

