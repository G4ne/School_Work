#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int body_mass_calc(vector<unsigned int>&);

int main() {

	//Create an input stream variable and open the input file
	ifstream input;
	input.open("masses.txt");

	//Check to see if input file was opened successfully
	if (!input) {
		cout << "[Error] File does not exist" << endl;
		system("pause");
		return -1;
	}

	//Create vector to hold input values and a temp variable to hold values (to be appended to vector)
	vector<unsigned int> asteroids;
	unsigned int asteroid_temp;

	//Take input from file, place that into the temp value and then append that to asteroids vector
	while (input >> asteroid_temp) {
		asteroids.push_back(asteroid_temp);
	}

	//Close input file
	input.close();

	//Pass the asteroid vector into body_mass_calc, taking the returned value into body_mass
	unsigned int body_mass = body_mass_calc(asteroids);

	//Create and open an output file stream, writing the final celestial body mass to it
	ofstream output;
	output.open("result.txt");
	output << body_mass;

	//Close the output file
	output.close();

	return 0;
}


/** Calculates the minimum mass of a celestial body to destroy all asteroids in a given asteroid vector
* @param ast_vec: a vector of unsigned int objects that represent asteroids, passed by reference
* @return body_mass: returns the minimum mass the celestial body needs to be to destroy all asteroids
*/
unsigned int body_mass_calc(vector<unsigned int>& ast_vec) {

	//Sort the vector, smallest to largest
	sort(ast_vec.begin(), ast_vec.end());

	//Declare an unsigned int representing the minimum mass of the celestial body and a bool to determine if it destroys all astroids for use in a while-loop
	unsigned int body_mass = 0;
	bool destroys_all = false;

	/* Continuously loop a for-loop while destroys_all is false
	*  body_mass_temp is a temp object for testing a given body_mass and i is used to iterate through asteroids
	*  The for-loop checks the current body_mass_temp against each iterated item in the asteroids vector
	*  The for-loop is broken if body_mass_temp is <= the given asteroids vector item
	*  After the for-loop, if the iterator got to the end then the celestial body successfully destroyed all asteroids. Subsequently destroys_all is made true, effectively ending the loop
	*  If the for-loop was broken then the iterator cannot be at the end which causes body_mass to be incremented
	*/
	while (!destroys_all) {

		unsigned int body_mass_temp = body_mass;
		vector<unsigned int>::iterator i;

		for (i = ast_vec.begin(); i != ast_vec.end(); i++) {

			if (body_mass_temp <= *i) { break; }
			else { body_mass_temp += *i; }
		}

		if (i == ast_vec.end()) { destroys_all = true; }
		else { body_mass++; }

	}

	return body_mass;
}