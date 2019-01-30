#include "pch.h"

void(*block[])(int, int, std::vector<std::string>, int&, int&) = { prioRight,prioLeft,prioUp,prioDown,prioUpRight,prioDownRight,prioUpLeft,prioDownLeft };
bool(*pf[])(int, int, std::vector<std::string>, int, char) = { checkUp,checkDown,checkRight,checkLeft,checkUpRight,checkUpLeft,checkDownRight,checkDownLeft };

Gomokuia::Gomokuia()
{
}

Gomokuia::~Gomokuia()
{
}

//on va stocker le plateau de jeu avec des 0 (vide) dans un std::vector
void	Gomokuia::initBoard()
{
	std::string line("0000000000000000000");

	for (int i = 0; i != 19; i++) {
		myBoard.push_back(line.c_str());
	}
	tour = 0;
}

//on place le pion adverse joué dans notre vector
void	Gomokuia::fillBoard(std::string pos)
{
	std::string posX = pos.substr(0, pos.find(','));
	std::string posY = pos.substr(pos.find(',') + 1);
	myBoard[std::stoi(posY)][std::stoi(posX)] = '2';
	lastOppoPlayX = std::stoi(posX);
	lastOppoPlayY = std::stoi(posY);
}

//vérif si 2 pions de la même équipe sont alignés
bool	Gomokuia::checkTwo(int i, int j, char player)
{
	for (int k = 0; k != 8; k++) {
		if (pf[k](i, j, myBoard, 2, player) == true)
			return (true);
	}
	return (false);
}

//vérif si 3 pions de la même équipe sont alignés
bool	Gomokuia::checkThree(int i, int j, char player)
{
	for (int k = 0; k != 8; k++) {
		if (pf[k](i, j, myBoard, 3, player) == true)
			return (true);
	}
	return (false);
}

//vérif si 4 pions de la même équipe sont alignés
bool	Gomokuia::checkFour(int i, int j, char player)
{
	for (int k = 0; k != 8; k++) {
		if (pf[k](i, j, myBoard, 4, player) == true)
			return (true);
	}
	return (false);
}

//vérif si 1 pion de la même équipe est aligné
bool	Gomokuia::checkOne(int i, int j, char player)
{
	for (int k = 0; k != 8; k++) {
		if (pf[k](i, j, myBoard, 1, player) == true)
			return (true);
	}
	return (false);
}

//check si l'adv ou moi peut jouer d'un côté en fonction du plus grand nombre de pions alignés (attaque privilégiée si égalité)
bool	Gomokuia::checkBlockedOneSide(int x, int y, int nbAlign, char player)
{
	for (int k = 0; k != 8; k++) {
		if (pf[k](x, y, myBoard, nbAlign, player) == true) {
			switch (k) {
			case 0:
				if (x - nbAlign >= 0 && x - nbAlign < 19 && myBoard[x - nbAlign][y] == player)
					return (true);
				break;
			case 1:
				if (x + nbAlign < 19 && x + nbAlign >= 0 && myBoard[x + nbAlign][y] == player)
					return (true);
				break;
			case 2:
				if (y + nbAlign < 19 && y + nbAlign >= 0 && myBoard[x][y + nbAlign] == player)
					return (true);
				break;
			case 3:
				if (y - nbAlign >= 0 && y - nbAlign < 19 && myBoard[x][y - nbAlign] == player)
					return (true);
				break;
			case 4:
				if (x - nbAlign >= 0 && y + nbAlign < 19 && x - nbAlign < 19 && y + nbAlign >= 0 && myBoard[x - nbAlign][y + nbAlign] == player)
					return (true);
				break;
			case 5:
				if (x - nbAlign >= 0 && y - nbAlign >= 0 && x - nbAlign < 19 && y - nbAlign < 19 && myBoard[x - nbAlign][y - nbAlign] == player)
					return (true);
				break;
			case 6:
				if (x + nbAlign < 19 && y + nbAlign < 19 && x + nbAlign >= 0 && y + nbAlign >= 0 && myBoard[x + nbAlign][y + nbAlign] == player)
					return (true);
				break;
			case 7:
				if (x + nbAlign < 19 && y - nbAlign >= 0 && x + nbAlign >= 0 && y - nbAlign < 19 && myBoard[x + nbAlign][y - nbAlign] == player)
					return (true);
				break;
			};
		}
	}
	return (false);
}

