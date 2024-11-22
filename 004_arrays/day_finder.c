#include <stdio.h>
int main()
{
    int choice;
    char arr[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    scanf("%d", &choice);
    printf("%s\n", (choice > 0 && choice < 8) ? arr[--choice]:"ERR");
    return 0;
}
