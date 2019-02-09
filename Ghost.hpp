#pragma once

#include "Engine/Sprite.hpp"
#include "Engine/Globals.hpp"
#include "Pac.hpp"

class Ghost : public Sprite
{
	GameManager* gm;
	char dir;
public:

	Ghost(GameManager *gm,int x,int y);
	bool collision();
	void move();
	void render(double &dt);
};