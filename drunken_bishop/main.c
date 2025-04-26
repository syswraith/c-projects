#include <stdio.h>
#define HEIGHT 9
#define WIDTH 17


struct coordinates { int x, y; };
char moves[] = {' ', '.', 'o', '+', '=', '*', 'B', '0', 'X', '@', '%', '&', '#', '/', '^'};
int board[HEIGHT][WIDTH] = {0};


struct coordinates current_position = {5, 9};


void Move(int move)
{
    switch (move)
    {
        case 0b00:
            current_position.x -= 1;
            current_position.y -= 1;
            break;

        case 0b01:
            current_position.x -= 1;
            current_position.y += 1;
            break;

        case 0b10:
            current_position.x += 1;
            current_position.y -= 1;
            break;

        case 0b11:
            current_position.x += 1;
            current_position.y += 1;
            break;
    }
    board[current_position.x][current_position.y] += 1;
}


void Draw()
{
    for (int x = 1; x <= HEIGHT; x++)
    {
        for (int y = 1; y <= WIDTH; y++)
        {
            printf(" %c", moves[board[x][y]]);
        }
        printf("\n");
    }
}


int main()
{
    board[current_position.x][current_position.y] += 1;
    Move(0b10);
    Move(0b01);
    Draw();

    return 0;
}
