#include <stdio.h>
int main()
{
    int rows;
    printf(">> ");
    scanf("%d", &rows);
    for (int y = 1; y <= rows; y++)
    {
	for (int x = 1; x <= y; x++)
	{
	    printf(" *");
	}
	printf("\n");
    }
    return 0;
}
