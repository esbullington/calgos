

CC = gcc

EXE = program
TEST_EXE = unittests

ODIR = obj
_OBJ = linkedlist.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

IDIR = inc
_DEPS = linkedlist.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

CFLAGS = -Wall -std=c11 -pedantic -I $(IDIR)

# LIBS := -lm
# LDFLAGS =


$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ) main.c
	$(CC) -o $@ $^ $(CFLAGS)


test: $(OBJ)
	$(CC) -o $(TEST_EXE) $^ test.c $(CFLAGS)

all: $(EXE)

clean:
	rm -f $(ODIR)/*.o $(EXE) $(TEST_EXE)

run:
	make --no-print-directory && ./$(EXE)


.PHONY: clean run
