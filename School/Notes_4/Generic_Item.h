#ifndef GENERIC_ITEM_H
#define GENERIC_ITEM_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Generic_Item {

public:

	//Constructors
	Generic_Item(const string & = "", unsigned int = 0);

	//Getters
	string get_name() const;
	unsigned int get_quantity() const;

	//Setters
	void set_name(const string&);
	void set_quantity(unsigned int);

	//Class-member function
	virtual void print(ostream&) const; //Writes the item to an output stream

private:

	//Data Fields
	string name;
	unsigned int quantity;

};


#endif