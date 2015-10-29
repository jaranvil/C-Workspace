#include <conio.h>
#include <iostream>
#include <sstream>
#include "Student.h"
using namespace std;



	//default
	Student::Student()
	{
		cout << endl << "default constructor fired" << endl;
		this->name = "";
		this->numCourses = 0;
		this->courseList = new string[numCourses];
	}

	// w/ args
	Student::Student(string input)
	{
		cout << endl << "one argument constructor fired" << endl;
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
		cout << endl << "copy constructor fired" << endl;
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
		cout << endl << "destructor fired" << endl;

		if (this->courseList != NULL)
		{
			if (!numCourses == 0)
				delete[] this->courseList;
		}
	}

	// assignment operator
	Student& Student::operator= (const Student& input)
	{
		cout << endl << "assignment operator fired" << endl;

		// copy course list
		delete[] courseList;
		courseList = new string[input.numCourses];
		numCourses = input.numCourses;
		for (int i = 0; i<numCourses; i++)
			courseList[i] = input.courseList[i];

		// copy name
		name = input.name;


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
		numCourses = 0;
		delete[] courseList;
	}

	void Student::setName(string name)
	{
		this->name = name;
	}

	string Student::getName()
	{
		return this->name;
	}

	string Student::getCourse(int index)
	{
		return this->courseList[index];
	}

	int Student::getNumCourses()
	{
		return this->numCourses;
	}

	ostream& operator<<(ostream &output, Student &student)
	{
		output << endl << "Name of student: " << student.getName() << endl;
		output << "Number of Courses: " << student.getNumCourses() << endl;
		output << "Class List:" << endl;

		for (int i = 0; i < student.getNumCourses(); i++)
		{
			output << (i + 1) << "> " << student.getCourse(i) << endl;
		}
		return output;
	}