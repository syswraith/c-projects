#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
  int value;
  struct node *next;
} node_t;


void print_node(node_t *head)
{
  node_t *temp = head;
  while (temp->next != NULL)
  {
    printf("%d->", temp->value);
    temp = temp->next;
  }
}


node_t* create_node(int value)
{
  node_t *temp = calloc(1, sizeof(node_t));
  temp->value = value;
  temp->next = NULL;
  return temp;
}


int main()
{
  node_t *head, *temp;
  head = NULL;
  
  for (int i = 0; i < 25; i++)
  {
    temp = create_node(i);
    temp->next = head;
    head = temp;


  }

  return 0;
}
