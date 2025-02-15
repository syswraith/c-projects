#include <stdio.h>

int main()
{
    int runsum = 0;
    int arr[5] = {0,1,2,3,4};
    int arr2[sizeof(arr)/sizeof(arr[0])];
    for (int x = 0; x < sizeof(arr)/sizeof(arr[0]); x++)
    {
	runsum += arr[x];
	arr2[x]	= runsum;
    }
    printf("%d\n%d\n%d\n%d\n%d\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
    return 0; 
}
