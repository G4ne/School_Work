#include "Generic_Item.h"


//Constructor
Generic_Item::Generic_Item(const string& name, unsigned int quantity) : name(name), quantity(quantity) {}


//Getters
string Generic_Item::get_name() const { return name; }

unsigned int Generic_Item::get_quantity() const { return quantity; }


//Setters
void Generic_Item::set_name(const string& name) {
	this->name = name;
}

void Generic_Item::set_quantity(unsigned int num) {
	quantity = num;
}

//Writes the item to an output stream
void Generic_Item::print(ostream& out) const {
	out << "Name: " << name << std::endl;
	out << "Quantity: " << quantity << std::endl;
}