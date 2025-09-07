#include <ctype.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*   
   .▄▄ ·  ▄· ▄▌.▄▄ · ▄▄▌ ▐ ▄▌▄▄▄   ▄▄▄· ▪  ▄▄▄▄▄ ▄ .▄
   ▐█ ▀. ▐█▪██▌▐█ ▀. ██· █▌▐█▀▄ █·▐█ ▀█ ██ •██  ██▪▐█
   ▄▀▀▀█▄▐█▌▐█▪▄▀▀▀█▄██▪▐█▐▐▌▐▀▀▄ ▄█▀▀█ ▐█· ▐█.▪██▀▐█
   ▐█▄▪▐█ ▐█▀·.▐█▄▪▐█▐█▌██▐█▌▐█•█▌▐█ ▪▐▌▐█▌ ▐█▌·██▌▐▀
    ▀▀▀▀   ▀ •  ▀▀▀▀  ▀▀▀▀ ▀▪.▀  ▀ ▀  ▀ ▀▀▀ ▀▀▀ ▀▀▀ ·
           "Magic blooms only in rare souls"  
*/

typedef struct
{
  int game_board[9];
  int winner;
  bool game_not_over;
  bool player_turn;
} board_state;

const char *move_char[] = {
  "\x1b[37m~\x1b[0m", // white
  "\x1b[31mX\x1b[0m", // red
  "\x1b[34mO\x1b[0m"  // blue
};

const int winning_variations[8][3] = 
  {
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,4,8},
    {2,4,6}
  };

void DrawBoard(board_state *board)
{
  printf("\n");
  for (int j = 0; j < 3; j++)
  {
    for (int i = 0; i < 3; i++)
    {
      int index = j * 3 + i;
      printf(" %s ", move_char[board->game_board[index]]);
    }
    printf("\n");
  }
  printf("\n");
}

void MakeMove(board_state *board)
{
  int choice;
  printf("Enter choice (0-8): ");
  scanf("%d", &choice);

  if (choice < 0 || choice > 8)
  {
    printf("Invalid choice. Try again.\n");
    return;
  }

  if (board->game_board[choice] != 0)
  {
    printf("Move already made. Try again.\n");
    return;
  }

  if (board->player_turn) 
  {
    board->game_board[choice] = 1;
    board->player_turn = false;
  }
  else 
  {
    board->game_board[choice] = 2;
    board->player_turn = true;
  }
}

bool WinDetector(board_state *board)
{
  for (int i = 0; i < 8; i++)
  {
    int a = winning_variations[i][0];
    int b = winning_variations[i][1];
    int c = winning_variations[i][2];

    if (board->game_board[a] != 0 &&
        board->game_board[a] == board->game_board[b] &&
        board->game_board[b] == board->game_board[c])
    {
      board->winner = board->game_board[a];
      return true;
    }
  }
  return false;
}

bool DrawDetector(board_state *board)
{
  for (int i = 0; i < 9; i++)
    if (board->game_board[i] == 0)
      return false;
  return true;
}

bool CheckIfNotGameOver(board_state *board)
{
  if (WinDetector(board))
  {
    printf("Player %d wins!\n", board->winner);
    return false;
  }

  if (DrawDetector(board))
  {
    printf("It's a draw!\n");
    return false;
  }

  return true;
}

int main()
{
  board_state board = 
    {
      .game_board = {0, 0, 0, 0, 0, 0, 0, 0, 0},
      .winner = 0,
      .game_not_over = true, 
      .player_turn = true
    };

  DrawBoard(&board);
  while (board.game_not_over)
  {
    MakeMove(&board);
    DrawBoard(&board);
    board.game_not_over = CheckIfNotGameOver(&board);
  }

  return 0;
}
