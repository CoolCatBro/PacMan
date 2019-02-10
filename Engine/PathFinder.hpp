#pragma once

#include <list>
#include <deque>
#include "Sprite.hpp"

using std::list;
using std::deque;

struct node
{
	node(int dir,int x,int y,node* parent)
	{
		this->dir = dir;
		this->x = x;
		this->y = y;
		this->parent = parent;
	}

	int dir;
	int x,y;
	node* parent;
	list<node*> child;
};

class PathFinder
{
	Sprite *sp;
	Sprite *dp;
	deque<node*> queue;

public:

	int visited[200][200] = { 0 };
	node* root;
	node* currnode;

	PathFinder(Sprite*,Sprite*);
	int addChild(int dir);
	void getNeighbour();

};