#include "Pixel.h"

using std::ostream;
using std::istream;
using std::string;

//Default Constructor
Pixel::Pixel() : red(0), green(0), blue(0) {}


/* Gives the color of the pixel in string form
* @return: A string describing the color of the pixel
*/
string Pixel::get_color() const {

	switch (red) {

	case 169:
		return "red";
		break;

	case 255:
		return "white";
		break;

	case 30:
		return "blue";
		break;

	}

}


//Stream Insertion Operator
ostream& operator << (ostream& out, const Pixel& pixel) {

	out << pixel.red << '\t' << pixel.green << '\t' << pixel.blue;

	return out;

}

//Stream Extraction Operator
istream& operator >> (istream& in, Pixel& pixel) {

	in >> pixel.red >> pixel.green >> pixel.blue;

	return in;

}