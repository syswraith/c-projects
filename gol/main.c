#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 25
#define BACKGROUND ' '
#define CELL '#'

typedef enum {
  DEAD,
  ALIVE,
} State;

typedef struct {
  State state;
} Cell;




Cell grid[HEIGHT][WIDTH] = {0};

void init_grid()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      grid[i][j].state = DEAD;
    }
  }
}


void gen_next()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      int alive_count = 0;
      for (int k = -1; k < 2; k++)
      {
        for (int l = -1; l < 2; l++)
        {
          if (k == 0 && l == 0) continue;
          if (i + k < HEIGHT && i + k >= 0 && j + l < WIDTH && j + l >= 0)
          {
            if (grid[i+k][j+l].state == ALIVE)
            {
              alive_count++;
            }

          }
        }
      }

      switch (alive_count)
      {
        case 0:
        case 1:
          grid[i][j].state = DEAD;
          break;
        case 2:
        case 3:
          if (grid[i][j].state == DEAD && alive_count == 3)
            grid[i][j].state = ALIVE;
          break;
        default:
          grid[i][j].state = DEAD;
      }
    }


  }
}



int draw_grid()
{
  int alive_count = 0;
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      if (grid[i][j].state == ALIVE) {
        alive_count++;
        printf("%c", CELL);
      }
      else {
        printf("%c", BACKGROUND);
      }
    }
    printf("\n");
  }
  return alive_count;
}

int main()
{
  init_grid();

  for (int i = 0; i < HEIGHT/2; i++)
  {
    for (int j = 0; j < WIDTH/2; j++)
    {
      grid[i][j].state = ALIVE;
    }
  }


  while (draw_grid())
  {
    usleep(90 * 1000);
    gen_next();
    system("clear");
  }

  return 0;
}
