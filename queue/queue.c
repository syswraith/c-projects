#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 100

typedef struct 
{
  int arr[MAX_SIZE];
  int top;
  int bottom;
} Qu;


void initialize(Qu *qu)
{
  qu->top = -1;
  qu->bottom = -1;
}


bool isEmpty(Qu *qu) { return (qu->top - qu->bottom == 0); };
bool isFull(Qu *qu) { return (qu->top == MAX_SIZE - 1); };


void enqu(Qu *qu, int element) 
{

  if ( isFull(qu) )
    printf("Queue is full");
  else {
    qu->top++;
    qu->arr[qu->top] = element;
  }

};


void dequ(Qu *qu) 
{

  if ( isEmpty(qu) )
    printf("Queue is empty\n");
  else 
    qu->bottom++;
  
};


void print_qu(Qu *qu)
{

  for (int i = qu->bottom; i <= qu->top; i++)
    printf("%d\n", qu->arr[i]);

}


int main()
{
  Qu qu;
  initialize(&qu);

  enqu(&qu, 1);
  enqu(&qu, 2);
  enqu(&qu, 3);
  enqu(&qu, 4);
  enqu(&qu, 5);

  dequ(&qu);
  dequ(&qu);
  dequ(&qu);
  dequ(&qu);
  dequ(&qu);

  print_qu(&qu);

  return 0;
}
