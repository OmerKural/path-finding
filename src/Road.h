#ifndef ROAD
#define ROAD

#include <SFML/Graphics.hpp>
#include "MapSquare.h"

using namespace std;
using namespace sf;

class Road:public MapSquare
{
private:

public:
	static const Color color;

	Road(int, int);
	Road(Vector2f);

	Color getColor() override;
};

#endif // ROAD

