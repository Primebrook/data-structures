CC = clang
CFLAGS = -I include/
DEPS = include/array.h include/test_array.h
OBJ = src/main.o src/array.o src/test_array.o

src/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_ds: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

