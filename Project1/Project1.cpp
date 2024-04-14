#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*This program will help the user calculate how many gallons of water 
are in a rectangular swimming pool.*/
//By: Zaydan Dadabhai 

int main() {
	double length;
	double width;
	double depth;
	double cubic_inches;
	double result;

	cout << left;
	cout << fixed;
	cout << setprecision(1);
	cout << setw(42) << "Please enter the length of the pool (ft): ";
	cin >> length;
	cout << setw(42) << "Please enter the width of the pool (ft): ";
	cin >> width;
	cout << setw(42) << "Please enter the depth of the pool (ft): ";
	cin >> depth;
	
	length *= 12;
	width *= 12;
	depth *= 12;

	cubic_inches = length * width * depth;
	result = cubic_inches / 231;

	cout << setprecision(2);
	cout << setw(42) << "Your swimming pool contains approximately " << result << " gallons" << endl;
}