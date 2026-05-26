CC=clang

DEBUG_FLAGS=-g -fsanitize=address,undefined -fno-omit-frame-pointer
WARN_FLAGS=-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror
STD_FLAGS=-std=c17

CFLAGS=$(STD_FLAGS) $(WARN_FLAGS) $(DEBUG_FLAGS)

TARGET=main
SRC=main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

valgrind:
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET)
