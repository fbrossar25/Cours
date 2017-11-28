#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SYMBOL_SIZE 32

typedef struct symbol symbol;

struct symbol
{
	char* identifier;
	bool isConstant;
	int value;
	struct symbol* next;
};

symbol* sybol_alloc();
symbol* symbol_newtemp(symbol** table);
symbol* symbol_lookup(symbol* table, char* name);
symbol* symbol_add(symbol** table, char* name);
symbol* symbol_get_or_create(symbol** table, char* name);
void symbol_destroy(symbol* table);
void symbol_print(symbol* symbol);
void symbol_print_value_or_id(symbol* s);

#endif