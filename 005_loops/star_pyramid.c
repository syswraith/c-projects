#include <stdio.h>
int main()
{
    int rows, x, y, s;
    printf(">> ");
    scanf("%d", &rows);
    for (y = 0; y <= rows; y++)
    {
	for (s = 0; s <= rows; s++)
	{
	    printf(" ");
	}
	for (x = 0; x <= y; x++)
	{
	    printf("**");
	}
	printf("\n");
	rows--;
    }

    return 0;
}
