/**
* Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr
*			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr
**/

#include "boardgame.h"

/*
struct boardgame
{
	size_t height;
	size_t width;
	int *map;
};
*/

void boardgame_create(boardgame *self, size_t width, size_t height)
{
	self->width = width;
	self->height = height;
	self->map = calloc(width*height,sizeof(int));
	for(size_t y=0; y<height; y++)
	{
		for(size_t x=0; x<width; x++)
		{
			self->map[y * self->height + x] = UNKNOWN;
		}
	}
}


void boardgame_destroy(boardgame *self)
{
	if(self == NULL)
	{
		return ;
	}
	free(self->map);
	self->height = 0;
	self->width = 0;
}

bool boardgame_is_empty(const boardgame *self)
{
	return (self == NULL || self->map == NULL || self->width == 0 || self->height == 0);
}

void boardgame_set(boardgame *self, size_t x, size_t y, int type)
{
	if(x >= 0 && x < self->width && y >= 0 && y < self->height)
	{
		self->map[y * self->height + x] = type;
	}
	else
	{
		fprintf(stderr,"Cannot set cell(%zu,%zu) to %d. Map size (w * h) : %zu * %zu\n",x,y,type,self->width,self->height);
		exit(EXIT_FAILURE);
	}
}

char cell_print(int cell);

void boardgame_print(const boardgame *self)
{
	for(size_t y=0; y<self->height; y++)
	{
		for(size_t x=0; x<self->width; x++)
		{
			printf(" %c ",cell_print(self->map[y * self->height + x]));
		}
		printf("\n");
	}
}

void boardgame_print_stderr(const boardgame *self)
{
	for(size_t y=0; y<self->height; y++)
	{
		for(size_t x=0; x<self->width; x++)
		{
			fprintf(stderr," %c ",cell_print(self->map[y * self->height + x]));
		}
		fprintf(stderr,"\n\n");
	}
}

char cell_print(int cell)
{
	switch(cell)
	{
		case SELF:
		{
			return 'S';
		}
		break;
		case ENEMY:
		{
			return 'E';
		}
		break;
		case ROCK:
		{
			return 'X';
		}
		break;
		case VOID:
		{
			return '.';
		}
		break;
		case UNKNOWN:
		{
			return '?';
		}
		break;
		case PLAYABLE:
		{
			return 'P';
		}
		break;
		default:
		{
			return '!';
		}
	}
}

void boardgame_update(boardgame *self, char *rep, position *pos){
	if(self == NULL || rep == NULL || pos == NULL)//Null pointer
	{
		fprintf(stderr,"Null pointer given for update\n");
		exit(EXIT_FAILURE);
	}

	if(strcmp(rep,"ERROR\n") == 0)//error occured
	{
		fprintf(stderr,"Received 'ERROR' from server\n");
		return ;
	}

	fprintf(stderr,"Server sent : %s\n",rep);

	if(strcmp(rep,"PASS\n") == 0 || strcmp(rep,"FINISH\n") == 0)//player pass or game finished
	{
		return ;
	}

	if(strcmp(rep,"ENEMY\n") == 0)
	{
		boardgame_set(self, pos->x, pos->y, ENEMY);
	}

	if(strcmp(rep,"WALL\n") == 0)//rock placed
	{
		fprintf(stderr,"rock placed\n");
		boardgame_set(self, pos->x, pos->y, SELF);

		if(pos->x > 0)//not at the top
		{
			if(boardgame_get(self, pos->x-1, pos->y) == UNKNOWN)
			{
				boardgame_set(self, pos->x-1, pos->y, PLAYABLE);
			}
		}

		if(pos->x < self->height - 1)//not at the bottom
		{
			if(boardgame_get(self, pos->x+1, pos->y) == UNKNOWN)
			{
				boardgame_set(self, pos->x+1, pos->y, PLAYABLE);
			}
		}

		if(pos->y > 0)//not at the left
		{
			if(boardgame_get(self, pos->x, pos->y-1) == UNKNOWN)
			{
				boardgame_set(self, pos->x, pos->y-1, PLAYABLE);
			}
		}

		if(pos->y < self->width - 1)//not at the right
		{
			if(boardgame_get(self, pos->x, pos->y+1) == UNKNOWN)
			{
				boardgame_set(self, pos->x, pos->y+1, PLAYABLE);
			}
		}
	}
}

void boardgame_start(boardgame *self, int x, int y)
{
	boardgame_set(self, x, y, SELF);

	if(x > 0)//not at the top
	{
		boardgame_set(self, x-1, y, PLAYABLE);
	}

	if(x < self->width - 1)//not at the bottom
	{
		boardgame_set(self, x+1, y, PLAYABLE);
	}

	if(y > 0)//not at the left
	{
		boardgame_set(self, x, y-1, PLAYABLE);
	}

	if(y < self->height - 1)//not at the right
	{
		boardgame_set(self, x, y+1, PLAYABLE);
	}
}

int boardgame_get(const boardgame *self, size_t x, size_t y)
{
	return self->map[y * self->height + x];
}