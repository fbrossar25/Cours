CC=mpicc
CFLAGS= -O3 -Wall -fopenmp -funroll-loops 
LDFLAGS= 
SOURCES= Init.c Calcul.c main.c 
EXECNAME= MatrixProduct
N_MACHINES=1
N_THREADS=1
SIZE=1024
RESOURCE=socket
RANKBY=$(RESOURCE)
BINDTO=$(RESOURCE)


all:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECNAME) $(SOURCES) -lm -lopenblas

mpirun: machines-file
	mpirun -np $(N_MACHINES) -map-by ppr:1:$(RESOURCE) -rank-by $(RANKBY) -bind-to $(BINDTO) -machinefile machines.txt ./MatrixProduct -klc 1 -k 1 -nt $(N_THREADS) -lc $(SIZE)

machines-file:
	sort -u $$OAR_NODEFILE > machines.txt

clean:
	rm -f *.o core $(EXECNAME)



