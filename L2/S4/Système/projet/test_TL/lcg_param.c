#include "lcg.h"

/* initialize the parameters of self */
void lcg_param(struct lcg *self, size_t mult, size_t incr, size_t mod){
	self->mult = mult;
	self->incr = incr;
	self->mod = mod;
}