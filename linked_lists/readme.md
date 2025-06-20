# typedef

https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-typedef-Statement
```c
// In the case of custom data types, you can use typedef to make a new name for the type while defining the type:

typedef struct fish
{
  float weight;
  float length;
  float probability_of_being_caught;
} fish_type;
```


# Memory

Memory allocated with `malloc()` is allocated on the heap. 
It persists beyond function calls until manually freed (unlike stack memory).
It can also be resized to grow or shrink.

```c
node_t* createNode(int value)
{
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
```
- This function returns a pointer.
- We create a new node pointer with the size of node datatype, typecasted to node datatype.
- We set the data equal to value and the next pointer equal to NULL. We will change this later.
- We return the new node.

```c
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

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
```
- Declare the elements as nodepointers
- Create nodes with values
- Set the next pointer manually to the next element (we don't use & because its already a pointer pointing to something)
- Free the memory

https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-typedef-Statement
```c
// In the case of custom data types, you can use typedef to make a new name for the type while defining the type:

typedef struct fish
{
  float weight;
  float length;
  float probability_of_being_caught;
} fish_type;
```


# Memory

Memory allocated with `malloc()` is allocated on the heap. 
It persists beyond function calls until manually freed (unlike stack memory).
It can also be resized to grow or shrink.

```c
node_t* createNode(int value)
{
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
```
- This function returns a pointer.
- We create a new node pointer with the size of node datatype, typecasted to node datatype.
- We set the data equal to value and the next pointer equal to NULL. We will change this later.
- We return the new node.

```c

```
