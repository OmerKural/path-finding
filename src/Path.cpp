
#include "Path.h"

const Color Path::color = Color(99, 43, 108);


Path::Path()
{
	this->getSprite()->setFillColor(color);
}

Color Path::getColor()
{
	return color;
}