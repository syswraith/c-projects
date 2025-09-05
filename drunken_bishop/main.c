#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_Y 17
#define BOARD_X 17


typedef struct 
{
  int y;
  int x;
} coord_t;


int board[BOARD_Y][BOARD_X] = {0};
char transition[] = {' ', '.', 'o', '+', '=', '*', 'B', '0', 'X', '@', '%', '&', '#', '/', '^'};


void DrawBoard()
{
  int top_bottom_border = BOARD_X*2+3;
  for (int border_top = 0; border_top < top_bottom_border; border_top++) printf( ((border_top == top_bottom_border-1)?"-\n":"-"));
  for (int y = 0; y < BOARD_Y; y++) {
    printf("| ");
    for (int x = 0; x < BOARD_X; x++)
      printf("%c ", transition[board[y][x]]);
    printf("|\n");
  }

  for (int border_top = 0; border_top < top_bottom_border; border_top++) printf( ((border_top == top_bottom_border-1)?"-\n":"-"));
  printf("\n");
}


void ChangeState(coord_t *position)
{
    if (board[position->y][position->x] < (int)(sizeof(transition)-1))
        board[position->y][position->x]++;
}

void MoveMaker(coord_t *position, int moves[], size_t moves_length)
{
  for (int i = 0; i < moves_length-1; i+=2) {
    int new_y = position->y;
    int new_x = position->x;

    if (moves[i] == 0 && moves[i+1] == 0) { new_y--; new_x--; }
    else if (moves[i] == 0 && moves[i+1] == 1) { new_y--; new_x++; }
    else if (moves[i] == 1 && moves[i+1] == 0) { new_y++; new_x--; }
    else { new_y++; new_x++; }

    // check collisions and slide
    if (new_y < 0 && new_x < 0) { new_y = position->y; new_x = position->x; }
    else if (new_y < 0) new_y = position->y;  
    else if (new_y >= BOARD_Y) new_y = position->y;
    if (new_x < 0) new_x = position->x;
    else if (new_x >= BOARD_X) new_x = position->x;

    position->y = new_y;
    position->x = new_x;

    ChangeState(position);
  }
}


int main(int argc, char *argv[])
{
  size_t moves_arr_length = atoi(argv[1]);
  if ((moves_arr_length >> 2) << 2 == moves_arr_length) moves_arr_length++;

  int moves_arr[moves_arr_length];
  srand(time(NULL));

  for (int i = 0; i < moves_arr_length; i++)
  {
    int random = rand();
    int random_inrange = rand() % 2;
    moves_arr[i] = random_inrange;
  }

  coord_t current_position = { BOARD_Y/2, BOARD_X/2 };

  MoveMaker(&current_position, moves_arr, moves_arr_length);
  DrawBoard();

  return 0;
}
