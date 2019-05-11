#include "quad.h"

quad* quad_gen(char* op, symbol* arg1, symbol* arg2, symbol* res)
{
	quad* new = malloc(sizeof(quad));
	new->op = strdup(op);
	new->arg1 = arg1;
	new->arg2 = arg2;
	new->res = res;
	new->next = NULL;
	return new;
}

void quad_add(quad** dest, quad* src)
{
	if(*dest == NULL)
    {
		*dest = src;
	}
    else
    {
		quad* scan = *dest;
		while(scan->next !=NULL)
        {
			scan = scan->next;
		}
		scan->next = src;
	}
}

void quad_destroy(quad* q)
{
	if(q == NULL)
	{
		return;
	}

	quad* tmp;
	
	while(q != NULL)
	{
		tmp = q;
		q = q->next;
		symbol_destroy(tmp->res);
		symbol_destroy(tmp->arg1);
		symbol_destroy(tmp->arg2);
		free(tmp->op);
		free(tmp);
	}
}

void quad_print(quad* q)
{
    while(q != NULL)
    {
		quad_print_one(q);
        q = q->next;
    }
}

void quad_print_one(quad* q)
{
	if(q == NULL)
	{
		printf("NULL quad! \n");
		return;
	}
	symbol_print_value_or_id(q->res);
	printf(" <- ");
	symbol_print_value_or_id(q->arg1);
	printf(" %s ", q->op);
	symbol_print_value_or_id(q->arg2);
	printf("\n");
}