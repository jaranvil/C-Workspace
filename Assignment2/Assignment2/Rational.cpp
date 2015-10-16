#include <iostream>
#include <sstream>
#include <conio.h>
#include "Rational.h"
using namespace std;

bool validateRational(string s);

	// constructors
	Rational::Rational()//default
		:numerator(0), denominator(1) {}
	Rational::Rational(int numerator, int denominator)
		:numerator(numerator), denominator(denominator) {}
	Rational::Rational(int num)
		:numerator(num), denominator(1) {}

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
		int numerator = this->numerator / rightObj.numerator;
		int denominator = this->denominator / rightObj.denominator;

		normalize(numerator, denominator);

		return Rational(numerator, denominator);
	}

	//string toString()//clean
	//{
	//	stringstream strStream;
	//	string x, y;
	//	//next 5 lines used to do conversions for double to str
	//	strStream << this->real;//place prop in stream
	//	strStream >> x;//rec it back converted to a string
	//	strStream.clear();
	//	strStream << this->imaginary;
	//	strStream >> y;

	//	//return a string representing the 
	//	//current value of this obj in a+bi format
	//	return (x + "+" + y + "i");

	//}//end toString




void operator>> (istream &input, Rational &num)
{
	string s;
	getline(input, s);//assign input to string var

	int n = 0;
	int d = 1;
	if (validateRational(s))
	{
		int del = s.find("/");
		string num1 = s.substr(0, del);
		string num2 = s.substr(del + 1);

		stringstream ss(num1);
		ss >> n;
		stringstream ss2(num2);
		ss2 >> d;	
	}
	else {
		
	}

	num = Rational(n, d);
}

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
	for (int i = denominator * numerator; i > 1; i--) {
		if ((denominator % i == 0) && (numerator % i == 0)) {
			denominator /= i;
			numerator /= i;
		}

	}
}