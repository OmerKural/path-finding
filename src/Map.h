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
private:
	vector<vector<vector<int>>> _maps;
	vector<vector<vector<MapSquare>>> maps;

	void preprocessMaps();

protected:
	static Vector2i dimensions;
	static Vector2f mapPosition;

public:
	Map();

	static Vector2i getDimensions();
	static Vector2f getMapPosition();
	vector<vector<MapSquare>> get(int);
};

#endif // !MAP


