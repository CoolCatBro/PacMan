#pragma once

#include <functional>
#include <cmath>
#include<cstdio>
#include<conio.h>
#include<ctime>

#include "Sprite.hpp"
#include "Globals.hpp"

using std::function;

class GameManager:public Scene
{
public:
	int score;
	double tmp;

	GameManager(int width,int height);

	bool collision(Sprite*,char ch,function<void(int,int)> event,int side=0);
	bool collision(Sprite*,Sprite*,function<void(int,int)> event);

	void render(double dt);
};