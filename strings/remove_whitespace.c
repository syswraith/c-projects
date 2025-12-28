#include <stdio.h>
#include <string.h>

char *prefix_trim(char *s) {
  // check pointer and if pointer == ' ' then increment
  while (*s && *s == ' ')
    s++;
  return s;
}

void suffix_trim(char *s) {
  // i is true length of string excluding the null terminator
  int i = strlen(s) - 1;
  // while i is greater than or equal to 0 and s at i is ' ' decrement i
  while (i >= 0 && s[i] == ' ') {
    i--;
  }
  // set the last i + 1 to null
  s[i + 1] = '\0';
}

int main() {
  char string[] = " hello friend ";
  printf("%d\n", (int)strlen(string));
  char *trimmed = prefix_trim(string);
  suffix_trim(trimmed);
  printf("%d\n", (int)strlen(trimmed));

  return 0;
}
