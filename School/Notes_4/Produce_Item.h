#ifndef PRODUCE_ITEM_H
#define PRODUCE_ITEM_H

#include "Generic_Item.h"

class Produce_Item : public Generic_Item {
public:

	//Constructor
	Produce_Item(const string& = "", unsigned int = 0, const string& = "");

	//Getter
	string get_expiration_date() const;

	//Setter
	void set_expiration_date(const string&);

	//Class-member Function
	virtual void print(ostream&) const;

private:

	//Data Fields
	string expiration_date;

};

#endif