#include <stdio.h>

int main()
{
    int x = 1, y = 2, z[10];
    int *ip;
    ip = &x;
    printf("%d\n", *ip);
    y = *ip;
    printf("%d\n", y);
    *ip = 0;
    printf("%d\n", *ip);
    /*
       ip points to x
       y now points to the thing that ip points to i.e. x
       the thing that ip points to, its now 0
     */
    return 0; 
}
