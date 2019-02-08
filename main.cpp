#include "Sprite.hpp"
#include "Globals.hpp"
#include "Level.hpp"
#include "Pac.hpp"
#include "Ghost.hpp"

#include<cstdio>
#include<conio.h>
#include<ctime>

int main()
{
	//Scenes
	Scene gsc(GAME_WIDTH,GAME_HEIGHT+1);

	//Nodes
	Level* level = new Level(&gsc);
	Maze* maze = new Maze(&gsc,37,110,1);
	Pac* pac = new Pac(&gsc,maze,1,1);
	Ghost* ghost1 = new Ghost(&gsc,maze,pac,55, 13);
	Ghost* ghost2 = new Ghost(&gsc,maze,pac,62, 13);
	Ghost* ghost3 = new Ghost(&gsc,maze,pac, 65, 7);

	//Add Nodes to the level
	level->addNode(maze);
	level->addNode(pac);
	level->addNode(ghost1);
	level->addNode(ghost2);
	level->addNode(ghost3);

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

		pac->move();
		ghost3->move();

		//Print Score
		gsc.game.mvprintW(0, 37, "Score:" + std::to_string(pac->score));

		gsc.game.refresh();
	 }
	return 0;
}