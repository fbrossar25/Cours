#include "fa.h"

/*
struct fa{
	size_t alpha_count;
	size_t state_count;
	struct state_set **transitions;
	struct state *states;
};
*/

void fa_create(struct fa *self, size_t alpha_count, size_t state_count)
{
	assert(self != NULL);
	self->alpha_count = alpha_count;
	self->state_count = state_count;
	self->transitions = calloc(self->state_count, sizeof(struct state_set*));
	self->states = calloc(self->state_count, sizeof(struct state));
	for(size_t i=0; i<self->state_count; i++)
	{
		self->transitions[i] = calloc(self->alpha_count, sizeof(struct state_set));
		for(size_t j=0; j<self->alpha_count; j++)
		{
			state_set_create(&self->transitions[i][j],self->alpha_count);
		}
	}

	for(size_t i=0; i<self->state_count; i++)
	{
		state_create(&self->states[i]);
	}
}

void fa_destroy(struct fa *self)
{
	if(self == NULL) return;
	if(self->transitions != NULL)
	{
		for(size_t i=0; i<self->state_count; i++)
		{
			for(size_t j=0; j<self->alpha_count; j++)
			{
				state_set_destroy(&self->transitions[i][j]);
			}
			free(self->transitions[i]);
		}
		free(self->transitions);
		self->transitions = NULL;
	}
	if(self->states != NULL)
	{
		free(self->states);
		self->states = NULL;
	}
	self->alpha_count = 0;
	self->state_count = 0;
}

void fa_set_state_initial(struct fa *self, size_t state)
{
	assert(self != NULL);
	if(state >= self->state_count) return;
	state_set_final(&self->states[state]);
}

void fa_set_state_final(struct fa *self, size_t state)
{
	assert(self != NULL);
	if(state >= self->state_count) return;
	state_set_initial(&self->states[state]);
}

void fa_unset_state_initial(struct fa *self, size_t state)
{
	assert(self != NULL);
	if(state >= self->state_count) return;
	state_unset_initial(&self->states[state]);
}

void fa_unset_state_final(struct fa *self, size_t state)
{
	assert(self != NULL);
	if(state >= self->state_count) return;
	state_unset_final(&self->states[state]);
}

void fa_add_transition(struct fa *self, size_t from, char alpha, size_t to)
{
	assert(self != NULL);
	assert(alpha >= 'a' && alpha <= 'z' && from < self->state_count && to < self->state_count);
	state_set_add(&self->transitions[from][(size_t)(alpha - 'a')], to);
}

void fa_pretty_print(const struct fa *self)
{
	assert(self != NULL);
	printf("Initial states:\n\t");
	for(size_t i=0; i<self->state_count; i++)
	{
		if(state_is_initial(&self->states[i])) printf("%zu ",i);
	}
	printf("\nFinal States:\n\t");
	for(size_t i=0; i<self->state_count; i++)
	{
		if(state_is_final(&self->states[i])) printf("%zu ",i);
	}
	printf("\nTransitions:\n");
	for(size_t i=0; i<self->state_count;i++)
	{
		printf("\tFor state %zu:\n",i);
		for(size_t j=0; j<self->alpha_count; j++)
		{
			printf("\t\tFor letter %c: ",(unsigned char)('a' + j));
			state_set_dump(&self->transitions[i][j]);
			printf("\n");
		}
	}
}

bool array_contain(const size_t *self, size_t n, size_t size)
{
	if(self == NULL || size == 0) return false;
	for(size_t i=0; i<size; i++)
	{
		if(self[i] == n) return true;
	}
	return false;
}

static int cmpsize_t(const void *p1, const void *p2)
{
   return (p1 - p2);
}

bool printDoubleCircleStates(const struct fa *self, FILE *out)
{
	assert(self != NULL && out != NULL);
	size_t listArray[self->state_count];
	size_t count = 0;
	for(size_t i=0; i<self->state_count; i++)
	{
		if(state_is_final(&self->states[i]) || state_is_initial(&self->states[i]))
		{
			if(!array_contain(listArray, i, count))
			{
				listArray[count] = i;
				count++;
			}
		}
	}
	if(count == 0)
	{
		return false;
	}

	qsort(listArray, count, sizeof(size_t), cmpsize_t);

	for(size_t i=0; i<count; i++)
	{
		fprintf(out,"%zu ",listArray[i]);
	}
	return true;
}

void fa_dot_print(const struct fa *self, FILE *out)
{
	assert(self != NULL);
	if(out == NULL) return;
	fprintf(out,"digraph finite_state_machine {\n");
	fprintf(out,"\tnode [shape = doublecircle]; ");
	if(printDoubleCircleStates(self,out)) fprintf(out,";\n\tnode [shape = circle];\n");
	else fprintf(out,"\n\tnode [shape = circle];\n");
	/*
	lignes de la forme :
		etat_depart -> etat_arrivée [ label = "alpha" ];
		alpha étant la lettre
	*/
	for(size_t i=0; i<self->state_count; i++)//pour chaque état
	{
		for(size_t j=0; j<self->alpha_count; j++)//pour chaque lettre
		{
			size_t stateListSize = state_set_size(&self->transitions[i][j]);
			if(stateListSize > 0)//S'il y a des transitions
			{
				size_t *stateList = state_set_get_states(&self->transitions[i][j]);
				for(size_t k=0; k<stateListSize; k++)
				{
					fprintf(out,"\t%zu -> %zu [ label = \"%c\" ];\n",i,stateList[k],(unsigned char)('a' + j));
				}
			}
		}
	}
	fprintf(out,"}\n");
}

