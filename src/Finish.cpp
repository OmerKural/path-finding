#include "Finish.h"

const Color Finish::color = Color(39, 15, 54);

Finish::Finish()
{
	this->getSprite()->setFillColor(color);
}

Color Finish::getColor()
{
	return color;
}
