#include "Pac.hpp"

Pac::Pac(GameManager *gm,int x, int y)
	:Sprite(&gm->gsc, "pac", 6, 4, x, y, 8),gm(gm),dir(0)
{}

void Pac::move() 
{
	if(!gm->collision(this,WALL_CHAR))
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
	if (x < 0)
		return;
	if (key == RIGHT)
		dir = 0;
	if (key == DOWN)
		dir = 2;
	if (key == LEFT)
		dir = 4;
	if (key == UP)
		dir = 6;
}

void Pac::render(double &dt)
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