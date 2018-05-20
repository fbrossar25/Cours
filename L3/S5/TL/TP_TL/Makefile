TARGET = testfa
CC = gcc
CFLAGS = -Wall -o2 -std=c99 -O -g -I include
LDFLAGS = 
SRC = $(shell ls src/ | sed 's/\.c//g' | tr '\n' ' ')

OBJ := $(addsuffix .o, $(addprefix obj/, $(SRC)))
SRC := $(addsuffix .c, $(addprefix src/, $(SRC)))

all: ${TARGET}

${TARGET}: dir ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

obj/%.o: src/%.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -rf obj/
	rm -f .fuse*
	rm -f *.gv
	rm -f *.png

mrproper: clean
	rm -f ${TARGET}

dir :
	@if [ ! -d obj/ ]; then mkdir obj/; fi

remake: mrproper all
