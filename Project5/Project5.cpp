#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
	const int SIZE = 25;
	int x[SIZE];
	int y[SIZE];
	int input = 0;
	int unique = 0;
	int num;
	bool done = false;

	while (!done) {
		cout << "Enter a number: ";
		cin >> num;
		if (num == -1) {
			done = true;
		}
		else if (num < 0) {
			cout << "Error! Make sure you only use positive numbers" << endl;
		}
		else if (input >= SIZE) {
			cout << "Only 25 numbers are allowed" << endl;
			done = true;
		}
		else {
			x[input] = num;
			input++;
		}
	}

	cout << "The numbers you entered were: ";
	for (int i = 0; i < input; i++) {
		cout << x[i];
		if (i < input - 1) {
			cout << ", ";
		}
	}
	cout << "." << endl;

	for (int i = 0; i < input; i++) {
		bool itsunique = true;
		for (int j = 0; j < unique; j++) {
			if (x[i] == y[j]) {
				itsunique = false;
				done = true;
			}
		}
		if (itsunique) {
			y[unique] = x[i];
			unique++;
		}
	}

	cout << "The unique numbers are: ";
	for (int i = 0; i < unique; i++) {
		cout << y[i];
		if (i < unique - 1) {
			cout << ", ";
		}
	}
	cout << "." << endl;

	cout << "You entered " << input << " numbers, " << unique << " unique." << endl;
	cout << "Have a nice day!" << endl;
	return 0;
}