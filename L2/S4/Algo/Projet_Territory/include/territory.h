#ifndef TERRITORY_H
#define TERRITORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "boardgame.h"
#include "position.h"

//Select the next position to place a wall when p is under 25% of the map's height
bool territory_choose_pos_bottom(boardgame *b, position *p);

//Select the next position to place a wall when p is below 75% of the map's height
bool territory_choose_pos_top(boardgame *b, position *p);

//Select the next position to place a wall when p is between 50% and 75% of the map's height
bool territory_choose_pos_middlet(boardgame *b, position *p, position *start);

//Select the next position to place a wall when p is between 25% and 50% of the map's height
bool territory_choose_pos_middleb(boardgame *b, position *p, position *start);
#endif