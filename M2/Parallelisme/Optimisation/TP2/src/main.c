/*********************************************************************************/
/* Optimized and multithreaded matrix product                                    */
/* S. Vialle - october 2014                                                      */
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#include "main.h"
#include "Init.h"
#include "Calcul.h"


/*-------------------------------------------------------------------------------*/
/* Global variable declarations.                                                 */
/*-------------------------------------------------------------------------------*/

/* Matrixes: C = A.B                                                             */
/* We use the Transposed B matrix, in place of B, to improve cache memory usage. */
double A[SIZE][SIZE];                            /* A Matrix.                   */
double B[SIZE][SIZE];                            /* B Matrix.                   */
double TB[SIZE][SIZE];                           /* B Transposed Matrix.        */
double C[SIZE][SIZE];                            /* C matrix (result matrix).   */

/* Global variables to control computations.                                     */
int NbThreads = -1;
int KernelId = -1; 


/*-------------------------------------------------------------------------------*/
/* Print result of the parallel computation and performances                     */
/*-------------------------------------------------------------------------------*/
void PrintResultsAndPerf(double gigaflops, double d1,double d2)
{
   fprintf(stdout,"PE%d: Product of two square matrixes of %dx%d doubles:\n",
           0,SIZE,SIZE);
   fprintf(stdout,"\tPE%d: C[%d][%d] = %f\n",
           0,0,SIZE-1,
           (float) C[0][SIZE-1]);
   fprintf(stdout,"\tPE%d: C[%d][%d] = %f\n",
           0,SIZE/2,SIZE/2,
           (float) C[SIZE/2][SIZE/2]);
   fprintf(stdout,"\tPE%d: C[%d][%d] = %f\n",
           0,SIZE-1,0,
           (float) C[SIZE-1][0]);
   fprintf(stdout,"\n\tPE%d: Elapsed time of the loop = %f(s)\n",
           0,(float) d1);
   fprintf(stdout,"\tPE%d: Total Gigaflops = %f\n",
           0,(float) gigaflops);
   fflush(stdout);

   fprintf(stdout,"\n\tPE%d: Total elapsed time of the application = %f(s)\n",
           0,(float) d2);
   fflush(stdout);
}


/*-------------------------------------------------------------------------------*/
/* Toplevel function.                                                            */
/*-------------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
  double td1, tf1;                      /* Time measures of the computation loop */
  double td2, tf2;                      /* Time measures of the entire programe  */
  double d1, d2;
  double gigaflops;

  td2 = omp_get_wtime(); 
  CommandLineParsing(argc,argv);                  /* For future evolutions ...   */
  LocalMatrixInit();                              /* Initialization of the data  */

  fprintf(stdout,"Computation starts: Matrixes %dx%d, KernelId %d, NbThreads %d\n",
                  SIZE, SIZE, KernelId, NbThreads);
  fflush(stdout);

  td1 = omp_get_wtime();                       
  LocalMatrixProduct();                           /* Parallel Matrix product.    */
  tf1 = omp_get_wtime();                          /* End of the time measurement */
	                                              
  d1 = tf1 - td1;                                 /* Performance computation     */
  gigaflops = 2.0*SIZE*SIZE*SIZE/1E9/d1;

  tf2 = omp_get_wtime();                          /* End of time measurement     */
  d2 = tf2 - td2;

  PrintResultsAndPerf(gigaflops,d1,d2);           /* Results and perf printing   */

  return(EXIT_SUCCESS);
}


