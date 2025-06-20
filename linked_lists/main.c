#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} node_t;


node_t* createNode(int value)
{
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


int main() 
{
    node_t* n1;
    node_t* n2;
    node_t* n3;
    n1 = createNode(1);
    n2 = createNode(2);
    n3 = createNode(3);

    n1->next = n2;
    n2->next = n3;

    node_t* temp = n1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
