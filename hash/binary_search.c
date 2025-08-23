#include <stdio.h>
#include <string.h>


typedef struct 
{
    char* key;
    int value;
} item;

item* binary_search(item* items; size_t size; char* key)
{
    size_t midpoint = size/2;
    if (items[midpoint].key == key) return *items[midpoint];
    else 
    {
        item low;
        item high;
        for (size_t i = 0; i < midpoint; i++) low[i] = items[i];
        for (size_t i = midpoint; i < size; i++) high[i] = items[i];
        binary_search(*low, midpoint, key);
        binary_search(*high, size, key);
    }
}


int main()
{

    item items[] = 
    {
        {"bob", 0},
        {"alice", 1},
        {"stalin", 2},
        {"churchill", 3}
    }

    size_t items_size = sizeof(items) / sizeof(item);
    item* found = binary_search(items, items_size, "stalin");
    printf("found stalin: %d\n", found->value);
    return 0;
}
