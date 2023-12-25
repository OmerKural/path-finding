#ifndef PATH
#define PATH

#include "MapSquare.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Path:public MapSquare
{
private:

public:
	const static Color color;

	Path();

	Color getColor();
};

#endif // !PATH


