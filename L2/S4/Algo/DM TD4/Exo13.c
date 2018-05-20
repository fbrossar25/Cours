#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

struct list_node{
	int data;
	struct list_node *next;
};

struct list{
	struct list_node *first;
};

int list_size(const struct list *self);
void list_mirror(const struct list *self, struct list *res);
struct list *list_create();
void list_create_random(struct list *self, int size);
void list_display(const struct list *self);
void list_copy(const struct list *self, struct list *res);
void list_concat(const struct list *l1, const struct list *l2, struct list *res);

int main(int argc, char *argv[]){
	srand(time(NULL));
	struct list *toto = list_create();
	list_create_random(toto,10);
	printf("toto :\n");
	list_display(toto);
	struct list *mirror = list_create();
	list_create_random(mirror,10);
	list_mirror(toto,mirror);
	printf("\ntoto mirror:\n");
	list_display(mirror);
	list_copy(mirror,toto);
	printf("mirror copy:\n");
	list_display(toto);
	struct list *concat = list_create();
	list_create_random(concat,20);
	list_mirror(toto,mirror);
	list_concat(toto,mirror,concat);
	printf("concat:\n");
	list_display(concat);
	return 0;
}

int list_size(const struct list *self) {
	int i = 0;
	struct list_node *curr = self->first;
	while(curr != NULL){
		i++;
		curr = curr->next;
	}
	return i;
}

//l'affectation est l'opération élémentaire
//avec n la taille de la liste
//N(S1) = n(n+1) / 2 = O(n²)
//N(S2) = 3n
//C(n) =  N(S1) + N(S2) = O(n²) + 3n = O(n²)
void list_mirror(const struct list *self, struct list *res){
	int size = list_size(self);
	assert(size > 0);
	struct list_node *curr = self->first;
	struct list_node *other = res->first;
	for(int i=size; i>0; i--){
		for(int j=0; j<i-1; j++){
			curr = curr->next;//S1
		}
		//S2
		other->data = curr->data;
		other = other->next;
		curr = self->first;
		//fin S2
	}
}

struct list *list_create(){
	struct list *toto = malloc(sizeof(struct list));
	toto->first = malloc(sizeof(struct list_node));
	return toto;
}

void list_create_random(struct list *self, int size){
	assert(size > 0);
	struct list_node *curr = self->first;
	int i = 0;
	do{
		//curr->data = random()%100;
		curr->data = i;
		if(i < size-1){
			curr->next = malloc(sizeof(struct list_node));
			curr = curr->next;
		}
		i++;
	}while(i < size-1);
	//curr->data = random()%100;
	curr->data = i;
}

void list_display(const struct list *self){
	int size = list_size(self);
	assert(size > 0);
	struct list_node *curr = self->first;
	for(int i=0; i<size; i++){
		printf("node %d : data = %d\n",i,curr->data);
		curr = curr->next;
	}
	printf("\n\n");
}

//l'affectation est l'opération élémentaire
//avec n la taille de la liste
//C(n) =  3n = O(n)
void list_copy(const struct list *self, struct list *res){
	struct list_node *curr = self->first;
	struct list_node *other = res->first;
	while(curr != NULL){
		other->data = curr->data;
		curr = curr->next;
		other = other->next;
	}
}

//l'affectation est l'opération élémentaire
//avec n la taille de la liste
//N(S1) = N(S2) = 3n
//C(n) =  2*3n = 6n = O(n)
void list_concat(const struct list *l1, const struct list *l2, struct list *res){
	struct list_node *curr = l1->first;
	struct list_node *other = res->first;
	while(curr != NULL){//S1
		other->data = curr->data;
		curr = curr->next;
		other = other->next;
	}
	curr = l2->first;
	while(curr != NULL){//S3
		other->data = curr->data;
		curr = curr->next;
		other = other->next;
	}
}
