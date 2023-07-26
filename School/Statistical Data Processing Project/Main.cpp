#include "Dynamic_Array.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

//Function Definitions
double sum_set(const Dynamic_Array&);
double Standard_Deviation(const Dynamic_Array&);
double Correlation_Coefficient(const Dynamic_Array&, const Dynamic_Array&);
double Best_Fitting_Line_Slope(const Dynamic_Array&, const Dynamic_Array&);
double Best_Fitting_Line_Intercept(const Dynamic_Array&, const Dynamic_Array&);

int main() {

	//Create ifstream and open input file
	std::ifstream in("data.txt");

	//Test input file
	if (!in) {
		std::cout << "[Error] Input file not found" << std::endl;
		system("pause");
		return -1;
	}

	//Create x and y dynamic arrays and data fields to temporarily hold the input values as they are read
	Dynamic_Array x_array, y_array;
	double temp_x, temp_y;

	//Read in x and y values from input file
	while (in >> temp_x >> temp_y) {

		//Append the respective values to their dynamic arrays
		x_array.push_back(temp_x);
		y_array.push_back(temp_y);

	}

	//Create and open ofstream
	std::ofstream out("results.txt");

	//Write precursor info about x-y pairs
	out << "Number of x-y pairs read: " << x_array.size() << std::endl << std::endl;

	//Create values to hold average value of each dynamic array
	double x_average = 0, y_average = 0;

	//Calculate average of each set of values
	for (unsigned int i = 0; i < x_array.size(); i++) {
		x_average += x_array[i];
		y_average += y_array[i];
	}
	x_average /= x_array.size();
	y_average /= y_array.size();

	//Set the amount of decimals to be kept when writing to the output file
	out << std::fixed << std::setprecision(4);

	//Write averages to the output file
	out << "Algebraic average of x: " << x_average << std::endl;
	out << "Algebraic average of y: " << y_average << std::endl;
	
	//Compute and write each value set's standard deviation to the output file
	out << "Standard deviation of x: " << Standard_Deviation(x_array) << std::endl;
	out << "Standard deviation of y: " << Standard_Deviation(y_array) << std::endl << std::endl;
	
	//Compute and write the correlation coefficient to the output file
	out << "Correlation coefficient: " << std::fixed << std::setprecision(4) << Correlation_Coefficient(x_array, y_array) << std::endl << std::endl;

	//Compute and store slope and intercept values to be output in two forms
	double slope = Best_Fitting_Line_Slope(x_array, y_array), intercept = Best_Fitting_Line_Intercept(x_array, y_array);

	//Write slope and intercept values in slope-intercept form and by themselves
	out << "Linear fitting function:" << std::endl << std::endl;
	out << "y = " << slope << "x + " << intercept << std::endl << std::endl;
	out << "Slope: " << slope << std::endl << "Intercept: " << intercept << std::endl;

	//Close input and output streams
	in.close();
	out.close();

	return 0;
}



/* Sums the contents of a dynamic array
* @param array: The array to be summed up
* @return: Returns the sum of all contents of the array
*/
double sum_set(const Dynamic_Array& array) {

	double sum = 0;

	for (unsigned int i = 0; i < array.size(); i++) {
		sum += array[i];
	}

	return sum;
}



/* Calculates the Standard deviation of a set of values
* @param coords: A dynamic array of the coordinates to be evaluated
* @return: Returns the standard deviation in the form of a double
*/
double Standard_Deviation(const Dynamic_Array& coords) {

	//Declare some useful data fields
	double coord_average = 0; //The average of the values
	double coord_sum_diff = 0; //The sum of squared differences for the values
	double deviation; //The final value to be calculated

	//Add all the values in the dynamic array together (to be averaged)
	coord_average = sum_set(coords);

	//Get the average of the dynamic array
	coord_average /= coords.size();

	//Loop through and calculate the sum of squared differences for the values
	for (unsigned int i = 0; i < coords.size(); i++) {

		double temp; //These are values to be manipulated
		temp = coords[i];

		//Calculate the difference and square it
		temp = pow((temp - coord_average), 2);

		//Add the produced values to the sum of differences
		coord_sum_diff += temp;

	}

	//Take the average of the sum of differences
	coord_sum_diff /= coords.size();

	//Take the square root of the average sum of differences
	deviation = sqrt(coord_sum_diff);

	//Return the final standard deviation value
	return deviation;

}



