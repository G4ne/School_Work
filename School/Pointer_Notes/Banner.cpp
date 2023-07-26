#include "Banner.h"

//Assignment Operator
const Banner& Banner::operator=(const Banner& rhs) {
	//Step 1: Avoid self-assignment
	if (this != &rhs) {
		//Step 2: Release dynamic memory
		//Make sure there is dynamic memory
		if (text) {
			delete text;
			text = NULL;
		}

		//Step 3: Copy Static Data
		width = rhs.width;
		height = rhs.height;

		//Step 4: Copy Dynamic Data (Make sure there is dynamic data to copy)
		if (rhs.text) {
			text = new string(*rhs.text);
		}
	}
	return *this;
}

//Copy Constructor
Banner::Banner(const Banner& other) {
	text = NULL;
	*this = other;
}

//Destructor (This is automatically called when the object is going out of scope)
Banner::~Banner() {
	if (text) {
		delete text;
	}
}