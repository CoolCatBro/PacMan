#include "Maze.hpp"

Maze::Maze(Scene* scene, int width, int height, int nmazes)
	:Sprite(scene, "maze", width, height, 0, 0, nmazes), currMaze(0),mztime(0.0) {
}

void Maze::nextMaze() {
	if (currMaze < nframe - 1)
		currMaze++;
}

void Maze::prevMaze() {
	if (currMaze > 0)
		currMaze--;
}

void Maze::load() {
	Sprite::load();
	for (int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < frames[currMaze][i].length(); j++)
		{
			if (frames[currMaze][i][j] == '#')
				frames[currMaze][i][j] = WALL_CHAR;
		}
	}
}

void Maze::render(double &dt) {
	for (int i = 0; i < height; i++)
	{
		scene->game.mvprintW(x, i + y, frames[currMaze][i]);
	}
	if (mztime > 30.0)
	{
		scene->game.mvprintW(55, 11, "                ");
	}
	mztime += dt;
}