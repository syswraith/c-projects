#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10

typedef struct bucket_t {
  char *data;
  int probe;
} bucket;

bucket *table[MAX];
void init_table();
int calc_index(char *word);
int probe(int bucket_index);
void create_element(char *key);
void delete_table();
void print_table();

void init_table() {
  for (int i = 0; i < MAX; i++)
    table[i] = NULL;
}

int probe(int bucket_index) {
  for (int i = 0; i < MAX; i++) {
    int circular_value = (bucket_index + i) % MAX;
    if (table[circular_value] == NULL) {
      return i;
    }
  }
  return -1;
}

int calc_index(char *key) {
  int index = strlen(key) % MAX;
  return index;
}

void create_element(char *word) {
  char *key = malloc(strlen(word) + 1);
  strcpy(key, word);

  int bucket_index = calc_index(key);
  int probe_value = probe(bucket_index);

  if (probe_value == -1) {
    printf("Can't insert %s. Hash table has overflowed\n", key);
    free(key);
    return;
  }

  int circular_value = (bucket_index + probe_value) % MAX;
  bucket *element = malloc(sizeof(bucket));
  element->data = key;
  element->probe = probe_value;

  printf("Inserting %s at index %d\n", key, circular_value);
  table[circular_value] = element;
}

void delete_table() {
  printf("Deleting table\n");
  for (int i = 0; i < MAX; i++) {
    if (table[i] == NULL)
      continue;
    free(table[i]->data);
    free(table[i]);
    table[i] = NULL;
  }
}

void print_table() {
  bool table_empty = true;

  for (int i = 0; i < MAX; i++) {
    if (table[i] != NULL) {
      table_empty = false;
      break;
    }
  }

  if (table_empty) {
    printf("Nothing to print. Table is empty\n");
    return;
  }

  printf("Printing hash table:\n");
  printf("Index | Probe | Stuff\n");
  for (int i = 0; i < MAX; i++)
    if (table[i] != NULL)
      printf("  %.2d  |  %.2d   | %s\n", i, table[i]->probe, table[i]->data);
}

int main(void) {

  init_table();
  create_element("Lorem");
  create_element("Ipsum");
  create_element("Dolor");
  create_element("Something");
  create_element("Something");
  create_element("Overflow");
  create_element("Already");
  create_element("!!!");
  create_element("...");
  create_element("...");
  create_element("...");
  print_table();
  delete_table();
  print_table();

  return 0;
}
