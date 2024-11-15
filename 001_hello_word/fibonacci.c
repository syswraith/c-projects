#include <stdio.h>

int main()
{
    int a, b, c;
    a = 0;
    b = 1;
    printf("%d\n%d\n", a, b);
    for (int x = 0; x < 10; x++)
    {
	printf("%d\n", a+b);
	c = a + b;
	a = b;
	b = c;
	c = 0;
    }
    return 0;
}
