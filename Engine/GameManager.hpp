#pragma once

#include <functional>
#include "Sprite.hpp"

using std::function;

class GameManager:public Scene
{
public:
	int score;

	GameManager(int width,int height);

	bool collision(Sprite*,char ch,function<void(int,int)> event,int side=0);
	bool collision(Sprite*,Sprite*,function<void(int,int)> event);
};