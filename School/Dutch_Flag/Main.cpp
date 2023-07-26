#include "Pixel.h"
#include "Machine.h"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;

int main() {

	//Open input file
	ifstream in("scrambled_flag.ppm");

	//Check input file opened correctly
	if (!in) {

		std::cout << "[Error] Input file not found" << endl;
		system("pause");
		return -1;

	}

	//Open / Create Output file
	ofstream out("unscrambled_flag.ppm");

	//Create objects to hold the header info, the vector for the pixels and a temp value to hold the pixel info before it is pushed back
	string p3;
	unsigned int width, height, color_depth;
	vector<Pixel> flag;
	Pixel temp;

	//Read in header info
	in >> p3 >> width >> height >> color_depth;

	//Read pixels in and place them into the vector
	while (in >> temp) { flag.push_back(temp); }

	//Unscramble the flag
	unscramble(flag);

	//Write the header info and flag to the output file
	out << p3 << endl << width << '\t' << height << endl << color_depth << endl;
	for (size_t i = 0; i < flag.size(); i++) { out << flag.at(i) << endl; }

	//Close files
	in.close();
	out.close();

	return 0;
}