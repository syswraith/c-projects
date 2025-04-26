#include <stdio.h>
#include <string.h>

#define HEIGHT 9
#define WIDTH 17


struct coordinates { int x, y; };
char moves[] = {' ', '.', 'o', '+', '=', '*', 'B', '0', 'X', '@', '%', '&', '#', '/', '^'};
int board[HEIGHT][WIDTH] = {0};
char binary[2048] = "";

struct coordinates current_position = {5, 9};


void Move(int move)
{
    switch (move)
    {
        // up left
        case 0:
            if (current_position.x == 0 && current_position.y!=0) current_position.y--;
            else if (current_position.x > 0 && current_position.y > 0) {
                current_position.x -= 1;
                current_position.y -= 1;
            }
            break;
        // up right
        case 1:
            if (current_position.x == (WIDTH-1)) current_position.y--;
            else if (current_position.x > 0 && current_position.y < WIDTH-1) {
                current_position.x -= 1;
                current_position.y += 1;
            }
            break;
        // down left
        case 2:
            if (current_position.x == 0) current_position.y++;
            else if (current_position.x < HEIGHT-1 && current_position.y > 0) {
                current_position.x += 1;
                current_position.y -= 1;
            }
            break;
        // down right
        case 3:
            if (current_position.x == (WIDTH-1)) current_position.y++;
            else if (current_position.x < HEIGHT-1 && current_position.y < WIDTH-1) {
                current_position.x += 1;
                current_position.y += 1;
            }
            break;
    }

    board[current_position.x][current_position.y] += 1;
}


void Draw()
{
    for (int x = 0; x < HEIGHT; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            printf(" %c", moves[board[x][y]]);
        }
        printf("\n");
    }
}


void Input()
{
    int index = 0;
    while (1)
    {
        int input = getchar();
        if (input == '\n') break;
        for (int i = 7; i >= 0; i--) binary[index++] = (((input >> i) & 1) == 0)?'0':'1';
    }
    if (strlen(binary)%2) binary[index++] = '0';
    binary[index] = '\0';
}


void Player()
{
    for (int x = 0; x < (strlen(binary)-1); x+=2)
    {
        if (binary[x] == '0' && binary[x+1] == '0') Move(0);
        else if (binary[x] == '0' && binary[x+1] == '1') Move(1);
        else if (binary[x] == '1' && binary[x+1] == '0') Move(2);
        else Move(3);
    }
}

int main()
{
    board[current_position.x][current_position.y] += 1;
    Input();
    Player();
    Draw();

    return 0;
}
