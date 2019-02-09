#include "Engine/Level.hpp"
#include "Engine/GameManager.hpp"
#include "Pac.hpp"
#include "Maze.hpp"
#include "Ghost.hpp"

#include<cstdio>
#include<conio.h>
#include<ctime>

int main()
{
	//Scenes
	GameManager gm(GAME_WIDTH,GAME_HEIGHT+1);

	//Create Objects
	Level* level = new Level(&gm);
	Maze*  maze  = new Maze(&gm,GAME_WIDTH,GAME_HEIGHT,1);
	Pac*   pac   = new Pac(&gm,1,1);
	Ghost* ghost = new Ghost(&gm, 65, 7);

	//Add Nodes to the level
	level->addNode(maze);
	level->addNode(pac);
	level->addNode(ghost);

	//Add Layers to Scene
	gm.addLayer(level);
	
	//Load Scene;
	gm.load();
	srand(time(nullptr));
	//Delta time keep record for time span of loop
	clock_t btime = clock();
	double dt;
	while (1) 
	{
		Sleep(40);
		dt = double(clock() - btime) / CLOCKS_PER_SEC;
		if (dt > 1.0)
			btime = clock();

		gm.render(dt);

		if (_kbhit())
			pac->setDirection(_getch());

		pac->move();
		ghost->move();

		gm.game.refresh();
	 }
	return 0;
}