#include "MapSquare.h"

const int MapSquare::size = 30;

MapSquare::MapSquare()
{
	position = Vector2f(0.f, 0.f);
	color = Color::White;

	shape.setSize(Vector2f(size, size));
	shape.setFillColor(color);
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
RectangleShape MapSquare::getSprite()
{
	return shape;
}
Color MapSquare::getColor()
{
	return color;
}
void MapSquare::setPos(Vector2f new_position)
{
	position = new_position;
	shape.setPosition(position);
}
void MapSquare::setColor(Color new_color)
{
	color = new_color;
	shape.setFillColor(color);
}