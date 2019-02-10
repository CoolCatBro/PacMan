/*Create a layer level to act as a base layer for every sprite in stage*/

#pragma once

#include "SceneGraph.hpp"
#include "Sprite.hpp"
#include "Globals.hpp"


class Level : public Layer
{
public:

	Level(Scene*);
	void render(double dt);
};