#include <stdio.h>
#include <string.h>

int main()
{
    char arr[] = "Hello friend :)";
    char *token = strtok(arr, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
