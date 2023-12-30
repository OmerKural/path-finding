#include "BFS.h"
#include "MapSquare.h"
#include "Engine.h"
#include "Wall.h"
#include "Path.h"
#include "SearchBlock.h"
#include "Map.h"

#include <vector>
#include <iostream>
using namespace std;

// private methods


// public methods

BFS::BFS(vector<vector<MapSquare*>> &grid, Vector2i startPos, Vector2i target)
{
	this->startPos = startPos;
	this->cur = this->startPos;
	this->target = target;

	visited = vector<vector<bool>>(Map::dimensions.x, vector<bool>(Map::dimensions.y, false));
	bfsQ = queue<vector<Vector2i>>(); bfsQ.push({ startPos });
	finished = false;
};


void BFS::step(vector<vector<MapSquare*>>& grid)
{
	if (bfsQ.empty() || finished) return;

	vector<Vector2i> path = bfsQ.front();
	cur = path[path.size()-1];
	bfsQ.pop();

	if (cur != startPos && cur != target)
	{
		grid[cur.x][cur.y] = new SearchBlock(cur.x, cur.y);
	}

	if (cur == target)
	{
		finished = true;
		for (Vector2i pos : path)
			if (pos != startPos && pos != target)
				grid[pos.x][pos.y] = new Path(pos.x, pos.y);
		return;
	}
	
	for (auto& d : directions)
	{
		int newX = cur.x + d.first;
		int newY = cur.y + d.second;
		if (0 <= newX && newX < grid.size() &&
			0 <= newY && newY < grid[0].size() &&
			!visited[newX][newY] && dynamic_cast<Wall*>(grid[newX][newY]) == nullptr)
		{
			MapSquare* sq = grid[newX][newY];
			vector<Vector2i> newPath = path;
			newPath.push_back(Vector2i(newX, newY));
			bfsQ.push(newPath);
			visited[newX][newY] = true;
		}
	}
}