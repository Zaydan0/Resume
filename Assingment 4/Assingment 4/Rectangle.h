#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
using namespace std;

class Rectangle {
public:
	Rectangle();
	Rectangle(int, int);
	int getHeight() const;
	void setHeight(int);
	int getWidth() const;
	void setWidth(int);

	int &operator [] (int index);

	friend ostream& operator << (ostream & , const Rectangle &);
	friend istream& operator >> (istream & , Rectangle &);

private:
	int height;
	int width;
};

bool operator < (const Rectangle& r1, const Rectangle& r2);
bool operator <= (const Rectangle& r1, const Rectangle& r2);
bool operator > (const Rectangle& r1, const Rectangle& r2);
bool operator >= (const Rectangle& r1, const Rectangle& r2);
bool operator == (const Rectangle& r1, const Rectangle& r2);
bool operator != (const Rectangle& r1, const Rectangle& r2);

#endif
