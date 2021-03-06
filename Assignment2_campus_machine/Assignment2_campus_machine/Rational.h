#pragma once
#ifndef RATIONAL_HEADER //if not defined
#define RATIONAL_HEADER

using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;
public:
	// constructors
	Rational();
	Rational(int, int);
	Rational(int);

	Rational operator+ (Rational &rightObj);
	Rational operator- (Rational &rightObj);
	Rational operator* (Rational &rightObj);
	Rational operator/ (Rational &rightObj);
	bool operator== (Rational &rightObj);
	bool operator> (Rational &rightObj);
	bool operator< (Rational &rightObj);
	
	friend bool validateRational(string s);
	friend void operator>> (istream &input, Rational &num);
	friend ostream& operator<<(ostream &output, Rational &num);
};


inline bool isInteger(const std::string & s);
void normalize(int &numerator, int &denominator);


#endif //end the ifnot defined statement