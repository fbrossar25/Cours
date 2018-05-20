/**
* Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr
*			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr
**/

#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "position.h"

//Types of cell
#define UNKNOWN -1
#define VOID 0
#define SELF 1
#define ENEMY 2
#define PLAYABLE 3
#define ROCK 4

typedef struct boardgame boardgame;

struct boardgame
{
	size_t width;
	size_t height;
	int *map;
};

//Create a boardgame of height * width size with map filled of UNKNOWN (-1)
void boardgame_create(boardgame *self, size_t width, size_t height);

//Set the boardgame to an initial state
void boardgame_start(boardgame *self, int x, int y);

//Destroy a boardgame leaving map = NULL, height = width = 0
void boardgame_destroy(boardgame *self);

//Return true if the boardgame is empty
bool boardgame_is_empty(const boardgame *self);

//Print a boardgame with letters (S = SELF, E = ENEMY, R = ROCK, O = VOID, P = PLAYABLE, ? = UNKNOWN, ! = others / error)
void boardgame_print(const boardgame *self);

//Print a boardgame in stderr
void boardgame_print_stderr(const boardgame *self);

//Set the value of the cell (x,y) in self to type;
void boardgame_set(boardgame *self, size_t x, size_t y, int type);

//Update the state of the boardgame
void boardgame_update(boardgame *self, char *rep, position *pos);

//Return the value at (x,y) in self
int boardgame_get(const boardgame *self, size_t x, size_t y);

#endif