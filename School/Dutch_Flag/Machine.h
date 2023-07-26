#ifndef MACHINE_H
#define MACHINE_H

#include "Pixel.h"
#include <vector>

using std::vector;


/* Unscrambles a given (Dutch) flag
* @param flag: A vector of the pixels in the flag
*/
void unscramble(vector<Pixel>& flag) {

	//Create position variables
	unsigned int end_red = 0, current = 0, start_blue = flag.size() - 1;

	//Examine pixels and swap them based off colors
	while (!(current > start_blue)) {

		//Create temp value to hold pixel value while swapping
		Pixel temp;

		//Checks if the pixels are red, blue or white and processes them accordingly
		if (flag.at(current).get_color() == "red") {

			temp = flag.at(end_red);
			flag.at(end_red) = flag.at(current);
			flag.at(current) = temp;
			end_red++;
			current++;
		
		}
		else if (flag.at(current).get_color() == "blue") {

			temp = flag.at(start_blue);
			flag.at(start_blue) = flag.at(current);
			flag.at(current) = temp;
			start_blue--;

		}
		else { current++; }

	}

	return;

}

#endif