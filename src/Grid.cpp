#include "Grid.h"

#include <iostream>

using namespace std;

Grid::Grid()
{
	this->startPos = Vector2i(0, 0);
	this->targetPos = Vector2i(Map::getDimensions().y - 1, Map::getDimensions().x - 1);
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
			MapSquare* sq = new Road();
			sq->setPos(
				Vector2f(
					i * sq->getSize() + mapPosition.x,
					j * sq->getSize() + mapPosition.y
				)
			);
			row.push_back(sq);
		}
		grid.push_back(row);
	}
	Start *st = new Start();
	st->setPos(Vector2f(
		startPos.x * st->getSize() + mapPosition.x,
		startPos.y * st->getSize() + mapPosition.y));
	Finish *fi = new Finish();
	fi->setPos(Vector2f(
		targetPos.x * fi->getSize() + mapPosition.x,
		targetPos.y * fi->getSize() + mapPosition.y));
	grid[startPos.x][startPos.y] = st;
	grid[targetPos.x][targetPos.y] = fi;
}


Vector2i Grid::getSquareByMousePos(int x, int y)
{
	int x0 = Map::getMapPosition().x;
	int y0 = Map::getMapPosition().y;
	int dx = x - x0;
	int dy = y - y0;
	cout << "selected square -> x = " << dx / MapSquare::getSize() << ", y = " << dy / MapSquare::getSize() << endl;
	return Vector2i(dx/MapSquare::getSize(), dy/MapSquare::getSize());
}

void Grid::updateSquare(Vector2i squarePos, int type)
{
	if (type == 1) grid[squarePos.x][squarePos.y] = new Wall();
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
