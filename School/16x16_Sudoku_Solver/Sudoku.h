#ifndef SUDOKU_H
#define SUDOKU_H


#include <iostream>
#include <string>

using std::ostream;
using std::istream;

class Sudoku {
public:

	//Default Constructor
	Sudoku();

	//Copy Constructor
	Sudoku(const Sudoku&);

	//Destructor
	~Sudoku();

	//Class-member functions
	void load_data(istream&); // Reads in the puzzle from an input stream
	void solve(ostream&); //Wrapper Function
	

	//Operator Overloadings
	const Sudoku& operator = (const Sudoku&);

private:

	//Data Fields
	char** board;
	static const unsigned int SIZE;
	static const char BLANK;
	static const std::string digit_list;
	bool solved;
	unsigned int solution_num;


	//Class-member Functions
	int next_row_index(int, int) const; // Row index of the next cell
	int next_col_index(int, int) const; // Column index of the next cell
	bool in_same_row(int, char) const; // Test if a digit is already in a row
	bool in_same_col(int, char) const; // Test if a digit is already in a column
	bool in_same_grid(int, int, char) const; // Test if a digit is already in a column
	void solve(int, int, ostream&); // Solves the puzzle given a starting row and column
	void print_solution(ostream&) const; //Writes current solution to an output stream

};

#endif
