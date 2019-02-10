#include "GameManager.hpp"

GameManager::GameManager(int width, int height)
	        :Scene(width,height),score(0),gtime(0.0)
{
	srand(time(nullptr));
}

bool GameManager::collision(Sprite* sprt, char ch,function<void(int,int)> event,int side)
{
	bool collide = false;

	if (side == 1 || side == 0)
	for (int i = 0; i < sprt->height; i++)
	{
		if (game.moveXY(sprt->x + sprt->width, sprt->y + i) && game.readCh() == ch)
		{
			event(sprt->x + sprt->width, sprt->y + i);
			collide = true;
		}
	}

	if (side == 2 || side == 0)
	for (int i = 0; i < sprt->width; i++)
	{
		if (game.moveXY(sprt->x + i,sprt->y + sprt->height) && game.readCh() == ch)
		{
			event(sprt->x + i, sprt->y + sprt->height);
			collide = true;
		}
	}

	if (side == 3 || side == 0)
	for (int i = 0; i < sprt->height; i++)
	{
		if (game.moveXY(sprt->x - 1, sprt->y + i) && game.readCh() == ch)
		{
			event(sprt->x -1, sprt->y + i);
			collide = true;
		}
	}

	if (side == 4 || side == 0)
	for (int i = 0; i < sprt->width; i++)
	{
		if (game.moveXY(sprt->x + i, sprt->y - 1) && game.readCh() == ch)
		{
			event(sprt->x + i, sprt->y - 1);
			collide = true;
		}
	}

	return collide;
}

bool GameManager::collision(Sprite *a, Sprite *b,function<void(int,int)> event)
{
	if ( (( a->x <= b->x) && (a->x + a->width >= b->x)) 
	   && ((a->y <= b->y) && (a->y + a->height >= b->y)))
	{
		event(a->x,a->y);
		return true;
	}
	return false;
}

float GameManager::distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) * 1.0);
}

void GameManager::render(double dt)
{
	Scene::render(dt);
	game.mvprintW(1,GAME_HEIGHT, "Score:" + std::to_string(score));
	gtime += dt;
}