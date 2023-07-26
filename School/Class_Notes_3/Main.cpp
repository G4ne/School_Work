#include <iostream>
#include <vector>
#include "C:\Users\aj-mo\Documents\Scripts\School\Matrix Addition\Matrix.h"
//THIS SUCKS. CHANGE IT

using namespace std;

int main() {

	//X is some value
	int x = 5;

	//y is a value of x's memory address. It is a pointer, pointing to x

	int* y = &x;

	//Above is a sample of what a variable pointer looks like. The * is used to denote to the compiler that it is a pointer to that type. (in this case int)

	//In this example, this would reference x, using y
	cout << *y << endl;

	// * and & are opposite operators (dereferencing and referencing operators respectively)

	//Pointers should be initialized to a safe value

	char* z1 = NULL;

	//OR

	char* z2 = nullptr;

	//nullptr is a reserved keyword and doesn;t require any libraries BUT needs C++ 11 or later
	//NULL needs iostream or stddef.h but can be used in any C++ version
	//NULL == false. Therefore if *x = NULL, x is false and !x is true


	//To change the value of a variable using a point, dereference the variable and set it
	
	*y = 7;

	cout << *y << endl;

	/* Pointers and regular arrays
	* Arrays are always passed by reference so you do not need to pass them with &
	* ex: int arr[5];
	* ex: int* p = arr;
	* array pointers point to the first element of the array
	* look at slide 11 of the module 8 notes to see some operations with array pointers
	*/

	/* Pointers and vectors
	* There are many different types of vector pointers (pointer of vector of integers, vector of integer pointers, pointer of vector of integer pointers
	* -> is used to dereference
	* if i wanted to get the size of a vector using a pointer (named p1)
	* size_t n = (*p1).size(); THIS IS BAD
	* size_t n = p1->size(); THIS IS GOOD
	* use the size_t n = ... if you are storing the size. Just use the right side if you just need the value once
	* This works for everything
	* p1->push_back(), p1->empty(), p1->at()
	*/

	/* Pointers and User Classes
	* Pointers to user classes function normally as you would think they do
	* You must pass the object as a reference when making the pointer
	* You can make pointers to user classes but it is not a typical way to use C pointers on C++ classes (EXPLORED MORE NEXT WEEK)
	* You should use C++ pointers on C++ classes
	* WE WILL LEARN ABOUT new OPERATOR (C++ POINTER) NEXT WEEK CONTINUE HERE
	*/

	/* const pointers
	* You can make a pointer a const
	* When a pointer is const, you cannot change the value of the referenced variable but you can change what variable is referenced
	* 
	* int x = 5;
	* int y = 10;
	* const int* p1 = x;
	* *p1 = 7; DOES NOT WORK
	* p1 = &y; WORKS
	* 
	* You cannot create a pointer to a const variable
	* A POINTER MUST BE CONST IF THE DESIRED VARIABLE IS CONST
	*/


	/* Pointers and string literals
	* Regular arrays and pointers are the same thing
	* a c-string is an array of characters
	* char* p1 = "Hello World";
	* const char* p1 = "Hello World";
	* 
	* These work because arrays are pointers
	* This will be explained a bit more later
	*/

	/* Pointer to Pointer
	* int** p = NULL;
	* 
	* c pointers: this is a pointer to pointer to integer
	* c++ pointers: this is a 2 dimensional dynamic array
	*/

	/* Pointer this
	* 'this' is a pointer that points to the current object
	* it is a pointer that is initialized when a class object is initialized
	* 
	* Python has self and Visual Basic has Me
	* 
	* 'this' points to the current class object
	* 'this' IS SOMETIMES OMITTABLE BUT IT IS MORE UNDERSTANDABLE IF YOU USE IT
	* sometimes it is not omittable
	* if there are two variables are named the same you need to use 'this' (think private data field and parameter named the same thing. ex: width)
	* this cannot be called with static or friend functions because they belong to the class and are non-class-member functions respectively
	* *this is a reference to the current class object
	*/

	system("pause");
	return 0;
}