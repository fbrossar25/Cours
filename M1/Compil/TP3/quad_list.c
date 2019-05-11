#include "quad_list.h"

quad_list* quad_list_newlist(quad* first)
{
    quad_list* l = malloc(sizeof(quad_list));
    l->next = NULL;
    l->q = first;
    return l;
}

void quad_list_concat(quad_list* l1, quad_list* l2)
{
    if(l1 == NULL)
    {
        l1 = l2;
        return;
    }

    if(l2 == NULL)
    {
        return ;
    }

    quad_list* scan = l1;
    while(scan->next != NULL)
    {
        scan = scan->next;
    }

    scan->next = l2;
}

void quad_list_complete(quad_list* l, int label)
{
    //TODO
}

void quad_list_destroy(quad_list* l)
{
    quad_list* tmp = l;
    while(l != NULL)
    {
        tmp = l;
        l = l->next;
        quad_destroy(tmp->q);
        free(tmp);
    }
}