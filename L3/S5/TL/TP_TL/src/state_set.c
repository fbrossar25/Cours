#include "state_set.h"

/*
struct state_set{
	size_t size;
	size_t capacity;
	size_t *states;
};
*/

//Fonction qui agrandis self->states si besoin, le créer s'il n'existe pas ou si sa capacité est nulle
void state_expand(struct state_set *self)
{
	if(self->states == NULL || self->capacity == 0)
	{
		state_set_create(self,1);
	}
	else if(self->size == self->capacity)
	{
		size_t prevCap = self->capacity;
		self->capacity *= 2;
		size_t *newStates = calloc(self->capacity, sizeof(size_t));
		memcpy(newStates,self->states,prevCap * sizeof(size_t));
		free(self->states);
		self->states = newStates;
	}
}

void state_set_create(struct state_set *self, size_t capacity)
{
	self->capacity = capacity;
	self->states = calloc(self->capacity,sizeof(size_t));
	self->size = 0;
}

void state_set_destroy(struct state_set *self)
{
	if(self == NULL) return;
	if(self->states != NULL)
	{
		free(self->states);
		self->states = NULL;
	}
	self->size = 0;
	self->capacity = 0;
}

bool state_set_is_empty(const struct state_set *self)
{
	return (self == NULL || self->capacity == 0 || self->size == 0 || self->states == NULL);
}

size_t state_set_size(const struct state_set *self)
{
	return self->size;
}

bool state_set_is_sorted(const struct state_set *self)
{
	if(self == NULL || state_set_is_empty(self))
	{
		return true;
	}
	size_t size = state_set_size(self);
	for(size_t i=0; i<size-1; i++)
	{
		if(self->states[i] > self->states[i+1])
		{
			return false;
		}
	}
	return true;
}

size_t *state_set_get_states(const struct state_set *self)
{
	assert(self);
	return self->states;
}

size_t state_set_binary_search(const size_t *states, size_t size, size_t value, size_t lo, size_t hi)
{
	if (lo == hi)
	{
		return size;
	}
	size_t mid = (lo + hi) / 2;
	if (value < states[mid])
	{
		return state_set_binary_search(states, size, value, lo, mid);
	}
	if (states[mid] < value)
	{
		return state_set_binary_search(states, size, value, mid + 1, hi);
	}
	return mid;
}

size_t state_set_search_sorted(const struct state_set *self, size_t value)
{
	size_t size = state_set_size(self);
	return state_set_binary_search(self->states, size, value, 0, size);
}

void state_set_swap(size_t *states, ssize_t k, ssize_t l)
{
	size_t tmp = states[k];
	states[k] = states[l];
	states[l] = tmp;
}

ssize_t state_set_partition(size_t *states, ssize_t i, ssize_t j)
{
	ssize_t pivot_index = i;
	const size_t pivot = states[pivot_index];
	state_set_swap(states, pivot_index, j);
	ssize_t l = i;
	for (ssize_t k = i; k < j; ++k)
	{
		if (states[k] < pivot)
		{
			state_set_swap(states, k, l);
			l++;
		}
	}
	state_set_swap(states, l, j);
	return l;
}

void state_set_quick_sort_partial(size_t *states, ssize_t i, ssize_t j)
{
	if (i < j) {
		ssize_t p = state_set_partition(states, i, j);
		state_set_quick_sort_partial(states, i, p - 1);
		state_set_quick_sort_partial(states, p + 1, j);
	}
}

void state_set_quick_sort(struct state_set *self)
{
	ssize_t size = self->size;
	state_set_quick_sort_partial(self->states, 0, size - 1);
}

void state_set_sort(struct state_set *self)
{
	state_set_quick_sort(self);
}

size_t state_set_search(struct state_set *self, size_t target)
{
	if(state_set_is_empty(self)) return 0;
	state_set_sort(self);
	return state_set_search_sorted(self,target);
}

//ajout de l'élément state
void state_set_add(struct state_set *self, size_t state)
{
	state_expand(self);//si self->size < self->capacity, ne modifie rien. Sinon augmente de la capacité
	if(state_set_search(self,state) < self->size)//On ajoute pas deux fois le même élément
	{
		printf("Element already in this state_set\n");
		return;
	}
	self->states[self->size] = state;
	self->size++;
	state_set_sort(self);
}

//détruits self et le reconstruit avec les éléments de other
void state_set_import(struct state_set *self, const size_t *other, size_t size)
{
	if(!state_set_is_empty(self))
	{
		state_set_destroy(self);
	}
	for(size_t i=0; i<size; i++)
	{
		state_set_add(self,other[i]);
	}
}

void state_set_dump(const struct state_set *self)
{
	if(state_set_is_empty(self)) return;
	for(size_t i=0; i<self->size; i++)
	{
		printf("%zu ", self->states[i]);
	}
}

void state_set_remove(struct state_set *self, size_t state)
{
	if(state_set_is_empty(self)) return;
	size_t index = state_set_search(self,state);
	if(index == self->size) return;
	for(size_t i=index; i<self->size-1; i++)
	{
		self->states[i] = self->states[i+1];
		self->states[i]--;
	}
	self->size--;
}