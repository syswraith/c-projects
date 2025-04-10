#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4};
    int *pT = &arr[0];
    // prints out the memaddr of the values 
    printf("%p %p\n", pT+6, *(pT+6));
    // prints out the values stored in each pointer location 
    printf("%d %d %d %d %d %d %d",*(pT-1) , *pT, *(pT+1), *(pT+2), *(pT+3), *(pT+4), *(pT+5));
    return 0; 
}
