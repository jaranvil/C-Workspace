#include <iostream>
#include <sstream>
#include <conio.h>
#include "Rational.h"
#include <cmath>
using namespace std;

bool validateRational(string s);

// constructors
Rational::Rational()//default
:numerator(0), denominator(1) {}
Rational::Rational(int numerator, int denominator)
: numerator(numerator), denominator(denominator) {}
Rational::Rational(int num)
: numerator(num), denominator(1) {}

// addition
Rational Rational::operator+ (Rational &rightObj)
{
	int numerator = this->numerator + rightObj.numerator;
	int denominator = this->denominator + rightObj.denominator;

	normalize(numerator, denominator);

	return Rational(numerator, denominator);
}

// subtraction
Rational Rational::operator- (Rational &rightObj)
{
	int numerator = this->numerator - rightObj.numerator;
	int denominator = this->denominator - rightObj.denominator;

	normalize(numerator, denominator);

	return Rational(numerator, denominator);
}

// multipication 
Rational Rational::operator* (Rational &rightObj)
{
	int numerator = this->numerator * rightObj.numerator;
	int denominator = this->denominator * rightObj.denominator;

	normalize(numerator, denominator);

	return Rational(numerator, denominator);
}

// division
Rational Rational::operator/ (Rational &rightObj)
{
	if (rightObj.numerator == 0)
		return Rational(0);

	int numerator = this->numerator / rightObj.numerator;
	int denominator = this->denominator / rightObj.denominator;

	normalize(numerator, denominator);

	return Rational(numerator, denominator);
}

// equals
bool Rational::operator== (Rational &rightObj)
{
	normalize(this->numerator, this->denominator);
	normalize(rightObj.numerator, rightObj.denominator);
	if (this->numerator == rightObj.numerator && this->denominator == rightObj.denominator)
		return true;
	else
		return false;
}

// greater than
bool Rational::operator> (Rational &rightObj)
{
	int left = this->numerator * rightObj.denominator;
	int right = this->denominator * rightObj.numerator;
	return left > right;
}

// less than
bool Rational::operator< (Rational &rightObj)
{
	int left = this->numerator * rightObj.denominator;
	int right = this->denominator * rightObj.numerator;
	return left < right;
}

// input override
void operator>> (istream &input, Rational &num)
{
	string s;
	getline(input, s);//assign input to string var

	int n = 0;
	int d = 1;

	if (isInteger(s))
	{
		// single interger inputted
		stringstream ss(s);
		ss >> n;
		num = Rational(n);
	} else if (validateRational(s))
	{
		// valid rational inputted
		int del = s.find("/");
		string num1 = s.substr(0, del);
		string num2 = s.substr(del + 1);

		stringstream ss(num1);
		ss >> n;
		stringstream ss2(num2);
		ss2 >> d;

		if (d == 0)
			input.setstate(istream::failbit);

		num = Rational(n, d);
	}
	else {
		//invalid input
		input.setstate(istream::failbit);
	}
}

// output override
ostream& operator<<(ostream &output, Rational &num)
{
	output << num.numerator << "/" << num.denominator;
	return output;
}

bool validateRational(string s)
{
	int del = s.find("/");
	string num1 = s.substr(0, del);
	string num2 = s.substr(del + 1);

	if (isInteger(num1) && isInteger(num2))
		return true;

	return false;
}

inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

void normalize(int &numerator, int &denominator)
{
	bool numNeg = false;
	bool denNeg = false;
	// make numers positive
	if (numerator < 0) {
		numerator = abs(numerator);
		numNeg = true;
	}
		
	if (denominator < 0) {
		denominator = abs(denominator);
		numNeg = true;
	}
	
	// normalize
	for (int i = denominator * numerator; i > 1; i--) {
		if ((denominator % i == 0) && (numerator % i == 0)) {
			denominator /= i;
			numerator /= i;
		}
	}

	// restore negatives
	if (numNeg) 
		numerator = -numerator;
	if (denNeg)
		denominator = -denominator;
	
}