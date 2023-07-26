#include "Dynamic_Array.h"

const unsigned int Dynamic_Array::DEFAULT_CAPACITY = 10;

//Default Constructor
Dynamic_Array::Dynamic_Array() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
	data = new unsigned int[DEFAULT_CAPACITY];
}

/* Overloads Assignment Operator
* @param other: The dynamic array being copied
* @return: The dynamic array with all its data copied over from the rhs dynamic array
*/
const Dynamic_Array& Dynamic_Array::operator = (const Dynamic_Array& other) {
	
	//Avoid Self-Assignment
	if (this != &other) {
		
		//Release Dynamic Memory and assign it to a safe value
		if (data) {
			delete[] data;
			data = nullptr;
		}

		//Copy Static Data
		capacity = other.capacity;
		num_of_items = other.num_of_items;

		//Copy Dynamic Data
		if (other.data) {
			data = new unsigned int[capacity];
			for (unsigned int i = 0; i < other.num_of_items; i++) {
				data[i] = other.data[i];
			}
		}

	}

	//Return
	return *this;
}

//Destructor
Dynamic_Array::~Dynamic_Array() {
	if (data) { delete[] data; }
}

//Copy Constructor
Dynamic_Array::Dynamic_Array(const Dynamic_Array& other) {
	data = nullptr;
	*this = other;
}

/* Overloads the Lvalue Subscript operator
* @param index: The index of the value to be retrieved
* @return: The value at a given index
*/
unsigned int& Dynamic_Array::operator [] (size_t index) { return data[index]; }

/* Overloads the Rvalue Subscript operator
* @param index: The index of the given value to be retrieved
* @return: The value at the given index
*/
const unsigned int& Dynamic_Array::operator [] (size_t index) const { return data[index]; }

//Doubles the size of the dynamic array
void Dynamic_Array::resize() {

	//Doubles capacity and creates a new dynamic array with the doubled capacity
	capacity *= 2;
	unsigned int* new_data = new unsigned int[capacity];

	//Iterates through and copies data's items into new_data
	for (unsigned int i = 0; i < num_of_items; i++) {
		new_data[i] = data[i];
	}

	//Frees up data's old dynamic memory and assigns it to new_data's doubled dynamic array
	delete[] data;
	data = new_data;
}

/* Gives the number of items in the dynamic array
* @return: The num_of_items in the dynamic array
*/
unsigned int Dynamic_Array::size() const { return num_of_items; }

/* Returns true if the dynamic array is empty, false if not
* @return: Returns true if the array is empty, false otherwise
*/
bool Dynamic_Array::empty() const { return !size(); }

/* Places an int at the end of the array
* @param num: The number to be appended to the dynamic array
* @return: None
*/
void Dynamic_Array::push_back(unsigned int num) {

	//Checks to see if the dynamic array is at capacity, and doubles its size if it is
	if (num_of_items == size()) { resize(); }

	//Places the number after the last item in the dynamic array and increments num_of_items
	data[num_of_items++] = num;

}

// Deletes the last value in the dynamic array
void Dynamic_Array::pop_back() {

	//Decrements num_of_items, effectively deleting the value because any future 'push_back's will overwrite the value in the spot
	num_of_items--;

}