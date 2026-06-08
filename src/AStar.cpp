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

	gScore = vector<vector<int>>(Map::dimensions.x, vector<int>(Map::dimensions.y, INT_MAX));
	fScore = vector<vector<int>>(Map::dimensions.x, vector<int>(Map::dimensions.y, 0));
	cameFrom = vector<vector<Vector2i>>(Map::dimensions.x, vector<Vector2i>(Map::dimensions.y));
	visited = vector<vector<bool>>(Map::dimensions.x, vector<bool>(Map::dimensions.y, false));
	astarQ = priority_queue<pair<int, Vector2i>, vector<pair<int, Vector2i>>, Compare>();
	gScore[startPos.x][startPos.y] = 0;
	fScore[startPos.x][startPos.y] = calcDist(startPos, targetPos);
	astarQ.push({ fScore[startPos.x][startPos.y], startPos});
	finished = false;
}

void AStar::step(vector<vector<MapSquare*>>& grid)
{
	if (astarQ.empty() || finished) return;

	pair<int, Vector2i> cur = astarQ.top(); astarQ.pop();
	Vector2i curPos = cur.second;
	visited[curPos.x][curPos.y] = true;

	if (curPos != startPos && curPos != targetPos)
		grid[curPos.x][curPos.y] = new SearchBlock(curPos.x, curPos.y);

	if (curPos == targetPos)
	{
		finished = true;
		
		Vector2i pos = curPos;

		while (pos != startPos) {
			if (pos != startPos && pos != targetPos)
				grid[pos.x][pos.y] = new Path(pos.x, pos.y);
			pos = cameFrom[pos.x][pos.y];
		}
			
		return;
	}

	for (auto &[r, c] : directions)
	{
		int newR = curPos.x + r;
		int newC = curPos.y + c;
		if (!isValid(newR, newC) || dynamic_cast<Wall*>(grid[newR][newC]) != nullptr) continue;
		int provisional_gScore = gScore[curPos.x][curPos.y] + (r != 0 && c != 0 ?  14 : 10);
		if (provisional_gScore < gScore[newR][newC]) {
			cameFrom[newR][newC] = curPos;
			gScore[newR][newC] = provisional_gScore;
			fScore[newR][newC] = provisional_gScore + calcDist(Vector2i(newC, newR), targetPos);
			if (!visited[newR][newC]) {
				astarQ.push({ fScore[newR][newC], Vector2i(newR, newC) });
			}
		}
	}
}