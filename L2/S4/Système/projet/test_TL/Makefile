CC=gcc
CFLAGS=-Wall -std=c99 -o2 -o
LDFLAGS=
TARGET=test

all: ${TARGET}

${TARGET}: lcg_demo.o lcg_param.o lcg_max.o lcg_next.o lcg_seed.o
	${CC} ${CFLAGS} $@ $^

lcg_demo.o: lcg_demo.c lcg.h
	${CC} ${CFLAGS} $@ -c lcg_demo.c

lcg_param.o: lcg_param.c lcg.h
	${CC} ${CFLAGS} $@ -c lcg_param.c

lcg_max.o: lcg_max.c lcg.h
	${CC} ${CFLAGS} $@ -c lcg_max.c

lcg_next.o: lcg_next.c lcg.h
	${CC} ${CFLAGS} $@ -c lcg_next.c

lcg_seed.o: lcg_seed.c lcg.h
	${CC} ${CFLAGS} $@ -c lcg_seed.c

clean:
	rm -f *.o

mrproper: clean
	rm -f ${TARGET}