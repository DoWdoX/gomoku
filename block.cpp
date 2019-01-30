#include "pch.h"

void	prioRight(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	y += 1;
	while (y < 19 && count < 5 && myBoard[x][y - 1] != '2') {
		y += 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioLeft(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	y -= 1;
	while (y >= 0 && count < 5 && myBoard[x][y + 1] != '2') {
		y -= 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioUp(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	x -= 1;
	while (x >= 0 && count < 5 && myBoard[x + 1][y] != '2') {
		x -= 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioDown(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	x += 1;
	while (x < 19 && count < 5 && myBoard[x - 1][y] != '2') {
		x += 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioUpRight(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	x -= 1;
	y += 1;
	while (x >= 0 && y < 19 && count < 5 && myBoard[x + 1][y - 1] != '2') {
		y += 1;
		x -= 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioDownRight(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	x += 1;
	y += 1;
	while (x < 19 && y < 19 && count < 5 && myBoard[x - 1][y - 1] != '2') {
		y += 1;
		x += 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioUpLeft(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	x -= 1;
	y -= 1;
	while (x >= 0 && y >= 0 && count < 5 && myBoard[x + 1][y + 1] != '2') {
		y -= 1;
		x -= 1;
		count += 1;
	}
	playX = x;
	playY = y;
}

void	prioDownLeft(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY)
{
	int count = 1;

	x += 1;
	y -= 1;
	while (x < 19 && y >= 0 && count < 5 && myBoard[x - 1][y + 1] != '2') {
		y -= 1;
		x += 1;
		count += 1;
	}
	playX = x;
	playY = y;
}