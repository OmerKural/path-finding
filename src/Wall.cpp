#include "Wall.h"

const Color Wall::color = Color::White;

Wall::Wall(int x, int y)
{
	this->getSprite()->setFillColor(color);
	setPos(x, y);
}

Color Wall::getColor()
{
	return color;
}