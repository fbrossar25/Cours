#ifndef QUAD_H
#define QUAD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"

struct quad{
	char* op;
	struct symbol* arg1;
	struct symbol* arg2;
	struct symbol* res;
	struct quad* next;
};

typedef struct quad quad;

quad* quad_gen(char* op, symbol* arg1, symbol* arg2, symbol* res);
void quad_add(quad** dest, quad* src);
void quad_destroy(quad* q);
void quad_print(quad* q);
void quad_print_one(quad* q);

#endif