#include <stdio.h>
#define UPPER 255
#define LOWER 0


int main()
{
    int count;
    printf("ASCII\tCHAR\tHEX\tOCTAL\n");
    for (count=LOWER; count!=UPPER; count++)
    {
	printf("%d\t%c\t%X\t%o\n", count, putchar(count), count, count);
    }
}
