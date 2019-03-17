CC=mpicc
CFLAGS= -O3 -Wall -fopenmp -funroll-loops 
LDFLAGS= 
SOURCES= Init.c Calcul.c main.c 
EXECNAME= MatrixProduct
NP=1
NT=1
KLC=8
RESOURCE=socket
RANKBY=$(RESOURCE)
BINDTO=$(RESOURCE)


all:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECNAME) $(SOURCES) -lm -lopenblas

mpirun: machines-file
	mpirun -np $(NP) -map-by ppr:1:$(RESOURCE) -rank-by $(RANKBY) -bind-to $(BINDTO) -machinefile machines.txt ./MatrixProduct -klc $(KLC) -k 1 -nt $(NT)

machines-file:
	sort -u $$OAR_NODEFILE > machines.txt

clean:
	rm -f *.o core $(EXECNAME)



