#include "DFS.h"
#include "MapSquare.h"
#include "Engine.h"
#include "Wall.h"
#include "Path.h"
#include "SearchBlock.h"

#include <stack>
#include <iostream>
using namespace std;

// private methods


// public methods

DFS::DFS(vector<vector<MapSquare*>>& grid, Vector2i startPos, Vector2i targetPos)
{
	this->dimensions = Vector2i(grid.size(), grid[0].size());
	this->startPos = startPos;
	this->cur = this->startPos;
	this->targetPos = targetPos;

	visited = vector<vector<bool>>(dimensions.x, vector<bool>(dimensions.y, false));
	dfsS = stack<vector<Vector2i>>(); dfsS.push({ startPos });
	finished = false;
};


void DFS::step(vector<vector<MapSquare*>>& grid)
{
	if (dfsS.empty() || finished) return;

	vector<Vector2i> path = dfsS.top();
	cur = path[path.size() - 1];
	dfsS.pop();

	if (cur != startPos && cur != targetPos)
	{
		grid[cur.x][cur.y] = new SearchBlock(cur.x, cur.y);
	}

	if (cur == targetPos)
	{
		finished = true;
		for (Vector2i pos : path)
			if (pos != startPos && pos != targetPos)
				grid[pos.x][pos.y] = new Path(pos.x, pos.y);
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
			dfsS.push(newPath);
			visited[newX][newY] = true;
		}
	}
}