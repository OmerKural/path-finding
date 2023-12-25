#include "Wall.h"

const Color Wall::color = Color::Black;

Wall::Wall()
{
	this->getSprite()->setFillColor(color);
}

Color Wall::getColor()
{
	return color;
}