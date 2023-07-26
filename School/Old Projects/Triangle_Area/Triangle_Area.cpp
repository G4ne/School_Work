#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {


	//Declare variables
	double side_1, side_2, side_3, area;
	ifstream inTri;
	ofstream outTri;


	//Open input file and check if the opening went smoothly, printing to console and returning -1 if there was an error
	inTri.open("triangles.txt");
	if (!inTri.good()) {
		cout << "Input File failed to open." << endl;

		system("pause");

		return -1;
	}

	//Open or create output file
	outTri.open("areas.txt");


	// While there is three inputs, the loop will grab them and run
	while (inTri >> side_1 >> side_2 >> side_3) {

		//Check Triangle inequalities
		if (!((side_1 + side_2) > side_3)) {
			outTri << "Invalid triangle" << endl;
			continue;
		} 
		else if (!((side_2 + side_3) > side_1)) {
			outTri << "Invalid triangle" << endl;
			continue;
		}
		else if (!((side_1 + side_3) > side_2)) {
			outTri << "Invalid triangle" << endl;
			continue;
		}

		//Initialize variable for S in Heron's formula
		double halfPerim = ((side_1 + side_2 + side_3) / 2);

		//Calculate area using Heron's formula
		area = sqrt(halfPerim * (halfPerim - side_1) * (halfPerim - side_2) * (halfPerim - side_3));

		//Write calculated area to output file
		outTri << setprecision(2) << fixed << area << endl;

	}

	//Close files
	inTri.close();
	outTri.close();

	return 0;
}