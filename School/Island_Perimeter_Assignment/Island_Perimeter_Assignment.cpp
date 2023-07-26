#include <iostream>
#include<fstream>
#include <vector>

using namespace std;

int Calc_Perimeter(const vector<vector<unsigned int>>&);

int main() {
	
	//Open input file
	ifstream i_file;
	i_file.open("island.txt");

	//Check if file is open
	if (!i_file) {
		cout << "[Error] File not found" << endl;
		system("pause");
		return -1;
	}

	//Take in the dimensions of the 2-D vector
	unsigned int row_num;
	unsigned int col_num;
	i_file >> row_num >> col_num;

	/*Take in the 1's and 0's of the 2-D vector
	* temp_val is used to store the values
	* temp_val is then appended to the list at 'i' using .push_back
	*/
	vector<vector<unsigned int>> island(row_num);
	for (unsigned int i = 0; i < row_num; i++) {
		
		unsigned int temp_val;

		//loop reads and then pushes back the 1's and 0's
		for (unsigned int j = 0; j < col_num; j++) {
			i_file >> temp_val;
			island.at(i).push_back(temp_val);
		}

	}

	//Close input file
	i_file.close();

	//Create and open an output file
	ofstream o_file;
	o_file.open("perimeter.txt");

	//Pass 2-D vector island into perimeter calculation function, printing its return value to the o_file
	o_file << "Perimeter: " << Calc_Perimeter(island);

	//Close output file
	o_file.close();

	return 0;
}

/** Calculates the perimeter of a given 'island'
* @param isl_vec: const 2-D vector consisting of 1's and 0's, representing an island. Passed by reference
* @return: Calculated perimeter of the 'island'
*/

int Calc_Perimeter(const vector<vector<unsigned int>>& isl_vec) {

	//unsigned int object used to store the perimiter value
	unsigned int perim_count = 0;

	//loop that goes through each item and finds how many bordering 0's there are, adding a corresponding amount to perim_count
	for (int i = 0; i < isl_vec.size(); i++) {

		//object used to check for 0's and increment perim_count depending on how many 0's border the 'tile'
		unsigned int perim_add;

		for (int j = 0; j < isl_vec.at(i).size(); j++) {

			//perim_add starts as 4 to signify the 4 possible neighboring zeroes and the number is decreased if a one is detected
			perim_add = 4;

			//Checks if the current value is 0, continuing if there is no island
			if (isl_vec.at(i).at(j) == 0) { continue; }
			else {
				/*Runs an algorithm checking how many nearby 0's there are. if a one is detected, 1 is subtracted from perim_add
				* If one of the variables used for iteration is on an edge or a corner, it checks all spots except the edge
				* Comments below are showing where the execution must be for the branch to activate
				*/
				//Top Left Corner
				if (i == 0 && j == 0) {
					if (isl_vec.at(i).at(j + 1) != 0) { perim_add--; }
					if (isl_vec.at(i + 1).at(j) != 0) { perim_add--; }
				}
				//Bottom Right Corner
				else if (i == isl_vec.size() - 1 && j == isl_vec.at(i).size() - 1) {
					if (isl_vec.at(i).at(j - 1) != 0) { perim_add--; }
					if (isl_vec.at(i - 1).at(j) != 0) { perim_add--; }
				}
				//Bottom Left Corner
				else if (i == isl_vec.size() - 1 && j == 0) {
					if (isl_vec.at(i).at(j + 1) != 0) { perim_add--; }
					if (isl_vec.at(i - 1).at(j) != 0) { perim_add--; }
				}
				//Top Right Corner
				else if (i == 0 && j == isl_vec.at(i).size() - 1) {
					if (isl_vec.at(i).at(j - 1) != 0) { perim_add--; }
					if (isl_vec.at(i + 1).at(j) != 0) { perim_add--; }
				}
				//Anywhere along the top (that isn't in the corners)
				else if (i == 0) {
					if (isl_vec.at(i).at(j + 1) != 0) { perim_add--; }
					if (isl_vec.at(i).at(j - 1) != 0) { perim_add--; }
					if (isl_vec.at(i + 1).at(j) != 0) { perim_add--; }
				}
				//Anywhere along the bottom (that isn't in the corners)
				else if (i == isl_vec.size() - 1) {
					if (isl_vec.at(i).at(j - 1) != 0) { perim_add--; }
					if (isl_vec.at(i).at(j + 1) != 0) { perim_add--; }
					if (isl_vec.at(i - 1).at(j) != 0) { perim_add--; }
				}
				//Anywhere along the left (that isn't in the corners)
				else if (j == 0) {
					if (isl_vec.at(i).at(j + 1) != 0) { perim_add--; }
					if (isl_vec.at(i + 1).at(j) != 0) { perim_add--; }
					if (isl_vec.at(i - 1).at(j) != 0) { perim_add--; }
				}
				//Anywhere along the right (that isn't in the corners)
				else if (j == isl_vec.at(i).size() - 1) {
					if (isl_vec.at(i).at(j - 1) != 0) { perim_add--; }
					if (isl_vec.at(i - 1).at(j) != 0) { perim_add--; }
					if (isl_vec.at(i + 1).at(j) != 0) { perim_add--; }
				}
				//Everywhere else
				else {
					if (isl_vec.at(i).at(j - 1) != 0) { perim_add--; }
					if (isl_vec.at(i).at(j + 1) != 0) { perim_add--; }
					if (isl_vec.at(i - 1).at(j) != 0) { perim_add--; }
					if (isl_vec.at(i + 1).at(j) != 0) { perim_add--; }
				}

				//Adds whatever number is left in perim_add to perim_count
				perim_count += perim_add;
			}
		}

	}
	return perim_count;

}