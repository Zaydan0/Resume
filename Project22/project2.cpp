#include <iostream>
using namespace std;

int main() {

	int num = 0;
	int max = 9999;
	int min = 0;
	int maximum = 0;
	int minimum = 0;


	cout << "Please enter as many numbers as you like. Enter -1 to stop." << endl;

	do {
		cout << "Please enter a number: ";
		cin >> num;
		if (num != -1) {
			minimum = 0;
		}
		else if (num > 9999 || num < 0) {
			cout << "I accept positive numbers less than 9999 (or -1 to stop)" << endl;
		}

		if (num > maximum) {
			maximum = num;
		}
		else if (num < minimum) {
			minimum = num;
		}

	} while (num != -1);

	cout << "Maximum= " << maximum << endl;
	cout << "Minimum= " << minimum << endl;
}