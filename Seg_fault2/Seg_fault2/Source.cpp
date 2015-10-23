//A custom string class that allocates mem to hold
//a string that we can pass in. Note without a customized
//copy constructor or assignment operator C++ will
//provide defaults that shallow copy

#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class MyString
{
private:
	char *pchString; //this needs to be deep copied
	int nLength; //this may be shallow copied
public:
	~MyString();//custom destructor
	MyString(const MyString& cSource);//custom copy constructor
	MyString& operator = (const MyString& cSource);//custom copy assignment operator

	string getString()
	{
		string s(this->pchString);//use of built in conversion from char* to string
		return s;
	}
	int GetLength(){ return this->nLength; }

	MyString(char *pchString = "")//constructor with args
	{
		nLength = strlen(pchString) + 1;//get str len + terminator
		this->pchString = new char[nLength];//create buffer of that length
		strncpy(this->pchString, pchString, nLength);//copy into buffer
		this->pchString[nLength - 1] = '\0';//terminate string
	}
};//end class

//BIG THREE

//Custom destructor
MyString::~MyString()
{
	if (pchString != 0)
	{
		delete[] pchString;
		pchString = 0; // safe the pointer 
	}
}

//Custom copy contructor 
MyString::MyString(const MyString& cSource)
{
	// shallow copy on int
	this->nLength = cSource.nLength;
	// deep copy on char array
	if (cSource.pchString) 
	{
		//allocate memory for the copy 
		pchString = new char[nLength];
		strncpy(this->pchString, cSource.pchString, this->nLength);
	}
	else // nothing to deep copy
	{
		this->pchString = 0;
	}
}

//Custom copy assignment operator 
MyString& MyString::operator=(const MyString& cSource)
{
	// self assignment test
	if (this == &cSource)
	{
		return *this;
	}

	// deallocate any value string is already holding
	delete[] this->pchString;

	// copy routine
	this->nLength = cSource.nLength;
	if (cSource.pchString)
	{
		pchString = new char[nLength];
		strncpy(this->pchString, cSource.pchString, this->nLength);
	}
	else 
	{
		this->pchString = 0;
	}
	return *this;
}

int main()
{
	cout << "Use of copy constructor" << endl;
	MyString strHello("Hello World!"); // constructor with args
	MyString strOther(strHello); // copy constructor 
	cout << "From strHello: " << strHello.getString() << endl;
	cout << "From strOther: " << strOther.getString() << endl;

	cout << "Use of assignment operator" << endl;
	strOther = strHello; // use of assignment operator
	cout << "From strHello: " << strHello.getString() << endl;
	cout << "From strOther: " << strOther.getString() << endl;

	_getch();
	return 0;
}


