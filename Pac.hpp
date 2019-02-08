#pragma once

#include "Engine/Sprite.hpp"
#include "Engine/Globals.hpp"
#include "GameManager.hpp"
#include "Level.hpp"

class Pac : public Sprite
{
	GameManager* gm;

public:
	
	int dir;

	Pac(GameManager* gm,int x, int y);

	void move();
	void setDirection(char key);
	bool collision();
	void render(double &dt);
};