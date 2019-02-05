#include "Level.hpp"
		
		//Base Layer for every object in game
//Level---------------------------------------------------------

Level::Level(Scene* scene) : Layer(scene,"level"){}

void Level::load()
{
   for(int i=0;i<Nodes.size();i++)
   {
	   Nodes[i]->load();
   }
}
        //set mazes
//Maze----------------------------------------------------------

Maze::Maze(Scene* scene, int height,int width,int nmazes)
	  :Sprite(scene,"maze",height,width,0,0,nmazes),currMaze(0) {
}

void Maze::nextMaze() {
	if (currMaze < nframe-1)
		currMaze++;
}

void Maze::prevMaze() {
	if (currMaze > 0)
		currMaze--;
}

void Maze::render(double dt) {
	for (int i = 0; i < height; i++)
		scene->game.mvprintW(x, i + y, frames[currMaze][i]);
}