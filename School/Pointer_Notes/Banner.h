#ifndef BANNER_H
#define BANNER_H

#include <string>

using std::string;

class Banner {
public:

	//Assignment Operator
	const Banner& operator = (const Banner&); //Always return const reference with assignment

	//Copy Constructor
	Banner(const Banner&);

	//Destructor
	~Banner();

private:

	//Data Fields
	unsigned int width, height;
	string* text;
};

#endif