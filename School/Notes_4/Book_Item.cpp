#include "Book_Item.h"

//Constructor
Book_Item::Book_Item(const string& name, unsigned int num, const string& isbn) : Generic_Item(name, num), isbn(isbn) {}

//Getter
string Book_Item::get_isbn() const { return isbn; }

//Setter
void Book_Item::set_isbn(const string& isbn) { this->isbn = isbn; }

void Book_Item::print(ostream& out) const {
	Generic_Item::print(out);
	out << "ISBN: " << isbn << std::endl;
}