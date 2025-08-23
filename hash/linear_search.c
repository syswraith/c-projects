#include <stdio.h>
#include <string.h>

typedef struct 
{
    char* key;
    int data;
} item;

item* linear_search(item* items, size_t size, char* key)
{
    for (size_t i = 0; i < size; i++)
        if ( strcmp(items[i].key, key) == 0 ) return &items[i];
    
    return NULL;
}


int main()
{
    item items[] = 
    {
        {"bob", 10},
        {"alice", 11},
        {"stalin", 12},
        {"churchill", 13}
    };

    size_t items_size = sizeof(items) / sizeof(items[0]);
    item* found = linear_search(items, items_size, "stalin");
    if (!found) return 1;
    printf("found stalin: %d\n", found->data);

    return 0;
}
