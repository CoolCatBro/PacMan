/*Create a layer level to act as a base layer for every sprite in stage*/

#pragma once

#include "Engine/SceneGraph.hpp"
#include "Engine/Sprite.hpp"
#include "Engine/Globals.hpp"


class Level : public Layer
{
public:

	Level(Scene*);
};