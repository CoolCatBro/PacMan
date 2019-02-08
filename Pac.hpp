#pragma once

#include "Sprite.hpp"
#include "Globals.hpp"
#include "Level.hpp"

class Pac : public Sprite
{
	Maze* maze;

public:
	
	int dir, score;

	Pac(Scene* scene,Maze* maze,int x, int y);

	void move();
	void setDirection(char key);
	bool collision();
	void render(double &dt);
};