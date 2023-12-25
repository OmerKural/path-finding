#ifndef SEARCHBLOCK
#define SEARCHBLOCK

#include "MapSquare.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class SearchBlock:public MapSquare
{
private:

public:
	static const Color color;
	
	SearchBlock(int, int);

	Color getColor();
};

#endif // !SEARCHBLOCK


