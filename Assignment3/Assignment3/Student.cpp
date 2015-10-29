#include <conio.h>
#include <iostream>
#include <sstream>
#include "Student.h"
using namespace std;



	//default
	Student::Student()
	{
		cout << "default constructor fired" << endl;
		this->name = "";
		this->numCourses = 0;
		this->courseList = new string[numCourses];
	}

	// w/ args
	Student::Student(string input)
	{
		cout << "one argument constructor fired" << endl;
		//int len = strlen(input);
		//this->name = new char[len + 1];
		//strcpy(this->name, input);
		
		this->name = input;

		this->numCourses = 0;
		this->courseList = new string[numCourses];
	}

	// copy constructor
	Student::Student(const Student& input)
	{
		cout << "copy constructor fired" << endl;
		//int len = strlen(strIn.strMem);
		//this->strMem = new char[len + 1];
		
		name = input.name;
		courseList = new string[input.numCourses];
		numCourses = input.numCourses;
		for (int i = 0; i<numCourses; i++)
			courseList[i] = input.courseList[i];
	}


	Student::~Student()// destuctor
	{
		cout << "destructor fired" << endl;

		if (this->courseList != NULL)
		{
			delete[] this->courseList;
		}
	}

	// assignment operator
	Student& Student::operator= (const Student& input)
	{
		cout << "assignment operator fired" << endl;

		// copy course list
		delete[] courseList;
		courseList = new string[input.numCourses];
		numCourses = input.numCourses;
		for (int i = 0; i<numCourses; i++)
			courseList[i] = input.courseList[i];

		// copy name
		name = input.name;
		/*char *temp = this->name;
		int len = strlen(this->name) + strlen(input.name) + 1;
		this->strMem = new char[len];
		strcpy(this->strMem, temp);
		strcat(this->strMem, strIn.strMem);
		delete[] temp;*/

		return *this;
	}

	void Student::addCourse(string course)
	{

		numCourses++;
		string *temp = new string[numCourses];
		for (int i = 0; i < numCourses - 1; i++)
		{
			temp[i] = courseList[i];
		}
		delete[] courseList;
		courseList = temp;

		courseList[numCourses - 1] = course;

		/*
		size_t newSize = numCourses + 1;
		string* newArr = new string[newSize];

		memcpy(newArr, courseList, numCourses * sizeof(string));

		numCourses = newSize;
		delete[] courseList;
		courseList = newArr;
		courseList[numCourses-1] = course;
		*/

	}

	void Student::output()
	{
		cout << endl << "Name of student: " << name << endl;
		cout << "Number of Courses: " << numCourses << endl;
		cout << "Class List:" << endl;
		
		for (int i = 0; i < numCourses; i++)
		{
			cout << (i+1) << "> " << courseList[i] << endl;
		}
		
	}

	void Student::clear()
	{

	}

	ostream& operator<<(ostream &output, Student &student)
	{
		output << "other test" << 6;
		return output;
	}