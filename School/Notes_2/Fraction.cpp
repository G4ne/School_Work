#include "Fraction.h"

//Constructor
Fraction::Fraction(int numerator, unsigned int denominator) : numerator(numerator), denominator(denominator) {

	simplify();

}

//Print Function
void Fraction::print(std::ostream& out) const {
	out << numerator << " / " << denominator << std::endl;
}

//Getters
int Fraction::Get_Numerator() const { return numerator; }
unsigned int Fraction::Get_Denominator() const { return denominator; }

//Setters
void Fraction::Set_Numerator(int x) { numerator = x; }
void Fraction::Set_Denominator(unsigned int x) { denominator = x; }

/** Finds the greatest common divisor of the fraction
* @param x: Numerator of the fraction
* @param y: Denominator of the fraction
* @return: The always-positive Greatest Common Denominator
*/
unsigned int Fraction::GCD(unsigned int x, unsigned int y) {
	if (x < y) { return GCD(y, x); }
	if (x % y == 0) { return y; }
	return GCD(y, x % y);
}

/** Some Docstring here
*/
void Fraction::simplify() {
	if (!numerator) {
		denominator = 1;
		return;
	}

	unsigned int gcd = GCD(std::abs(numerator), denominator);

	numerator /= gcd;
	denominator /= gcd;
	return;
}

//Reciprocal Function
Fraction Fraction::reciprocal() const {
	Fraction result;
	result.numerator = denominator;
	result.denominator = std::abs(numerator);
	result.numerator *= numerator > 0 ? 1 : -1;
	return result;
}

//Overload addition operators
Fraction Fraction::operator + (const Fraction& rsd) const {
	Fraction new_fract;

	new_fract.denominator = denominator * rsd.denominator;
	new_fract.numerator = numerator * rsd.denominator + rsd.numerator * denominator;

	new_fract.simplify();
	return new_fract;
}

Fraction Fraction::operator + (int x) const {
	return *this + Fraction(x, 1);
}

Fraction operator + (int left, const Fraction& right) {
	return right + left;
}

Fraction& Fraction::operator + () {
	return *this;
}

//Fraction - Overloadings
Fraction Fraction::operator - () const {
	return Fraction(-numerator, denominator);
}

Fraction Fraction::operator - (const Fraction& other) const {
	return *this + -other;
}

Fraction Fraction::operator - (int x) const {
	return *this - Fraction(x, 1);
}

Fraction operator - (int left, const Fraction& right) {
	return Fraction(left, 1) - right;
}

//Fraction * Overloadings
Fraction Fraction::operator * (const Fraction& other) const {
	Fraction result;
	result.numerator = numerator * other.numerator;
	result.denominator = denominator * other.denominator;

	result.simplify();

	return result;
}

Fraction Fraction::operator * (int x) const {
	return *this * Fraction(x, 1);
}

Fraction operator * (int left, const Fraction& right) {
	return right * left;
}

Fraction Fraction::operator / (const Fraction& other) const {
	return *this * other.reciprocal();
}

//Fraction / Overloadings
Fraction Fraction::operator / (int x) const {
	return *this / Fraction(x, 1);
}

Fraction operator / (int left, const Fraction& right) {
	return Fraction(left, 1) / right;
}

//Fraction += Overloadings
Fraction Fraction::operator += (const Fraction& other) {
	return *this = *this + other;
}
Fraction Fraction::operator += (int x) {
	return *this = *this + x;
}

//Fraction -= Overloadings
Fraction Fraction::operator -= (const Fraction& other) {
	return *this = *this - other;
}
Fraction Fraction::operator -= (int x) {
	return *this = *this - x;
}

//Fraction *= Overloadings
Fraction Fraction::operator *= (const Fraction& other) {
	return *this = *this * other;
}
Fraction Fraction::operator *= (int x) {
	return *this = *this * x;
}

//Fraction /= Overloadings
Fraction Fraction::operator /= (const Fraction& other) {
	return *this = *this / other;
}
Fraction Fraction::operator /= (int x) {
	return *this = *this / x;
}

//These overloadings' docstrings should be /** Overloads "Fraction++". */ (changed accordingly)

//Fraction ++ prefix overloading
Fraction& Fraction::operator ++ () {
	*this += 1;
	return *this;
}

//Fraction ++ postfix overloading
Fraction Fraction::operator ++ (int) {
	Fraction result = *this;

	++*this;

	return result;
}

//Fraction -- prefix overloading
Fraction& Fraction::operator -- () {
	*this -= 1;
	return *this;
}

//Fraction -- postfix overloading
Fraction Fraction::operator -- (int) {
	Fraction result = *this;

	--*this;

	return result;
}

//Comparison Overloadings

//Fraction < Fraction
bool Fraction::operator < (const Fraction& other) const {
	return numerator * other.denominator < denominator* other.numerator;
}

//Fraction < Integer
bool Fraction::operator < (int other) const {
	return *this < Fraction(other, 1);
}

//Integer < Fraction
bool operator < (int left, const Fraction& right) {
	return Fraction(left, 1) < right;
}

//Fraction <= Fraction
bool Fraction::operator <= (const Fraction& other) const {
	return numerator * other.denominator <= denominator* other.numerator;
}

//Fraction <= Integer
bool Fraction::operator <= (int other) const {
	return *this <= Fraction(other, 1);
}

//Integer <= Fraction
bool operator <= (int left, const Fraction& right) {
	return Fraction(left, 1) <= right;
}

//Fraction > Fraction
bool Fraction::operator > (const Fraction& other) const {
	return numerator * other.denominator > denominator* other.numerator;
}

//Fraction > Integer
bool Fraction::operator > (int other) const {
	return *this > Fraction(other, 1);
}

//Integer > Fraction
bool operator > (int left, const Fraction& right) {
	return Fraction(left, 1) > right;
}

//Fraction >= Fraction
bool Fraction::operator >= (const Fraction& other) const {
	return numerator * other.denominator >= denominator* other.numerator;
}

//Fraction >= Integer
bool Fraction::operator >= (int other) const {
	return *this >= Fraction(other, 1);
}

//Integer >= Fraction
bool operator >= (int left, const Fraction& right) {
	return Fraction(left, 1) >= right;
}

//Fraction == Fraction
bool Fraction::operator == (const Fraction& other) const {
	return numerator * other.denominator == denominator * other.numerator;
}

//Fraction == Integer
bool Fraction::operator == (int other) const {
	return *this == Fraction(other, 1);
}

//Integer == Fraction
bool operator == (int left, const Fraction& right) {
	return Fraction(left, 1) == right;
}

//Fraction != Fraction
bool Fraction::operator != (const Fraction& other) const {
	return numerator * other.denominator != denominator * other.numerator;
}

//Fraction != Integer
bool Fraction::operator != (int other) const {
	return *this != Fraction(other, 1);
}

//Integer != Fraction
bool operator != (int left, const Fraction& right) {
	return Fraction(left, 1) != right;
}

//Stream Insertion Operator Overloading
std::ostream& operator << (std::ostream& out, const Fraction& f) {
	return out << f.numerator << " / " << f.denominator << std::endl;
}

//Stream Extraction Operator Overloading
std::istream& operator >> (std::istream& in, Fraction& result) {
	in >> result.numerator >> result.denominator;
	result.simplify();
	return in;
}
