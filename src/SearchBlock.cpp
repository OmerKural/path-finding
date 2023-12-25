#include "SearchBlock.h"

const Color SearchBlock::color = Color(240, 159, 156);


SearchBlock::SearchBlock()
{
	this->getSprite()->setFillColor(color);
}

Color SearchBlock::getColor()
{
	return color;
}