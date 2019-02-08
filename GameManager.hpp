#pragma once

#include "Engine/Sprite.hpp"

class GameManager
{
public:
	
	Scene gsc;

	GameManager(int width,int height);

	bool collision(Sprite*,char ch);
	bool collision(Sprite*,Sprite*);
};