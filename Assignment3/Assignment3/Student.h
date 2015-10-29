#pragma once
#ifndef RATIONAL_HEADER //if not defined
#define RATIONAL_HEADER

#include <conio.h>
#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	int numCourses;
	string *courseList;
public:
	// constructors
	Student();
	Student(string);

	//big three
	Student(const Student&);
	~Student();
	Student& operator= (const Student&);

	
	void addCourse(string course);
	void clear();
	void output();

	void setName(string);
	string getName();
	string getCourse(int);
	int getNumCourses();


	friend ostream& operator<<(ostream &output, Student &num);

};



#endif //end the ifnot defined statement