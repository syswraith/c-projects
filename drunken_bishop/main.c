#include <stdio.h>
#define HEIGHT 9
#define WIDTH 17


char moves[] = {' ', '.', 'o', '+', '=', '*', 'B', '0', 'X', '@', '%', '&', '#', '/', '^'};

struct coordinates
{
    int x;
    int y;
};

void Move(struct coordinates c)
{
    
    while (c.x != 0)
    {
	printf(".\n");
	c.x--;
    }
    
    while (c.y != 0)
    {
	printf(".");
	c.y--;
    }

    printf("x");
}


int main()
{
    struct coordinates center = {9, 5};
    Move(center);
    printf("\n");
    return 0;
}
