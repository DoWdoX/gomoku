#include "pch.h"

bool	checkUp(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && x >= 0) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		x -= 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkDown(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && x < 19) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		x += 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkRight(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && y < 19) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		y += 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkLeft(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && y >= 0) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		y -= 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkUpRight(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && x >= 0 && y < 19) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		x -= 1;
		y += 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkUpLeft(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && x >= 0 && y >= 0) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		x -= 1;
		y -= 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkDownRight(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && x < 19 && y < 19) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		x += 1;
		y += 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}

bool	checkDownLeft(int x, int y, std::vector<std::string> myBoard, int nbOccu, char player)
{
	int count = 0;
	int occu = 0;

	if (nbOccu < 0)
		nbOccu *= -1;
	while (count <= nbOccu && x < 19 && y >= 0) {
		if (myBoard[x][y] == player)
			occu += 1;
		count += 1;
		x += 1;
		y -= 1;
	}
	if (occu == nbOccu)
		return (true);
	return (false);
}