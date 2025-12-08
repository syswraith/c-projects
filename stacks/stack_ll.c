#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t *next;
} node;

node *head = NULL;
node *tail = NULL;

// operations: pop, push, peek, is_empty, free_stack

void push(int value) {

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
}

bool is_empty() {
  bool result = (head == tail);
  return result;
}

node *pop() {

  if (is_empty())
    return NULL;

  node *result;
  node *tmp = head;

  while (tmp->next != tail)
    tmp = tmp->next;

  result = tail;

  tail = tmp;
  tail->next = NULL;
  tmp = NULL;

  return result;
}

void free_stack() {
  node *tmp = head;

  while (tmp != NULL) {
    node *next = tmp->next;
    free(tmp);
    tmp = next;
  }
}

void print_stack() {
  node *tmp = head;

  while (tmp != NULL) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {

  for (int i = 0; i < 10; i++)
    push(i);

  free(pop());
  print_stack();
  free_stack();
  return 0;
}
