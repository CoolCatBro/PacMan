#include "Pac.hpp"

Pac::Pac(Scene* scene, int x, int y)
	:Sprite(scene, "pac", 5, 5, x, y, 8),dir(0)
{}

void Pac::move(char key) 
{
	if (key == RIGHT)
	{
		x++; dir = 0;
	}
	if (key == DOWN)
	{
		y++; dir = 2;
	}
	if (key == LEFT)
	{
		x--; dir = 4;
	}
	if (key == UP)
	{
		y--; dir = 6;
	}
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