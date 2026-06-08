#ifndef ENGINE
#define ENGINE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Map.h"

using namespace sf;

class Engine
{
private:
	const unsigned int FPS = 60;
	const char* TITLE = "Path Finder";

	Vector2u resolution;
	Event event;

public:
	static const int GRID_SIZE = 30;
	static const unsigned int WIDTH = GRID_SIZE * 12 + 150;
	static const unsigned int HEIGHT = GRID_SIZE * 12 + 40;
	static Vector2f MID;

	RenderWindow window;

	Engine();

	void run();
};


#endif