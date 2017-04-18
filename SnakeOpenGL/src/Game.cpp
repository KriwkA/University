#include "Game.h"
#include "Map.h"
#include "Painter.h"
#include "Snake.h"
#include "Level.h"
#include <ctime>

Game::Game() : map(), heigh(20), width(30), size(20)
{
	srand(time(NULL));
	NewGame();
}

void Game::NewFruit()
{
	int x, y;
	do
	{
		x = rand() % width;
		y = rand() % heigh;
	} while (map.GetBlock(x, y));
	map.SetBlock(x, y, FRUIT);
}

void Game::NewGame()
{
	state = GAME;
	snake.DeleteSnake();
	for (int i(0); i < heigh; i++)
		for (int j(0); j < width; j++)
		{
			switch (Level[i][j])
			{
			case 'G':map.SetBlock(j, i, WALL); break;
			default:map.SetBlock(j, i, EMPTY); break;
			}
		}
	snake.SetDirection(Snake::Direction(rand()% 4));
	X = width / 2;
	Y = heigh / 2;
	snake.PushBlock(X, Y);
	map.SetBlock(X, Y, SNAKE);
	NewFruit();
}

void Game::drow()
{
	for (int i(0); i < heigh; i++)
		for (int j(0); j < width; j++)
		{
			switch (map.GetBlock(j, i))
			{
			case SNAKE :
				painter.SetColor(Painter::GREEN);
				painter.drowRect(j*size+1, i*size+1, j*size + size-1, i*size + size-1);
				break;
			case FRUIT:
				painter.SetColor(Painter::RED);
				painter.drowRect(j*size + 3, i*size + 3, j*size + size - 3, i*size + size - 3);
				break;
			case WALL:
				painter.SetColor(Painter::BLUE);
				painter.drowRect(j*size, i*size, j*size + size, i*size + size);
				break;
			}
		}
}

int Game::tick()
{
	if (state == State::PAUSE) return 2;
	switch (snake.GetDirection())
	{
	case Snake::UP   : Y++; break;
	case Snake::DOWN : Y--; break;
	case Snake::LEFT : X--; break;
	case Snake::RIGHT: X++; break;
	}
	if (X < 0 || X >= width || Y < 0 || Y >= heigh)
		return 1;
	Block block = map.GetBlock(X, Y);
	Snake_Block temp;
	switch (block)
	{
	case EMPTY:		
		snake.PushBlock(X, Y);
		map.SetBlock(X, Y, SNAKE);
		temp = snake.PopBlock();
		map.SetBlock(temp.first,temp.second,EMPTY);
		break;
	case SNAKE:
		return 1;
		break;
	case FRUIT:
		snake.PushBlock(X, Y);
		map.SetBlock(X, Y, SNAKE);
		NewFruit();
		break;
	case WALL:
		return 1;
		break;
	}
	speed = 3*snake.GetSnakeSize();
	if (speed > 149) speed = 149;
	return 0;
}

void Game::keyEvent(Key key)
{
	switch (key)
	{
	case Key::UP: snake.SetDirection(Snake::UP); break;
	case Key::DOWN: snake.SetDirection(Snake::DOWN); break;
	case Key::LEFT: snake.SetDirection(Snake::LEFT); break;
	case Key::RIGHT: snake.SetDirection(Snake::RIGHT); break;
	case Key::PAUSE: state == GAME ? state = State::PAUSE : state = State::GAME; break;
	}
}

int Game::GetSpeed()
{
	return speed;
}
