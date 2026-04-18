#include "string_module.h"

/* Returns length of string */
int stringLength(char s[], int i)
{
    if (s[i] == '\0')
        return 0;

    return 1 + stringLength(s, i + 1);
}

/* Compares two strings alphabetically */
int stringCompare(char s1[], char s2[], int i)
{
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;

    if (s1[i] == '\0')
        return -1;

    if (s2[i] == '\0')
        return 1;

    if (s1[i] < s2[i])
        return -1;

    if (s1[i] > s2[i])
        return 1;

    return stringCompare(s1, s2, i + 1);
}

/* Checks if string is palindrome */
int isPalindrome(char s[], int start, int end)
{
    if (start >= end)
        return 1;

    if (s[start] != s[end])
        return 0;

    return isPalindrome(s, start + 1, end - 1);
}

/* Replace all occurrences of c1 with c2 */
void replaceChar(char s[], char c1, char c2, int i)
{
    if (s[i] == '\0')
        return;

    if (s[i] == c1)
        s[i] = c2;

    replaceChar(s, c1, c2, i + 1);
}

/* Find smallest character */
char smallestChar(char s[], int i)
{
    if (s[i + 1] == '\0')
        return s[i];

    char minChar = smallestChar(s, i + 1);

    if (s[i] < minChar)
        return s[i];
    else
        return minChar;
}
