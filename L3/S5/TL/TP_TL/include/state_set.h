#ifndef STATE_SET_H
#define STATE_SET_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//Allocation dynamique des numeros des etats
struct state_set
{
	size_t size;//Taille / nombre d'elements dans *states
	size_t capacity;//Capacite
	size_t *states;//Numeros des etats d'arrive
};

//Initialis self->capacity a capacity, self->size a 0 et alloue capacity size_t a self->states
void state_set_create(struct state_set *self, size_t capacity);
//Detruits self, cad desalloue self->states et definis self->size et self->capacity a 0
void state_set_destroy(struct state_set *self);
//Retourne true si self est vide, cad si self == NULL ou si self->states == NULL ou si self->size ou self->capacity == 0
bool state_set_is_empty(const struct state_set *self);
//Trie self->states avec un quicksort
void state_set_sort(struct state_set *self);
//Retourne l'index de target s'il est dans self->states, self->size sinon. Recherche dichotomique
size_t state_set_search(struct state_set *self, size_t target);
//Ajoute l'etat state a self->states. Gere la reallocation si besoin
void state_set_add(struct state_set *self, size_t state);
//Importe *states dans self->states. Si self->states contient deja des element, self->states est detruit puis on lui realloue size elements
void state_set_import(struct state_set *self, const size_t *states, size_t size);
//Affiche les elements de self->states "n0 n1 n2 ..."
void state_set_dump(const struct state_set *self);
//Retourne self->states
size_t *state_set_get_states(const struct state_set *self);
//Retourne self->size
size_t state_set_size(const struct state_set *self);
//Supprime l'etat state s'il est present dans self->states, ne fait rien sinon
void state_set_remove(struct state_set *self, size_t state);

#endif