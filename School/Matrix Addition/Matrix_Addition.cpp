#include "Matrix.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


int main() {

	Matrix matrix1(3, 3);

	for (unsigned int i = 0; i < matrix1.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < matrix1.Get_Num_Of_Columns(); j++) {

			matrix1.Set(i, j, 5);

		}

	}

	Matrix matrix2(2, 6);

	for (unsigned int i = 0; i < matrix2.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < matrix2.Get_Num_Of_Columns(); j++) {

			matrix2.Set(i, j, 7);

		}

	}

	cout << matrix1.Get_Num_Of_Rows() << "\t" << matrix2.Get_Num_Of_Columns() << endl << endl;

	cout << matrix1 * matrix2 << endl << endl;

	system("pause");
	return 0;
}