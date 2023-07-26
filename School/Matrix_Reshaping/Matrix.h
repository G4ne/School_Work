#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::istream;

class Matrix {

public:

	//Default Constructor
	Matrix();

	//Class-member Function
	void reshape(unsigned int, unsigned int);

	//Overloaded Operators
	friend ostream& operator << (ostream&, const Matrix&); //Stream Insertion Operator
	friend istream& operator >> (istream&, Matrix&); //Stream Extraction Operator

private:

	//Data Fields
	unsigned int num_of_rows;
	unsigned int num_of_cols;
	vector<vector<char>> data;

};

#endif