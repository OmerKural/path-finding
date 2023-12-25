#ifndef WALL
#define WALL

#include <SFML/Graphics.hpp>
#include "MapSquare.h"

using namespace std;
using namespace sf;

class Wall:public MapSquare
{
private:

public:
	static const Color color;

	Wall(int, int);

	Color getColor();
};

#endif // !WALL







