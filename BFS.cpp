#include "BFS.h"
#include "MapSquare.h"

#include <vector>
#include <iostream>
using namespace std;

// private methods


// public methods

BFS::BFS(vector<vector<MapSquare>> &grid, Vector2i start, Vector2i target)
{
	this->dimentions = Vector2i(grid.size(), grid[0].size());
	this->start = start;
	this->cur = this->start;
	this->target = target;

	visited = vector<vector<bool>>(dimentions.x, vector<bool>(dimentions.y, false));
	bfsQ = queue<vector<Vector2i>>(); bfsQ.push({ start });
	finished = false;
};


void BFS::step(vector<vector<MapSquare>>& grid)
{
	if (bfsQ.empty() || finished) return;

	vector<Vector2i> path = bfsQ.front();
	cur = path[path.size()-1];
	bfsQ.pop();

	if (cur != start && cur != target)
	{
		grid[cur.x][cur.y].setColor(Color(240, 159, 156));
	}

	if (cur == target)
	{
		finished = true;
		for (Vector2i pos : path)
			if (pos != start && pos != target)
				grid[pos.x][pos.y].setColor(Color(99, 43, 108));
		return;
	}
	
	for (auto& d : directions)
	{
		int newX = cur.x + d.first;
		int newY = cur.y + d.second;
		if (0 <= newX && newX < grid.size() &&
			0 <= newY && newY < grid[0].size() &&
			!visited[newX][newY])
		{
			vector<Vector2i> newPath = path;
			newPath.push_back(Vector2i(newX, newY));
			bfsQ.push(newPath);
			visited[newX][newY] = true;
		}
	}
}