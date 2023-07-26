#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const double fed_withhold = 0.15; // Creates a constant double for the federal withholding rate
	const double state_withhold = 0.05; // Creates a constant double for the state withholding rate

	cout << "Please enter your last name: "; // Writes the string to the console and then takes input into the "last_name" string variable
	string last_name;
	cin >> last_name;

	cout << "Please enter the last four digits of your SSN: "; // Writes the string to the console and then takes input into the "ssn" integer variable
	int ssn;
	cin >> ssn;

	cout << "Please enter your hourly pay rate: "; // Writes the string to the console and then takes input into the "hourly_rate" double variable
	double hourly_rate;
	cin >> hourly_rate;

	cout << "Please enter the number of hours you worked: "; // Writes the string to the console and then takes input into the "hours_worked" integer variable
	unsigned int hours_worked;
	cin >> hours_worked;

	cout << endl; // Creates a bit of whitespace for readability
	cout << endl;

	cout << "Payroll Summary for: " << last_name << endl; // These 3 lines repeat the input info back to the user
	cout << "SSN (Last 4 Digits): " << setfill('0') << setw(4) << ssn << endl;
	cout << "You worked " << hours_worked << " hours at $" << setprecision(2) << fixed << hourly_rate << " per hour." << endl;

	cout << endl; // Whitespace for readability

	double gross_pay = hourly_rate * hours_worked; // Initializes and calculates gross pay
	cout << "Gross Pay:              $" << setfill(' ') << setw(8) << setprecision(2) << fixed << gross_pay << endl; // Writes gross pay to console
	cout << "Federal Withholding:    $" << setfill(' ') << setw(8) << setprecision(2) << fixed << gross_pay * fed_withhold << endl; // Writes federal withholding to console
	cout << "State Withholding:      $" << setfill(' ') << setw(8) << setprecision(2) << fixed << gross_pay * state_withhold << endl; // Writes state withholding to console
	cout << "---------------------------------" << endl; // Line for readability and text separation
	cout << "Net Pay:                $" << setfill(' ') << setw(8) << setprecision(2) << fixed << gross_pay - (gross_pay * fed_withhold) - (gross_pay * state_withhold) << endl; // Writes net pay to console

	system("pause");
	return 0;
}