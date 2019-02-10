#include "Engine/Level.hpp"
#include "Engine/GameManager.hpp"
#include "Pac.hpp"
#include "Maze.hpp"
#include "Ghost.hpp"

int main()
{
	//Scenes
	GameManager gm(GAME_WIDTH,GAME_HEIGHT+1);

	//Create Objects
	Level* level = new Level(&gm);
	Maze*  maze  = new Maze(&gm,GAME_WIDTH,GAME_HEIGHT,1);
	Pac*   pac   = new Pac(&gm,1,1);
	Ghost* ghost = new Ghost(&gm, 55, 13);
	Ghost* ghost2 = new Ghost(&gm, 61, 13);
	Ghost* ghost3 = new Ghost(&gm, 64, 13);

	//Add Nodes to the level
	level->addNode(maze);
	level->addNode(pac);
	level->addNode(ghost);
	level->addNode(ghost2);
	level->addNode(ghost3);

	//Add Layers to Scene
	gm.addLayer(level);
	
	//Load Scene;
	gm.load();
	
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

		if (gm.gtime > 35.0)
		{
			ghost->move();
			ghost2->move();
			ghost3->move();
		}

		gm.game.refresh();
	 }
	return 0;
}