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

	Road();

	Color getColor() override;
};

#endif // ROAD

