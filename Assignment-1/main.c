#include <stdio.h>
#include "string_module.h"
#include "array_module.h"

int main()
{
    char s1[100], s2[100];
    int arr[100], n, key;

    /* Demonstrate string comparison */
    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    printf("String Compare Result: %d\n", stringCompare(s1, s2, 0));

    /* Palindrome check */
    printf("Enter string for palindrome check: ");
    scanf("%s", s1);

    if (isPalindrome(s1, 0, stringLength(s1, 0) - 1))
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    /* Replace character */
    char c1, c2;
    printf("Enter string: ");
    scanf("%s", s1);

    printf("Enter character to replace: ");
    scanf(" %c", &c1);

    printf("Enter new character: ");
    scanf(" %c", &c2);

    replaceChar(s1, c1, c2, 0);
    printf("Updated string: %s\n", s1);

    /* Smallest character */
    printf("Smallest character: %c\n", smallestChar(s1, 0));

    /* Array operations */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Largest element: %d\n", findLargest(arr, n));

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (searchElement(arr, n, key))
        printf("Element Found\n");
    else
        printf("Element Not Found\n");

    printf("Reverse order: ");
    printReverse(arr, n);
    printf("\n");

    printf("Sum of elements: %d\n", arraySum(arr, n));

    return 0;
}
