#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {

public:

	//Constructor
	Matrix( unsigned int num_of_rows = 0, unsigned int num_of_columns = 0 );

	//Setters not needed for this class

	//Getters
	unsigned int Get_Num_Of_Rows() const;
	unsigned int Get_Num_Of_Columns() const;

	//Class-member Functions
	int Get(unsigned int, unsigned int) const;
	void Set(unsigned int, unsigned int, int);

	//Overloaded Operators
	Matrix operator + (const Matrix&) const; //Matrix + Matrix
	Matrix operator + (int) const; //Matrix + Integer
	Matrix operator ++ (); //Increment Matrix prefix
	Matrix operator ++ (int); //Increment Matrix postfix
	Matrix operator - (const Matrix&) const; //Matrix - Matrix
	Matrix operator - (int) const; //Matrix - Number
	Matrix operator -- (); //Decrement Matrix prefix
	Matrix operator -- (int); //Decrement Matrix postfix
	Matrix operator * (const Matrix&) const; //Matrix * Matrix
	Matrix operator * (int) const; //Matrix * Integer
	friend std::ostream& operator << (std::ostream&, const Matrix&); //Stream Insertion Operator Overloading

private:

	//Data Fields
	unsigned int num_of_rows;
	unsigned int num_of_columns;
	std::vector<std::vector<int>> data;

	//Class-member Functions
	int multiply_cells(const Matrix&, unsigned int, unsigned int) const; //Does a piece of matrix multiplication

};

//Overload operators
Matrix operator * (int, const Matrix&); //Integer * Matrix

#endif