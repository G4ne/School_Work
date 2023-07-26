#include "Generic_Item.h"
#include <iostream>
#include "Produce_Item.h"
#include "Fruit_Produce.h"
#include "Book_Item.h"

using namespace std;


int main() {

	// Derived Classes
	// ex: Generic Item class
	/* A generic item is any random item (in a grocery store for example)
	* A generic item would have a quantity and name if it were a grocery store item
	*/

	Generic_Item item_1("Hat", 10);

	item_1.print(std::cout);
	
	//When Creating a derived class you must use : public CLASS_NAME
	//public means the public of CLASS_NAME becomes the public of the created class
	//if you replace that with private, the public of CLASS_NAME becomes the private of the created class
	//When you use public CLASS_NAME you inherit everything (it will be imported) into the new class
	//This is called inheritance

	//After this, you cannot access the private data fields regardless
	//There are three ways to use those data fields
	//1. Use the Setters of the parent class
	//2. Instead of private, you can use 'protected' which is private but derived classes can access it too
	//3. Use the constructor of the base class (derived_item::derived_item(string something1, string something) : base_item(int some_num, unsigned int count), name(something1), name2(something2)

	/* Extra Facts
	* Any class can be a base class
	* NO changes to that class are required
	* The derived class is said to inherit all the properties of the base class (this is called inheritance)
	*/

	cout << endl;

	Produce_Item item_2("Eggplant", 50, "04/20/23");
	item_2.print(cout);

	//If you want to use the same function from the base class but you want to ALTER its functionality for the derived class, you must use OVERRIDING
	/* TO BE ABLE TO DO THIS, YOU MUST USE THE 'virtual' KEYWORD IN THE BASE FUNCTION DEFINITION
	* Afterwards, you just redefine the same function in the derived class and the redefined function will take precendence
	* Remember that you can use the base function to accomplish a part of the task and then add whatever you need (see print in Produce_Item.cpp)
	* The derived function must have all the same properties of the base function (return type, parameters, name, etc)
	*/

	/* Some extra examples
	* A derived class can be a base class for another different derived class
	*/

	cout << endl;

	Fruit_Produce item_3("Apple", 15, "04/20/23", true);
	item_3.print(cout);

	cout << endl;

	Book_Item item_4("C++ Programming", 5, "111000004353246");
	item_4.print(cout);


	//Polymorphism
	/* To use polymorphism, you MUST use pointers
	* Polymorphism is, distilled down, a pointer of the base-most class can be pointed to any of its derived classes
	* 
	* Example:
	* Generic_Item* item = nullptr;
	* 
	* item = new Generic_Item("Hat", 25);
	* delete item;
	* 
	* item = new Fruit_Produce("Apple", 20, true);
	* delete item;
	* 
	* item = new Book_Item("C++ Programming", 5, "14536897451423754");
	* delete item;
	* 
	* All of these definitons work
	* You need only ONE pointer to instantiate any derivations of a base class
	* This is called Polymorphism
	* 
	* This is important because sometimes we don't know the data type when we write the code
	* For example, the input file could contain the data type
	* Polymorphism can determine the data type at RUNTIME
	*/

	//You can also use polymorphism in vectors
	//A vector of Generic_Item* type can hold any type of derivative items (book, fruit, produce etc)

	//The differences between overloading and overriding are: 1. Overloaded functions must have the same name but different parameter types
	//2.Overridden functions take precedence over the base function with the same name and parameters
	//These two are bad reasons, use the below ones

	/* Differences between overloading and overriding
	* The compiler compiles code before running the program
	* In overloading, the program can see the function's parameters and compile the function differently if it sees one parameter type vs another
	* In overriding, the compiler does not know what which version to use at compilation time and so the overridden code is not compiled at compilation time
	* So, at compilation time, the compiler will place a mark at the point it cannot compile
	* Once execution hits this mark, the compiler is reawakened and it looks at the type needed based off what is already executed
	*/

	//The essence of overloading vs overriding is they are compiled at different time
	//Overloading is compiled at program compilation time
	//Overriding is compiled at program runtime

	//Abstract Classes
	/* An abstract class is a class that guides the design of derived class but cannot be instantiated
	* It is similar in philosophy to how humans abstract nature
	* Think a mammal, its an abstract concept that describes a lot of things, but is not a physical thing itself
	* 
	* An abstract class is a class that cannot be instantiated but serves as a guide for how derived classes are implemented
	* Abstract classes have PURE VIRTUAL functions which means they have no definition
	* Defined as: type FUNCTION_NAME = 0;
	* Also called abstraction functions
	* If a class has a pure virtual function, the entire class is abstract
	* 
	* A derived class of an abstract class MUST override all the pure virtual functions
	*/

	system("pause");
	return 0;
}