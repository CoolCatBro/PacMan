#pragma once

#include "Sprite.hpp"
#include "Globals.hpp"

class Pac : public Sprite
{
public:
	
	int dir;
	Pac(Scene* scene, int x, int y);

	void move(char key);
	void render(double dt);
};