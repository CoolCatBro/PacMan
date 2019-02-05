#include "Sprite.hpp"
#include "Globals.hpp"
#include "Level.hpp"
#include "Pac.hpp"

#include<cstdio>
#include<conio.h>
#include<ctime>
#include<iostream>

int main()
{
	//Scenes
	Scene gsc(GAME_WIDTH,GAME_HEIGHT);

	//Nodes
	Level* level = new Level(&gsc);
	//Maze* maze = new Maze(&gsc, 31, 28,1);
	Pac* pac = new Pac(&gsc,0,0);

	level->addNode(pac);
	level->load();

	clock_t btime = clock();
	double dt;
	while (1) 
	{
		dt = double(clock() - btime) / CLOCKS_PER_SEC;
		if (dt > 1.0)
			btime = clock();
		if (_kbhit())
			pac->move(_getch());
		level->render(dt);
		gsc.game.refresh();
		gsc.game.clear();
	}
	return 0;
}