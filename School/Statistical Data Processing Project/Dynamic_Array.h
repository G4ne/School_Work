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

	//Operator Overloadings
	const Dynamic_Array& operator = (const Dynamic_Array&); //Deep Copy Assignment
	const double& operator [] (unsigned int) const; //Lvalue Subscript
	double& operator [] (unsigned int); //Rvalue Subscript

	//Class-member Functions
	unsigned int size() const;
	bool empty() const;
	void push_back(double);

private:

	//Data Fields
	static const unsigned int DEFAULT_CAPACITY;
	unsigned int capacity;
	unsigned int num_of_items;
	double* data;

	//Class-member Functions
	void resize();

};

#endif