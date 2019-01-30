#pragma once

#ifndef GOMOKU_H
# define GOMOKU_H

# include <iostream>
# include <string>
# include <vector>
# include <stdbool.h>

class Gomokuia {
public:
	Gomokuia();
	~Gomokuia();

	void initBoard();
	int lauchAlgo();
	void fillBoard(std::string);
	void setPriority();
	void definePosPlay();
	bool checkOne(int, int, char);
	bool checkTwo(int, int, char);
	bool checkThree(int, int, char);
	bool checkFour(int, int, char);
	bool checkBlockedOneSide(int, int, int, char);
	void checkMyAttack(int, int);

private:
	std::vector<std::string> myBoard;
	int playX;
	int playY;
	int playXAttack;
	int playYAttack;
	int tour;
	int dangerOppo;
	int myDanger;
	int lastOppoPlayX;
	int lastOppoPlayY;
};

void prioRight(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioLeft(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioUp(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioDown(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioUpRight(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioDownRight(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioUpLeft(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);
void prioDownLeft(int x, int y, std::vector<std::string> myBoard, int &playX, int &playY);

bool checkUp(int, int, std::vector<std::string>, int, char);
bool checkDown(int, int, std::vector<std::string>, int, char);
bool checkRight(int, int, std::vector<std::string>, int, char);
bool checkLeft(int, int, std::vector<std::string>, int, char);
bool checkUpRight(int, int, std::vector<std::string>, int, char);
bool checkUpLeft(int, int, std::vector<std::string>, int, char);
bool checkDownRight(int, int, std::vector<std::string>, int, char);
bool checkDownLeft(int, int, std::vector<std::string>, int, char);

bool checkStart(std::string);

#endif /*GOMOKU_H*/