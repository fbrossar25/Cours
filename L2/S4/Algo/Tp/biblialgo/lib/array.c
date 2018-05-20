#include "array.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
struct array {
  int *data;
  size_t capacity;
  size_t size;
};
*/

void array_create(struct array *self) {
	self->capacity = 10;
	self->data = calloc(self->capacity,sizeof(int));
	self->size = 0;
}

void array_destroy(struct array *self) {
	if(self->data != NULL)
	{
		free(self->data);
	}
	self->data = NULL;
	self->size = 0;
	self->capacity = 0;
}

bool array_equals(const struct array *self, const int *content, size_t size) {
	if(self->size != size)
	{
		return false;
	}
	for(size_t i=0; i<size; i++){
		if(self->data[i] != content[i])
		{
			return false;
		}
	}
	return true;
}

void array_add(struct array *self, int value) {
	if(self->data == NULL || self->capacity == 0)
	{
		self->capacity = 10;
		self->data = calloc(self->capacity, sizeof(int));
		self->data[0] = value;
		self->size = 1;
	}
	else
	{
		if(self->size == self->capacity)
		{
			size_t prevCap = self->capacity;
			self->capacity *= 2;
			int *newData = calloc(self->capacity, sizeof(int));
			memcpy(newData,self->data,prevCap * sizeof(int));
			free(self->data);
			self->data = newData;
		}
		self->data[self->size] = value;
		self->size++;
	}
}

void array_insert(struct array *self, int value, size_t index) {
	if(index > self->size)
	{
		return ;
	}
	int *newData;
	if(self->size == self->capacity)
	{
		self->capacity *= 2;
	}
	newData = calloc(self->capacity, sizeof(int));
	for(size_t i=0; i<index; i++){
		newData[i] = self->data[i];
	}
	newData[index] = value;
	for(size_t i=index; i<self->size; i++){
		newData[i+1] = self->data[i];
	}
	free(self->data);
	self->data = newData;
	self->size++;
}

void array_remove(struct array *self, size_t index) {
	if(index > self->size)
	{
		return ;
	}
	for(size_t i=index; i < self->size; i++){
		self->data[i] = self->data[i+1];
	}
	self->size--;
}

int *array_get(const struct array *self, size_t index) {
	if(array_is_empty(self) || index > self->size-1)return NULL;
	else return &self->data[index];
}

bool array_is_empty(const struct array *self) {
	return (self == NULL || self->data == NULL || self->size == 0);
}

size_t array_size(const struct array *self) {
	return self->size;
}

size_t array_search(const struct array *self, int value) {
	size_t size = array_size(self);
	size_t i = 0;
	while(i < size){
		if(self->data[i] == value)
		{
			break ;
		}
		i++;
	}
	return i;
}

size_t array_binary_search(const int *data, size_t size, int value, size_t lo, size_t hi);

size_t array_search_sorted(const struct array *self, int value) {
	size_t size = array_size(self);
	return array_binary_search(self->data, size, value, 0, size);
}

size_t array_binary_search(const int *data, size_t size, int value, size_t lo, size_t hi){
	if (lo == hi)
	{
		return size;
	}
	size_t mid = (lo + hi) / 2;
	if (value < data[mid])
	{
		return array_binary_search(data, size, value, lo, mid);
	}
	if (data[mid] < value)
	{
		return array_binary_search(data, size, value, mid + 1, hi);
	}
	return mid;
}

void array_import(struct array *self, const int *other, size_t size) {
	if(!array_is_empty(self))
	{
		array_destroy(self);
	}
	for(size_t i=0; i<size; i++)
	{
		array_add(self,other[i]);
	}
}

void array_dump(const struct array *self) {
	for(size_t i=0; i<self->size; i++)
	{
		printf("%d, ",self->data[i]);
	}
	printf("\n");
}

bool array_is_sorted(const struct array *self) {
	if(self == NULL || array_is_empty(self))
	{
		return true;
	}
	size_t size = array_size(self);
	for(size_t i=0; i<size-1; i++)
	{
		if(self->data[i] > self->data[i+1])
		{
			return false;
		}
	}
	return true;
}

void array_quick_sort_partial(int *data, ssize_t i, ssize_t j);
ssize_t array_partition(int *data, ssize_t i, ssize_t j);

