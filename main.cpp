#include "Sprite.hpp"
#include "Globals.hpp"
#include "Level.hpp"
#include "Pac.hpp"

#include<cstdio>
#include<conio.h>
#include<ctime>

int main()
{
	//Scenes
	Scene gsc(GAME_WIDTH,GAME_HEIGHT+1);

	//Nodes
	Level* level = new Level(&gsc);
	Maze* maze = new Maze(&gsc,100,30,1);
	Pac* pac = new Pac(&gsc,maze,1,1);
	
	level->addNode(maze);
	level->addNode(pac);
	level->load();

	//Delta time keep record for time span of loop
	clock_t btime = clock();
	double dt;
	while (1) 
	{
		Sleep(40);
		dt = double(clock() - btime) / CLOCKS_PER_SEC;
		if (dt > 1.0)
			btime = clock();

		level->render(dt);

		if (_kbhit())
			pac->setDirection(_getch());

		pac->move();

		gsc.game.refresh();
	 }
	return 0;
}