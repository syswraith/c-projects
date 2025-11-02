#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char* key;
  char* value;
  struct node* next;

} node_t;


void setNode(struct node* node, char* key, char* value)
{
  node->key = key;
  node->value = value;
  node->next = NULL;
  return;
}

int main()
{
  return;
}
