#include "state.h"

void state_create(struct state *self)
{
	self->is_initial = false;
	self->is_final = false;
}

void state_set(struct state *self, bool is_initial, bool is_final)
{
	if(self == NULL) return;
	self->is_initial = is_initial;
	self->is_final = is_final;
}

void state_set_final(struct state *self)
{
	if(self == NULL) return;
	self->is_final = true;
}

void state_set_initial(struct state *self)
{
	if(self == NULL) return;
	self->is_initial = true;
}

void state_set_final_only(struct state *self)
{
	if(self == NULL) return;
	self->is_final = true;
	self->is_initial = false;
}

void state_set_initial_only(struct state *self)
{
	if(self == NULL) return;
	self->is_final = false;
	self->is_initial = true;
}

void state_unset(struct state *self)
{
	if(self == NULL) return;
	self->is_final = false;
	self->is_initial = false;
}

void state_unset_initial(struct state *self)
{
	if(self == NULL) return;
	self->is_initial = false;
}

void state_unset_final(struct state *self)
{
	if(self == NULL) return;
	self->is_final = false;
}

void state_dump(const struct state *self)
{
	if(self == NULL) return;
	printf("%s and %s\n",(self->is_initial) ? "initial" : "not initial",(self->is_final) ? "final" : "not final");
}

bool state_is_final(const struct state *self)
{
	assert(self);
	return self->is_final;
}

bool state_is_initial(const struct state *self)
{
	assert(self);
	return self->is_initial;
}