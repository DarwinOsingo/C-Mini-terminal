CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/parser.c src/executor.c src/builtins.c src/prompt.c src/signals.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = cmini

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
