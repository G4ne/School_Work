#include "Produce_Item.h"

//Constructor
Produce_Item::Produce_Item(const string& name, unsigned int num, const string& expir) : Generic_Item(name, num), expiration_date(expir) {}


//Getter
string Produce_Item::get_expiration_date() const { return expiration_date; }

//Setter
void Produce_Item::set_expiration_date(const string& date) { expiration_date = date; }

//Outputs a produce item's details to an output stream
void Produce_Item::print(ostream& out) const {
	Generic_Item::print(out);
	out << "Expiration Date: " << expiration_date << std::endl;
}
