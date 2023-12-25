#include "Engine.h"
#include "MapSquare.h"
#include "Road.h"
#include "Wall.h"
#include "Start.h"
#include "Finish.h"
#include "Map.h"
#include <iostream>

using namespace std;

const int MapSquare::size = 16;

MapSquare::MapSquare()
{
	position = Vector2f(0.f, 0.f);

	shape.setSize(Vector2f(size, size));
	shape.setFillColor(Color::White);
	shape.setOutlineColor(Color::Black);
	shape.setOutlineThickness(2.f);
}

int MapSquare::getSize()
{
	return size;
}
Vector2f MapSquare::getPos()
{
	return position;
}
RectangleShape* MapSquare::getSprite()
{
	return &shape;
}
void MapSquare::setPos(int x, int y)
{
	setPos(Vector2f(x * size + Map::mapPosition.x, y * size + Map::mapPosition.y));
}
void MapSquare::setPos(Vector2f new_position)
{
	position = new_position;
	shape.setPosition(new_position);
}

Color MapSquare::getColor()
{
	return Color();
}