#include "Mode.h"

Mode::Mode()
{
	modeVal = 0;
}

int8_t Mode::getModeVal()
{
	return modeVal;
}

void Mode::setModeVal(int8_t modeVal)
{
	this->modeVal = modeVal;
}

