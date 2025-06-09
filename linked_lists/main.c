#include <stdio.h>
#include <stdlib.h>

// create a Node datatype and make it have a data and node* pointer
//
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

