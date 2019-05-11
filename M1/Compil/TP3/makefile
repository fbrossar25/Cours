CC = gcc
LEX = lex
YACC = yacc -d
CFLAGS = -O2 -Wall
LDFLAGS = -ly -ll -lfl # Linux: -lfl / OSX: -ll
EXEC = expr
SRC = symbol.c quad.c quad_list.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ) y.tab.c lex.yy.c
	$(CC) $(CFLAGS) -o $(EXEC) $^ $(LDFLAGS)

y.tab.c: $(EXEC).y
	$(YACC) $(EXEC).y

lex.yy.c: $(EXEC).l
	$(LEX) $(EXEC).l

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

valgrind: remake
	valgrind ./$(EXEC)

clean:
	rm -f *.o y.tab.c y.tab.h lex.yy.c

mrproper: clean
	rm -f $(EXEC)

remake: mrproper all