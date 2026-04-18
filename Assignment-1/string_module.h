#ifndef STRING_MODULE_H
#define STRING_MODULE_H

/* String related recursive functions */

int stringLength(char s[], int i);
int stringCompare(char s1[], char s2[], int i);
int isPalindrome(char s[], int start, int end);
void replaceChar(char s[], char c1, char c2, int i);
char smallestChar(char s[], int i);

#endif
