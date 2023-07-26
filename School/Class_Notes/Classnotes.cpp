#include <iostream>
#include "Classnotes.h"

using namespace std;

unsigned int Rectangle::area() const {
	return width * height;
}

unsigned int Rectangle::perimeter() const {
	return width + width + height + height;
}

unsigned int Rectangle::get_width() const {
	return width;
}

unsigned int Rectangle::get_height() const {
	return height;
}

void Rectangle::set_width(unsigned int new_width) {
	width = new_width;
}

void Rectangle::set_height(unsigned int new_height) {
	height = new_height;
}

//Default Constructor Acceptable Usage
Rectangle::Rectangle() {
	width = 0;
	height = 0;
}

//Better usage of default constructor
Rectangle::Rectangle() : width(0), height(0) {}

//Using overloaded constructor
Rectangle::Rectangle(unsigned int width, unsigned int height) : width(width), height(height) {}

bool Rectangle::is_square() const {
	return width == height;
}

bool Rectangle::is_smaller_than(const Rectangle& rect) const {
	return area() < rect.area();
}

int main() {

	Rectangle rect;

	

	system("pause");
	return 0;
}