#ifndef FA_H
#define FA_H

#include "state_set.h"
#include "state.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//Structure d'un automate a nombre d'etat finit
struct fa
{
	size_t alpha_count;//Nombre de lettres
	size_t state_count;//Nombre d'etats
	struct state_set **transitions;//Tableau a deux dimensions avec allocation dynamique stockant les etats d'arrive des transition
	//Acces a ces transition comme suit : self->transitions[a][b]
	//a est l'etat de depart (compris entre 0 et self->state_count)
	//b est l'etiquette / la lettre de la transition (comprise entre 0 et self->alpha_count)
	//On peut y accèder soit par l'index alphabétique de ladite lettre, soit par lettre - 'a' (lettre appartenant a ['a','z'])
	struct state *states;//Tableau dynamique stockant les proprietes des etats (etats final et/ou initial ou non)
};

//Creer un automate avec alpha_count lettre et state_count etat
void fa_create(struct fa *self, size_t alpha_count, size_t state_count);
//Detruit l'automate self, cad desalloue self->states et self->transitions et definis self->alpha_count et self->sate_count a 0
void fa_destroy(struct fa *self);
//Definis l'etat state de self comme initial
void fa_set_state_initial(struct fa *self, size_t state);
//Definis l'etat state de self comme final
void fa_set_state_final(struct fa *self, size_t state);
//Definis l'etat state de self comme non initial
void fa_unset_state_initial(struct fa *self, size_t state);
//Definis l'etat state de self comme non final
void fa_unset_state_final(struct fa *self, size_t state);
//Ajoute un transition partant de from vers to, etiquettee alpha, si elle existe deja aucun doublon n'est cree
void fa_add_transition(struct fa *self, size_t from, char alpha, size_t to);
//Affiche les proprietes des etats et les transitions de l'automate self
void fa_pretty_print(const struct fa *self);
//Ecrit dans out la representation de l'automate self au format graphviz
void fa_dot_print(const struct fa *self, FILE *out);
//Supprime la transition partant de from vers to, etiquettee alpha si elle existe
void fa_remove_transition(struct fa *self, size_t from, char alpha, size_t to);
//Supprime l'etat state s'il existe ainsi que toutes transitions partant ou arrivant a cet etat
void fa_remove_state(struct fa *self, size_t state);
//Retourne le nombre de transitions de l'automate self
size_t fa_count_transitions(const struct fa *self);
//Retourne true si l'automate self est deterministe, cad s'il y a au plus une seule transition par lettre pour chaque etat, false sinon
bool fa_is_deterministic(const struct fa *self);
//Retourne true si l'automate self et complet, cad s'il y a au moins une transition pour chaque lettre pour chaque etat, false sinon
bool fa_is_complete(const struct fa *self);
//Si l'automate self n'est pas complet, ajoute les transitions manquantes vers l'etat ou elles manquent. 
void fa_make_complete(struct fa *self);
//Fusionne les etats s1 et s2 de l'automate self s'ils existent
void fa_merge_states(struct fa *self, size_t s1, size_t s2);
//Retourne true si l'automate self est vie, cad si self, self->transitions ou self->states == NULL ou si self->state_count == 0, false sinon
bool fa_is_empty(struct fa *self);
//Retourne true si l'automate self est detruit, cad si self == NULL ou si self->alpha_count == self->state_count == 0 et self->transitions == self->states == NULL
bool fa_is_destroyed(struct fa *self);

#endif