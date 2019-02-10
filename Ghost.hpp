#pragma once

#include "Engine/Sprite.hpp"
#include "Engine/Globals.hpp"
#include "Engine/PathFinder.hpp"
#include "Maze.hpp"
#include "Pac.hpp"

#include <algorithm>
using std::max;

class Ghost : public Sprite
{
	GameManager* gm;
	Maze* maze;
	Pac* pac;

	int dir;
	deque<int> path;
	double ghtime;
	
	int rx, ry;
public:

	Ghost(GameManager *gm,int x,int y);
	void move();
	void scatter();
	void chase();
	void frighten();
	void eat();
	void reset();
	void findPath();
	void load();
	void render(double &dt);
};