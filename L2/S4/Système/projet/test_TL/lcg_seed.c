#include "lcg.h"

/* initialize self (similar to srand()) */
void lcg_seed(struct lcg *self, size_t n){
	self->seed = n;
}