/*********************************************************************************/
/* Optimized and multithreaded matrix product                                    */
/* S. Vialle - october 2014                                                      */
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

//#include <openblas/cblas.h>
#include <cblas.h>

#include "main.h"
#include "Calcul.h"


/*-------------------------------------------------------------------------------*/
/* Matrix products (different kernels)                                           */
/*-------------------------------------------------------------------------------*/
void LocalMatrixProduct()
{
  int i, j, k;

  // Fixe le nbr de thread d'OpenMP
  omp_set_num_threads(NbThreads);

  switch (KernelId) {

  // Kernel 0 : Code optimise' implante' par le developpeur de l'application
  // - PARALLELISEZ CE CODE AVEC OpenMP
  case 0 :
    // Noyau de calcul en "ijk avec TB"
    //#pragma omp parallel private(i)
    //{
    #pragma omp parallel for private(i,j,k)
    for (i = 0; i < SIZE; i++) {
      //pragma omp parallel for private(j,k)
      for (j = 0; j < SIZE; j++) {
        double accu[8];
        accu[0] = accu[1] = accu[2] = accu[3] = accu[4] = accu[5] = accu[6] = accu[7] = 0.0;
        //#pragma omp for private(k)
        for (k = 0; k < (SIZE/8)*8; k += 8) {
           accu[0] += A[i][k+0] * TB[j][k+0];
           accu[1] += A[i][k+1] * TB[j][k+1];
           accu[2] += A[i][k+2] * TB[j][k+2];
           accu[3] += A[i][k+3] * TB[j][k+3];
           accu[4] += A[i][k+4] * TB[j][k+4];
           accu[5] += A[i][k+5] * TB[j][k+5];
           accu[6] += A[i][k+6] * TB[j][k+6];
           accu[7] += A[i][k+7] * TB[j][k+7];
        }
        for (k = (SIZE/8)*8; k < SIZE; k++) {
           accu[0] += A[i][k] * TB[j][k];
        } 
        //#pragma omp critical
        //{
        C[i][j] = accu[0] + accu[1] + accu[2] + accu[3] + accu[4] + accu[5] + accu[6] + accu[7];
        //}
        //} -- End omp parallel
      }
    }
    //}
    // Noyau de calcul en "ikj"
    /*
    for (i = 0; i < SIZE; i++) {
      for (k = 0; k < SIZE; k++) {
        for (j = 0; j < SIZE; j++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    */
    
    break;

  // Kernel 1 : Code très optimise' implante' dans une bilbiotheque "BLAS"
  // - PARALLELISEZ CET APPEL AUX "BLAS" AVEC OpenMP
  case 1 :
    #pragma omp parallel
    {
        int slice_size = SIZE / omp_get_num_threads();
        int colonne = slice_size * omp_get_thread_num();
        //printf("%d/%d/%d\n",omp_get_thread_num(), omp_get_num_threads(),slice_size),
	    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                slice_size, SIZE, SIZE,
                1.0, &A[colonne][0], SIZE,
                &B[0][0], SIZE,
                0.0, &C[colonne][0], SIZE);
            #pragma omp single
            {
                int reste = (SIZE % omp_get_num_threads());
                if(reste != 0)
                {
                    colonne = SIZE - reste;
                    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                        reste, SIZE, SIZE,
                        1.0, &A[colonne][0], SIZE,
                        &B[0][0], SIZE,
                        0.0, &C[colonne][0], SIZE);
                }
            }
    }
    break;

  default :
    fprintf(stderr,"Error: kernel %d not implemented!\n",KernelId);
    exit(EXIT_FAILURE);
    break;
  }
}
