#include <iostream>
#include <sstream>
#include <conio.h>
#include "Rational.h"
using namespace std;



int main()
{
	string s = "5/6";
	string delimiter = "/";
	string num1 = "";
	string num2 = "";

	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		
		num1 = token;
		cout << token;

		s.erase(0, pos + delimiter.length());
	}
	cout << num1 << " " << num2 << endl;

	cout << "Press any key to begin" << endl;
	_getch();
	Rational num;
	cout << num << endl;//use of << override
	_getch();

	////test of the + operator
	//cout << "Test of + operator and toString method" << endl;
	//ComplexNumber cn1(8, 8);//instanced using const with args
	//ComplexNumber cn2(2, 2);
	//ComplexNumber cn3 = cn1 + cn2;
	//cout << cn1.toString() << " + " << cn2.toString() << " = " << cn3.toString() << endl;
	//_getch();


	Rational r;
	cout << "Enter rational number as a string: " << endl;
	cin >> r; //use of input friend function
				//note: have the overloaded input call a validation method and
				//execute a cin.fail if the string is not valid - loop and ask again
	cout << r << endl;//use of output friend function STUBBED!
	cout << "\n Test complete" << endl;
	_getch();


	return 0;
}

