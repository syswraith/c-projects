# Instructions to run

| Method name       | Description                                           |
|-------------------|-------------------------------------------------------|
| chaining          | Uses linked list to resolve collisions.               |
| linear_probing    | Checks the next available bucket to handle collision. |
| quadratic_probing | Checks (bucket + probe^2) to handle collision.        |

1. First make the files

```bash
make <method-name>
```

2. Pipe the input into the executable

```bash
cat input.txt | <executable-name>
```
