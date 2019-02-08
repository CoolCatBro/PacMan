#pragma once

#include "Sprite.hpp"
#include "Pac.hpp"
#include "Level.hpp"
#include "Globals.hpp"

class Ghost : public Sprite
{
	Pac* pac;
	Maze* maze;
	char dir;
public:

	Ghost(Scene* scene,Maze* maze,Pac* pac,int x,int y);
	bool collision();
	void move();
	void render(double &dt);
};