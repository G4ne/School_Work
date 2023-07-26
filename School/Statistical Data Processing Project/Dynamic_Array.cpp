#include "Dynamic_Array.h"

//Set default capacity
const unsigned int Dynamic_Array::DEFAULT_CAPACITY = 10;

//Default Constructor
Dynamic_Array::Dynamic_Array() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
	data = new double[capacity];
}

//Copy Constructor
Dynamic_Array::Dynamic_Array(const Dynamic_Array& rhs) {
	data = nullptr;
	*this = rhs;
}

//Destructor
Dynamic_Array::~Dynamic_Array() {
	if (data) {
		delete[] data;
		data = nullptr;
	}
}

//Assignment Operator Overloading
const Dynamic_Array& Dynamic_Array::operator = (const Dynamic_Array& rhs) {
	//Avoid Self-Assignment
	if (this != &rhs) {

		//Free up dynamic memory
		if (data) {
			delete[] data;
			data = nullptr;
		}
		
		//Copy Static Data
		capacity = rhs.capacity;
		num_of_items = rhs.num_of_items;

		//Deep-copy Dynamic Data
		if (rhs.data) {
			data = new double[capacity];
			for (unsigned int i = 0; i < capacity; i++) {
				data[i] = rhs.data[i];
			}
		}
	}

	//Return
	return *this;
}

//Lvalue Subscript Operator Overloading
const double& Dynamic_Array::operator [] (unsigned int index) const { return data[index]; }

//Rvalue Subscript Operator Overloading
double& Dynamic_Array::operator [] (unsigned int index) { return data[index]; }

/* Doubles the size of the dynamic array
* @return: None
*/
void Dynamic_Array::resize() {

	//Double the capacity and create a new dynamic array with given capacity
	capacity *= 2;
	double* new_data = new double[capacity];

	//Read all values from the original dynamic array into the new one
	for (unsigned int i = 0; i < num_of_items; i++) {
		new_data[i] = data[i];
	}

	//Free up the old dynamic array's memory and point data at the new array
	delete[] data;
	data = new_data;

}

/* Gives size of the dynamic array
* @return: The number of items in the array
*/
unsigned int Dynamic_Array::size() const { return num_of_items; }

/* Indicates whether the dynamic array is empty or not
* @return: Returns true if it is empty, false if not
*/
bool Dynamic_Array::empty() const { return !size(); }

/* Appends a double to the end of the dynamic array
* @param value: The double to be appended to the array
* @return: None
*/
void Dynamic_Array::push_back(double value) {

	//Determine if the array is at capacity and resize it if it is full
	if (num_of_items == capacity) { resize(); }

	//Append input value and increment num_of_items
	data[num_of_items++] = value;

}