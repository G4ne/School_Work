#include "Game.h"

#include <iostream>
#include <fstream>

int main() {

	//Create and open input file
	std::ifstream in("games.txt");

	//Test input file
	if (!in) {
		std::cout << "[Error] Input file not found" << std::endl;
		system("pause");
		return -1;
	}

	//Create and open output file stream
	std::ofstream out("results.txt");

	unsigned int target, turns;

	//Parse data, play games, and write those games' results to the output file
	while (in >> target >> turns) {

		Game new_game(target, turns);

		new_game.play(27);

		new_game.print_result(std::cout);

	}

	return 0;
}