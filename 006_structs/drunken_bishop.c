#include <stdio.h>
int main()
{
    
    struct posn
    {
	int y;
	int x;
    } posn;
    
    struct posn board_posn = { 17, 35 };
    struct posn bishop_posn = { 9, 5 };

    for (int up = 0; up < board_posn.x; up++)
    {
	printf("*");
    }
    printf("\n");
    for (int lr = 0; lr <= board_posn.y; lr++)
    {
	printf("*%*c*\n", board_posn.x - 2, ' ');
    }

    for (int down = 0; down < board_posn.x; down++)
    {
	printf("*");
    }
    printf("\n");
    return 0; 
}
