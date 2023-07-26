#ifndef REFRIGERATOR_CAR_H
#define REFRIGERATOR_CAR_H

#include "Box_Car.h"

class Refrigerator_Car : public Box_Car {
public:

	//Constructor
	Refrigerator_Car(double = 0, double = 0, double = 0, int = 0);

	//Getter
	int get_temperature() const;

	//Setter
	void set_temperature(int);

protected:

	//Data Field
	int temperature;

};

#endif