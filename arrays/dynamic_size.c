#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = malloc(sizeof(int) * 5);
    for (int x = 0; x < 5; x++) p[x] = 1+x;
    for (int x = 0; x < 5; x++) printf("%d\n", p[x]);
    free(p);
}
