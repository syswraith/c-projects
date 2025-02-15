/*
Day 003: 
Things learned:
- Symbolic Constants
*/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    float fahr;
    for (fahr=LOWER; fahr!=UPPER; fahr+=STEP) printf("%6.3f F\t %6.3f C\n", fahr, ((5.0/9.0)*(fahr-32)));
    return 0;
}
