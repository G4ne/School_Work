#ifndef CLASSNOTES_H
#define CLASSNOTES_H

/*You need to include the titles for each section in both private and public sections
* Constructors
* Getters
* Setters
* Class-member Functions
*/

class Rectangle {
public:

	//Constructors (do not have a return type and the name matches the class name)
	Rectangle(); //Default Constructor
	Rectangle(unsigned int, unsigned int); //Overloading Constructor
	Rectangle(unsigned int = 0, unsigned int = 0); //Combines Default and Overloaded Constructor | THIS SHOULD BE USED PRIMARILY

	//Data Fields should not be put in here by convention (usually)
	unsigned int area() const;
	unsigned int perimeter() const;

	//As seen above, functions are public and data fields are private so we need functions to access and modify the private data fields

	//Getters
	unsigned int get_width() const;
	unsigned int get_height() const;

	//Setters
	void set_width(unsigned int);
	void set_height(unsigned int);

	//Functions
	bool is_square() const;

	bool is_smaller_than(const Rectangle&) const;

	//Static Variables belong to all class objects and changing one will cause all instances of it to change. Should be public
	static unsigned int sides;

	//Static Functions can be made but can only call static variables and other static functions
	static unsigned int function_thing(unsigned int);

	//Friend functions/classes allow a function or class to access the private section of the originating class (not the friend)
	//Since there is no other classes or functions defined, this is how its defined (in comment form)
	/* friend class Other_class */
	/* friend [return type] Some_Function() */

	//Friend Functions are non-class-member functions even though they are inside the class and CANNOT BE STATIC OR CONST

private:

	//Data Fields should be put here
	unsigned int width;
	unsigned int height;

};

#endif