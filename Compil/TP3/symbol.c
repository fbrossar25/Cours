#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"

symbol* symbol_alloc()
{
	symbol* new = malloc(sizeof(symbol));
	new->identifier = NULL;
	new->isConstant = false;
	new->value = 0;
	new->next = NULL;
	return new;
}

symbol* symbol_add(symbol** table, char* name)
{
	if(*table == NULL)
	{
		*table = symbol_alloc();
		(*table)->identifier = strdup(name);
		return *table;
	}
	else
	{
		symbol* scan = *table;
		while (scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = symbol_alloc();
		scan->next->identifier = strdup(name);
		return scan->next;
	}
}

symbol* symbol_get_or_create(symbol** table, char* name)
{
	symbol* s = symbol_lookup(*table, name);
	if(s == NULL)
	{
		s = symbol_add(table, name);
	}
	return s;
}

symbol* symbol_newtemp(symbol** table)
{
	static int temp_num = 0;
	char temp_name[SYMBOL_SIZE];
	snprintf(temp_name, SYMBOL_SIZE, "temp_%d", temp_num);
	temp_num++;
	return symbol_add(table, temp_name);
}

symbol* symbol_lookup(symbol* table, char* name)
{
	while(table != NULL)
	{
		if(strcmp(table->identifier,name) == 0) //symbole trouvé
		{
			return table;
		}
		table=table->next;
	}
	return NULL;
}

void symbol_destroy(symbol* table)
{
	if(table == NULL)
	{
		return;
	}

	symbol* tmp;
	
	while(table != NULL)
	{
		tmp = table;
		table = table->next;
		free(tmp->identifier);
		free(tmp);
	}
}

void symbol_print(symbol* s)
{
	while(s != NULL)
	{
		printf("id: %7s, isConstant: ", s->identifier);
		if(s->isConstant)
		{
			printf("true, value: %d\n", s->value);
		} else
		{
			printf("false, value: N/A\n");
		}
		s = s->next;
	}
}

void symbol_print_value_or_id(symbol* s)
{
	if(s == NULL)
	{
		printf("NULL symbol");
	}
	if(s->isConstant)
	{
		printf("%d <- ",s->value);
	}
	else
	{
		printf("%s <- ",s->identifier);
	}
}