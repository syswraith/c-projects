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

char *transition[] = {
  "\x1b[38;5;232m \x1b[0m", // darkest
  "\x1b[38;5;234m.\x1b[0m",
  "\x1b[38;5;236mo\x1b[0m",
  "\x1b[38;5;238m+\x1b[0m",
  "\x1b[38;5;240m=\x1b[0m",
  "\x1b[38;5;242m*\x1b[0m",
  "\x1b[38;5;244mB\x1b[0m",
  "\x1b[38;5;246m0\x1b[0m",
  "\x1b[38;5;248mX\x1b[0m",
  "\x1b[38;5;250m@\x1b[0m",
  "\x1b[38;5;252m%\x1b[0m",
  "\x1b[38;5;253m&\x1b[0m",
  "\x1b[38;5;254m#\x1b[0m",
  "\x1b[38;5;255m/\x1b[0m",
  "\x1b[38;5;255m^\x1b[0m"  // brightest
};

#define TRANSITION_COUNT (sizeof(transition)/sizeof(transition[0]))

int board[BOARD_Y][BOARD_X] = {0};

void DrawBoard()
{
  int top_bottom_border = BOARD_X*2+3;
  for (int border_top = 0; border_top < top_bottom_border; border_top++) 
    printf((border_top == top_bottom_border-1)?"-\n":"-");
  for (int y = 0; y < BOARD_Y; y++) {
    printf("| ");
    for (int x = 0; x < BOARD_X; x++)
      printf("%s ", transition[board[y][x]]);
    printf("|\n");
  }
  for (int border_top = 0; border_top < top_bottom_border; border_top++) 
    printf((border_top == top_bottom_border-1)?"-\n":"-");
  printf("\n");
}

void ChangeState(coord_t *position)
{
  if (board[position->y][position->x] < TRANSITION_COUNT - 1)
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

    if (new_y < 0) new_y = position->y;  
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
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <moves_length>\n", argv[0]);
    return 1;
  }

  size_t moves_arr_length = atoi(argv[1]);
  if ((moves_arr_length >> 2) << 2 == moves_arr_length) moves_arr_length++;

  int moves_arr[moves_arr_length];
  srand(time(NULL));

  for (int i = 0; i < moves_arr_length; i++)
    moves_arr[i] = rand() % 2;

  coord_t current_position = { BOARD_Y/2, BOARD_X/2 };

  MoveMaker(&current_position, moves_arr, moves_arr_length);
  DrawBoard();

  return 0;
}

