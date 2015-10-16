#include <iostream>
#include <sstream>
#include <conio.h>
#include "Rational.h"
using namespace std;

void normalize(int numerator, int denominator);

int main()
{
	// rational numbers
	Rational r1;
	Rational r2;

	//get number inputs
	cout << "Enter the first rational number as a string: " << endl;
	cin >> r1;
	while (cin.fail())
	{
		cin.clear();
		cout << "Invalid input. Try again. " << endl;
		cin >> r1;
	}

	cout << "Enter the second rational number as a string: " << endl;
	cin >> r2;
	while (cin.fail())
	{
		cin.clear();
		cout << "Invalid input. Try again.  " << endl;
		cin >> r2;
	}

	//calculations
	Rational sum = r1 + r2;
	Rational difference = r1 - r2;
	Rational quotient = r1 / r2;
	Rational product = r1 * r2;

	//results 
	cout << r1 << " + " << r2 << " = " << sum << endl;
	cout << r1 << " - " << r2 << " = " << difference << endl;
	cout << r1 << " * " << r2 << " = " << product << endl;
	cout << r1 << " / " << r2 << " = " << quotient << endl;

	if (r1 == r2)
		cout << r1 << " == " << r2 << " = " << "true" << endl;
	else
		cout << r1 << " == " << r2 << " = " << "false" << endl;

	if (r1 > r2)
		cout << r1 << " > " << r2 << " = " << "true" << endl;
	else
		cout << r1 << " > " << r2 << " = " << "false" << endl;

	if (r1 < r2)
		cout << r1 << " < " << r2 << " = " << "true" << endl;
	else
		cout << r1 << " < " << r2 << " = " << "false" << endl;

	_getch();
	main();

	return 0;
}

