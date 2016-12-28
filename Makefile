
CC = gcc

TEST_EXE = unittests

ODIR = obj
_OBJ = linkedlist.o linkedlist_tests.o \
       hashtable.o hashtable_tests.o \
       CuTest.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

IDIR = include
_DEPS = linkedlist.h linkedlist_tests.h \
        hashtable.h hashtable_tests.h \
        CuTest.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

CFLAGS = -Wall -std=c11 -pedantic -I $(IDIR)

LIBS := -lm
# LDFLAGS =


$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $(TEST_EXE) $(LIBS) $^ tests.c $(CFLAGS)

all: test

clean:
	rm -f $(ODIR)/*.o $(TEST_EXE)

run:
	make --no-print-directory && ./$(TEST_EXE)


.PHONY: clean run
