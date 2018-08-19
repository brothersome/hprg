CC=gcc
CFLAGS=-O2 -Wall -W -Wshadow -D_DEF_NORMAL -I.
OS=Windows

OBJDIR=../../obj/base

objects = handleparams.o \
	logging.o \
	memory.o \
	readconfig.o \
	stringmanip.o \
	timemanip.o \
	basemem.o
	
OBJS = $(patsubst %,$(OBJDIR)/%,$(objects))

$(OBJDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
	
all: $(OBJS)

clean:
	rm $(OBJDIR)/*.o *~
