#include "Tank_Car.h"
#include <cmath>

//Constructor
Tank_Car::Tank_Car(double length, double radius) : radius(radius) { this->length = length; }

//Getter
double Tank_Car::get_radius() const { return radius; }

//Setter
void Tank_Car::set_radius(double radius) { this->radius = radius; }

/* Calculates the volume of the Tank car
* @return: Returns thr volume of the Tank car
*/
double Tank_Car::volume() {
	return ((4 * atan(1)) * pow(radius, 2) * length);
}