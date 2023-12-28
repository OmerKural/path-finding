#include "Panel.h"
#include <iostream>

using namespace std;

Vector2i Panel::rc2Pos()
{
	return Vector2i(
		panelPosition.x + nextCol * Button::size.x + nextCol * elemSep,
		panelPosition.y + nextRow * Button::size.y + nextRow * elemSep
	);;
}

Panel::Panel()
{
	panelRect = IntRect(panelPosition, panelSize);
	nextCol = 0, nextRow = 0;
	nextPosition = rc2Pos(); // initial button position
}

/**
* Puts the button to the next position in the panel and returns
* the position.
*/
Button Panel::addButton() 
{
	Button button(nextPosition);
	nextCol = (nextCol >= xMax-1) ? 0,nextRow++ : nextCol + 1;
	nextPosition = rc2Pos();
	return button;
}
