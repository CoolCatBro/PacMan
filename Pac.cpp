#include "Pac.hpp"

Pac::Pac(Scene* scene, Maze* maze,int x, int y)
	:Sprite(scene, "pac", 4, 6, x, y, 8),maze(maze),dir(0),score(0)
{}

bool Pac::collision()
{
	char ch;
	if (dir == 0)
	{
		for (int i = 0; i < height; i++)
		{
			if (scene->game.moveXY(x + width, y + i) &&
				(ch = scene->game.readCh()))
			{
				if (ch == FOOD_CHAR)
				{
					maze->frames[maze->currMaze][y+i][x+width] = ' ';
					score++;
				}
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
				if (ch == FOOD_CHAR)
				{
					maze->frames[maze->currMaze][y+height][x+i] = ' ';
					score++;
				}
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	if (dir == 4)
	{
		for (int i = 0; i < height; i++)
		{
			if (scene->game.moveXY(x - 1, y + i) &&
				(ch = scene->game.readCh()) )
			{
				if (ch == FOOD_CHAR)
				{
					maze->frames[maze->currMaze][y+i][x-1] = ' ';
					score++;
				}
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	if (dir == 6)
	{
		for (int i = 0; i < width; i++)
		{
			if (scene->game.moveXY(x + i, y - 1) &&
				(ch = scene->game.readCh()) )
			{
				if (ch == FOOD_CHAR)
				{
					maze->frames[maze->currMaze][y-1][x+i] = ' ';
					score++;
				}
				if (ch == WALL_CHAR)
					return true;
			}
		}
	}
	return false;
}

void Pac::move() 
{
	if(!collision())
	{
	if (dir == 0)
		x++;
	if (dir == 2)
		y++;
	if (dir == 4)
		x--;
	if (dir == 6)
		y--;
	}
}

void Pac::setDirection(char key)
{
	if (key == RIGHT)
		dir = 0;
	if (key == DOWN)
		dir = 2;
	if (key == LEFT)
		dir = 4;
	if (key == UP)
		dir = 6;
}

void Pac::render(double dt)
{
	if (dt < 0.5)
	{
		for (int i = 0; i < height; i++)
			scene->game.mvprintW(x, y + i, frames[dir][i]);
	}
	else
	{
		for (int i = 0; i < height; i++)
			scene->game.mvprintW(x, y + i, frames[dir+1][i]);
	}
}