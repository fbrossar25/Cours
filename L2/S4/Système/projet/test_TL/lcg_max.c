#include "lcg.h"

/* get the max that self can return (similar to RAND_MAX) */
size_t lcg_max(struct lcg *self){
	return self->mod - 1;
}