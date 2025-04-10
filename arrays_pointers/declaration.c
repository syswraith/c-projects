#include <stdio.h>

int main()
{
    int array1[] = {1,2,3};
    int array2[3] = {1,2,3};
    // size is taken from 1 and not from 3
    int array3[3][1] = {128,2,3};
    printf("array1: %p\narray2: %p\narray3: %p\n", array1, array2, array3);
    printf("size of array1 is: %d\n", sizeof(array1));
    printf("size of array2 is: %d\n", sizeof(array2));
    printf("size of array3 is: %d\n", sizeof(array3));
    return 0;
}
