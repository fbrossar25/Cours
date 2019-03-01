/*********************************************************************************/
/* Optimized and multithreaded matrix product                                    */
/* S. Vialle - october 2014                                                      */
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include <openblas/cblas.h>
#include <cblas.h>

#include "main.h"
#include "Init.h"


/*-------------------------------------------------------------------------------*/
/* Initialisation of local matrixes A, B and C                                   */
/*-------------------------------------------------------------------------------*/
void LocalMatrixInit(void)
{
 int i, j;                                /* Local matrix indexes                */

/* Initialization of the local matrix elements                                   */
 for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
       A[i][j] = (double) (i*SIZE + j);
 
 for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++) {
       B[i][j] = (double) (2*i*SIZE + j + 1);
       TB[j][i] = B[i][j];
    }
 
 for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
       C[i][j] = 0.0;
}


/*-------------------------------------------------------------------------------*/
/* Command Line parsing.                                                         */
/*-------------------------------------------------------------------------------*/
void usage(int ExitCode, FILE *std)
{
 fprintf(std,"MatrixProduct usage: \n");
 fprintf(std,"\t [-k <Kernel Id> (default %d)]\n",DEFAULT_KERNEL_ID);
 fprintf(std,"\t [-h]: print this help\n");
 fprintf(std,"\t [-nt <number of threads> (default %d)]\n",DEFAULT_NB_THREADS);

 exit(ExitCode);
}


void CommandLineParsing(int argc, char *argv[])
{
 // Default init
 NbThreads = DEFAULT_NB_THREADS;
 KernelId = DEFAULT_KERNEL_ID;
 Quiet = 0;
 // Init from the command line
 argc--; argv++;
 while (argc > 0) {
     if (strcmp(argv[0],"-nt") == 0) {
       argc--; argv++;
       if (argc > 0) {
         NbThreads = atoi(argv[0]);
         argc--; argv++;
         if (NbThreads <= 0) {
           fprintf(stderr,"Error: number of thread has to be >= 1!\n");
           exit(EXIT_FAILURE);
         }
       } else {
         usage(EXIT_FAILURE, stderr);
       }
     } else if (strcmp(argv[0],"-k") == 0) {
       argc--; argv++;
       if (argc > 0) {
         KernelId = atoi(argv[0]);
         argc--; argv++;
         if (KernelId < 0 || KernelId > 1) {
           fprintf(stderr,"Error: kernel Id has to be an integer in [0;1]\n");
           exit(EXIT_FAILURE);
         }
       } else {
         usage(EXIT_FAILURE, stderr);
       }
     } else if (strcmp(argv[0],"-h") == 0) {
       usage(EXIT_SUCCESS, stdout);
     } else if(strcmp(argv[0], "-q") == 0) {
       argc--; argv++;
       Quiet = 1;
     } else {
       usage(EXIT_FAILURE, stderr);
     }
 }
 
 // Complementary inits
 openblas_set_num_threads(1);                    // Set OpenBLAS in sequential mode
}

