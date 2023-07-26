#include "Matrix.h"

#include <iostream>
#include <stdexcept>

using std::endl;

//Default Constructor
Matrix::Matrix() : num_of_rows(0), num_of_cols(0) {}


//Stream Insertion Operator
ostream& operator << (ostream& out, const Matrix& matrix) {

	out << matrix.num_of_rows << '\t' << matrix.num_of_cols << endl << endl;

	for (unsigned int i = 0; i < matrix.num_of_rows; i++) {

		for (unsigned int j = 0; j < matrix.num_of_cols; j++) {

			//Write each cell's data to the output stream
			out << matrix.data.at(i).at(j) << '\t';

		}

		out << endl;

	}

	return out;

}

//Stream Extraction Operator
istream& operator >> (istream& in, Matrix& matrix) {

	//Create objects to hold number of rows, columns, and a temporary holding place for each piece of data before it is placed into the matrix
	unsigned int num_row, num_col;
	char temp_data;

	//Read in the num of rows and cols and set the matrix's data fields to the values
	in >> num_row >> num_col;

	matrix.num_of_rows = num_row;
	matrix.num_of_cols = num_col;

	//Resize the matrix to be the correct size
	matrix.data.resize(matrix.num_of_rows);

	for (unsigned int i = 0; i < matrix.num_of_rows; i++) {

		matrix.data.at(i).resize(matrix.num_of_cols);

	}

	//Read in the data
	for (unsigned int i = 0; i < matrix.num_of_rows; i++) {

		for (unsigned int j = 0; j < matrix.num_of_cols; j++) {

			in >> temp_data;

			matrix.data.at(i).at(j) = temp_data;

		}

	}

	return in;

}


/* Reshapes the matrix to a given size (if the size is compatible)
* @param rows: The number of rows the reshaped matrix will have (if compatible)
* @param cols: The number of cols the reshaped matrix will have (if compatible)
*/
void Matrix::reshape(unsigned int rows, unsigned int cols) {

	//Throw a runtime error if the given row and column number is incompatible with the current row and column number
	if ((rows * cols) != (num_of_rows * num_of_cols)) { throw std::runtime_error("Illegal Reshaping"); }

	//Create a temporary matrix of the reshaped size to place the data into
	vector<vector<char>> temp_matrix;

	temp_matrix.resize(rows);

	for (unsigned int i = 0; i < temp_matrix.size(); i++) {

		temp_matrix.at(i).resize(cols);

	}

	//Create helpful objects for iterating through both matricies simultaneously
	unsigned int original_row_num = 0, original_col_num = 0; //Holds the position of the cell currently being copied over to the temporary matrix
	unsigned int new_row_num = 0, new_col_num = 0; //Holds the position of the cell to be copied to from the original matrix

	//Iterate through both matricies simultaneously using their total size, taking each item from the original matrix and copying it over to the temporary one
	//Moves to the next row once num_of_cols - 1 is reached
	for (unsigned int i = 0; i < (rows * cols); i++) {

		//Copy the data over
		temp_matrix.at(new_row_num).at(new_col_num) = data.at(original_row_num).at(original_col_num);

		//Move to the next cell, moving to the first cell in the next row if the final cell in the current row has been reached
		if (new_col_num == cols - 1) {

			new_col_num = 0;
			new_row_num++;

		}
		else { new_col_num++; }

		if (original_col_num == num_of_cols - 1) {

			original_col_num = 0;
			original_row_num++;

		}
		else { original_col_num++; }

	}

	//Copy temp matrix into original matrix and set the num_of_rows and num_of_cols to the correct values
	num_of_rows = rows;
	num_of_cols = cols;
	data = temp_matrix;

	return;

}