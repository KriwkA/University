#include "Map.h"

Map::Map() : heigh(20), width(30)
{
	map = new Block*[width];
	for (int i(0); i < width; i++)
		map[i] = new Block[heigh];
}

void Map::SetBlock(int x, int y, Block block)
{
	map[x][y] = block;
}

Block Map::GetBlock(int x, int y)
{
	return map[x][y];
}

Map::~Map()
{
	for (int i(0); i < heigh; i++)
		delete[] map[i];
	delete[] map;
}
