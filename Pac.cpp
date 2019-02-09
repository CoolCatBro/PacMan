#include "Pac.hpp"

Pac::Pac(GameManager *gm,int x, int y)
	:Sprite(gm, "pac", 6, 4, x, y, 8),gm(gm),dir(0)
{}

void Pac::move() 
{
	if (x + width == GAME_WIDTH && dir==0)
		x = -width;
	if (x == 0 && dir == 4)
		x = GAME_WIDTH;

	if (dir == 0)
	{
		gm->collision(this, FOOD_CHAR, [this](int x, int y) {this->eat(x, y);},1);
		if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 1))
			x++;
	}
	if (dir == 2)
	{
		gm->collision(this, FOOD_CHAR, [this](int x, int y) {this->eat(x, y);}, 2);
		if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 2))
			y++;
	}
	if (dir == 4)
	{
		gm->collision(this, FOOD_CHAR, [this](int x, int y) {this->eat(x, y); }, 3);
		if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 3))
			x--;
	}
	if (dir == 6)
	{
		gm->collision(this, FOOD_CHAR, [this](int x, int y) {this->eat(x, y); }, 4);
		if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 4))
			y--;
	}
}

void Pac::eat(int x,int y)
{
	maze->frames[maze->currMaze][y][x] = ' ';
	gm->score++;
}

void Pac::setDirection(char key)
{
	if (x < 0 || x > GAME_WIDTH - width)
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

void Pac::load()
{
	Sprite::load();
	maze = (Maze*)gm->getLayer("level")->getNode("maze");
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