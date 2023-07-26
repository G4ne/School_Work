#include "Sudoku.h"

#include <string>

using std::string;
using std::getline;
using std::exception;

const char Sudoku::BLANK = '.';
const unsigned int Sudoku::SIZE = 16;
const string Sudoku::digit_list = "0123456789abcdef";

//Default Constructor
Sudoku::Sudoku() : solved(false), solution_num(0) {
	board = new char*[SIZE];

	for (unsigned int row = 0; row < SIZE; row++) {
		board[row] = new char[SIZE];
	}

}


//Copy Constructor
Sudoku::Sudoku(const Sudoku& rhs) {
	board = nullptr;
	*this = rhs;
}


//Deep-copy Operator
const Sudoku& Sudoku::operator = (const Sudoku& rhs) {

	//Avoid self-assignment
	if (this != &rhs) {

		//Free up dynamic memory
		if (board) {
			for (unsigned int i = 0; i < SIZE; i++) {
				delete[] board[i];
			}
			delete[] board;
			board = nullptr;
		}

		//Copy Static data
		this->solved = rhs.solved;
		this->solution_num = rhs.solution_num;

		//Copy Dynamic data
		board = new char* [SIZE];
		for (unsigned int row = 0; row < SIZE; row++) {

			board[row] = new char[SIZE];

			for (unsigned int col = 0; col < SIZE; col++) {
				board[row][col] = rhs.board[row][col];
			}

		}

	}

	//Return
	return *this;

}


//Destructor
Sudoku::~Sudoku() {

	for (unsigned int row = 0; row < SIZE; row++) {

		delete[] board[row];

	}

	delete[] board;
	board = nullptr;

}


/* Loads a sudoku board given an input stream containing a sudoku puzzle
* @param in: The input stream from which to read the puzzle
*/
void Sudoku::load_data(istream& in) {

	string currentline;

	for (unsigned int row = 0; row < SIZE; row++) {

		getline(in, currentline);

		for (unsigned int col = 0; col < SIZE; col++) {

			board[row][col] = currentline[col];

		}

	}

}


/* Gets the index of the next row item
* @param row: The row of the current item
* @param col: The column of the current item
* @return: The row index of the next item
*/
int Sudoku::next_row_index(int row, int col) const {

	if (row == SIZE - 1 && col == SIZE - 1) { return -1; }
	else if (col == SIZE - 1) { return row + 1; }
	else { return row; }

}


/* Gets the index of the item in the next column item
* @param row: The row of the current item
* @param col: The column of the current item
* @return: The column index of the next item;
*/
int Sudoku::next_col_index(int row, int col) const {

	if (row == SIZE - 1 && col == SIZE - 1) { return -1; }
	else if (col == SIZE - 1) { return 0; }
	else { return col + 1; }

}

/* Returns true if an identical digit to the given digit is in the same row
* @param row: The row to be scanned for matching digits
* @param num: The number to be scanned for
* @return: Returns true if there is an identical digit
*/
bool Sudoku::in_same_row(int row, char digit) const {

	for (unsigned int col = 0; col < SIZE; col++) {

		if (board[row][col] == digit) { return true; }

	}

	return false;

}


/* Returns true if an identical digit to the given digit is in the same column
* @param col: The column to be scanned for matching digits
* @param num: The digit to be scanned for
* @return: Returns true if there is an identical digit
*/
bool Sudoku::in_same_col(int col, char digit) const {

	for (unsigned int row = 0; row < SIZE; row++) {

		if (board[row][col] == digit) { return true; }

	}

	return false;

}


/* Returns true if an identical digit is found in the same 4x4 grid
* @param row: The row of the current digit, to be scanned from
* @param col: The column of the current digit, to be scanned from
* @param num: The digit that is being scanned for in the 4x4
* @return: Returns true if the digit is found, false if not
*/
bool Sudoku::in_same_grid(int row, int col, char digit) const {

	int grid_start_row = row / 4 * 4, grid_start_col = col / 4 * 4;

	for (unsigned int i = grid_start_row; i < grid_start_row + 4; i++) {

		for (unsigned int j = grid_start_col; j < grid_start_col + 4; j++) {

			if (board[i][j] == digit) { return true; }

		}

	}

	return false;

}


/* Solves the puzzle
* @param row: The row index at which to start solving
* @param col: The column index at which to start solving
* @param out: The ostream to print the solutions to
*/
void Sudoku::solve(int row, int col, ostream& out) {

	//Base case
	if (row == -1 || col == -1) {
		
		solved = true;
		return;

	}
	
	//The current cell is not blank
	else if (board[row][col] != BLANK) { 

		solve(next_row_index(row, col), next_col_index(row, col), out);

	}

	//The current cell is blank
	else {

		//Iterate through each letter, attempting all combinations with it
		for (unsigned int i = 0; i < digit_list.size(); i++) {

			//If a matching digit is in the same row, column, or grid, we continue
			if ( in_same_row(row, digit_list.at(i)) || in_same_col(col, digit_list.at(i)) || in_same_grid(row, col, digit_list.at(i)) ) { continue; }

			//If nothing is found, we are in the clear and can change the cell
			board[row][col] = digit_list.at(i);

			//After, we solve from the next cell
			solve( next_row_index(row, col), next_col_index(row, col), out );

			//If a solution has been found, increment solution num, print the solution, clear the current cell and set solved to false for any further loops
			if (solved) {

				solution_num++;

				print_solution(out);

				board[row][col] = BLANK;

				solved = false;

				continue;

			}
			//If its not solved then set the cell to BLANK
			if (!solved) {

				board[row][col] = BLANK;

			}

		}

	}

	return;

}


/* Wrapper function for solve
* @param out: The ostream for potential solutions to be printed to
*/
void Sudoku::solve(ostream& out) { solve(0, 0, out); }


/* Prints the current solution
* @param out: The ostream to print the solution to
*/
void Sudoku::print_solution(ostream& out) const {

	if (!solved) { throw exception("Attempted to output solution for unsolved puzzle"); }
	else {

		out << "Solution " << solution_num << std::endl << std::endl;

		for (unsigned int i = 0; i < SIZE; i++) {

			for (unsigned int j = 0; j < SIZE; j++) {

				out << board[i][j];

			}
			out << std::endl;
		}

		out << std::endl;

	}

	return;

}