#include "Complex_Number.h"

/** Constructor (default values set in .h file
* @param i: The value to assign the real number to
* @param j: The value to assign the imaginary number to
*/
Complex_Number::Complex_Number(int i, int j) : real(i), imaginary(j) {}

/** Overloading the + operator
* @param rhs: The right-hand-side complex number to be added
* @return Complex_Number: Returns the sum of the two complex numbers
*/
Complex_Number Complex_Number::operator + (const Complex_Number& rhs) const {
	
	Complex_Number result((real + rhs.real), (imaginary + rhs.imaginary));
	
	return result;

}

/** Overloading the stream insertion operator
* @param out: Takes the reference of an output stream
* @param com_num: Takes a const reference of the complex number being output
* @return ostream&: Returns the ostream that is output to
*/
std::ostream& operator << (std::ostream& out, const Complex_Number& com_num) {

	out << com_num.real << "\t" << com_num.imaginary;

	return out;

}

/** Overloading the stream extraction operator
* @param in: Takes the reference of an insertion stream
* @param com_num: Takes the reference of a complex number that the input values are being assigned to
* @return istream&: Returns the istream the inputs were extracted from
*/
std::istream& operator >> (std::istream& in, Complex_Number& com_num) {

	in >> com_num.real >> com_num.imaginary;

	return in;

}