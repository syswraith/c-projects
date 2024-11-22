#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4};
    int *pT = &arr[0];
    printf("%d %d %d %d %d %d %d",*(pT-1) , *pT, *(pT+1), *(pT+2), *(pT+3), *(pT+4), *(pT+5));
    return 0; 
}
