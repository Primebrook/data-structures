CC = clang
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lcheck -lm -lpthread -lrt

SRCDIR = src
TESTDIR = test

SRCFILES = $(wildcard $(SRCDIR)/*.c)
HDRFILES = $(wildcard $(SRCDIR)/*.h)
TESTFILES = $(wildcard $(TESTDIR)/*.c)

SRCOBJS = $(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.o, $(SRCFILES))
TESTOBJS = $(patsubst $(TESTDIR)/%.c, $(TESTDIR)/%.o, $(TESTFILES))

TARGET = dynamic_array
TESTTARGET = test_dynamic_array

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRCOBJS)
	$(CC) $(CFLAGS) $(SRCOBJS) -o $(TARGET)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCOBJS) $(TESTOBJS) $(TARGET) $(TESTTARGET)

test: $(TESTTARGET)
	./$(TESTTARGET)

$(TESTTARGET): $(TESTOBJS) $(SRCOBJS)
	$(CC) $(CFLAGS) $(TESTOBJS) $(SRCOBJS) -o $(TESTTARGET) $(LIBS)

$(TESTDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
