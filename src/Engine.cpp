#include "Engine.h"
#include "MapSquare.h"
#include "BFS.h"
#include "DFS.h"
#include "Mode.h"
#include "Map.h"
#include "Grid.h"

#include <iostream>
#include <vector>

using namespace std;


/// > ALWAYS USE X, Y
/// > EXCEPTION: INDEXING -> Y, X

/// <todo>
/// Algorithm virtual class
/// -> add update function to update the grid.
/// -> make the grid an attribute, or at least accessible.
/// MapSquare redefine virtual
/// <\todo>

Vector2f Engine::MID = Vector2f(Engine::WIDTH / 2, Engine::HEIGHT / 2);

Engine::Engine()
{
	resolution = Vector2u(WIDTH, HEIGHT);
	window.create(VideoMode(resolution.x, resolution.y), TITLE, Style::Default);
	window.setFramerateLimit(FPS);
	event = Event();
}

void Engine::run()
{
	Mode mode;

	Grid gridObj(Vector2i(1, 0), Vector2i(15, 15));
	vector<vector<MapSquare*>> grid = gridObj.getGrid();

	BFS bfsAlgo(grid, gridObj.getStartPos(), gridObj.getTargetPos());
	// DFS dfsAlgo(grid, gridObj.getStartPos(), gridObj.getTargetPos());

	bool isLMBDown = false;

	while (window.isOpen())
	{
		//sleep(milliseconds(100));,
		
		// Controls
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Num0)
				mode.setModeVal(0);
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Num1)
				mode.setModeVal(1);
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Num2)
				mode.setModeVal(2);

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				isLMBDown = true;
			}
			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				isLMBDown = false;
			}
		}

		if (isLMBDown)
		{
			Vector2i selectedSquare = Grid::getSquareByMousePos(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			gridObj.updateSquare(selectedSquare, 1);
			grid = gridObj.getGrid();
			bfsAlgo = BFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
		}

		// Play ------------------------------------
		if (mode.getModeVal() == 2) {
			bfsAlgo.step(grid);

		}

		window.clear();
		
		for (auto &row : grid)
			for (auto &sq : row)
				window.draw(*sq->getSprite());

		window.display();
	}
}