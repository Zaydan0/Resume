#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
	height = 0;
	width = 0;
}
Rectangle::Rectangle(int h, int w) {
	setHeight(h);
	setWidth(w);
}
int Rectangle::getHeight() const {
	return height;
}
void Rectangle::setHeight(int h) {
	if (h > 80) {
		height = 80;
	}
	else {
		height = h;
	}
}
int Rectangle::getWidth() const {
	return width;
}
void Rectangle::setWidth(int w) {
	if (w > 80) {
		width = 80;
	}
	else {
		width = w;
	}
}
ostream &operator<<(ostream &out, const Rectangle &r) {
	for (int i = 0; i < r.height; i++) {
		for (int j = 0; j < r.width; j++) {
			out << "*";
		}
		out << endl;
	}
	return out;
}
istream &operator>>(istream &in, Rectangle &r1) {
	int height;
	int width;
	cout << "Enter width: ";
	in >> width;
	cout << "Enter height: ";
	in >> height;
	r1.setWidth(width);
	r1.setHeight(height);
	return in;
}
int &Rectangle::operator[](int index)  {
	if (index == 0) {
		return width;
	}
	else
		return height;
}

bool operator<(const Rectangle &r1, const Rectangle &r2) {
	return r1.getHeight() * r1.getWidth() < r2.getHeight() * r2.getWidth();
}

bool operator<=(const Rectangle& r1, const Rectangle& r2) {
	if (r1 < r2) {
		return true;
	}
	else if (r1 == r2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const Rectangle& r1, const Rectangle& r2) {
	return  r1.getHeight() * r1.getWidth() > r2.getHeight() * r2.getWidth();
}

bool operator>=(const Rectangle& r1, const Rectangle& r2) {
	if (r1 > r2) {
		return true;
	}
	else if (r1 == r2) {
		return true;
	}
	else {
		return false;
	}
}

bool operator ==(const Rectangle& r1, const Rectangle& r2) {
	return r1.getHeight() * r1.getWidth() == r2.getHeight() * r2.getWidth();
}

bool operator!=(const Rectangle& r1, const Rectangle& r2) {
	return  r1.getHeight() * r1.getWidth() != r2.getHeight() * r2.getWidth();;
}