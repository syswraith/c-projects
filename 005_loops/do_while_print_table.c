#include <stdio.h>
int main()
{
    int x, y;
    x = 2;
    y = 0;
    do
    {
	printf("%d x %d = %d\n", x, y, x*y);
	y++;
    
    }
    while (y < 11);
    return 0;
}
