CC=gcc
CFLAGS= -fopenmp -funroll-loops
OPTIFLAGS= -O3
LDFLAGS= 
SOURCES= Init.c Calcul.c main.c 
EXECNAME= MatrixProduct

all:
	$(CC) $(CFLAGS) $(OPTIFLAGS) $(LDFLAGS) -o $(EXECNAME) $(SOURCES) -lm -lopenblas
o0:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECNAME) $(SOURCES) -lm -lopenblas

clean:
	rm -f *.o core $(EXECNAME)
