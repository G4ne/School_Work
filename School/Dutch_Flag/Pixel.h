#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <string>

class Pixel {

public:

	//Default Constructor
	Pixel();

	//Class-member Function
	std::string get_color() const;

	//Overloaded Operators
	friend std::ostream& operator << (std::ostream&, const Pixel&); //Stream Insertion Operator
	friend std::istream& operator >> (std::istream&, Pixel&); //Stream Extraction Operator

private:

	//Data Fields
	unsigned int red;
	unsigned int green;
	unsigned int blue;

};

#endif