#ifndef GRID
#define GRID

#include <SFML/Graphics.hpp>
#include "Map.h"

using namespace sf;

class Grid : public Map
{
private:
	vector<vector<MapSquare*>> grid;
	Vector2i startPos, targetPos;

	void create();

public:
	Grid();
	Grid(Vector2i, Vector2i);

	void restartSearch();
	static Vector2i getSquareByMousePos(int, int);
	void updateSquare(Vector2i, int);
	vector<vector<MapSquare*>> getGrid();
	Vector2i getStartPos();
	Vector2i getTargetPos();
};

#endif // !GRID




