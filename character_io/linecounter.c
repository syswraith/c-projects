#include <stdio.h>

int main()
{
    int c, nc, input;
    nc = 0;
    for (c=0; (input=getchar()) !=EOF; ++c)
    {
	if (input == '\n') {++nc;}

    }
    printf("Lines: %d\n", nc);
    return 0;

}
