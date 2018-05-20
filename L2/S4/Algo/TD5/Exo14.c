#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct deque{
	size_t capacity;
	size_t start;
	size_t end;
	int *data;
};

void deque_create(struct deque *self);
bool deque_is_empty(struct deque *self);
void deque_push(struct deque *self, int value);
size_t next(size_t i, size_t capacity);
size_t prev(size_t i, size_t capacity);
void deque_inject(struct deque *self, int value);
void deque_pop(struct deque *self);
void deque_eject(struct deque *self);
int deque_front(struct deque *self);
int deque_back(struct deque *self);

int main(int argc, char **argv){

	return EXIT_SUCCESS;
}

void deque_create(struct deque *self){
	self->capacity = 0;
	self->start = 0;
	self->end = 0;
	self->data = NULL;
}

bool deque_is_empty(struct deque *self){
	return (self->start == self->end);
}

void deque_push(struct deque *self, int value){
	if(next(self->end,self->capacity) == self->start){
		size_t cap = self->capacity * 2;
		int *data = calloc(cap,sizeof(int));
		memcpy(data,self->data + self->start,(self->capacity - self->start)*sizeof(int));
		memcpy(data + (self->capacity - self->start),self->data,(self->end % (self->capacity - 1))*sizeof(int));
		//car si self->end = self->capacity - 1 on copie rien
		self->start = 0;
		self->end = self->capacity - 1;
		free(self->data);
		self->data = data;
		self->capacity = cap;
	}
	self->start = prev(self->start,self->capacity);
	self->data[self->start] = value;
}

void deque_inject(struct deque *self, int value){
	
}

size_t next(size_t i, size_t capacity){
	return (i+1)%capacity;
}

size_t prev(size_t i, size_t capacity){
	return (i-1)%capacity;
}

void deque_pop(struct deque *self){
	assert(!deque_is_empty(self));
	self->end = prev(self->end,self->capacity);
}

void deque_eject(struct deque *self){
	assert(!deque_is_empty(self));
	prev(self->start,self->capacity);
}

int deque_front(struct deque *self){
	assert(!deque_is_empty(self));
	return self->data[self->start];
}
int deque_back(struct deque *self){
	assert(!deque_is_empty(self));
	return self->data[prev(self->end,self->capacity)];
}