#include "Dynamic_Array.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	//Create ifstream and open the input file
	ifstream in("commands.txt");

	//Test to make sure the input file opens correctly
	if (!in) {
		cout << "[Error] Input File not Found" << endl;
		system("pause");
		return -1;
	}

	//Create the dynamic array and data fields to store the Command ID, Command, and any potential values to be appended
	Dynamic_Array array;
	unsigned int CID;
	string command;
	int user_input;

	//Create ofstream, open the output file, and write the initial line to it
	ofstream out("invalid.txt");
	out << "INVALID COMMANDS" << endl;

	//Loop through the input file, parsing commands
	while (in >> CID >> command) {

		if (command == "PUSH") {
			
			//Takes extra input if the command is PUSH
			in >> user_input;

			//Checks if the input is valid, appending it to the array if it is and writing the command's ID to the output file if it is not
			if (user_input > 0) { array.push_back(user_input); }
			else { out << CID << endl; }

		}
		else {
	
			//Checks if the array has any values to be popped, writing the command's ID to the output file if there are none
			if (!array.empty()) { array.pop_back(); }
			else { out << CID << endl; }

		}

	}

	//Close the input and output files
	in.close();
	out.close();

	return 0;
}