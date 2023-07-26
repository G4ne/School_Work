#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	//Create ifstream object for input image file
	ifstream inp_image;

	//Open and check the integrity of the input image file
	inp_image.open("color_image.ppm");
	if (!inp_image) {
		cout << "[Error] Image file not found" << endl;
		system("pause");
		return -1;
	}

	//Create holding variables for the first four values
	string skip1, skip2;
	unsigned int dimensions1, dimensions2;

	//Grab first four lines, effectively skipping them. Image dimensions are stored for later use while everything else is discarded
	inp_image >> skip1 >> dimensions1 >> dimensions2 >> skip2;

	//Create ofstream object and open the output file
	ofstream output_file;
	output_file.open("grayscale_image.ppm");

	//Write precursor info to output ppm, such as P3, dimensions and 255
	output_file << "P3" << endl << dimensions1 << " " << dimensions2 << endl << 255 << endl;

	//Create unsigned int objects to store the colored pixel values and and gray pixel value
	unsigned int red_pix, green_pix, blue_pix, gray_value;

	/* Loop that runs while there is a red, green, and blue pixel to input
	 * Converts those pixel values into a singular gray value.
	 * That value is then output three times in place of a red / green / blue value
	 */
	while (inp_image >> red_pix >> green_pix >> blue_pix) {
		gray_value = (0.3 * red_pix) + (0.59 * green_pix) + (0.11 * blue_pix);

		output_file << gray_value << endl << gray_value << endl << gray_value << endl;
	}

	//Close Files
	inp_image.close();
	output_file.close();

	return 0;
}