/*********************************************************************************/
/* Matrix product program with MPI on a virtual ring of processors               */
/* S. Vialle - October 2014                                                      */
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <mpi.h>

#include "main.h"
#include "Init.h"
#include "Calcul.h"


/*-------------------------------------------------------------------------------*/
/* Global variable declarations.                                                 */
/*-------------------------------------------------------------------------------*/

/* Matrixes: C = A.B                                                             */
/* We use the Transposed B matrix, in place of B, to improve cache memory usage. */
double *A_Slice;                                /* A Matrix.                    */
double *B_Slice;                                /* B Matrix.                    */
double *TB_Slice;                               /* Transposed B Matrix.         */
double *C_Slice;                                /* C matrix (result matrix).    */

unsigned long SIZE;                            /* Matrix side                   */
unsigned long LOCAL_SIZE;                      /* Nb of lines on 1 process      */

/* Global variables for the management of the parallelisation.                   */
/* Need to be initialized dynamically: set to dummy values for the moment.       */
int Me = -1;                                    /* Processor rank                */
int NbPE = -1;                                  /* Number of processors          */

/* Global variables for the management of the result and performance printing.   */
unsigned long PrinterPE = 0;          /* Processor hosting the central elt of C.*/
unsigned long PrintedElt_i = 0;       /* Coordinates of the central elt of C in */ 
unsigned long PrintedElt_j = 0;       /* its host processor.                    */

/* Global variables to control computations.                                     */
int NbThreads = -1;
int KernelId = -1; 

/*-------------------------------------------------------------------------------*/
/* Parallel computation: local computations and data circulations.               */
/*-------------------------------------------------------------------------------*/
void ComputationAndCirculation()
{
 unsigned long step=0;
 while(step !=NbPE){
    OneLocalProduct(step);
    OneStepCirculation(step);
    step++;
 } 
/******************************** TO DO ******************************************/
}
/*-------------------------------------------------------------------------------*/
/* Elementary circulation of A and B.                                            */
/*-------------------------------------------------------------------------------*/
void OneStepCirculation(unsigned long step)
{
 MPI_Status   status;
 MPI_Sendrecv_replace(A_Slice,
                    LOCAL_SIZE*SIZE,
                    MPI_DOUBLE,
                    ((Me-1)+NbPE)%NbPE,
                    0,
                    (Me+1)%NbPE,
                    0,
                    MPI_COMM_WORLD, &status);
}


/*-------------------------------------------------------------------------------*/
/* Toplevel function.                                                            */
/*-------------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double td1, tf1;                    /* Time measures of the computation loop */
    double td2, tf2;                    /* Time measures of the entire programe  */
    double d1, d2;                      /* Elapsed times to measure.             */
    double gigaflops;                   /* Program performances to measure.      */

    /* Initialisations --------------------------------------------------------- */
    MPI_Init(&argc,&argv);                        /* MPI initialisation.         */
    td2 = MPI_Wtime();                            /* Start app. time measurement.*/
    ProcessorInit();             /* TO COMPLETE *//* Important init on the proc. */
    CommandLineParsing(argc,argv);                /* Cmd line parsing.           */
    ProcessorPostInit();                          /* Postinit.                   */
    LocalMatrixAllocInit();                       /* Initialization of the data  */
    omp_set_num_threads(NbThreads);               /* Max nb of threads/node.     */

    /* Matrix product computation ---------------------------------------------- */ 
    if (Me == PrinterPE) {
      fprintf(stdout,"Product of two square matrixes of %lux%lu doubles:\n",
              SIZE,SIZE);
      fprintf(stdout,"- Number of MPI processes: %d\n",NbPE);
      fprintf(stdout,"- Max number of OpenMP threads per process: %d\n", NbThreads);
      fprintf(stdout,"- Kernel Id: %d\n",KernelId);
      fprintf(stdout,"- Parallel computation starts...\n");
      fflush(stdout);
    }
    MPI_Barrier(MPI_COMM_WORLD);                  /* Start comp. time measurement*/ 
    td1 = MPI_Wtime();                       
    ComputationAndCirculation(); /* TO COMPLETE *//* Parallel Matrix product.    */
    MPI_Barrier(MPI_COMM_WORLD);                  /* End of all. time measures.  */
    tf1 = MPI_Wtime();                            /* - end of comp. time measure.*/
    tf2 = MPI_Wtime();                            /* - end of app. time measure. */

    /* Performance computation, results and performance printing --------------- */
    d1 = tf1 - td1;                               /* Elapsed comp. time.         */
    d2 = tf2 - td2;                               /* Elapsed app. time.          */
    gigaflops = (2.0*pow(SIZE,3))/d1*1E-9;        /* Performance achieved.       */
    PrintResultsAndPerf(gigaflops,d1,d2);         /* Results and perf printing   */

    /* End of the parallel program --------------------------------------------- */
    Cleanup();
    MPI_Barrier(MPI_COMM_WORLD);                  
    MPI_Finalize();                               /* End of the MPI usage.       */
    return(EXIT_SUCCESS);
}

