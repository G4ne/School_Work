#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

int main() {

	//Declare variables
	unsigned int userYear;
	unsigned int userMonthNum;
	string firstDayofMonth;
	bool isLeap;
	unsigned int dayCount;
	unsigned int dayNum = 1;
	unsigned int row_count = 5;
	string userMonthstr;
	int row_i;
	int col_i;

	/*
	 *userYear takes the year
	 *userMonthNum takes the calendar number of the month
	 *firstDayofMonth is self-explanatory
	 *isLeap = true if its a leap year, false otherwise
	 *dayCount keeps track of how many days are in the month ex: in a leap February, dayCount = 29
	 *dayNum is incremented every time a day is printed onto calendar, effectively being the day portion of the date. If it is > or < dayCount, nothing is printed
	 *row_count keeps track of the amount of rows needed for the month
	 *userMonthstr; userMonthNum is translated into a string of the month's name, which is stored here
	 *row_i and col_i are index variables meant to be used for building the calendar with for-loops
	 */

	//Taking in user data from console
	cout << "Please enter the year: ";
	cin >> userYear;
	cout << endl << "Please enter the calendar number of a month: ";
	cin >> userMonthNum;
	cout << endl << "Please enter the first three letters of the first day of the month: ";
	cin >> firstDayofMonth;
	cout << endl;

	//Branches checking if it is a leap year
	if (userYear % 4 != 0) {
		isLeap = false;
	}
	else if (userYear % 100 != 0) {
		isLeap = true;
	}
	else if (userYear % 400 != 0) {
		isLeap = false;
	}
	else {
		isLeap = true;
	}

	//Switch-case statement to determine the string name of a month and assign dayCount accordingly
	switch(userMonthNum) {

	case 1:
		userMonthstr = "January";
		dayCount = 31;
		break;

	case 2:
		userMonthstr = "February";
		if (isLeap) {
			dayCount = 29;
		}
		else {
			dayCount = 28;
		}
		break;

	case 3:
		userMonthstr = "March";
		dayCount = 31;
		break;

	case 4:
		userMonthstr = "April";
		dayCount = 30;
		break;

	case 5:
		userMonthstr = "May";
		dayCount = 31;
		break;

	case 6:
		userMonthstr = "June";
		dayCount = 30;
		break;

	case 7:
		userMonthstr = "July";
		dayCount = 31;
		break;

	case 8:
		userMonthstr = "August";
		dayCount = 31;
		break;

	case 9:
		userMonthstr = "September";
		dayCount = 30;
		break;

	case 10:
		userMonthstr = "October";
		dayCount = 31;
		break;

	case 11:
		userMonthstr = "November";
		dayCount = 30;
		break;

	case 12:
		userMonthstr = "December";
		dayCount = 31;
		break;

	default:
		cout << "[Error] Unknown Month";
		return -1;
	}

	//For loop iterating through input string firstDayofMonth and making all letters lowercase
	for (int char_i = 0; char_i < 3; char_i++) {
		firstDayofMonth.at(char_i) = tolower(firstDayofMonth.at(char_i));
	}

	/* If - else branches that determine what the first day of the month isand makes some other adjustments based on that
	 * Negative numbers means the start point is further in the week
	 * If there is 31 days and the first day is a Friday, another row is required to fit all the days
	 * If there is 30 or more days and the first day is a Satudary, another row is required to fit all the days
	 */
	if (firstDayofMonth == "mon") {
		dayNum = 0;
	}
	else if (firstDayofMonth == "tue") {
		dayNum = -1;
	}
	else if (firstDayofMonth == "wed") {
		dayNum = -2;
	}
	else if (firstDayofMonth == "thu") {
		dayNum = -3;
	}
	else if (firstDayofMonth == "fri") {
		dayNum = -4;

		if (dayCount == 31) {
			row_count++;
		}
	}
	else if (firstDayofMonth == "sat") {
		dayNum = -5;

		if (dayCount >= 30) {
			row_count++;
		}
	}
	else if (firstDayofMonth == "sun") {
		dayNum = 0;
	}
	else {
		cout << "[Error] Invalid day input";
		system("pause");
		return -1;
	}

	//Info output above the calendar
	cout << right << setw(14) << userMonthstr << " " << userYear << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

	//Nested for loops used to build the calendar, outer loop is for the week (row) and inner loop is for each day (column)
	for (row_i = 0; row_i < row_count; row_i++) {

		for (col_i = 0; col_i < 7; col_i++) {

			//Checks if dayNum is outside the normal calendar day amount and prints nothing if it is (raising the number in case it was assigned below 0)
			if (dayNum <= 0 || dayNum > dayCount) {
				cout << right << setw(3) << " " << " ";
				dayNum++;
				continue;
			}

			cout << right << setw(3) << dayNum << " ";
			dayNum++;
		}

		//Ends the week and goes to the next line
		cout << endl;

	}

	//Line for readbility and for some extra whitespace
	cout << endl;
	system("pause");
	return 0;
}