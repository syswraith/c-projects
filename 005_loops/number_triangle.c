#include <stdio.h>
int main()
{
    int rows, sum;
    sum = 1;
    printf(">> ");
    scanf("%d", &rows);
    for (int y = 1; y <= rows; y++)
    {
	for (int x = 1; x <= y; x++)
	{
	    printf(" %2.2d", sum++);
	}
	printf("\n");
    }
    return 0;
}
