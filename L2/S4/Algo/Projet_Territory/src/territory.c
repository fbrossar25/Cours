/**
* Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr
*			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr
**/

/*
typedef struct position position

struct position
{
	size_t x;
	size_t y;
};

typedef struct boardgame boardgame;

struct boardgame
{
	size_t width;
	size_t height;
	int *map;
};
*/

#include "territory.h"

//depart entre 0 et 25%
bool territory_choose_pos_bottom(boardgame *b, position *p)
{
	if(p->y < b->height/4) // on monte jusqu'a 25%
	{
		if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
		{
			position_set(p, p->x, p->y+1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == b->height/4) // on est à 25%
	{
		bool l=true;
		for(size_t k=0; k < b->width; ++k)
		{
			if(boardgame_get(b, k, p->y) == PLAYABLE)
			{
				l=false;
			}
		}

		if(l==true) // si la ligne est déjà faite on monte
		{
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}
			else
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0; k < b->width; ++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if(p->y < b->height/2 && p->y > b->height/4) // on monte jusqu'a 50%
	{
		if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
		{
			position_set(p, p->x, p->y+1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == b->height/2) // on est à 50%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l == true) // si la ligne est déjà créé on monte
		{
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
				{
					position_set(p, p->x, p->y+1);
					return true;
				}
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if(p->y < ((b->height*75)/100) && p->y > b->height/2) //on monte à 75%
	{
		if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
		{
			position_set(p, p->x, p->y+1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == ((b->height*75)/100)) // on est à 75%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l == true) // si la ligne est déjà créé on stop
		{
			return false;
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	return false;
}

// départ entre 75% et 100%
bool territory_choose_pos_top(boardgame *b, position *p)
{
	if(p->y > ((b->height*75)/100)) // on descend jusqu'a 75%
	{
		if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
		{
			position_set(p, p->x, p->y-1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == ((b->height*75)/100)) // on est à 75%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k){
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l==true){ // si la ligne est déjà créé on descend
			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}

		}
		else{ // sinon on créer la ligne
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if((p->y < ((b->height*75)/100)) && p->y > b->height/2) // on descend jusqu'a 50%
	{
		if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
		{
			position_set(p, p->x, p->y-1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == b->height/2) // on est à 50%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l==true) // la ligne est déjà créé on descend
		{
			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
				{
					position_set(p, p->x, p->y-1);
					return true;
				}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
		else  // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if(p->y<b->height/2 && p->y>b->height/4) // on descend jusqu'a 25%
	{
		if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
		{
			position_set(p, p->x, p->y-1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y==b->height/4) // on est à 25%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l==true) // la ligne est déjà créé on stop
		{
			return false;
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	return false;
}

// départ entre 50% et 75%
bool territory_choose_pos_middlet(boardgame *b, position *p, position *start)
{
	if((p->y < ((b->height*75)/100)) && p->y > b->height/2) //on descend jusqu'a 50%
	{
		if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
		{
			position_set(p, p->x, p->y-1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == b->height/2) // on est à 50%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l == true) // la ligne est déjà créé on descend
		{
			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
				{
					position_set(p, p->x, p->y-1);
					return true;
				}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if(p->y < b->height/2 && p->y > b->height/4) // on descend jusqu'a 25%
	{
		if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
		{
			position_set(p, p->x, p->y-1);
			return true;
		}
		else 
		{
			if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
			{
				position_set(p, p->x+1, p->y);
				return true;
			}

			if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
			{
				position_set(p, p->x-1, p->y);
				return true;
			}
		}
	}
	
	if(p->y == b->height/4) // on est à 25%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l == true) // la ligne est déjà créé on revient à la position start et on monte
		{
			position_set(p,start->x,start->y);
			if(boardgame_get(b, p->x, p->y+1) != PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) == PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if((p->y > start->y && p->y < ((b->height*75)/100)) || p->y == start->y) // on monte jusqu'a 75%
	{
	
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
	}
	
		if(p->y == ((b->height*75)/100)) // on est à 75%
		{
			bool l=true;
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) != PLAYABLE)
				{
					l=false;
				}
			}
			if(l==true) // la ligne est déjà créé on stop
			{
				return false;
			}
			else // sinon on créé la ligne
			{
				for(size_t k=0;k<b->width;++k)
				{
					if(boardgame_get(b, k, p->y) == PLAYABLE)
					{
						position_set(p, k, p->y);
						return true;
					}
				}
				if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
				{
					position_set(p, p->x, p->y+1);
					return true;
				}

				if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
				{
					position_set(p, p->x, p->y-1);
					return true;
				}
			}
		}
	
	return false;
}

// départ entre 25% et 50%
bool territory_choose_pos_middleb(boardgame *b, position *p, position *start)
{
	if(p->y < b->height/2 && p->y > b->height/4) // on monte jusqu'a 50%
	{
		if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
		{
			position_set(p, p->x, p->y+1);
			return true;
		}
		else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
	}
	
	if(p->y == b->height/2) // on est à 50%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l == true) // la ligne est déjà créé on monte
		{
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
				{
					position_set(p, p->x, p->y+1);
					return true;
				}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) != PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if(p->y < ((b->height*75)/100) && p->y > b->height/2) // on monte jusqu'a 75%
	{
		if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
		{
			position_set(p, p->x, p->y+1);
			return true;
		}
		else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
	}
	
	if(p->y == ((b->height*75)/100)) // on est à 75%
	{
		bool l=true;
		for(size_t k=0;k<b->width;++k)
		{
			if(boardgame_get(b, k, p->y) != PLAYABLE)
			{
				l=false;
			}
		}
		if(l == true) // la ligne est déjà créé on revient à la position start et on descend
		{
			position_set(p,start->x,start->y);
			if(boardgame_get(b, p->x, p->y-1) != PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
		else // sinon on créer la ligne
		{
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) != PLAYABLE)
				{
					position_set(p, k, p->y);
					return true;
				}
			}
			if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
			{
				position_set(p, p->x, p->y+1);
				return true;
			}

			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
		}
	}
	
	if((p->y < start->y && p->y > b->height/4) || p->y == start->y) // on descend jusqu'a 25%
	{
		if(p->y<b->height/2 && p->y>b->height/4)
		{
			if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
			{
				position_set(p, p->x, p->y-1);
				return true;
			}
			else 
			{
				if(boardgame_get(b, p->x+1, p->y) == PLAYABLE)
				{
					position_set(p, p->x+1, p->y);
					return true;
				}

				if(boardgame_get(b, p->x-1, p->y) == PLAYABLE)
				{
					position_set(p, p->x-1, p->y);
					return true;
				}
			}
		}
	
		if(p->y==b->height/4)
		{
			bool l=true;
			for(size_t k=0;k<b->width;++k)
			{
				if(boardgame_get(b, k, p->y) != PLAYABLE)
				{
					l=false;
				}
			}
			if(l==true) // la ligne est déjà créé on stop
			{
				return false;
			}
			else // sinon on créer la ligne
			{
				for(size_t k=0;k<b->width;++k)
				{
					if(boardgame_get(b, k, p->y) != PLAYABLE)
					{
						position_set(p, k, p->y);
						return true;
					}
				}
				if(boardgame_get(b, p->x, p->y+1) == PLAYABLE)
				{
					position_set(p, p->x, p->y+1);
					return true;
				}

				if(boardgame_get(b, p->x, p->y-1) == PLAYABLE)
				{
					position_set(p, p->x, p->y-1);
					return true;
				}
			}
		}
	}
	return false;	
}