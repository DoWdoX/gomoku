#include "pch.h"

int main()
{
	//lancement de l'IA
	while (42) {
		Gomokuia gomoku;
		gomoku.initBoard();
		if (gomoku.lauchAlgo() == 0)
			return (0);
	}
	return (0);
}

//vérif taille plateau
bool	checkStart(std::string start)
{
	std::string size = start.substr(6);
	if (std::stoi(size) == 19)
		return (true);
	return (false);
}
