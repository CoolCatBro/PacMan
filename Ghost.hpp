#pragma once

#include "Engine/Sprite.hpp"
#include "Engine/Globals.hpp"
#include "Maze.hpp"
#include "Pac.hpp"

class Ghost : public Sprite
{
	GameManager* gm;
	Maze* maze;
	Pac* pac;

	int dir;
public:

	Ghost(GameManager *gm,int x,int y);
	void move();
	void scatter();
	void load();
	void render(double &dt);
};