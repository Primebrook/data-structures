# Makefile for dynamic array test

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lcheck -lm

# Source files
SRC_FILES = array.c testarray.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Output executable
EXECUTABLE = dynamic_array_test

# Main target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_FILES) -o $@

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)

.PHONY: all clean
