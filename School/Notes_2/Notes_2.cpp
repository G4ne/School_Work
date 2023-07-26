#include "Fraction.h"

#include<iostream>

using namespace std;

int main() {

	Fraction f_1(1, 2), f_2(3, 10);

	f_1.print(cout);
	f_2.print(cout);

	cout << endl;

	Fraction f_3 = f_1 + f_2;

	f_3.print(cout);

	Fraction f_4 = f_1 + 3;

	f_4.print(cout);

	cout << endl << endl << f_4 << endl << endl;

	Fraction f_5;
	Fraction f_6;

	cin >> f_5 >> f_6;
	cout << endl << f_5 << endl << f_6 << endl;

	system("pause");
	return 0;
}