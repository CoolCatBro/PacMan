#include "Level.hpp"
#include "Pac.hpp"
#include "Maze.hpp"
#include "GameManager.hpp"

#include<cstdio>
#include<conio.h>
#include<ctime>

int main()
{
	//Scenes
	GameManager gm(GAME_WIDTH,GAME_HEIGHT+1);

	//Nodes
	Level* level = new Level(&gm.gsc);
	Maze*  maze  = new Maze(&gm.gsc,37,110,1);
	Pac*   pac   = new Pac(&gm,1,1);

	//Add Nodes to the level
	level->addNode(maze);
	level->addNode(pac);

	//Load the level;
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

		//Print Score
		//gsc.game.mvprintW(0, 37, "Score:" + std::to_string(pac->score));

		gm.gsc.game.refresh();
	 }
	return 0;
}