/*********************************************************************************/
/* Optimized and multithreaded matrix product                                    */
/* S. Vialle - october 2014                                                      */
/*********************************************************************************/

/*-------------------------------------------------------------------------------*/
/* CONSTANTES.                                                                   */
/*-------------------------------------------------------------------------------*/

// Pour les mises au point ----------
#define SIZE            8192
//#define SIZE            1027

// Pour les benchmarks  -------------
//#define SIZE            4096
//#define SIZE            4099


#define DEFAULT_NB_THREADS 1
#define DEFAULT_KERNEL_ID  0


/*-------------------------------------------------------------------------------*/
/* Global variable declarations.                                                 */
/*-------------------------------------------------------------------------------*/

/* Matrixes: C = A.B                                                             */
/* We use the Transposed B matrix, in place of B, to improve cache memory usage. */
extern double A[SIZE][SIZE];                   
extern double B[SIZE][SIZE];
extern double TB[SIZE][SIZE];
extern double C[SIZE][SIZE];

/* Global variables to control computations.                                     */
extern int NbThreads;
extern int KernelId;
extern int Quiet;

/*-------------------------------------------------------------------------------*/
/* Global functions.                                                             */
/*-------------------------------------------------------------------------------*/
void PrintResultsAndPerf(double gigaflops, double d1,double d2);
int main(int argc, char *argv[]);
