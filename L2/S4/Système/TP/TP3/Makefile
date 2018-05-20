CC=gcc
CFLAGS=-Wall -std=c99 -o2
all: ints mycc printargs readenv env 
ints: 
	${CC} ${CFLAGS} -o ints ints.c
mycc: 
	${CC} ${CFLAGS} -o mycc mycc.c
printargs: 
	${CC} ${CFLAGS} -o printargs printargs.c
readenv: 
	${CC} ${CFLAGS} -o readenv readenv.c
env:
	${CC} ${CFLAGS} -o env env.c
clean:
	rm ints mycc printargs readenv env