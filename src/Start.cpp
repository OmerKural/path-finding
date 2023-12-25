#include "Start.h"

const Color Start::color = Color(39, 15, 54);

Start::Start()
{
	this->getSprite()->setFillColor(color);
}

Color Start::getColor()
{
	return color;
}