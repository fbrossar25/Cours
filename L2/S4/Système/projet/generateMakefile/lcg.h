#ifndef LCG_H
#define LCG_H


#include <stdlib.h>


struct lcg {
	size_t seed; //x
	size_t mult; //a
	size_t incr; //c
	size_t mod;  //m
};

/* initialize the parameters of self */
void lcg_param(struct lcg *self, size_t mult, size_t incr, size_t mod);

/* initialize self (similar to srand()) */
void lcg_seed(struct lcg *self, size_t n);

/* get the next random number (similar to rand()) */
size_t lcg_next(struct lcg *self);

/* get the max that self can return (similar to RAND_MAX) */
size_t lcg_max(struct lcg *self);

#endif