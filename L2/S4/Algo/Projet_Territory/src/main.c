/**
* Authors : Florian BROSSARD - florian.brossard@edu.univ-fcomte.fr
*			Fanny MILLOTTE	 - fanny.millotte02@edu.univ-fcomte.fr
**/

#include "territory.h"

#define BUFSIZE 1024

int main() {
	char buf[BUFSIZE];
	// get the width
	fgets(buf, BUFSIZE, stdin);
	int width = atoi(buf);
	// get the height
	fgets(buf, BUFSIZE, stdin);
	int height = atoi(buf);
	// get the initial x
	fgets(buf, BUFSIZE, stdin);
	int x = atoi(buf);
	// get the initial y
	fgets(buf, BUFSIZE, stdin);
	int y = atoi(buf);
	// initialize the state of the game
	boardgame b;
	boardgame_create(&b,width,height);
	
	boardgame_start(&b,x,y);

	position start;
	position_set(&start,x,y);
	
	position pos;
	position_set(&pos,x,y);
	bool wall;

	size_t turn = 0;

	for (;;) {
		fprintf(stderr,"\nturn %zu :\n",turn);
		boardgame_print_stderr(&b);
		fprintf(stderr,"\npos = (%i,%i)\n",pos.x,pos.y);
		// play
		// choose a new x and y
		if(start.y <= b.height/4)
		{
			wall = territory_choose_pos_bottom(&b,&pos);
		}
		else if(start.y>b.height/4 && start.y<=b.height/2)
		{
			wall = territory_choose_pos_middleb(&b,&pos,&start);
		}
		else if(start.y>b.height/2 && start.y<((b.height*75)/100))
		{
			wall = territory_choose_pos_middlet(&b,&pos,&start);
		}
		else if(start.y>((b.height*75)/100))
		{
			wall = territory_choose_pos_top(&b,&pos);
		}
		else
		{
			wall=false;
		}
		
		if(wall)// "WALL" or "PASS"
		{
			puts("WALL");
			printf("%i %i\n", pos.x, pos.y);
			fflush(stdout);
			// get the response: WALL, ENEMY, ROCK, PASS, FINISH or ERROR
			fgets(buf, BUFSIZE, stdin);
			// update the state of the game
			boardgame_update(&b,buf,&pos);
		}
		else
		{
			puts("PASS");
		}

		turn++;
	}
	boardgame_destroy(&b);
	return 0;
}