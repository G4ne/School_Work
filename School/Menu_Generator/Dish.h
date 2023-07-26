#ifndef DISH_H
#define DISH_H

#include <string>

class Dish {
public:

	//Constructor
	Dish(const std::string& = "", unsigned int = 0, unsigned int = 0);

	//Getters
	std::string get_dish_name() const;
	unsigned int get_dish_type() const;
	unsigned int get_dish_price() const;

	//Setters
	void set_dish_name(const std::string&);
	void set_dish_type(unsigned int);
	void set_dish_price(unsigned int);

	//Class-member Functions
	void print_dish(std::ostream&) const;

private:

	//Data Fields
	std::string dish_name;
	unsigned int dish_type;
	unsigned int dish_price;

};

#endif