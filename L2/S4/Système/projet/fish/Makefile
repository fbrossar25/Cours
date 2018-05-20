CFLAGS=-Wall -g -std=c99 -D_POSIX_C_SOURCE=200809L

TARGETS=fish cmdline_test

all: $(TARGETS)

cmdline_test.o cmdline.o fish.o:  cmdline.h
fish: fish.o cmdline.o
cmdline_test: cmdline_test.o cmdline.o

clean:
	rm -f *.o
	rm -f $(TARGETS)

