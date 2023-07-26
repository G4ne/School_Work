#include <iostream>

using namespace std;

int main() {

	//RECURSION
	//recursion is math, not cs
	//The repetition of a function on a previous thing (think f(n) and f(n-1))

	//A recursive algorithm solves a problem by breaking it into pieces, solving those pieces and combining their solutions
	//You need to find the recurrence relation before you can do anything

	//Recursion is a function calling itself
	//Notes will help greatly here
	//LEARN RECURSION

	//Four steps to create a recursive solution
	/*
	* 1. See if you need to redefine the problem
	* 2. Find base case(s)
	* 3. Find recurrence relation(s)
	* 4. Write wrapper functions
	* 
	* A wrapper functions is a function that converts the problem you re-defined back into the original problem
	* For the search example, think a 1-line function that calls the function that searches using locations, only taking the vector and target as parameters
	*/

	/* Base case and recurrence relations
	* 
	* 1. factorial non-negative int
	* Base: if n = 1
	* Recurrence: f(n) = n * (n-1)! (factorial of n-1)
	* 
	* 2. Reverse a string
	* Base: empty string
	* Recurrence Relation: reverse all char except the first
	* 
	* 3. Test whether a string is all lowercase
	* Base: empty string
	* Recurrence Relation: Check all char after first, then check first char
	*/

	system("pause");
	return 0;
}