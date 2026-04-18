#include <stdio.h>
#include "array_module.h"

/* Find largest element */
int findLargest(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int max = findLargest(arr, n - 1);

    if (arr[n - 1] > max)
        return arr[n - 1];
    else
        return max;
}

/* Search element in array */
int searchElement(int arr[], int n, int key)
{
    if (n == 0)
        return 0;

    if (arr[n - 1] == key)
        return 1;

    return searchElement(arr, n - 1, key);
}

/* Print array in reverse */
void printReverse(int arr[], int n)
{
    if (n == 0)
        return;

    printf("%d ", arr[n - 1]);
    printReverse(arr, n - 1);
}

/* Sum of array elements */
int arraySum(int arr[], int n)
{
    if (n == 0)
        return 0;

    return arr[n - 1] + arraySum(arr, n - 1);
}
