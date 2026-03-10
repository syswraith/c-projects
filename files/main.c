#include <stdio.h>

int main() {

  FILE *fp;
  int c;

  fp = fopen("readfile.c", "r");

  while ((c = fgetc(fp)) != EOF)
    printf("%c", c);

  fclose(fp);

  return 0;
}
