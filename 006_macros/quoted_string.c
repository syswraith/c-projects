#include <stdio.h>
#define dprint(expr) printf(#expr " %g\n", expr)

int main()
{
    dprint(3/2);
}
