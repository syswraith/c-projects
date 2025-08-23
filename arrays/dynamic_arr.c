#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter size of array: ");
    int size;
    scanf("%d", &size);
    int* arr_ptr = (int*) malloc(size*sizeof(int));
    for (size_t i = 0; i < size; i++) arr_ptr[i] = i+1;
    for (size_t i = 0; i < size; i++) printf(((i < size-1)?"%d -> ":"%d\n"), arr_ptr[i]);
    return 0;
}