/* Calculates the correlation coefficient of a set of x-y values
* @param x_coords: A dynamic array of all the x-coordinates
* @param y_coords: A dynamic array of all the y-coordinates
* @return: Returns the correlation coefficient of the set of x-y values in the form of a double
*/
double Correlation_Coefficient(const Dynamic_Array& x_coords, const Dynamic_Array& y_coords) {

	//Declare some useful variables
	double x_average = 0; //The average of the x-values
	double y_average = 0; //The average of the y-values
	double x_sum_diff = 0; //The sum of squared differences for the x-values
	double y_sum_diff = 0; //The sum of squared differences for the y-values
	double sum_diff = 0; //The sum of differences for both values added together
	double corr_coeff; //The correlation coefficient of the two dynamic arrays
	

	//Get the sum of both sets of numbers (to be averaged)
	x_average = sum_set(x_coords);
	y_average = sum_set(y_coords);

	//Take the average of the sets of coords
	x_average /= x_coords.size();
	y_average /= y_coords.size();

	//Calculate the sum of the product of differences (top half of the formula)
	for (unsigned int i = 0; i < x_coords.size(); i++) {
		sum_diff += ((x_coords[i] - x_average) * (y_coords[i] - y_average));
	}

	//Calculate the sum of squared differences for both sets of values
	for (unsigned int i = 0; i < x_coords.size(); i++) {
		x_sum_diff += pow((x_coords[i] - x_average), 2);
		y_sum_diff += pow((y_coords[i] - y_average), 2);
	}

	//Square root the sum of squared differences (bottom half of the formula)
	x_sum_diff = sqrt(x_sum_diff);
	y_sum_diff = sqrt(y_sum_diff);

	//Calcualte the correlation coefficient
	corr_coeff = sum_diff / (x_sum_diff * y_sum_diff);

	return corr_coeff;

}



/* Calculates the slope of the best fitting line
* @param x_coords: Takes a dynamic array of x-coordinates
* @param y_coords: Takes a dynamic array of y-coordinates
* @return: Returns a double representing the slope of the best fitting line for a set of x-y coordinates
*/
double Best_Fitting_Line_Slope(const Dynamic_Array& x_coords, const Dynamic_Array& y_coords) {

	//Declaring some useful data fields
	double sum_xy = 0; //The sum of all x * y values
	double sum_x = sum_set(x_coords); //The sum of all x values
	double sum_y = sum_set(y_coords); //The sum of all y values
	double sum_x_sqr = 0; //The sum of all squared x values
	double slope; //The final slope value to be returned

	//Calculate the more complex value sums
	for (unsigned int i = 0; i < x_coords.size(); i++) {

		sum_xy += x_coords[i] * y_coords[i];
		sum_x_sqr += pow(x_coords[i], 2);

	}

	//Calculate the slope value
	slope = ((x_coords.size() * sum_xy) - (sum_x * sum_y)) / ((x_coords.size() * sum_x_sqr) - pow(sum_x, 2));

	return slope;

}



/* Calculates the intercept of the best fitting line
* @param x_coords: Takes a dynamic array of x-coordinates
* @param y_coords: Takes a dynamic array of y-coordinates
* @return: Returns a double representing the intercept of the best fitting line for a set of x-y coordinates
*/
double Best_Fitting_Line_Intercept(const Dynamic_Array& x_coords, const Dynamic_Array& y_coords) {

	//Declare some useful variables
	double slope = Best_Fitting_Line_Slope(x_coords, y_coords); //The slope of the line
	double sum_x = sum_set(x_coords); //The sum of all x-values
	double sum_y = sum_set(y_coords); //The sum of all y-values
	double intercept; //The final intercept value to be returned

	//Calculate the intercept
	intercept = (sum_y - (slope * sum_x)) / x_coords.size();

	return intercept;

}