#include <stdio.h>

int main()
{
    int arr[] = {4, 5, 1, 4, 5};
    for (int x = 0; x < 5; x++)
    {
	int counter = 1;
	for (int y = 0; y < 5; y++)
	{

	    if (x == y)
	    {
		continue;
	    }

	    else if (arr[x] == arr[y])
	    {
		counter++;
	    }

	}

	if (counter == 1)
	{
	    printf("%d\n", arr[x]); 
	}

    }
}