void array_swap(int *data, ssize_t k, ssize_t l){
	int tmp = data[k];
	data[k] = data[l];
	data[l] = tmp;
}

void array_selection_sort(struct array *self) {
	size_t size = array_size(self);
	for (size_t i = 0; i < size - 1; ++i)
	{
		size_t j = i;
		for (size_t k = j + 1; k < size; ++k)
		{
			if (self->data[k] < self->data[j])
			{
				j = k;
			}
		}
		array_swap(self->data, i, j);
	}
}

void array_bubble_sort(struct array *self) {
	size_t size = array_size(self);
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = size - 1; j > i; --j)
		{
			if (self->data[j] < self->data[j - 1])
			{
				array_swap(self->data, j, j - 1);
			}
		}
	}
}

void array_insertion_sort(struct array *self) {
	size_t size = array_size(self);
	for (size_t i = 1; i < size; ++i)
	{
		int x = self->data[i];
		size_t j = i;
		while (j > 0 && self->data[j - 1] > x)
		{
			self->data[j] = self->data[j - 1];
			j--;
		}
		self->data[j] = x;
	}
}

void array_quick_sort(struct array *self) {
	ssize_t size = array_size(self);
	array_quick_sort_partial(self->data, 0, size - 1);
}

void array_quick_sort_partial(int *data, ssize_t i, ssize_t j) {
	if (i < j) {
		ssize_t p = array_partition(data, i, j);
		array_quick_sort_partial(data, i, p - 1);
		array_quick_sort_partial(data, p + 1, j);
	}
}

ssize_t array_partition(int *data, ssize_t i, ssize_t j) {
	ssize_t pivot_index = i;
	const int pivot = data[pivot_index];
	array_swap(data, pivot_index, j);
	ssize_t l = i;
	for (ssize_t k = i; k < j; ++k)
	{
		if (data[k] < pivot)
		{
			array_swap(data, k, l);
			l++;
		}
	}
	array_swap(data, l, j);
	return l;
}

void heap_remove_max(int *heap, size_t n) {
	heap[0] = heap[n - 1];
	size_t i = 0;
	while (i < (n - 1) / 2)
	{
		size_t lt = 2 * i + 1;
		size_t rt = 2 * i + 2;
		if (heap[i] > heap[lt] && heap[i] > heap[rt])
		{
			break ;
		}
		size_t j = (heap[lt] > heap[rt]) ? lt : rt;
		array_swap(heap, i, j);
		i = j;
	}
}

void heap_insert(int *heap, size_t n, int value) {
	size_t i = n;
	heap[i] = value;
	while (i > 0)
	{
		ssize_t j = (i - 1) / 2;
		if (heap[i] < heap[j])
		{
			break;
		}
		array_swap(heap, i, j);
		i = j;
	}
}

void array_heap_sort(struct array *self){
	size_t n = array_size(self);
	for (size_t i = 0; i < n; ++i)
	{
		int value = self->data[i];
		heap_insert(self->data, i, value);
	}
	for (size_t i = 0; i < n; ++i)
	{
		int value = self->data[0];
		heap_remove_max(self->data,n-i);
		self->data[n - i - 1] = value;
	}
}

bool array_is_heap(const struct array *self){
	size_t size = array_size(self);
	for(size_t i=1; i<size; i++)
	{
		if(self->data[i] > self->data[ (i-1) / 2])
		{
			return false;
		}
	}
	return true;
}

void array_heap_add(struct array *self, int value) {
	if(self->capacity == 0)
	{
		self->capacity = 10;
		self->data = calloc(self->capacity, sizeof(int));
	}
	if(self->size == self->capacity)
	{
		size_t prevCap = self->capacity;
		self->capacity *= 2;
		int *newData = calloc(self->capacity, sizeof(int));
		memcpy(newData,self->data,prevCap * sizeof(int));
		free(self->data);
		self->data = newData;
	}
	heap_insert(self->data,self->size,value);
	self->size++;
}

int array_heap_top(const struct array *self) {
	if(self->size <= 0) exit(EXIT_FAILURE);
	return self->data[0];
}

void array_heap_remove_top(struct array *self) {
	heap_remove_max(self->data, self->size);
	self->size--;
}