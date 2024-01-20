#include "Map.h"

// static attributes

const Vector2i Map::dimensions = Vector2i(64, 64);

const Vector2f Map::mapPosition = Vector2f(
    Engine::MID.x - dimensions.x / 2 * MapSquare::size,
    Engine::MID.y - dimensions.y / 2 * MapSquare::size
);