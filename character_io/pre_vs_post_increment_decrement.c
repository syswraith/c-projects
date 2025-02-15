#include <stdio.h>

int main()
{
    int x, y, z;
    x = 0; 
    while (x != 100)
    {
	printf("x:%3.3d\t", x);
	y = x++; /* its value is incremented after its value is used */
	printf("y:%3.3d\t", y);
   	printf("x:%3.3d\t", x);
	z = ++x; /* its value is incremented before its value is used */
	printf("z:%3.3d\t", z);
	printf("x:%3.3d\t\n", x);

    }
    return 0;
}
