#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>

class Complex_Number {
public:

	//Constructor
	Complex_Number(int real = 0, int imaginary = 0);

	//Class-member functions
	Complex_Number operator + (const Complex_Number&) const;
	friend std::ostream& operator << (std::ostream&, const Complex_Number&);
	friend std::istream& operator >> (std::istream&, Complex_Number&);

private:
	
	//Data Fields
	int real;
	int imaginary;

};

#endif
