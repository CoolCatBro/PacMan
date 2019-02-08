#include "GameManager.hpp"

GameManager::GameManager(int width, int height)
	        :gsc(width,height)
{}

bool GameManager::collision(Sprite* sprt, char ch)
{
	for (int i = sprt->x; i < (sprt->x + sprt->height); i++)
	{
		if(gsc.game.moveXY(sprt->x + sprt->width,i) && gsc.game.readCh() == ch)
			return true;
	}
	return false;
}

bool GameManager::collision(Sprite *, Sprite *)
{
	return false;
}

