#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t size;
  size_t currentOffset;
  char *buffer;
} Arena;

Arena *ArenaInit(size_t size) {

  // if size == 0 then return NULL
  if (!size) {
    return NULL;
  }

  // allocate the arena pointer
  Arena *arenaPtr = malloc(sizeof(Arena));

  // allocate the buffer to 1 byte (char) * number of elements (size)
  arenaPtr->buffer = calloc(size, sizeof(char));
  arenaPtr->size = size;
  arenaPtr->currentOffset = 0;

  return arenaPtr;
}

char *ArenaAlloc(Arena *arena, size_t size, int value) {

  // if the arena offset is greater than or equal to the arena size then return
  // NULL
  if ((arena->currentOffset + size) > arena->size) {
    return NULL;
  }

  // get the current offset
  char *currentOffset = arena->buffer + arena->currentOffset;

  // set the value and increment the offset
  memcpy((currentOffset), &value, size);
  arena->currentOffset += size;

  // return the current offset
  return currentOffset;
}

void ArenaPrinter(Arena *arena, size_t size) {

  size_t currentOffset = arena->currentOffset;
  size_t counter = 0;

  if (arena->currentOffset == 0) {
    fprintf(stderr, "Error: Arena is empty");
    exit(1);
  }

  while (counter != currentOffset) {
    printf("%d\n", *(arena->buffer + counter));
    counter += size;
  }
}

void ArenaReset(Arena *arena) {
  // clear the buffer
  memset(arena->buffer, 0, arena->size);

  // reset the current
  arena->currentOffset = 0;
}

void ArenaFree(Arena *arena) {
  // first free the buffer in arena
  free(arena->buffer);

  // then free the arena itself
  free(arena);
}

int main(int argc, char **argv) {

  (void)argc;
  (void)argv;

  // 40 bytes have been allocated, and if not then NULL is returned
  Arena *arena = ArenaInit(40);

  // check for NULL
  if (arena == NULL) {
    fprintf(stderr, "Error: Arena initialization failed\n");
    exit(1);
  }

  // test #1
  for (int i = 0; i < 10; i++) {
    char *temp = ArenaAlloc(arena, sizeof(int), i);
    if (temp == NULL) {
      fprintf(stderr, "Error: Arena allocation failed\n");
      exit(1);
    }
  }

  ArenaPrinter(arena, sizeof(int));
  ArenaReset(arena);

  // test #2
  for (int i = 0; i < 10; i++) {
    char *temp = ArenaAlloc(arena, sizeof(int), i + 10);
    if (temp == NULL) {
      fprintf(stderr, "Error: Arena allocation failed\n");
      exit(1);
    }
  }

  ArenaPrinter(arena, sizeof(int));
  ArenaFree(arena);

  return 0;
}
