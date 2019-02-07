/*Create a layer level to act as a base layer for every sprite in stage*/

#pragma once

#include "SceneGraph.hpp"
#include "Globals.hpp"
#include "Sprite.hpp"

class Level;
class Maze;

class Level : public Layer
{
public:

	Level(Scene*);
	void load();
};


class Maze : public Sprite
{
public:

	int currMaze;

	Maze(Scene* scene,int height,int width,int nmazes);

	void nextMaze();
	void prevMaze();
	void load();
	void render(double dt);
};
