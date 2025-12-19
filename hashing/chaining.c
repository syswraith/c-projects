#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 10

typedef struct bucket_t {
  char *data;
  struct bucket_t *next;
} bucket;

typedef struct bucket_index_t {
  bucket *index_ptr;
} bucket_index;

bucket_index table[MAX_INDEX];

void initialize_table() {
  for (int i = 0; i < MAX_INDEX; i++)
    table[i].index_ptr = NULL;
}

void push_key(char *word) {
  char *key = malloc(strlen(word) + 1);
  strcpy(key, word);
  int key_length = strlen(key);
  int hash_value = key_length % MAX_INDEX;

  bucket *new_entry = malloc(sizeof(bucket));
  new_entry->data = key;
  new_entry->next = NULL;

  if (table[hash_value].index_ptr == NULL) {
    table[hash_value].index_ptr = new_entry;
  } else {
    bucket *tmp = table[hash_value].index_ptr;
    new_entry->next = tmp;
    table[hash_value].index_ptr = new_entry;
  }
}

void print_hash_table() {
  for (int i = 0; i < MAX_INDEX; i++) {
    printf("Index %d: ", i);
    bucket *head = table[i].index_ptr;
    while (head != NULL) {
      printf("%s ", head->data);
      head = head->next;
    }
    printf("\n");
  }
}

void delete_hash_table() {
  for (int i = 0; i < MAX_INDEX; i++) {
    bucket *head = table[i].index_ptr;
    while (head != NULL) {
      bucket *tmp = head->next;
      free(head->data);
      free(head);
      head = tmp;
    }
    table[i].index_ptr = NULL;
  }
}

int main() {

  int limit = 100;

  initialize_table();

  while (limit--) {
    char buff[100] = {0};
    scanf("%99s", buff);
    push_key(buff);
  }

  print_hash_table();
  delete_hash_table();

  return 0;
}
