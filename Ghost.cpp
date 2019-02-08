#include "Ghost.hpp"
#include "cstdlib"

Ghost::Ghost(Scene* scene,Maze* maze,Pac* pac,int x, int y)
	:Sprite(scene,"ghost",4,6, x, y, 1),maze(maze),pac(pac),dir(1)
{}

bool Ghost::collision()
{
	char ch;
	if (dir == 1)
	{
		if (x + width == GAME_WIDTH)
			x = 0-width;
		for (int i = 0; i < height; i++)
		{
			if (scene->game.moveXY(x + width, y + i) &&
				(ch = scene->game.readCh()))
			{
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	if (dir == 2)
	{
		for (int i = 0; i < width; i++)
		{
			if (scene->game.moveXY(x + i, y + height) && 
				(ch = scene->game.readCh()) )
			{
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	if (dir == 3)
	{
		if (x == 0)
			x = GAME_WIDTH;
		for (int i = 0; i < height; i++)
		{
			if (scene->game.moveXY(x - 1, y + i) &&
				(ch = scene->game.readCh()))
			{
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	if (dir == 4)
	{
		for (int i = 0; i < width; i++)
		{
			if (scene->game.moveXY(x + i, y - 1) &&
				(ch = scene->game.readCh()))
			{
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	return false;
}

void Ghost::move()
{
	int k=1;
	int temp = 0;
	while (1)
	{
		k = rand() % 4 + 1;
		temp = dir;
		if (dir == 1 && k != 3)
			dir = k;
		else if (dir == 3 && k != 1)
			dir = k;
		else if (dir == 2 && k != 4)
			dir = k;
		else if (dir == 4 && k != 2)
			dir = k;
		if (!collision())
			break;
		else
			dir = temp;
	}
	if (dir == 1)
		x++;
	if (dir == 2)
		y++;
	if (dir == 3)
		x--;
	if (dir == 4)
		y--;
}

void Ghost::render(double &dt)
{
	for (int i = 0; i < height; i++)
		scene->game.mvprintW(x, y + i, frames[0][i]);
}