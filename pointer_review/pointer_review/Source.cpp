#define _SCL_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Array
{
private:
	int size;
	int *vals;
public:
	Array(int s, int *v);
	~Array();
	string toString();
	Array(const Array& a); // copy constructor
	Array& operator=(const Array& a); //copy assignment operator
}; // end Array class

// implementations of Array class
string Array::toString()
{
	stringstream ss;
	string str;
	string x;

	for (int i = 0; i < this->size; i++) {
		ss << this->vals[i];
		ss >> x;
		str += x;
		ss.clear();
	}

	return(str);
}

Array::~Array()
{
	delete vals;
	vals = 0;
}

Array::Array(int s, int *v)
{
	size = s;
	vals = new int[size];
	copy(v, v + size, vals);
}

// implementation of copy constructor override
Array::Array(const Array& a)
{
	size = a.size;
	vals = new int[a.size];
	copy(a.vals, a.vals + size, vals);
}

// implementation of copy assignment operator overload 
Array& Array::operator=(const Array& a)
{
	if (&a != this) // avoid self assingment by comparing memory addresses
	{
		size = a.size;
		vals = new int[a.size];
		copy(a.vals, a.vals + size, vals);
	}
	return *this;
}

int main()
{
	cout << "Begin Seg Fault Test" << endl;
	int vals[4] = {1,2,3,4};

	Array a1(4, vals);
	Array a2(a1);
	a1 = a2;
	cout << "a1: " << a1.toString() << endl;
	cout << "a2: " << a1.toString() << endl;

	cout << "Seg Fault Test Complete" << endl;

	_getch();
	return 0;
} 