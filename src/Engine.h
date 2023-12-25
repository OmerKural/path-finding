#ifndef ENGINE
#define ENGINE


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Engine
{
private:
	const unsigned int FPS = 60;
	const char* TITLE = "Path Finder";

	Vector2u resolution;
	Event event;

public:
	static const unsigned int WIDTH = 800;
	static const unsigned int HEIGHT = 600;
	static Vector2f MID;
	

	// Resources

	RenderWindow window;

	Engine();

	void run();
};


#endif // !ENGINE