void fa_remove_transition(struct fa *self, size_t from, char alpha, size_t to)
{
	assert(alpha >= 'a' && alpha <= 'z');
	if(from >= self->state_count || to >= self->state_count) return;
	state_set_remove(&self->transitions[from][(size_t) (alpha - 'a')], to);
}

void fa_remove_state(struct fa *self, size_t state)
{
	assert(self != NULL);
	if(state >= self->state_count) return;
	for(size_t i=0; i<self->alpha_count; i++)
	{
		state_set_destroy(&self->transitions[state][i]);
	}
	free(self->transitions[state]);
	for(size_t i=state; i<self->state_count-1; i++)
	{
		self->states[i] = self->states[i+1];
		self->transitions[i] = self->transitions[i+1];
	}
	for(size_t i=0; i<self->state_count-1; i++)
	{
		for(size_t j=0; j<self->alpha_count; j++)
		{
			fa_remove_transition(self,i,(unsigned char) (j+'a'),state);
			size_t n = state_set_size(&self->transitions[i][j]);
			for(size_t k=0; k<n; k++)
			{
				if(self->transitions[i][j].states[k] > state)
				{
					self->transitions[i][j].states[k]--;
				}
			}
		}
	}
	self->state_count--;
}

size_t fa_count_transitions(const struct fa *self)
{
	assert(self != NULL);
	size_t res = 0;
	for(size_t i=0; i<self->state_count; i++)
	{
		for(size_t j=0; j<self->alpha_count; j++)
		{
			res += state_set_size(&self->transitions[i][j]);
		}
	}
	return res;
}

bool fa_is_deterministic(const struct fa *self)
{
	assert(self != NULL);
	for(size_t i=0; i<self->state_count; i++)
	{
		for(size_t j=0; j<self->alpha_count; j++)
		{
			if(state_set_size(&self->transitions[i][j]) > 1)
			{
				return false;
			}
		}
	}
	return true;
}

bool fa_is_complete(const struct fa *self)
{
	assert(self != NULL);
	for(size_t i=0; i<self->state_count; i++)
	{
		for(size_t j=0; j<self->alpha_count; j++)
		{
			if(state_set_size(&self->transitions[i][j]) == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void fa_make_complete(struct fa *self)
{
	assert(self != NULL);
	for(size_t i=0; i<self->state_count; i++)
	{
		for(size_t j=0; j<self->alpha_count; j++)
		{
			if(state_set_size(&self->transitions[i][j]) == 0)
			{
				fa_add_transition(self,i,(size_t) (j + 'a'),i);
			}
		}
	}
}

//s1 et s2 doivent être initiaux pour donner un état initial, seulement un des deux pour final
void fa_merge_states(struct fa *self, size_t s1, size_t s2)
{
	assert(self != NULL);
	if(s1 >= self->state_count || s2 >= self->state_count) return;
	size_t sz;
	
	//Modifications
	for(size_t i=0; i<self->state_count; i++)
	{
		for(size_t j=0; j<self->alpha_count; j++)
		{
			sz = state_set_size(&self->transitions[i][j]);
			if(state_set_search(&self->transitions[i][j],s2) != sz)
			{
				state_set_add(&self->transitions[i][j],s1);
			}
		}
	}
	for(size_t i=0; i<self->alpha_count; i++)
	{
		sz = state_set_size(&self->transitions[s2][i]);
		size_t *tmp_set = state_set_get_states(&self->transitions[s2][i]);
		for(size_t j=0; j<sz; j++)
		{
			state_set_add(&self->transitions[s1][i],tmp_set[j]);
		}
	}

	//Reassignation en etat final et/ou initial
	if(state_is_initial(&self->states[s1]) && state_is_initial(&self->states[s2]))
	{
		state_set_initial(&self->states[s1]);
	}
	else
	{
		state_unset_initial(&self->states[s1]);
	}

	if(state_is_final(&self->states[s1]) || state_is_final(&self->states[s2]))
	{
		state_set_final(&self->states[s1]);
	}
	else
	{
		state_unset_final(&self->states[s1]);
	}

	fa_remove_state(self,s2);
}

bool fa_is_empty(struct fa *self)
{
	return(self == NULL || self->transitions == NULL || self->states == NULL || self->state_count == 0);
}

bool fa_is_destroyed(struct fa *self)
{
	return(self == NULL || (self->alpha_count == 0 && self->state_count == 0 && self->transitions == NULL && self->states == NULL));
}