#ifndef TANK_CAR_H
#define TANK_CAR_H

#include "Railroad_Car.h"

class Tank_Car : public Railroad_Car {
public:

	//Constructor
	Tank_Car(double = 0, double = 0);

	//Getter
	double get_radius() const;

	//Setter
	void set_radius(double);

	//Class-member Function
	double volume();

private:

	//Data Fields
	double radius;

};

#endif