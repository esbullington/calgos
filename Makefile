
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

ifeq ($(BUILD_ENV),development)
CFLAGS = -Wall -std=c11 -pedantic -I $(IDIR) -ffunction-sections -fdata-sections
else
CFLAGS = -Wall -std=c11 -pedantic -I $(IDIR)
endif


LIBS := -lm
# LDFLAGS =


$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(CFLAGS)
ifeq ($(BUILD_ENV),development)
	objdump -drh --no-show-raw-insn $@ > $*.asm
endif


test: $(OBJ)
	$(CC) -o $(TEST_EXE) $(LIBS) $^ tests.c $(CFLAGS)

all: test

clean:
	rm -f $(ODIR)/*.o *.asm $(TEST_EXE)

run:
	make --no-print-directory && ./$(TEST_EXE)


.PHONY: clean run
