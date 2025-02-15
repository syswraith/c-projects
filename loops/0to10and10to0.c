#include <stdio.h>
int main()
{
    int x, y;
    x = 0;
    y = 10;
    do 
    {
	printf("%2.2d\t%2.2d\n", x++, y--);
    }
    while ((x<=10)&&(y>=0));
    return 0;
}
