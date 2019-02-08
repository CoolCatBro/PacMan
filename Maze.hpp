#pragma once

#include "Engine/Globals.hpp"
#include "Engine/Sprite.hpp"

class Maze : public Sprite
{
public:

	int currMaze;

	Maze(Scene* scene, int height, int width, int nmazes);

	void nextMaze();
	void prevMaze();
	void load();
	void render(double &dt);
};
