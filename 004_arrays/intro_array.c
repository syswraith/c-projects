#include <stdio.h>

int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[5] = {1,2,3,4,5};
    printf("Size of without specifying array size: %lu bytes\nSize with specifying array size: %lu bytes\n", sizeof(arr1), sizeof(arr2));
    printf("Number of elements in arr1: %d\nNumber of elements in arr2: %d\n", (sizeof(arr1)/sizeof(arr1[0])), (sizeof(arr2)/sizeof(arr2[0])));
}
