#include "Refrigerator_Car.h"

//Constructor
Refrigerator_Car::Refrigerator_Car(double length, double width, double height, int temp) : temperature(temp) {
	this->length = length;
	this->height = height;
	this->width = width;
}

//Getter
int Refrigerator_Car::get_temperature() const { return temperature; }

//Setter
void Refrigerator_Car::set_temperature(int temperature) { this->temperature = temperature; }