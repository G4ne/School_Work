#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class Dynamic_Array {
public:

	//Default Constructor
	Dynamic_Array();

	//Copy Constructor
	Dynamic_Array(const Dynamic_Array&);
	
	//Destructor
	~Dynamic_Array();

	//Overloaded Operators
	const Dynamic_Array& operator = (const Dynamic_Array&); //Assignment Operator
	const unsigned int& operator [] (size_t) const; //Rvalue Subscript Operator
	unsigned int& operator [] (size_t); //Lvalue Subscript Operator

	//Class-member Functions
	unsigned int size() const;
	bool empty() const;
	void push_back(unsigned int);
	void pop_back();

private:

	//Data Fields
	static const unsigned int DEFAULT_CAPACITY;
	unsigned int capacity;
	unsigned int num_of_items;
	unsigned int* data;

	//Class-member Function
	void resize();

};

#endif