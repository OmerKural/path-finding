#ifndef MAP
#define MAP

#include <SFML/Graphics.hpp>
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
	Vector2i dimentions;
	vector<vector<vector<int>>> _maps;
	vector<vector<vector<MapSquare>>> maps;

	void preprocessMaps();

public:
	Map();

	vector<vector<MapSquare>> get(int);
};

#endif // !MAP


