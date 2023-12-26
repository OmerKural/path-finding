#include "Mode.h"

Mode::Mode()
{
	modeVal = 0;
}

int Mode::getModeVal()
{
	return modeVal;
}

void Mode::setModeVal(int modeVal)
{
	this->modeVal = modeVal;
}

void Mode::setPause()
{
	modeVal = 0;
}

void Mode::setDraw()
{
	modeVal = 1;
}

void Mode::setPlay()
{
	modeVal = 2;
}

bool Mode::isPause()
{
	return modeVal == 0;
}

bool Mode::isDraw()
{
	return modeVal == 1;
}

bool Mode::isPlay()
{
	return modeVal == 2;
}