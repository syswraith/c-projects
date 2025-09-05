#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


int main()
{
  int counter = 5;
  char *arr = calloc(counter, sizeof(char));
  int charcount = 0;

  while (true)
  {

    char input = getchar();

    if (isspace(input) || input == EOF) {
      break;
    } 
    else {
      if (charcount >= counter) {
        counter += 5;
        arr = realloc(arr, sizeof(char)*counter);
        arr[charcount] = input;
      }
      else {
        arr[charcount] = input;
      }
      charcount++;
    }

  }

  for (int i = 0; i < counter; i++) printf("%c", arr[i]);
  printf("\n");

  free(arr);
  arr = NULL;

  return 0;
}
