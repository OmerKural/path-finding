#include "Engine.h"
#include "MapSquare.h"
#include "BFS.h"
#include "DFS.h"

#include <iostream>
#include <vector>

using namespace std;

Engine::Engine()
{
	resolution = Vector2u(WIDTH, HEIGHT);
	window.create(VideoMode(resolution.x, resolution.y), TITLE, Style::Default);
	window.setFramerateLimit(FPS);
	event = Event();
}

void Engine::run()
{
	Vector2i dimensions   = Vector2i(16, 16);
	Vector2f map_position = Vector2f(
		MID.x - dimensions.x/2 * MapSquare::size, 
		MID.y - dimensions.y/2 * MapSquare::size
	);

	Vector2i start = Vector2i(12, 4);
	Vector2i target = Vector2i(dimensions.x-1, dimensions.y-1);

	vector<vector<MapSquare>> grid;
	for (int i = 0; i < dimensions.x; i++)
	{
		vector<MapSquare> row;
		for (int j = 0; j < dimensions.y; j++)
		{
			MapSquare sq;
			sq.setColor(Color(252, 195, 163));
			sq.setPos(
				Vector2f(
				j * sq.getSize() + map_position.x,
				i * sq.getSize() + map_position.y
				)
			);
			row.push_back(sq);
		}
		grid.push_back(row);
	}
	grid[start.x][start.y].setColor(Color(39, 15, 54));
	grid[target.x][target.y].setColor(Color(39, 15, 54));

	//BFS bfsAlgo(grid, start, target);
	DFS dfsAlgo(grid, start, target);

	// Main Loop
	while (window.isOpen())
	{
		sleep(milliseconds(100));
		// Controls
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed ||
				(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
		}

		// Update ------------------------------------
		//bfsAlgo.step(grid);
		dfsAlgo.step(grid);

		// Draw ---------------------------------------
		window.clear();
		
		for (auto &row : grid)
			for (auto &sq : row)
				window.draw(sq.getSprite());

		window.display();
	}
	// end Main Loop
}