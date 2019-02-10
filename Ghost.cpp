#include "Ghost.hpp"
#include "cstdlib"

Ghost::Ghost(GameManager* gm,int x, int y)
	:Sprite(gm,"ghost",6,4, x, y, 2),gm(gm),dir(1),ghtime(0.0)
{
	rx = x; ry = y;
}

void Ghost::move()
{
	if (x + width == GAME_WIDTH && dir == 1)
		x = -width;
	if (x == 0 && dir == 3)
		x = GAME_WIDTH;


	if (!gm->collision(this, pac, [](int, int) {}))
	{
		if (pac->power)
		{
			if (ghtime < 25.0)
				frighten();
			else if (ghtime > 25.0)
				scatter();
			else if (ghtime > 30.0)
				ghtime = 0.0;
		}

		else if (ghtime > 50.0)
			scatter();
		else if (ghtime < 50.0 && (x > 0 && x < GAME_WIDTH))
			chase();
		else if(ghtime > 60.0)
			ghtime = 0.0;
	}
	else
	{
		if (!pac->power)
			eat();
		else
			reset();
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

void Ghost::scatter()
{
	int k = 1;
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
		if (!gm->collision(this, WALL_CHAR, [](int, int) {}, dir))
			break;
		else
		{
			if (x + width >= GAME_WIDTH)
			{dir = 3; break;}
			if (x <= 0)
			{dir = 1; break;}
			dir = temp;
		}
	}
}

void Ghost::chase()
{
	if (path.size() < 30)
	{
		path.clear();
		findPath();
		dir = 0;
	}
	else
	{
		dir = path.front();
		path.pop_front();
	}
}

void Ghost::frighten()
{
	float mx, a, b, c, d;
	mx = a = b = c = d = 0.0f;

	if(!gm->collision(this,  WALL_CHAR, [](int, int){},  1))
	a = gm->distance(pac->x, pac->y, x + 1, y);
	if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 2))
	b = gm->distance(pac->x, pac->y, x, y + 1);
	if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 3))
	c = gm->distance(pac->x, pac->y, x - 1, y);
	if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 4))
	d = gm->distance(pac->x, pac->y, x, y - 1);

	mx = max(a, max(b, max(c, d)));
	if (mx == a)
		dir = 1;
	if (mx == b)
		dir = 2;
	if (mx == c)
		dir = 3;
	if (mx == d)
		dir = 4;
}

void Ghost::eat() 
{
	dir = 0;
	system("pause");
}

void Ghost::reset()
{
	x = rx; y = ry;
	gm->score += 20;
	path.clear();
}

void Ghost::findPath()
{
	PathFinder pf(this,pac);
	bool found = false;

	pf.addChild(0);
	while (true)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (i == 1)
			{
				if (!gm->collision(this, WALL_CHAR, [](int,int) {}, 1))
				{
					x++;
					if (pf.addChild(1))
						found = true;
				}
			}
			if (i == 2)
			{
				if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 2))
				{
					y++;
					if (pf.addChild(2))
						found = true;
				}
			}
			if (i == 3)
			{
				if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 3))
				{
					--x;
					if (pf.addChild(3))
						found = true;
				}
			}
			if (i == 4)
			{
				if (!gm->collision(this, WALL_CHAR, [](int, int) {}, 4))
				{
					--y;
					if (pf.addChild(4))
						found = true;
				}
			}
		}
		if (found)
			break;
		pf.getNeighbour();
	}
	while(pf.currnode->dir != 0)
	{
		path.push_front(pf.currnode->dir);
		pf.currnode = pf.currnode->parent;
	}

	x = pf.root->x;
	y = pf.root->y;
}

void Ghost::load()
{
	Sprite::load();
	maze = (Maze*)gm->getLayer("level")->getNode("maze");
	pac =  (Pac*)gm->getLayer("level")->getNode("pac");
}

void Ghost::render(double &dt)
{
	for (int i = 0; i < height; i++)
	{
		if(!pac->power)
		scene->game.mvprintW(x, y + i, frames[0][i]);
		else
		scene->game.mvprintW(x, y + i, frames[1][i]);
	}
	ghtime += dt;
}