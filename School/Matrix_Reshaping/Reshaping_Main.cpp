#include "Matrix.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;

int main() {

	//Open input file
	ifstream in("before.txt");

	//Check if input file opened correctly
	if (!in) {

		std::cout << "[Error] Input file not found" << endl;
		system("pause");
		return -1;

	}

	//Open output file
	ofstream out("after.txt");

	//Create matrix object
	Matrix matrix;

	//Read matrix data in
	in >> matrix;

	//Read in the reshaping parameters
	unsigned int reshaping_row, reshaping_col;

	in >> reshaping_row >> reshaping_col;

	//Attempt Reshaping
	try {

		matrix.reshape(reshaping_row, reshaping_col);

		out << matrix;

	}
	catch (std::runtime_error error) { out << error.what(); }

	return 0;
}