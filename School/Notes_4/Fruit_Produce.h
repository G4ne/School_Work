#ifndef FRUIT_PRODUCE_H
#define FRUIT_PRODUCE_H

#include "Produce_Item.h"

class Fruit_Produce : public Produce_Item {

public:

	//Constructor
	Fruit_Produce(const string & = "", unsigned int = 0, const string & = "", bool = false);

	//Getter
	bool get_has_seed() const;

	//Setter
	void set_has_seed(bool);

	//Class-member Function
	void print(ostream&) const;

private:

	//Data Field
	bool has_seed;

};

#endif