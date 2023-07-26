#include "Sudoku.h"
#include <fstream>
#include <iostream>

using std::endl;

int main() {

	//Open input file
	std::ifstream in("puzzle.txt");

	//Check to see if input file opened correctly
	if (!in) {

		std::cout << "[Error] Input file not found" << endl;
		system("pause");
		return -1;

	}

	//Create / open output file
	std::ofstream out("solutions.txt");

	//Create sudoku puzzle object
	Sudoku puzzle;

	//Read in puzzle from input file
	puzzle.load_data(in);

	//Solve puzzle and output all possible solutions to the output file
	puzzle.solve(out);

	//Close both files
	in.close();
	out.close();

	return 0;
}