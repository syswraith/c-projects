#include <stdio.h>
int main()
{
    int rows, ascii_counter;
    ascii_counter = 65;
    printf(">> ");
    scanf("%d", &rows);
    for (int y = 1; y <= rows; y++)
    {
	for (int x = 1; x <= y; x++)
	{
	    printf(" %c", ascii_counter++);
	}
	printf("\n");
    }
    return 0;
}
