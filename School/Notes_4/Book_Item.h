#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H

#include "Generic_Item.h"

class Book_Item : public Generic_Item {
public:

	//Constructor
	Book_Item(const string & = "", unsigned int = 0, const string & = "");

	//Getter
	string get_isbn() const;

	//Setter
	void set_isbn(const string&);

	//Class-member Function
	void print(ostream&) const;

private:

	//Data Field
	string isbn;

};

#endif