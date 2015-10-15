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

	// operators
	Rational Rational::operator+ (Rational &rightObj)
	{
		return Rational(this->numerator + rightObj.numerator,
			this->denominator + rightObj.denominator);
	}

	//code other operators here



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
		cout << "test";
		string delimiter = "/";
		string num1 = "";
		string num2 = "";

		size_t pos = 0;
		string token;
		bool first = true;
		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			if (first)
				num1 = token;
			else
				num2 = token;
			s.erase(0, pos + delimiter.length());
			first = false;
		}

		stringstream ss(num1);
		ss >> n;
		//stringstream ss(num2);
		ss >> d;	
	}
	else {
		cin.fail();
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
	string delimiter = "/";
	string num1 = "";
	string num2 = "";
	
	size_t pos = 0;
	string token;
	bool first = true;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		num1 = num1 + token;
		/*if (first)
			num1 = token;
		else
			num2 = token;*/
		first = false;
		s.erase(0, pos + delimiter.length());
	}
	cout << num1 << " " << num2 << endl;
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