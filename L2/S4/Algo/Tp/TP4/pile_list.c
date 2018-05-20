#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct stack_node {
	int data;
	struct stack_node *next;
};

struct stack {
	struct stack_node *first;
};

void stack_create(struct stack *self);
bool stack_is_empty(const struct stack *self);
void stack_push(struct stack *self, int data);
int stack_top(const struct stack *self);
void stack_pop(struct stack *self);
void stack_destroy(struct stack *self);
void stack_display(const struct stack *self);
void stack_random(struct stack *self, size_t n);

int main(int argc, char *argv[]){
	struct stack *st = calloc(1,sizeof(struct stack));
	stack_create(st);
	printf("random :\n");
	stack_random(st,10);
	stack_display(st);
	printf("pop :\n");
	stack_pop(st);
	stack_display(st);
	printf("top = %d\n",stack_top(st));
	stack_destroy(st);
	printf("List destroyed ? %s\n",(stack_is_empty(st)) ? "yes" : "no");
	return EXIT_SUCCESS;
}

void stack_create(struct stack *self){
	self->first = NULL;
}

bool stack_is_empty(const struct stack *self){
	return (self->first == NULL);
}

void stack_push(struct stack *self, int data){
	struct stack_node *other = malloc(sizeof(struct stack_node));
	other->data = data;
	if(stack_is_empty(self)){//si liste Nil
		self->first = other;
		other->next = NULL;
	}
	else{
		other->next = self->first;
		self->first = other;
	}
}

int stack_top(const struct stack *self){
	if(stack_is_empty(self)) return 0;
	return self->first->data;
}

void stack_pop(struct stack *self){
	if(stack_is_empty(self)) return;
	struct stack_node *curr = self->first;
	self->first = curr->next;
	free(curr);
}

void stack_destroy(struct stack *self){
	while(self->first != NULL){
		stack_pop(self);
	}
}

void stack_display(const struct stack *self){
	if(stack_is_empty(self))
	{
		printf("Pile vide\n");
		return;
	}
	struct stack_node *curr = self->first;
	while(curr != NULL)
	{
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void stack_random(struct stack *self, size_t n){
	for(size_t i=0; i<n; i++)
	{
		stack_push(self,n-i);
	}
}