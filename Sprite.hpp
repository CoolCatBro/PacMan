/*Sprite is texture + position. Anchor point of every sprite is top-left */

#pragma once

#include "SceneGraph.hpp"

#include <fstream>
#include <cassert>

using std::ifstream;

class Sprite : public Node
{
protected:

	string** frames;

public:

	int nframe
	,x, y
	,height, width;

	Sprite(Scene*,string,int height,int width,int x,int y,int nframe=1);
	virtual ~Sprite();

	void load(); 
	virtual void render(double dt) = 0;
};