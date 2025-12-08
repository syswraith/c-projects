#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100


typedef struct {
  int arr[MAX_ELEMENTS];
  int top;
} Stack;


void initialize(Stack *stack) { stack->top = -1; }
bool is_empty(Stack *stack) { return (stack->top == -1); }
bool is_full(Stack *stack) { return (stack->top == MAX_ELEMENTS - 1); }


// push an element onto the stack
void push(Stack *stack, int element)
{
  if (is_full(stack))
  {
    printf("Stack overflow\n");
  }
  else {
    //    top++;
    stack->arr[++(stack->top)] = element;
    printf("Element %d pushed onto the stack at position %d\n");
  }

}

// pop an element off the top of the stack
int pop(Stack *stack)
{
  if (is_empty(stack)) 
  { 
    printf("Stack underflow\n"); 
    return -1;
  }
  else {
    printf("Element %d popped from the stack\n", stack->arr[stack->top]);
    return stack->arr[(stack->top)--];
  }
}


// peek at the top of the stack
int peek(Stack *stack)
{
  if (is_empty(stack))
  {
    printf("Stack is empty\n");
    return 31337;
  }
  else 
  {
    return stack->arr[stack->top];
  }
}


// dump the whole stack to stdout
void print_stack(Stack *stack)
{
  int counter = stack->top;
  for (int i = 0; i < counter; i++)
    printf("Element %d at position %d \n", stack->arr[i], i);
}

int main()
{
  Stack stack;
  initialize(&stack);
  push(&stack, 1);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  peek(&stack);

  return 0;
}
