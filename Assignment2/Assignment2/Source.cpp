#include <iostream>
#include <sstream>
#include <conio.h>
#include "Rational.h"
using namespace std;

void normalize(int numerator, int denominator);

int main()
{
	//cout << "Press any key to begin" << endl;
	//_getch();
	//Rational num;
	//cout << num << endl;//use of << override
	//_getch();

	////test of the + operator
	//cout << "Test of + operator and toString method" << endl;
	//ComplexNumber cn1(8, 8);//instanced using const with args
	//ComplexNumber cn2(2, 2);
	//ComplexNumber cn3 = cn1 + cn2;
	//cout << cn1.toString() << " + " << cn2.toString() << " = " << cn3.toString() << endl;
	//_getch();


	Rational r1;
	Rational r2;
	cout << "Enter the first rational number as a string: " << endl;
	cin >> r1; 

	if (cin.fail())
		cout << "TEST";

	cout << "Enter the second rational number as a string: " << endl;
	cin >> r2;

	Rational sum = r1 + r2;
	Rational difference = r1 - r2;
	Rational quotient = r1 / r2;
	Rational product = r1 * r2;

	cout << r1 << " + " << r2 << " = " << sum << endl;
	cout << r1 << " - " << r2 << " = " << difference << endl;
	cout << r1 << " * " << r2 << " = " << product << endl;
	cout << r1 << " / " << r2 << " = " << quotient << endl;

	_getch();


	return 0;
}

