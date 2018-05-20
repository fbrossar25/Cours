#include "lcg.h"

/* get the next random number (similar to rand()) */
size_t lcg_next(struct lcg *self){
	self->seed = (self->mult * self->seed + self->incr) % self->mod;
	return self->seed;
}