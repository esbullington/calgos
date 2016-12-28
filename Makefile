
CC = gcc

TEST_EXE = unittests

ODIR = obj
_OBJ = linkedlist.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

IDIR = include
_DEPS = linkedlist.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

CFLAGS = -Wall -std=c11 -pedantic -I $(IDIR)

# LIBS := -lm
# LDFLAGS =


$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $(TEST_EXE) $^ tests.c $(CFLAGS)

all: test

clean:
	rm -f $(ODIR)/*.o $(TEST_EXE)

run:
	make --no-print-directory && ./$(TEST_EXE)


.PHONY: clean run
