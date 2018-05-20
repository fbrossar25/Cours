#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct disc{
	int width;
	struct disc *next;
};

struct tower{
	struct disc *first;
};

struct hanoi {
	struct tower towers[3];
};

//create hanoi game with n discs
void hanoi_create(struct hanoi *self, int n);
// create an empty tower
void tower_create(struct tower *self);
// push a disc of size k on top of the tower
void tower_push_disc(struct tower *self, int k);
// pop the top disc and return its size
int tower_pop_disc(struct tower *self);
// print the content of the tower
void tower_print(const struct tower *self);
//print the content of the hanoi game
void hanoi_print(const struct hanoi *self);
//move the smallest disc from i tower to j tower if possible
void hanoi_move_one_disc(struct hanoi *self, int i, int j);
//move n disc from i tower to j tower
void hanoi_move(struct hanoi *self, int n, int source, int destination);

int main(int argc, char *argv[]){
	struct hanoi *game = malloc(sizeof(struct hanoi));
	hanoi_create(game,4);
	printf("Départ :\n");
	hanoi_print(game);
	hanoi_move(game,4,0,1);
	return EXIT_SUCCESS;
}

// create an empty tower
void tower_create(struct tower *self){
	self->first = NULL;
}

// push a disc of size k on top of the tower
void tower_push_disc(struct tower *self, int k){
	if(k <= 0){
		printf("\ntrying a void push : very uneffective\n");
		return;
	}
	struct disc *other = malloc(sizeof(struct disc));
	//printf("\nfap\n");
	other->next = NULL;
	other->width = k;
	if(self->first == NULL){
		self->first = other;
		return;
	}
	struct disc *curr = self->first;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = other;
	//printf("\nflop\n");
}

// pop the top disc and return its size
// return -1 if there isn't any disc
int tower_pop_disc(struct tower *self){
	if(self->first == NULL)return -1;
	int width;
	struct disc *curr = self->first;
	struct disc *prev;
	while(curr->next !=NULL){
		prev = curr;
		curr = curr->next;
	}
	width = curr->width;
	free(curr);
	prev->next = NULL;
	return width;
}

// print the content of the tower
void tower_print(const struct tower *self){
	if(self->first == NULL) return;
	struct disc *curr = self->first;
	while(curr){
		printf("%d ",curr->width);
		curr = curr->next;
	}
}

void hanoi_create(struct hanoi *self, int n){
	struct tower *curr;
	for(int i=0; i<3; i++){
		curr = &(self->towers[i]);
		tower_create(curr);
	}
	curr = &(self->towers[0]);
	for(int i=n; i>0; i--){
		tower_push_disc(curr,i);
	}
}

void hanoi_print(const struct hanoi *self){
	for(int i=0; i<3 ;i++){
		printf("%c : ",'A'+i);
		tower_print(&(self->towers[i]));
		printf("\n");
	}
	printf("\n");
}

void hanoi_move_one_disc(struct hanoi *self, int i, int j){
	//printf("\nplop\n");
	struct tower *towerI = &(self->towers[i]);
	int width = tower_pop_disc(towerI);
	printf("Tower %d : disc %d to tower %d\n\n",i,width,j);
	if(width > 0){
		struct tower * towerJ = &(self->towers[j]);
		tower_push_disc(towerJ,width);
		//printf("\nfapping hard\n");
	}
}

void hanoi_move(struct hanoi *self, int n, int source, int destination){
	if(source == destination){
		printf("error : source == destination in hanoi_move\n");
		return;
	}
	if(n > 0){
		printf("\nparty hard\n");
		int inter;
		if(source != 0 && destination != 0) inter = 0;
		else if(source != 1 && destination != 1) inter = 1;
		else inter = 2;
		hanoi_move(self,n-1,source,inter);
		hanoi_move_one_disc(self,source,destination);
		//printf("\ntry hard\n");
		hanoi_print(self);
		//printf("\ntry hard 2 le retour\n");
		hanoi_move(self,n-1,inter,destination);
		//printf("\ntry hard 3 la vengeance\n");
	}
}

/*
n=1 => 1 mouvements
n=2 => 3 mouvements
n=3 => 7 mouvements
n=4 => 15 mouvements

2n-1 mouvements

procédure Hanoï(n, source, dest)
    si n ≠ 0
    	calcul de I //I != source && I != dest && I >= 0 && I < 3
        Hanoï(n-1, source, I)
        Déplacer le disque de source vers dest
        Hanoï(n-1, I, dest)
    fin-si
fin-procédure
*/
