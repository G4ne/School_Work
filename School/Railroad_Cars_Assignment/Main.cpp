#include "Railroad_Car.h"
#include "Box_Car.h"
#include "Tank_Car.h"
#include "Refrigerator_Car.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	//Create and open input file
	ifstream in("cars.txt");

	if (!in) {
		cout << "[Error] Input file not found" << endl;
		system("pause");
		return -1;
	}

	//Create and open output file
	ofstream out("volumes.txt");

	//Create variables to store the railroad car and data about it
	Railroad_Car* car = nullptr;
	string type;
	double length, width, height, radius;
	int temperature;

	//Set the precision to which the following volume calculations will be printed to
	out << fixed << setprecision(2);

	//Read in each car, parsing its info and taking in more input as required before outputting the volume of the car to the output file
	while (in >> type) {

		if (type == "Box") {

			in >> length >> width >> height;

			car = new Box_Car(length, width, height);

		}
		else if (type == "Tank") {

			in >> length >> radius;

			car = new Tank_Car(length, radius);

		}
		else if (type == "Refrigerator") {

			in >> length >> width >> height >> temperature;

			car = new Refrigerator_Car(length, width, height, temperature);

		}

		out << car->volume() << endl;

		delete car;
		car = nullptr;
	}

	in.close();
	out.close();

	return 0;
}