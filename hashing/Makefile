CC=gcc
# $@ refers to the .o file name mentioned
# $^ refers to the %.c file name mentioned
# they both must be the same

%.o: %.c
	$(CC) -o $@ $^

clean:
	rm $(shell find . -type f -executable)
