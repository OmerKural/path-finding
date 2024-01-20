#include "Engine.h"
#include "MapSquare.h"
#include "BFS.h"
#include "DFS.h"
#include "Mode.h"
#include "Map.h"
#include "Grid.h"
#include "Button.h"
#include "Panel.h"
#include "AStar.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace sf;


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
	Mouse mouse;
	Mode mode;
	Panel panel;

	Grid gridObj(Vector2i(4 , 4), Vector2i(55 , 55));
	vector<vector<MapSquare*>> grid = gridObj.getGrid();

	DFS dfsAlgo = DFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
	BFS bfsAlgo = BFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
	AStar astarAlgo = AStar(grid, gridObj.getStartPos(), gridObj.getTargetPos());
	bool restart = false; // restart key to restart the grid if play is pressed
	int playMode = 0; // 0 -> pause

	Button pauseButton = panel.addButton();
	Button drawButton = panel.addButton();
	Button startDFSButton = panel.addButton();
	Button startBFSButton = panel.addButton();
	Button startAStarButton = panel.addButton();
	/// \todo Button saveCustomGridButton = panel.addButton();


	bool isLMBDown = false, isRMBDown = false;
	while (window.isOpen())
	{
		//sleep(milliseconds(100));
		
		// Controls
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right)
				isRMBDown = true;
			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Right)
				isRMBDown = false;
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				isLMBDown = true;
			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				isLMBDown = false;
				/// button checks
				if (pauseButton.isClicked(mouse, window)) mode.setPause();
				if (drawButton.isClicked(mouse, window)) mode.setDraw();
				if (startDFSButton.isClicked(mouse, window)) 
				{
					mode.setPlay();
					restart = true;
					playMode = 1;
				}
				if (startBFSButton.isClicked(mouse, window))
				{
					mode.setPlay();
					restart = true;
					playMode = 2;
				}
				if (startAStarButton.isClicked(mouse, window))
				{
					mode.setPlay();
					restart = true;
					playMode = 3;
				}
			}
		}
		
		if (mode.isDraw() && isLMBDown)
		{
			Vector2i selectedSquare = Grid::getSquareByMousePos(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			gridObj.updateSquare(selectedSquare, 1);
			grid = gridObj.getGrid();
		}
		if (mode.isDraw() && isRMBDown)
		{
			Vector2i selectedSquare = Grid::getSquareByMousePos(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			gridObj.updateSquare(selectedSquare, 0);
			grid = gridObj.getGrid();
		}
		

		// Play ------------------------------------
		if (restart)
		{
			gridObj.restartSearch();
			grid = gridObj.getGrid();

			// to be optimised
			if (playMode == 1)
				dfsAlgo = DFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
			else if (playMode == 2)
				bfsAlgo = BFS(grid, gridObj.getStartPos(), gridObj.getTargetPos());
			else if (playMode == 3)
				astarAlgo = AStar(grid, gridObj.getStartPos(), gridObj.getTargetPos());
			
			restart = false;
		}
		if (mode.isPlay()) {
			if (playMode == 1)
				dfsAlgo.step(grid);
			else if (playMode == 2)
				bfsAlgo.step(grid);
			else if (playMode == 3)
				astarAlgo.step(grid);
		}

		window.clear();

		// draw the grid
		for (auto &row : grid)
			for (auto &sq : row)
				window.draw(*sq->getSprite());

		// draw the buttons
		window.draw(*pauseButton.getSprite());
		window.draw(*drawButton.getSprite());
		window.draw(*startDFSButton.getSprite());
		window.draw(*startBFSButton.getSprite());
		window.draw(*startAStarButton.getSprite());

		window.display();
	}
}