#pragma once

#include "Engine.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Scene;
class Layer;
class Node;

class Scene
{
protected:

	vector<Layer*> Layers;

public:

	Engine game;

	Scene();
	Scene(int width,int height);

	void	addLayer(Layer* layer);
	void	removeLayer(string id);
	Layer*	getLayer(string id);
	void	render(double);
};

class Layer
{
protected:

	Scene* scene;
	vector<Node*> Nodes;

public:

	string id;

	Layer(Scene* scene,string id);

	void   addNode(Node* node);
	void   removeNode(string id);
	Node*  getNode(string id);
	void   render(double);
};

class Node
{
protected:

	Scene* scene;

public:

	string id;

	Node(Scene* scene,string id);
	virtual ~Node();

	virtual void load() = 0;
	virtual void render(double &dt) = 0;
};