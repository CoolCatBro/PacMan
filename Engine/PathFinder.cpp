#include "PathFinder.hpp"

PathFinder::PathFinder(Sprite *sp,Sprite *dp):sp(sp),dp(dp),root(nullptr)
{}

int PathFinder::addChild(int dir)
{
	if (!visited[sp->x][sp->y])
	{
		if (root == nullptr)
		{
			root = new node(dir, sp->x,sp->y, nullptr);
			visited[sp->x][sp->y] = 1;
			currnode = root;
			queue.push_back(currnode);
		}
		else
		{
			visited[sp->x][sp->y] = 1;
			queue.push_back(new node(dir, sp->x, sp->y, currnode));
			currnode->child.push_back(queue.back());
			if ((sp->x == dp->x) && (sp->y == dp->y))
			{
				currnode = queue.back();
				return 1;
			}
			else
			{
				sp->x = currnode->x;
				sp->y = currnode->y;
			}
		}
	}
	else
	{
		sp->x = currnode->x;
		sp->y = currnode->y;
	}
	return 0;
}

void PathFinder::getNeighbour()
{
	if (queue.size() > 1)
	{
		queue.pop_front();
		currnode = queue.front();
		sp->x = currnode->x;
		sp->y = currnode->y;
	}
}
