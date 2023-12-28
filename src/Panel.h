#ifndef PANEL
#define PANEL

#include "Button.h"
#include "Map.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Panel
{
private:
	const int xMax = 2; // max elements on one row

	const int elemSep = 10; // gap between elements in the panel
	const Vector2i panelSize = Vector2i(Button::size.x * 2 + elemSep, 
										Map::dimensions.y * MapSquare::size);
	const int panelSep = 20; // gap between grid and panel
	const Vector2i panelPosition = Vector2i(Map::mapPosition.x + Map::dimensions.x * MapSquare::size + panelSep,
											Map::mapPosition.y); // upper left corner position

	IntRect  panelRect;

	int nextCol, nextRow;
	Vector2i nextPosition;

	Vector2i rc2Pos(); 

public:
	Panel();

	Button addButton();

};


#endif // !PANEL



/// Panel for the buttons 


