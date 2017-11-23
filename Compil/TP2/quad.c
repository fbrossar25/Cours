#include "quad.h"

quad* quad_gen(char op, symbol* arg1, symbol* arg2, symbol* res)
{
	quad* new = malloc(sizeof(quad));
	new->op = op;
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
    //TODO
}

void quad_print(quad* q)
{
    while(q != NULL)
    {
        printf("%s -> %s %c %s", q->res, q->arg1, q->op, q->arg2);
        q = q->next;
    }
}