//on check ici le taux de danger que j'ai en attaquant + détermination du danger
void	Gomokuia::checkMyAttack(int i, int j)
{
	if (checkFour(i, j, '1') == true && myDanger <= 5) { //si 4 pions alignés alors danger = 5
		playXAttack = j;
		playYAttack = i;
		myDanger = 5;
	}
	if (checkThree(i, j, '1') == true) { //si 3 pions alignés | 2 côtés libre : danger = 5 | si 1 côté libre danger = 4 | sinon danger = 3
		if (myDanger < 4) {
			playXAttack = j;
			playYAttack = i;
			myDanger = 4;
			if (checkBlockedOneSide(i, j, 4, '2') == true)
				myDanger = 3;
		}
		if (checkBlockedOneSide(i, j, -1, '1') == true && myDanger < 5) {
			playXAttack = j;
			playYAttack = i;
			myDanger = 5;
		}
	}
	if (checkTwo(i, j, '1') == true) { //si 2 pions alignés | 2 côtés libres : danger = 5 | 1 côté libre : danger = 4 | sinon danger = 3
		if (myDanger < 3) {
			playXAttack = j;
			playYAttack = i;
			myDanger = 3;
			if (checkBlockedOneSide(i, j, 3, '2') == true)
				myDanger = 2;
		}
		if (checkBlockedOneSide(i, j, -2, '1') == true && myDanger < 5) {
			playXAttack = j;
			playYAttack = i;
			myDanger = 5;
		}
		if (checkBlockedOneSide(i, j, -1, '1') == true && myDanger < 4) {
			playXAttack = j;
			playYAttack = i;
			myDanger = 4;
		}
	}
	if (checkOne(i, j, '1') == true) { //si 1 seul pion danger = 1
		if (myDanger < 2) {
			playXAttack = j;
			playYAttack = i;
			myDanger = 2;
			if (checkBlockedOneSide(i, j, 2, '2') == true)
				myDanger = 1;
		}
	}
}

//on va calculer ici le plus gros danger adverse + la position x,y du danger
void	Gomokuia::definePosPlay()
{
	if (tour == 0) {
		int posX = 0;
		int posY = 0;
		for (int y = 0; y != 19; y++) {
			for (int x = 0; x != 19; x++) {
				if (myBoard[y][x] == '2') {
					posX = y;
					posY = x;
				}
			}
		}
		if (posX == 18)
			posX -= 2;
		playX = posY;
		playY = posX + 1;
		tour += 1;
	}
	else {
		dangerOppo = 0;
		myDanger = 0;
		for (int i = 0; i != 19; i++) {
			for (int j = 0; j != 19; j++) {
				if (myBoard[i][j] == '0') {
					checkMyAttack(i, j);
					if (checkFour(i, j, '2') == true && dangerOppo <= 5) {
						playX = j;
						playY = i;
						dangerOppo = 5;
					}
					if (checkThree(i, j, '2') == true) {
						if (dangerOppo < 4) {
							playX = j;
							playY = i;
							dangerOppo = 4;
							if (checkBlockedOneSide(i, j, 4, '1') == true)
								dangerOppo = 3;
						}
						if (checkBlockedOneSide(i, j, -1, '2') == true && dangerOppo < 5) {
							playX = j;
							playY = i;
							dangerOppo = 5;
						}
					}
					if (checkTwo(i, j, '2') == true) {
						if (dangerOppo < 3) {
							playX = j;
							playY = i;
							dangerOppo = 3;
							if (checkBlockedOneSide(i, j, 3, '1') == true)
								dangerOppo = 2;
						}
						if (checkBlockedOneSide(i, j, -2, '2') == true && dangerOppo < 5) {
							playX = j;
							playY = i;
							dangerOppo = 5;
						}
						if (checkBlockedOneSide(i, j, -1, '2') == true && dangerOppo < 4) {
							playX = j;
							playY = i;
							dangerOppo = 4;
						}
					}
					if (checkOne(i, j, '2') == true && dangerOppo < 1) {
						playX = j;
						playY = i;
						dangerOppo = 2;
						if (checkBlockedOneSide(i, j, 2, '1') == true)
							dangerOppo = 1;
					}
				}
			}
		}
		if (myDanger >= dangerOppo || dangerOppo == 0) { //priorité sur l'attaque si égalité de danger avec la déf
			playX = playXAttack;
			playY = playYAttack;
		}
	}
}

//cette fonction est la récupération des pions joués par l'adv
int	Gomokuia::lauchAlgo()
{
	std::string retour;
	playX = rand() % 19;
	playY = rand() % 19;
	playXAttack = rand() % 19;
	playYAttack = rand() % 19;
	getline(std::cin, retour);
	if (retour.compare(0, 5, "START") == 0) {
		if (checkStart(retour) == false) {
			std::cout << "ERROR SIZE NOT GOOD" << std::endl;
			return (0);
		}
		std::cout << "OK" << std::endl;
	}
	while (42) {
		getline(std::cin, retour);
		while (retour.compare(0, 5, "BEGIN") != 0 && retour.compare(0, 4, "TURN") != 0 && retour.compare(0, 7, "RESTART") != 0)
			getline(std::cin, retour);
		if (retour.compare(0, 5, "BEGIN") == 0) {
			std::cout << playX << "," << playY << std::endl;
			myBoard[playY][playX] = '1';
			tour += 1;
		}
		else if (retour.compare(0, 4, "TURN") == 0) {
			fillBoard(retour.substr(5, std::string::npos));
			definePosPlay();
			std::cout << playX << "," << playY << std::endl;
			myBoard[playY][playX] = '1';
		}
		else if (retour.compare(0, 7, "RESTART") == 0) {
			std::cout << "OK" << std::endl;
			return (1);
		}
	}
	return (0);
}
