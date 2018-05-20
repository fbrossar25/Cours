/**
* Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr
*			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr
**/

/*
typedef struct position position

struct position
{
	int x;
	int y;
};
*/

#include <unistd.h>

#include "position.h"

void position_set(position *pos, int x, int y){
	pos->x = x;
	pos->y = y;
}