#include <stdio.h>
#define max(A, B) (A > B)?A:B
#define min(A, B) (A > B)?B:A

int main()
{
    printf("Max %d\nMin %d\n", max(4, 5), min(4, 5));
    return 0;
}
