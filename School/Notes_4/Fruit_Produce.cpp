#include "Fruit_Produce.h"

//Constructor
Fruit_Produce::Fruit_Produce(const string& name, unsigned int num, const string& exp, bool seed) : Produce_Item(name, num, exp), has_seed(seed) {}

//Getter
bool Fruit_Produce::get_has_seed() const { return has_seed; }

//Setter
void Fruit_Produce::set_has_seed(bool seed) { has_seed = seed; }

//Print
void Fruit_Produce::print(ostream& out) const {
	Produce_Item::print(out);
	out << "Has Seed: " << (has_seed ? "True" : "False") << std::endl;
}