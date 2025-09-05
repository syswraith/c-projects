#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr = malloc(sizeof(int) * 100);
  for (int i = 0; i < sizeof(arr)/sizeof(&arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
