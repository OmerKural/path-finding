#include "AStar.h"
#include "MapSquare.h"
#include "Engine.h"
#include "Wall.h"
#include "Path.h"
#include "SearchBlock.h"
#include "Map.h"

bool isValid(int r, int c)
{
	return (r >= 0 && c >= 0 && r < Map::dimensions.x && c < Map::dimensions.y);
}

int calcDist(Vector2i a, Vector2i b)
{
	return 14 * min(abs(a.x - b.x), abs(a.y - b.y)) + 10 * abs(abs(a.x - b.x) - abs(a.y - b.y));
}

AStar::AStar(vector<vector<MapSquare*>>& grid, Vector2i startPos, Vector2i targetPos)
{
	this->startPos = startPos;
	this->curPos = this->startPos;
	this->targetPos = targetPos;

	visited = vector<vector<bool>>(Map::dimensions.x, vector<bool>(Map::dimensions.y, false));
	astarQ = priority_queue<pair<Vector2i, vector<Vector2i>>, vector<pair<Vector2i, vector<Vector2i>>>, Compare>();
	astarQ.push({ Vector2i(0, calcDist(startPos, targetPos)), {startPos} });
	finished = false;
}

void AStar::step(vector<vector<MapSquare*>>& grid)
{
	if (astarQ.empty() || finished) return;

	pair<Vector2i, vector<Vector2i>> cur = astarQ.top();
	int gCost = cur.first.x, hCost = cur.first.y;
	int fCost = gCost + hCost;

	vector<Vector2i> path = cur.second;
	curPos = path[path.size() - 1];
	astarQ.pop();

	if (visited[curPos.x][curPos.y] == true) return;
	visited[curPos.x][curPos.y] = true;

	if (curPos != startPos && curPos != targetPos)
		grid[curPos.x][curPos.y] = new SearchBlock(curPos.x, curPos.y);

	if (curPos == targetPos)
	{
		finished = true;
		for (Vector2i pos : path)
			if (pos != startPos && pos != targetPos)
				grid[pos.x][pos.y] = new Path(pos.x, pos.y);
		return;
	}

	for (auto &[r, c] : directions)
	{
		int newR = curPos.x + r;
		int newC = curPos.y + c;
		int newG = (r == 0 || c == 0) ? gCost + 10 : gCost + 14;
		int newH = calcDist(targetPos, Vector2i(newR, newC));
		if (isValid(newR, newC) && !visited[newR][newC] && 
			dynamic_cast<Wall*>(grid[newR][newC]) == nullptr)
		{
			MapSquare* sq = grid[newR][newC];
			vector<Vector2i> newPath = path;
			newPath.push_back(Vector2i(newR, newC));
			astarQ.push({Vector2i(newG, newH), newPath });
		}
	}
}