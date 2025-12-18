#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct Queue_t {
  int arr[MAX];
  int top;
  int bottom;
} Queue;

Queue queue;

bool is_empty() { return (queue.top == queue.bottom - 1); };

bool is_full() { return (queue.top == MAX - 1); };

void initialize() {
  queue.top = -1;
  queue.bottom = 0;
};

void enqueue(int value) {
  if (is_full()) {
    printf("Queue overflow\n");
    return;
  }
  printf("arr[%d] = %d\n", queue.top + 1, value);
  queue.arr[queue.top++] = value;
};

int dequeue() {
  if (is_empty()) {
    printf("Queue underflow\n");
    return -1;
  }
  return queue.arr[queue.bottom++];
};

int peek() {
  if (is_empty()) {
    printf("Queue empty\n");
    return -1;
  }
  printf("arr[%d] = %d\n", queue.bottom, queue.arr[queue.bottom]);
  return queue.arr[queue.bottom];
};

int main() {
  initialize();

  for (int i = 0; i < 11; i++)
    enqueue(i);

  peek();

  for (int i = 0; i < 11; i++)
    dequeue();

  peek();

  return 0;
}
