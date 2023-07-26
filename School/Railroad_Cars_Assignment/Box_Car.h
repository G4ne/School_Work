#ifndef BOX_CAR_H
#define BOX_CAR_H

#include "Railroad_Car.h"

class Box_Car : public Railroad_Car {
public:

	//Constructor
	Box_Car(double = 0, double = 0, double = 0);

	//Getters
	double get_width() const;
	double get_height() const;

	//Setters
	void set_width(double);
	void set_height(double);

	//Class-member Function
	double volume();

protected:

	//Data Fields
	double width;
	double height;

};

#endif