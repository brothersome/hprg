CC=gcc
CFLAGS=-O2 -Wall -W -Wshadow -D_DEF_NORMAL -I.

OBJDIR=obj

OUTPUTDIR=out
SRCDIR=src
BUILDDIR=build


objects = main.o

OBJS = $(patsubst %,$(OBJDIR)/%,$(objects))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $(OUTPUTDIR)/$@ $^

all: $(OBJS)
	$(CC) -o $(OUTPUTDIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f $(OBJDIR)/*.o *~
	rm -r $(BUILDDIR)
	rm @(OUTPUTDIR)/*.*


build: 
	mkdir @(BUILDDIR)
	cp $(OUTPUTDIR)/*.exe $(BUILDIR)
	
