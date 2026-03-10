#include <stdio.h>

int main() {

  FILE *fp, *tmp;

  fp = fopen("main.c", "r");
  tmp = fp;
  tmp++;

  int c = fgetc(tmp);
  printf("%c\n", c);

  fclose(fp);

  return 0;
}
