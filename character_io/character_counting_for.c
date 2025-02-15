/*
Things learnt:
- double float (64bits over 32bits of the float type)
- same notation
- getchar() revision
- NULL statement 
- EOF is ctrld in most unixes and ctrlz in window
*/

#include <stdio.h>

int main()
{
    double nc;
    for (nc =0;getchar() != EOF; ++nc)
	;
    printf("%.0f\n", nc);
    return 0;
}
