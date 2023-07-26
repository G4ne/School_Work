#include <iostream>
#include "Bag.h"
#include <fstream>
#include <string>

using std::endl;

int main() {

	//Open input file
	std::ifstream in("bags.txt");

	//Check if input file opened correctly
	if (!in) {
		std::cout << "[Error] Input file not found" << endl;
		system("pause");
		return -1;
	}

	//Open output file
	std::ofstream out("results.txt");

	//Create variables for input bag size and type
	unsigned int bag_size;
	std::string type;

	//Parse input file, outputting maxes to the output file as it goes
	while (in >> type >> bag_size) {

		//Determine the type of bag needed, fill the bag, and output its max to the output file
		if (type == "string") {

			Bag<std::string> new_bag(bag_size);

			for (unsigned int i = 0; i < bag_size; i++) {

				std::string temp_data;
				in >> temp_data;
				new_bag.push(temp_data);

			}

			out << new_bag.max() << endl;
		}
		else if (type == "double") {

			Bag<double> new_bag(bag_size);

			for (unsigned int i = 0; i < bag_size; i++) {

				double temp_data;
				in >> temp_data;
				new_bag.push(temp_data);

			}

			out << new_bag.max() << endl;
		}
		else {

			Bag<int> new_bag(bag_size);

			for (unsigned int i = 0; i < bag_size; i++) {

				int temp_data;
				in >> temp_data;
				new_bag.push(temp_data);

			}

			out << new_bag.max() << endl;
		}

	}

	//Close Files
	in.close();
	out.close();

	return 0;
}