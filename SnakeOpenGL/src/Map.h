#pragma once

enum Block{ EMPTY, SNAKE, FRUIT, WALL };

class Map
{
private:
	const int heigh;
	const int width;
	Block **map;
public:
	Map();
	void SetBlock(int,int,Block);
	Block GetBlock(int, int);
	~Map();
};

