#pragma once

#include <functional>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <ctime>

#include "Sprite.hpp"
#include "Globals.hpp"

using std::function;

class GameManager:public Scene
{
public:
	int score;
	double gtime;

	GameManager(int width,int height);

	bool collision(Sprite*,char ch,function<void(int,int)> event,int side=0);
	bool collision(Sprite*,Sprite*,function<void(int,int)> event);

	float distance(int x1, int y1, int x2, int y2);

	void render(double dt);
};