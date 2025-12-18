#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
} node;

node *head = NULL;
node *tail = NULL;
int counter = -1;

// operations: enqueue, dequeue, isempty, peek

bool is_empty() { return (counter == -1); }

void enqueue(int value) {
  node *new_node = malloc(sizeof(node));
  new_node->data = value;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }

  printf("%d enqueued\n", value);
  counter++;
}

void dequeue() {

  if (counter == -1) {
    printf("Stack underflow\n");
    return;
  }

  node *tmptr = head;
  node *result = tail;

  while (tmptr->next != tail || head == tail)
    tmptr = tmptr->next;

  tmptr->next = NULL;
  tail = tmptr;

  printf("%d dequeued\n", result->data);
  free(result);
}

void peek() {}

int main() {

  for (int i = 0; i < 10; i++)
    enqueue(i);

  for (int i = 0; i < 11; i++)
    dequeue();

  return 0;
}
