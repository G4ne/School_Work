#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class Dynamic_Array {
public:
	//Constructors
	Dynamic_Array(); //Default
	

	//Operators
	const Dynamic_Array& operator = (const Dynamic_Array&); //Assignment Operator
	Dynamic_Array(const Dynamic_Array&); //Copy
	~Dynamic_Array(); //Destructor

	//Subscript Overloadings
	int& operator [] (size_t); //Lhs subscript operator
	const int& operator [] (size_t) const; //Rhs subscript operator

	//Class-member functions
	size_t size() const; //Returns size of the array
	bool empty() const; //Sees if the array is empty
	void push_back(int); //Pushes a number to the back of the array

private:
	//Data Fields
	static const size_t DEFAULT_CAPACITY;
	size_t capacity;
	size_t num_of_items;
	int* data;

	//Class-member functions
	void resize(); //Changes the capacity of the array
};

#endif