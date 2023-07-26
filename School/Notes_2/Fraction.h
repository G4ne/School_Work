#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

class Fraction {

public:

	//Constructor
	Fraction(int = 0, unsigned int = 1);

	//Getters
	int Get_Numerator() const;
	unsigned int Get_Denominator() const;

	//Setters
	void Set_Numerator(int);
	void Set_Denominator(unsigned int);

	//Class-member Functions

	void print(std::ostream&) const;

	//Overload + Operators of all types
	Fraction operator + (const Fraction&) const; //Fraction + Fraction
	Fraction operator + (int) const; //Fraction + int
	Fraction& operator + (); //+Fraction

	//Overload - Operators of all types
	Fraction operator - () const; //-Fraction
	Fraction operator - (const Fraction&) const; //Fraction - Fraction
	Fraction operator - (int) const; //Fraction - int

	//Overload * Operators of all types
	Fraction operator * (const Fraction&) const; //Fraction * Fraction
	Fraction operator * (int) const; //Fraction * int

	//Overload / Operators of all types
	Fraction operator / (const Fraction&) const; //Fraction / Fraction
	Fraction operator / (int) const; //Fraction / int

	//(some operator)= Overloadings
	Fraction operator += (const Fraction&); //Fraction += Fraction
	Fraction operator += (int); //Fraction += int
	Fraction operator -= (const Fraction&); //Fraction -= Fraction
	Fraction operator -= (int); //Fraction -= int
	Fraction operator *= (const Fraction&); //Fraction *= Fraction
	Fraction operator *= (int); //Fraction *= int
	Fraction operator /= (const Fraction&); //Fraction /= Fraction
	Fraction operator /= (int); //Fraction /= int

	//Unary operator Overloadings
	Fraction& operator ++ (); //Prefix ++ operator
	Fraction operator ++ (int); //Postfix ++ operator
	Fraction& operator -- (); //Prefix -- operator
	Fraction operator -- (int); //Postfix -- operator

	void simplify();

	//Comparison Operator Overloadings
	bool operator < (const Fraction&) const; //Fraction < Fraction
	bool operator < (int) const; //Fraction < int
	bool operator <= (const Fraction&) const; //Fraction <= Fraction
	bool operator <= (int) const; //Fraction <= int
	bool operator > (const Fraction&) const; //Fraction < Fraction
	bool operator > (int) const; //Fraction < int
	bool operator >= (const Fraction&) const; //Fraction <= Fraction
	bool operator >= (int) const; //Fraction <= int
	bool operator == (const Fraction&) const; //Fraction == Fraction
	bool operator == (int) const; //Fraction == int
	bool operator != (const Fraction&) const; //Fraction != Fraction
	bool operator != (int) const; //Fraction != int

	//Stream insertion operator
	friend std::ostream& operator << (std::ostream&, const Fraction&);

	//Stream extraction operator
	friend std::istream& operator >> (std::istream&, Fraction&);

	//Subscript Operator Overloading (MUST BE DONE TWICE)
	/*int& operator [] (unsigned int);
	const int operator [] (unsigned int);*/
	//LOOK AT CLASS NOTES FOR THIS 28 / 29

	//".", "::", "? :" operators cannot be overloaded

private:

	//Data Fields
	int numerator;
	unsigned int denominator;

	//Class-member Functions
	static unsigned int GCD(unsigned int x, unsigned int y);

	Fraction reciprocal() const;

};

Fraction operator + (int, const Fraction&); //Integer + Fraction
Fraction operator - (int, const Fraction&); //Integer - Fraction
Fraction operator * (int, const Fraction&); //Integer * Fraction
Fraction operator / (int, const Fraction&); //Integer / Fraction

bool operator < (int, const Fraction&); //Integer < Fraction
bool operator <= (int, const Fraction&); //Integer <= Fraction
bool operator > (int, const Fraction&); //Integer > Fraction
bool operator >= (int, const Fraction&); //Integer >= Fraction
bool operator == (int, const Fraction&); //Integer == Fraction
bool operator != (int, const Fraction&); //Integer != Fraction


#endif