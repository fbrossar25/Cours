TARGET = TP1
CC = g++
CFLAGS = -Wall -std=c++11 -o2 -O -g -Iinclude -D_GLIBCXX_DEBUG
#-fsanitize=address
LDFLAGS = 
SRC = $(shell ls src/ | sed 's/\.cpp//g' | tr '\n' ' ')

OBJ := $(addsuffix .o, $(addprefix obj/, $(SRC)))
SRC := $(addsuffix .c, $(addprefix src/, $(SRC)))

all: ${TARGET}

${TARGET}: dir ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

obj/%.o: src/%.cpp
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -rf obj/

mrproper: clean
	rm -f ${TARGET}
	rm -f .fuse*

dir :
	@if [ ! -d obj/ ]; then mkdir obj/; fi

remake: mrproper all