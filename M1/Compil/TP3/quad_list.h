#ifndef QUAD_LIST_H
#define QUAD_LIST_H

#include "quad.h"

struct quad_list{
    quad* q;
    struct quad_list* next;
};

typedef struct quad_list quad_list;

quad_list* quad_list_newlist(quad* first);
void quad_list_concat(quad_list* l1, quad_list* l2);
void quad_list_complete(quad_list* l, int label);
void quad_list_destroy(quad_list* l);

#endif