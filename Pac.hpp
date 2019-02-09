#pragma once

#include "Engine/Sprite.hpp"
#include "Engine/Globals.hpp"
#include "Engine/GameManager.hpp"
#include "Maze.hpp"

class Pac : public Sprite
{
	GameManager* gm;
	Maze* maze;

public:
	
	int dir;

	Pac(GameManager* gm,int x, int y);

	void move();
	void eat(int x,int y);
	void setDirection(char key);
	void load();
	void render(double &dt);
};