#include "Box_Car.h"

//Constructor
Box_Car::Box_Car(double length, double width, double height) : width(width), height(height) { this->length = length; }

//Getters
double Box_Car::get_width() const { return width; }
double Box_Car::get_height() const { return height; }

//Setters
void Box_Car::set_width(double width) { this->width = width; }
void Box_Car::set_height(double height) { this->height = height; }

/* Calculates Volume of the Car
* @return: Returns the volume of the Box Car
*/
double Box_Car::volume() { return (get_length() * width * height); }