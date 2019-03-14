/*********************************************************************************/
/* Matrix product program with MPI on a virtual ring of processors               */
/* S. Vialle - October 2014                                                      */
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <omp.h>

//#include <cblas.h>
#include <openblas/cblas.h>

#include "main.h"
#include "Calcul.h"

//TEST
/*-------------------------------------------------------------------------------*/
/* Sequential product of local matrixes (optimized seq product).                 */
/*-------------------------------------------------------------------------------*/
void OneLocalProduct(unsigned long step)
{
  unsigned long OffsetStepLigC;
  unsigned long i, j, k;

  // Set the number of OpenMP threads inside parallel regions
  omp_set_num_threads(NbThreads);

  // Compute the current step offset, in the MPI program, to access right C lines
  OffsetStepLigC = 0;  /*********************** TO DO  **************************/

  switch (KernelId) {

  // Kernel 0 : Optimized code implemented by an application developer
  case 0 :
    #pragma omp parallel for private(i,j,k)
    for (i = 0; i < LOCAL_SIZE; i++) {
      unsigned long iAoff = i*SIZE;
      for (j = 0; j < LOCAL_SIZE; j++) {
        unsigned long jTBoff = j*SIZE;
        double accu[8];
        accu[0] = accu[1] = accu[2] = accu[3] = accu[4] = accu[5] = accu[6] = accu[7] = 0.0;
        for (k = 0; k < (SIZE/8)*8; k += 8) {
           accu[0] += A_Slice[iAoff+k+0] * TB_Slice[jTBoff+k+0];
           accu[1] += A_Slice[iAoff+k+1] * TB_Slice[jTBoff+k+1];
           accu[2] += A_Slice[iAoff+k+2] * TB_Slice[jTBoff+k+2];
           accu[3] += A_Slice[iAoff+k+3] * TB_Slice[jTBoff+k+3];
           accu[4] += A_Slice[iAoff+k+4] * TB_Slice[jTBoff+k+4];
           accu[5] += A_Slice[iAoff+k+5] * TB_Slice[jTBoff+k+5];
           accu[6] += A_Slice[iAoff+k+6] * TB_Slice[jTBoff+k+6];
           accu[7] += A_Slice[iAoff+k+7] * TB_Slice[jTBoff+k+7];
        }
        for (k = (SIZE/8)*8; k < SIZE; k++) {
           accu[0] += A_Slice[iAoff+k] * TB_Slice[jTBoff+k];
        } 
        C_Slice[(i+OffsetStepLigC)*LOCAL_SIZE+j] = accu[0] + accu[1] + accu[2] + accu[3] +
                                                   accu[4] + accu[5] + accu[6] + accu[7];
      }
    }
    break;

  // Kernel 1 : Very optimized computing kernel implemented in a HPC library
  case 1 :
    #pragma omp parallel
    {
      unsigned long reste = LOCAL_SIZE % omp_get_num_threads();
      unsigned long quotient = LOCAL_SIZE / omp_get_num_threads();
      unsigned long NbLigTh = quotient + 
                    (omp_get_thread_num() < reste ? 1 : 0);
      unsigned long offsetThLigC = quotient*omp_get_thread_num() + 
                         (omp_get_thread_num() < reste ? omp_get_thread_num() : reste);
      cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                  NbLigTh, LOCAL_SIZE, SIZE,
                  1.0, &A_Slice[offsetThLigC*SIZE], SIZE, 
                  B_Slice, LOCAL_SIZE,
                  0.0, &C_Slice[(OffsetStepLigC+offsetThLigC)*LOCAL_SIZE], LOCAL_SIZE);
    }
    break;

  default :
    fprintf(stderr,"Error: kernel %d not implemented!\n",KernelId);
    exit(EXIT_FAILURE);
    break;
  }
}
