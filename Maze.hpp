#pragma once

#include "Engine/Globals.hpp"
#include "Engine/Sprite.hpp"
#include <utility>

using std::pair;

class Maze : public Sprite
{
public:

	int currMaze;

	pair<int, int> pacpos;
	vector<pair<int, int> > ghostpos;

	Maze(Scene* scene, int width, int height, int nmazes);

	void nextMaze();
	void prevMaze();
	void load();
	void render(double &dt);
};
