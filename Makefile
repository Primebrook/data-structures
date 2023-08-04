CC = clang
CFLAGS = -I include/
DEPS = include/array.h include/test_array.h
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o) 
OUTPUT = bin/test_ds

$(OUTPUT): $(OBJ)
	mkdir -p bin
	$(CC) -o $@ $^ $(CFLAGS)

src/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

format:
	@find . -iname "*.c" -o -iname "*.h" | xargs clang-format -i

clean:
	rm -rf $(OBJ) bin/

.PHONY: format

