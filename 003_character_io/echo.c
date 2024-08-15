#include <stdio.h>

int main()
{
    printf("Type something into the Void\n");
    int c;
    c = getchar();
    while(c!=EOF)
    {
	putchar(c); 
	c = getchar();
    }
}
