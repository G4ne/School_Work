#include "Matrix.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


int main() {

	//Create ifstream object and open the input file
	ifstream matrix_in;
	matrix_in.open("matrices.txt");

	//Make sure input file opened correctly
	if (!matrix_in) {

		cout << "[Error] Input File Not Detected" << endl;
		system("pause");
		return -1;
	}

	//Take in the dimensions of the matrices from the input file
	unsigned int num_rows, num_cols;
	matrix_in >> num_rows >> num_cols;

	//Create two matrices with the given dimensions
	Matrix matrix1(num_rows, num_cols), matrix2(num_rows, num_cols);

	//Set each cell in matrix1 to their corresponding value from the input file
	for (unsigned int i = 0; i < matrix1.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < matrix1.Get_Num_Of_Columns(); j++) {
			int val;
			matrix_in >> val;
			matrix1.Set(i, j, val);
		}

	}

	//Set each cell in matrix2 to their corresponding value from the input file
	for (unsigned int i = 0; i < matrix2.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < matrix2.Get_Num_Of_Columns(); j++) {
			int val;
			matrix_in >> val;
			matrix2.Set(i, j, val);
		}

	}

	//Close input file
	matrix_in.close();

	//Create / Open output file
	ofstream matrix_out("result.txt");

	//Write matrix dimensions and the sum of the contents of the two matrices to the output file
	matrix_out << num_rows << "\t" << num_cols << endl << endl;
	matrix_out << matrix1 + matrix2;

	//Close output file
	matrix_out.close();

	return 0;
}