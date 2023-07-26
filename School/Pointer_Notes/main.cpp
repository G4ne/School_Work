#include <iostream>
#include <vector>
#include "Banner.h"

using namespace std;

int main() {

	//Dynamically allocating things is when they are allocated at runtime

	//To use this with pointers use 'new'

	int* p;
	p = new int(4);

	//Here, a pointer (p) is made and is pointed at a dynamically allocated memory location which then store the integer 4

	//After using this dynamically allocated memory, you MUST release the memory after to be used elsewhere.
	//If you forget, you could end up with a memory leak

	//To deallocate memory:
	delete p;

	//This is used to free up dynamically allocated memory
	//Afterwards, you MUST set the pointer to a safe value
	p = NULL;

	//Delete cannot be used on statically allocated memory such as

	/* int x = 10;
	* int* y = &x; */

	//These cannot be 'deleted'

	//ALWAYS SET THE POINTER TO A SAFE VALUE AFTER YOU DELETE

	/*There are two forms of the delete keyword
	* delete is used to delete singular objects
	* delete[] is used to delete dynamically allocated arrays
	*/

	//There are two issues with DMA in c++

	//Shallow and deep copying is the issue

	//A shallow copy is

	int* p = new int(5);
	int* q = p; //q is a shallow copy of p

	//p is allocated with a certain chunk of memory
	//q is pointing at the same chunk of memory
	//This is what makes it a shallow copy
	//IF ONE IS CHANGED, THE OTHER WILL BE TOO (they are pretty much the same thing just different name)

	delete p;
	delete q;

	p = nullptr;
	q = nullptr;

	//The advantage of shallow copying is that it is faster but the disadvantage is that they are linked (if you delete q, p is also deleted) but they are unaware of changed to each other
	//Advantage is that no actual data is copied so its faster
	//Disadvantage is that its unreliable
	
	//A deep copy is (in comment bc its easier with his example)

	/*
	* Rectangle* p = new Rectangle(5, 2);
	* Rectangle* q = new Rectangle(p->get_width(), p->get_height());
	*/

	//The advantage of deep copies are that they are reliable and safe
	//The disadvantage is that they are slow because you are copying the actual data from one memory location into another dynamically allocated memory location



	//The second issue with DMA is memory leaks

	//If you want to change the memory location that a pointer is pointing at, YOU MUST DELETE THE OLD ONE BEFORE YOU POINT IT AT THE NEW ONE

	/* Example
	* Rectangle* p = new Rectangle(5, 9);
	* p = new Rectangle(8, 3);
	*/

	//You lose the reference to the original rectangle and it just sorta hangs out in memory, taking up space.
	//Once you leak a piece of memory, you CANNOT get back to it
	//A good example would be:

	/* Example
	* Rectangle* p = new Rectangle(5, 9);
	* delete p;
	* p = new Rectangle (6, 3);
	*/

	//In user-defined classes, pointers make things very complicated but with some extra work, you can avoid the big issues with DMA
	//First you MUST overload the = operator (deep-copy assignment)
	//Second, you overload the 'copy' constructor
	//Lastly, you overload the 'destructor'
	//These are often called the 'big three'
	//Check class notes and Banner.h

	//There are 5 steps to overloading deep-copy assignment operator
	/* 5 Steps
	* Avoid self assignment (if "b_2 = b_2", then do nothing) (basically, check if they have the same data)
	* Release dynamic memory
	* Copy static data
	* Copy dynamic data
	* Return
	*/
	//THERE IS A QUIZ OVER THIS

	//You can use pointer to create arrays that can change in size
	//Item_Type* arr = new Item_Type[size]
	//Where size can be a literal or variable
	//YOU MUST USE delete[] TO DELETE THESE ARRAYS
	//These are called dynamic arrays

	//2-D Dynamic Arrays
	//These have the same properties of a 2D vector (using int** data;)
	//Create the outer dynamic array using data = new int*[num_of_cols]
	//Then use a for-loop to iterate through each element and set them to new int[num_of_cols]
	//To delete a 2D array, you have to iterate through each inner dynamic array, only deleting the outer array once all the inner arrays have been deleted
	//Its deleted this way to avoid a memory leak

	return 0;
}