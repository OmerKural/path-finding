#ifndef MAP
#define MAP

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "MapSquare.h"
#include "Road.h"
#include "Wall.h"
#include "Start.h"
#include "Finish.h"
#include <vector>

using namespace std;

class Map
{
public:
	static const Vector2i dimensions;
	static const Vector2f mapPosition;
};

#endif // !MAP


