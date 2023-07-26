#include "Dish.h"
#include <iostream>
#include <fstream>
#include <vector>

//Includes string if its not already included
#ifndef string
#include <string>
#endif

//Set up constructor
Dish::Dish(const std::string& name, unsigned int type, unsigned int price) : dish_name(name), dish_type(type), dish_price(price) {}

//Set up Getters
std::string Dish::get_dish_name() const { return dish_name; }
unsigned int Dish::get_dish_type() const { return dish_type; }
unsigned int Dish::get_dish_price() const { return dish_price; }

//Set up Setters
void Dish::set_dish_name(const std::string& new_name) { dish_name = new_name; }
void Dish::set_dish_type(unsigned int new_type) { dish_type = new_type; }
void Dish::set_dish_price(unsigned int new_price) { dish_price = new_price; }

//Set up class-member function
void Dish::print_dish(std::ostream& out) const {
	out << dish_name << " ($" << dish_price << ")" << std::endl;
}

using namespace std;

void print_vector(const vector<Dish>&, ostream&);

int main() {

	//Create input file stream and open input file
	ifstream input;
	input.open("dishes.txt");

	//Check if input file was correctly found and opened
	if (!input) {
		cout << "[Error] Input File Not Found" << endl;
		system("pause");
		return -1;
	}

	//Create temp objects for reading data from input file and the vectors to store each type of dish
	string temp_type, temp_name;
	unsigned int temp_price;
	vector<Dish> appetizer, entree, dessert;

	//Loop reading in the data from input file and appending dish objects to their appropriate vector with the data input
	while (input >> temp_type >> temp_price && getline(input, temp_name)) {

		/*Branches to trim string if there is leading or trailing spaces
		* Read as: if the first or last character is not alphanumeric, erase all whitespace to the left of the first char and right of the last char
		*/
		if (!isalpha(temp_name.at(0))) {
			temp_name.erase(0, temp_name.find_first_not_of(" \t\n"));
		}
		if (isalpha(temp_name.at(temp_name.size() - 1))) {
			temp_name.erase(temp_name.find_last_not_of(" ") + 1);
		}

		//For-loop to make every dish type name lowercase
		for (unsigned int i = 0; i < temp_type.size() - 1; i++) {
			temp_type.at(i) = tolower(temp_type.at(i));
		}

		//If-statements checking what type of dish object is being created and appending a dish object to its corresponding vector
		if (temp_type == "appetizer") {
			appetizer.push_back( Dish(temp_name, 0, temp_price));
		}
		else if (temp_type == "entree") {
			entree.push_back(Dish(temp_name, 1, temp_price));
		}
		else {
			dessert.push_back(Dish(temp_name, 2, temp_price));
		}
	}

	//Close input file
	input.close();

	//Create and open output file
	ofstream output_menu;
	output_menu.open("menu.txt");

	//Print menu to file
	output_menu << "Menu" << endl << endl;

	output_menu << "Appetizer" << endl << endl;
	print_vector(appetizer, output_menu);

	output_menu << endl << "Entree" << endl << endl;
	print_vector(entree, output_menu);

	output_menu << endl << "Dessert" << endl << endl;
	print_vector(dessert, output_menu);
	output_menu << endl;

	//Close output file
	output_menu.close();

	return 0;
}

/*Function Used to print all of the items in a given vector
* @param category: This describes the category of the vector of Dishes; appetizer, entree or dessert
* @param ostrm: Takes an output stream that the vector is to be output to
* @return void: Because it is used to print to an output stream, nothing is returned
*/
void print_vector(const vector<Dish>& category, ostream& ostrm) {
	for (unsigned int i = 0; i < category.size(); i++) {
		category.at(i).print_dish(ostrm);
	}
}