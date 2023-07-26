#ifndef BAG_H
#define BAG_H

template<class Generic_Type>
class Bag {

public:

	//Default Constructor
	Bag(unsigned int);

	//Copy Constructor
	Bag(const Bag&);

	//Destructor
	~Bag();

	//Class-member Functions
	bool empty() const;
	unsigned int size() const;
	void push(Generic_Type&);
	Generic_Type max() const;

	//Deep-Copy Assignment Operator
	const Bag& operator = (const Bag&);

private:

	//Data Fields
	const unsigned int bag_size;
	unsigned int num_of_items;
	Generic_Type* data;

};

//Implementation

//Default Constructor
template<class Generic_Type>
Bag<Generic_Type>::Bag(unsigned int size) : bag_size(size), num_of_items(0) {
	
	data = new Generic_Type[bag_size];

}

//Copy Constructor
template<class Generic_Type>
Bag<Generic_Type>::Bag(const Bag& rhs) {
	data = nullptr;
	this = *rhs;
}

//Destructor
template<class Generic_Type>
Bag<Generic_Type>::~Bag() {
	if (data) { delete[] data; }
}

//Deep-Copy Assignment Operator
template<class Generic_Type>
const Bag<Generic_Type>& Bag<Generic_Type>::operator = (const Bag& rhs) {

	//Avoid Self-Assignment
	if (this != &rhs) {
	
		//Clear Dynamic Memory
		if (data) {
			delete[] data;
			data = nullptr;
		}

		//Copy Static Data
		num_of_items = rhs.num_of_items;
		bag_size = rhs.bag_size;

		//Copy Dynamic Data
		if (num_of_items <= bag_size) {
			data = new Generic_Type[bag_size];
				for (unsigned int i = 0; i < num_of_items; i++) {
					data[i] = rhs.data[i];
				}
		}

	}

	//Return
	return *this;

}

/* Tells if the bag is empty
* @return: Returns true if the bag is empty, false otherwise
*/
template<class Generic_Type>
bool Bag<Generic_Type>::empty() const { return !num_of_items; }

/* Returns the number of items in the bag
* @return: The number of items in the bag
*/
template<class Generic_Type>
unsigned int Bag<Generic_Type>::size() const { return num_of_items; }

/* Places an item into the bag
* @param item: The item to be added to the bag
*/
template<class Generic_Type>
void Bag<Generic_Type>::push(Generic_Type& item) {

	data[num_of_items] = item;
	num_of_items++;
	return;

}

/* Returns the largest item in the bag
* @return: The largest item in the bag
*/
template<class Generic_Type>
Generic_Type Bag<Generic_Type>::max() const {

	Generic_Type largest_seen = data[0];

	for (unsigned int i = 0; i < num_of_items; i++) {

		if (data[i] > largest_seen) { largest_seen = data[i]; }

	}

	return largest_seen;

}

#endif