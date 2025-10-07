# Stack

- LIFO
- isempty, isfull, push, pop, peek

```
struct { int arr[max]; int top; }
```
- when top is -1 then its empty

## isempty 
when top == -1 then empty

## isfull
when top == Max-1 then full

## push
if not empty then
++top = value

## pop
returns top element
top--
