#ifndef STATE_H
#define STATE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct state
{
	bool is_initial;
	bool is_final;
};

//Initialise is_final et is_initial a false
void state_create(struct state *self);
//Assigne is_final et is_initial aux variable passes en parametres
void state_set(struct state *self, bool is_initial, bool is_final);
//Affiche self sous la forme "initial/not initial and final/not final"
void state_dump(const struct state *self);
//Definis is_final a true
void state_set_final(struct state *self);
//Definis is_initial a true
void state_set_initial(struct state *self);
//Definis is_final a true et is_initial a false
void state_set_final_only(struct state *self);
//Definis is_final a false et is_initial a true
void state_set_initial_only(struct state *self);
//Definis is_final et is_initial a false
void state_unset(struct state *self);
//Definis is_initial a false
void state_unset_initial(struct state *self);
//Definis is_final a false
void state_unset_final(struct state *self);
//Retourne is_final
bool state_is_final(const struct state *self);
//Retourne is_initial
bool state_is_initial(const struct state *self);

#endif