#include "Dynamic_Array.h"

//Default Capacity
const size_t Dynamic_Array::DEFAULT_CAPACITY = 10;

//Default Constructor
Dynamic_Array::Dynamic_Array() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
	data = new int[DEFAULT_CAPACITY];
}

//Assignment Operator Overloading
const Dynamic_Array& Dynamic_Array::operator = (const Dynamic_Array& rhs) {

	//Avoid Self Assignment
	if (this == &rhs) {
		
		//Release Dynamic Memory
		if (data) {
			delete[] data;
			data = nullptr;
		}
	}
	

	//Copy Static Data
	capacity = rhs.capacity;
	num_of_items = rhs.num_of_items;

	//Copy Dynamic Data
	if (capacity) {

		data = new int[capacity];
		for (size_t i = 0; i < num_of_items; i++) {
			data[i] = rhs.data[i];
		}

	}
	//Return
	return *this;

}

//Copy Constructor
Dynamic_Array::Dynamic_Array(const Dynamic_Array& other) {
	data = nullptr;
	*this = other;
}

//Destructor
Dynamic_Array::~Dynamic_Array() {
	if (data) {
		delete[] data;
	}
}

//Lhs subscript operator
int& Dynamic_Array::operator[] (size_t index) {
	return data[index];
}

//Rhs subscript operator
const int& Dynamic_Array::operator[] (size_t index) const {
	return data[index];
}

//Returns the size of the dynamic array
size_t Dynamic_Array::size() const {
	return num_of_items;
}

//Sees if the array is empty
bool Dynamic_Array::empty() const {
	return !size();
}

//Double's capacity and keeps the data unchanged
void Dynamic_Array::resize() {
	capacity *= 2;
	int* new_data = new int[capacity];
	for (size_t i = 0; i < num_of_items; i++) {
		new_data[i] = data[i];
	}
	delete[] data;
	data = new_data;
}

//Appends an element to the back
void Dynamic_Array::push_back(int num) {
	if (num_of_items == capacity) { resize(); }
	data[num_of_items++] = num;
}
