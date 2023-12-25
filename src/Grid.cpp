#include "Grid.h"

#include <iostream>

using namespace std;

Grid::Grid()
{
	this->startPos = Vector2i(0, 0);
	this->targetPos = Vector2i(Map::dimensions.y - 1, Map::dimensions.x - 1);
	create();
}

Grid::Grid(Vector2i startPos, Vector2i targetPos)
{
	this->startPos = startPos;
	this->targetPos = targetPos;
	create();
}

void Grid::create()
{
	for (int i = 0; i < dimensions.x; i++)
	{
		vector<MapSquare*> row;
		for (int j = 0; j < dimensions.y; j++)
		{
			row.push_back(new Road(i, j));
		}
		grid.push_back(row);
	}
	grid[startPos.x][startPos.y] = new Start(startPos.x, startPos.y);
	grid[targetPos.x][targetPos.y] = new Finish(targetPos.x, targetPos.y);
}


Vector2i Grid::getSquareByMousePos(int x, int y)
{
	int x0 = Map::mapPosition.x;
	int y0 = Map::mapPosition.y;
	int dx = x - x0;
	int dy = y - y0;
	return Vector2i(dx/MapSquare::getSize(), dy/MapSquare::getSize());
}

void Grid::updateSquare(Vector2i squarePos, int type)
{
	if (squarePos.x < 0 || squarePos.y < 0 || squarePos.x >= dimensions.x || squarePos.y >= dimensions.y) return;
	if (type == 1) grid[squarePos.x][squarePos.y] = new Wall(squarePos.x, squarePos.y);
}

vector<vector<MapSquare*>> Grid::getGrid()
{
	return grid;
}
Vector2i Grid::getStartPos()
{
	return startPos;
}
Vector2i Grid::getTargetPos()
{
	return targetPos;
}
