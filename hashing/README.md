# Instructions to run

| Method name       | Description                                           |
|-------------------|-------------------------------------------------------|
| chaining          | Uses linked list to resolve collisions.               |
| linear_probing    | Checks the next available bucket to handle collision. |
| quadratic_probing | Checks (bucket + probe^2) to handle collision.        |

Make the files
```bash
make <method-name>
```

Pipe the input into the executable
```bash
cat input.txt | <executable-name>
```
Clean executables
```bash
make clean
```
