/**
* Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr
*			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr
**/

#ifndef POSITION_H
#define POSITION_H

typedef struct position position;

struct position
{
	int x;
	int y;
};

void position_set(position *pos, int x, int y);

#endif