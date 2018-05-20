CC=gcc
CFLAGS=-Wall -std=c99 -o2

all: cat tee wc

cat: 
	${CC} ${CFLAGS} -o cat_perso cat_perso.c
tee: 
	${CC} ${CFLAGS} -o tee_perso tee_perso.c
wc: 
	${CC} ${CFLAGS} -o wc_perso wc_perso.c

clean:
	rm cat_perso tee_perso wc_perso
