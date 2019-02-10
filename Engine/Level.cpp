#include "Level.hpp"
		
		//Base Layer for every object in game
//Level---------------------------------------------------------

Level::Level(Scene* scene) : Layer(scene,"level"){}

void Level::render(double dt)
{
	Layer::render(dt);
}