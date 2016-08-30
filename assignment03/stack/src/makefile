IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) $(shell pkg-config --cflags glib-2.0)

ODIR=obj
LDIR =../lib

LIBS=-lm $(shell pkg-config --libs glib-2.0)

_DEPS = my_library.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = queue_functions.o queue_using_stack.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stack: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)      

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~  