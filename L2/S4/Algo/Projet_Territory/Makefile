######################################################################
# Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr   #
#			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr   #
######################################################################

TARGET = exec
SERVER = territory-server
CC = gcc
CFLAGS = -Wall -O2 -std=c99 -O -g -I include
LDFLAGS = 
TESTFLAGS = 2
SRC = main boardgame position territory

OBJ := $(addsuffix .o, $(addprefix obj/, $(SRC)))
SRC := $(addsuffix .c, $(addprefix src/, $(SRC)))

all: ${TARGET}

test: ${TARGET}
	./${SERVER} ./${TARGET} ./${TARGET} ${TESTFLAGS}

${TARGET}: dir ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

obj/%.o: src/%.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -rf obj/

mrproper: clean
	rm -f ${TARGET}
	rm -f *.log
	rm -f .fuse*

dir:
	@if [ ! -d obj/ ]; then mkdir obj/; fi

remake: mrproper all