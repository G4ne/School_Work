#include "Matrix.h"

/** Constructor
* @param num_rows: Takes the number of rows that the matrix should be intialized to
* @param num_cols: Takes the number of columns that the matrix should be intialized to
*/
Matrix::Matrix(unsigned int num_rows, unsigned int num_cols) : num_of_rows(num_rows), num_of_columns(num_cols) {

	//Initialize 'outer' vector with given num_of_rows
	data.resize(num_of_rows);

	//Initialize every 'inner' vector with given num_of_columns
	for (unsigned int i = 0; i < data.size(); i++) {
		data.at(i).resize(num_of_columns);
	}

}

//Set up getters

/** Returns Number of Rows
* @return: Returns the matrix's number of rows
*/
unsigned int Matrix::Get_Num_Of_Rows() const { return num_of_rows; }

/** Returns Number of Columns
* @return: Returns the matrix's number of columns
*/
unsigned int Matrix::Get_Num_Of_Columns() const { return num_of_columns; }

//Initialize class-member functions with docstrings

/** Returns an int given the position in the matrix
* @param i: The row number of the desired number
* @param j: The column number of the desired number
* @return int: The desired number at (i, j)
*/
int Matrix::Get(unsigned int i, unsigned int j) const { return data.at(i).at(j); }

/** Sets an element at given location to a given value
* @param i: The row number location that should be set with the given value
* @param j: The column number location that should be set with the given value
* @param val: The value to be set at the given location
* @return: No return value
*/
void Matrix::Set(unsigned int i, unsigned int j, int val) { data.at(i).at(j) = val; }

/** Adds two matrices together
* @param other: The second matrix being added
* @return: Returns the added matrix
*/
Matrix Matrix::operator + (const Matrix& other) const {

	//Creates a matrix with identical dimensions to the input matrices
	Matrix result(num_of_rows, num_of_columns);

	//Iterates through the created matrix, setting each cell value equal to the added amount of the same cells in both input matrices
	for (unsigned int i = 0; i < num_of_rows; i++) {

		for (unsigned int j = 0; j < num_of_columns; j++) {
			result.Set(i, j, Get(i, j) + other.Get(i, j));
		}

	}

	return result;
}

/** Adds a matrix and an integer together
* @param num: Number to be added to all the elements in the matrix
* @return: Returns the matrix with the number added to all elements
*/
Matrix Matrix::operator + (int num) const {

	Matrix result(Get_Num_Of_Rows(), Get_Num_Of_Columns());

	for (unsigned int i = 0; i < result.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < result.Get_Num_Of_Columns(); j++) {

			result.Set(i, j, Get(i, j) + num);

		}

	}
	return result;
}

/** Increments a matrix (prefix)
* @return: Returns the original matrix + 1
*/
Matrix Matrix::operator ++ () {
	*this = *this + 1;
	return *this;
}

/** Increments a matrix (postfix)
* @return: Returns the matrix + 1
*/
Matrix Matrix::operator ++ (int) {
	Matrix result = *this;
	*this = *this + 1;
	return result;
}

/** Subtracts two matrices
* @param other: The Matrix being subtracted from the current matrix
* @return: Returns the difference of the matrices
*/
Matrix Matrix::operator - (const Matrix& other) const {
	
	//Creates a matrix with identical dimensions to the input matrices
	Matrix result(num_of_rows, num_of_columns);

	//Iterates through the created matrix, setting each cell value equal to the difference of the same cells in both input matrices
	for (unsigned int i = 0; i < num_of_rows; i++) {

		for (unsigned int j = 0; j < num_of_columns; j++) {
			result.Set(i, j, Get(i, j) - other.Get(i, j));
		}

	}

	return result;
}

/** Subtracts an integer from all elements of a matrix
* @param num: Number to be subtracted from all the elements in the matrix
* @return: Returns the matrix with the number subtracted from all elements
*/
Matrix Matrix::operator - (int num) const {

	Matrix result(Get_Num_Of_Rows(), Get_Num_Of_Columns());

	for (unsigned int i = 0; i < result.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < result.Get_Num_Of_Columns(); j++) {

			result.Set(i, j, Get(i, j) - num);

		}

	}
	return result;
}

/** Decrements a matrix (prefix)
* @return: Returns the matrix - 1
*/
Matrix Matrix::operator -- () {
	*this = *this - 1;
	return *this;
}

/** Decrements a matrix (postfix)
* @return: Returns the matrix - 1
*/
Matrix Matrix::operator -- (int) {
	Matrix result = *this;
	*this = *this - 1;
	return result;
}

/** Multiplies two matrices together
* @param other: The second matrix being multiplied (the right-hand side one)
* @return: The product matrix
*/
Matrix Matrix::operator * (const Matrix& other) const {
	
	//Checks to see if the input matrices are valid for matrix multiplication
	if (Get_Num_Of_Columns() != other.Get_Num_Of_Rows()) {
		std::cout << "[Error] Input Matrices are not valid for matrix multiplication" << std::endl;
		system("pause");
		return Matrix(0, 0);
	}

	//Creates temp variable to hold row count for result matrix
	unsigned int num_rows = Get_Num_Of_Rows();

	//Creates a matrix with the dimensions of the product matrix
	Matrix result(num_rows, other.Get_Num_Of_Columns());

	for (unsigned int i = 0; i < result.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < result.Get_Num_Of_Columns(); j++) {

			result.Set(i, j, multiply_cells(other, i, j));

		}

	}
	return result;
}

/** Performs Scalar Multiplication on a matrix
* @param num: The number which every element in the matrix is being multiplied by
* @return: Returns a multiplied matrix
*/
Matrix Matrix::operator * (int num) const {

	//Creates copy of matrix for multiplication
	Matrix result = *this;

	//Iterates through matrix copy and multiplies each element by the input number
	for (unsigned int i = 0; i < result.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < result.Get_Num_Of_Columns(); j++) {

			result.Set(i, j, Get(i, j) * num);

		}

	}

	return result;

}

/** Performs Scalar Multiplication on a matrix
* @param num: The number which every element in the matrix is being multiplied by
* @param matrix: The matrix being multiplied
* @return: Returns a multiplied matrix
*/
Matrix operator * (int left, const Matrix& right) {

	//Uses already defined multiplication function because multiplication is commutable
	Matrix result = right * left;
	return result;

}

/** Outputs the matrix to an ostream
* @param out: Takes an output stream to put the matrix to
* @param matrix: Takes a matrix to put to the output stream
* @return: Returns an ostream
*/
std::ostream& operator << (std::ostream& out, const Matrix& matrix) {
	
	//Puts the contents of the matrix to the output stream
	for (unsigned int i = 0; i < matrix.Get_Num_Of_Rows(); i++) {

		for (unsigned int j = 0; j < matrix.Get_Num_Of_Columns(); j++) {
			out << matrix.Get(i, j);
			if (j != matrix.num_of_columns) {
				out << "\t";
			}
		}

		out << std::endl;

	}
	return out;
}

/** Multiplies a row and column to make one cell in the product matrix
* @param other: The second matrix to be used in the matrix multiplication
* @param i: The row to be used in multiplication
* @param j: The column to be used in multiplication
* @return: Returns the product of the input row and column
*/
int Matrix::multiply_cells(const Matrix& other, unsigned int i, unsigned int j) const {

	int end_val = 0;

	for (unsigned int x = 0; x < other.Get_Num_Of_Rows(); x++) {

		end_val += other.Get(x, j) * Get(i, x);

	}

	return end_val;

}