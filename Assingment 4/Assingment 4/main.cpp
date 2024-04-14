#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.h"
using namespace std;

int main() {
	ifstream in("input.txt");
	int numRectangles;
	in >> numRectangles;
	for (int i = 0; i < numRectangles; i++) {
		Rectangle r;
		in >> r;
		cout << r[0] << " x " << r[1] << endl;
		cout << r;
	}
	Rectangle r1(4, 5), r2(10, 2);
	if (r1 == r2) {
		cout << "Both rectangles have the same area!" << endl;
	}
}