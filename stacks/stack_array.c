#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct Stack_t {
  int arr[MAX];
  int top;
} Stack;

Stack stack;

bool is_empty() { return (stack.top == -1); }

bool is_full() { return (stack.top == MAX - 1); }

void initialise() { stack.top = -1; }

void push(int value) {
  if (is_full()) {
    printf("Stack overflow\n");
    return;
  }
  printf("arr[%d] = %d\n", stack.top + 1, value);

  stack.arr[stack.top++] = value;
}

int pop() {
  if (is_empty()) {
    printf("Stack underflow\n");
    return -1;
  }

  return stack.arr[stack.top--];
}

int peek() {
  printf("arr[%d] = %d\n", stack.top, stack.arr[stack.top]);
  return stack.arr[stack.top];
}

int main() {
  initialise();
  for (int i = 0; i < 11; i++)
    push(i);

  for (int i = 0; i < 11; i++)
    pop();

  push(31337);
  push(1337);
  peek();
  peek();
}
