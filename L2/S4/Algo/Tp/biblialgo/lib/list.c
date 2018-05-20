#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct list_node {
  int value;
  struct list_node *next;
  //struct list_node *prev;
};

void list_create(struct list *self) {
	self->first = NULL;
}

void list_destroy(struct list *self) {
	struct list_node *tmp;
	while(self->first){
		tmp = self->first->next;
		free(self->first);
		self->first = tmp;
	}
}

bool list_equals(const struct list *self, const int *data, size_t size) {
	size_t sz = list_size(self);
	if(size != sz)
	{
		return false;
	}
	struct list_node *curr = self->first;
	for(size_t i=0; i<size; i++)
	{
		if(curr->value != data[i])
		{
			return false;
		}
		curr = curr->next;
	}
	return true;
}

void list_add_back(struct list *self, int value) {
	struct list_node *new = malloc(sizeof(struct list_node));
	new->value = value;
	new->next = NULL;
	if(list_is_empty(self)) self->first = new;
	else{
		struct list_node *curr = self->first;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = new;
	}
}

void list_add_front(struct list *self, int value) {
  struct list_node *new = malloc(sizeof(struct list_node));
  new->value = value;
  new->next = self->first;
  self->first = new;
}

void list_insert(struct list *self, int value, size_t index) {
	if(self == NULL)
	{
		return ;
	}
	size_t sz = list_size(self);
	if(sz == 0 && index == 0)
	{
		list_add_front(self,value);
	}
	if(sz+1 < index)
	{
		return ;
	}
	struct list_node *curr = self->first;
	struct list_node *prev = NULL;
	size_t i = 0;
	while(i < index){
		prev = curr;
		curr = curr->next;
		i++;
	}
	struct list_node *new = malloc(sizeof(struct list_node));
	new->value = value;
	new->next = curr;
	if(prev == NULL)
	{
		self->first = new;
	}
	else
	{
		prev->next = new;
	}
}

void list_remove(struct list *self, size_t index) {
	if(list_is_empty(self) || list_size(self) <= index) return;
	if(index == 0){
		struct list_node *target = self->first;
		self->first = target->next;
		free(target);
	}
	else{
		struct list_node *curr = self->first->next;
		struct list_node *prev = self->first;
		for(size_t i=1; i<index; i++){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

int *list_get(const struct list *self, size_t index) {
	if(list_is_empty(self) || list_size(self) <= index) return NULL;
	struct list_node *curr = self->first;
	for(size_t i = 0; i<index; i++){
		curr = curr->next;
	}
	return &curr->value;
}

bool list_is_empty(const struct list *self) {
  return (self->first == NULL);
}

size_t list_size(const struct list *self) {
  if(self == NULL || list_is_empty(self))
  	{
  		return 0;
  	}
  size_t i = 0;
  struct list_node *curr = self->first;
  while(curr)
  {
  	curr = curr->next;
  	i++;
  }
  return i;
}

size_t list_search(const struct list *self, int value) {
	if(self == NULL)
	{
		return 0;
	}
	struct list_node *curr = self->first;
	size_t index = 0;
	while(curr)
	{
		if(curr->value == value){
			break;
		}
		curr = curr->next;
		index++;
	}
	return index;
}

void list_import(struct list *self, const int *other, size_t size) {
	list_destroy(self);
	for(size_t i=0; i<size; i++){
		list_add_back(self, other[i]);
	}
}

void list_dump(const struct list *self) {
	struct list_node *curr = self->first;
	size_t count = 1;
	while(curr)
	{
		printf("%d, ",curr->value);
		curr = curr->next;
		if(count % 10 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

bool list_is_sorted(const struct list *self) {
	if(list_is_empty(self)){
		return true;
	}
	struct list_node *curr = self->first;
	int prev = curr->value;
	size_t sz = list_size(self);
	for(size_t i=1; i<sz; i++){
		curr = curr->next;
		if(prev > curr->value){
			return false;
		}
		prev = curr->value;
	}
	return true;
}

struct list_node* sortedmerge(struct list_node* a, struct list_node* b);
void frontbacksplit(struct list_node* source, struct list_node** frontRef, struct list_node** backRef);
void mergesort(struct list_node** headRef);

void list_merge_sort(struct list *self){
	mergesort(&self->first);
}

/*
Les algorithmes suivants sont une adaption des algorithmes trouvés sur le site geeksforgeeks.org
à notre implantation des listes chaînées.
http://www.geeksforgeeks.org/merge-sort-for-linked-list/

Une vidéo trouvée sur youtube aide à la compréhension de la méthode utilisé 
par ces algorithmes pour le tri par fusion de liste chaînées
https://www.youtube.com/watch?v=jOyYaBHyN28
*/
void mergesort(struct list_node **headRef)
{
    struct list_node *head = *headRef;
    struct list_node *a;
    struct list_node *b;
    if (head == NULL || head->next == NULL)//si un seul noeud ou pas noeud, le tri est fait
    {
        return;
    }
    frontbacksplit(head, &a, &b);//on sépare la liste en deux, chacune des sous liste on leurs pointeur (a et b)
    mergesort(&a);//tri récursif sur la première sous liste
    mergesort(&b);//tri récursif sur la seconde sous liste
    *headRef = sortedmerge(a, b);//fusion des listes
}
 
struct list_node *sortedmerge(struct list_node *a, struct list_node *b)
{
    struct list_node *result = NULL;
 
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
 
    if ( a->value <= b->value)
    {
        result = a;
        result->next = sortedmerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedmerge(a, b->next);
    }
    return result;
}
 
void frontbacksplit(struct list_node *source, struct list_node **frontRef, struct list_node **backRef)
{
	//fast est le pointeur qui avance le plus vite lors du parcours de la liste
	//slow avance deux fois moins vite
	struct list_node *fast;
	struct list_node *slow;
	if (source == NULL || source->next == NULL)
	{
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*frontRef = source;//pointeur sur le début de la liste source
		*backRef = slow->next;//pointeur sur le noeuds médian
		slow->next = NULL;
	}
}