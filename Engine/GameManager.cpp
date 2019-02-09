#include "GameManager.hpp"

GameManager::GameManager(int width, int height)
	        :Scene(width,height),score(0)
{}

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

bool GameManager::collision(Sprite *, Sprite *,function<void(int,int)> event)
{
	return false;
}