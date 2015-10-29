#include <conio.h>
#include <iostream>
#include <sstream>
#include "Student.h"
using namespace std;

int main()
{
	string name;
	string course;

	// get name
	cout << "Begin Student Test" << endl;
	cout << "Enter student name: ";
	getline(cin, name);

	// create student 1
	Student student1 = Student(name);

	cout << "Enter 'done' when you are complete" << endl;
	// get courses
	do {
		cout << "Enter course name: ";
		getline(cin, course);
		if (course == "done")
			break;

		student1.addCourse(course);
	} while (course != "done");

	// output 1st student
	//student1.output();
	cout << student1;

	// name second student
	cout << "Enter name of second student: ";
	getline(cin, name);

	// user of assignment operator
	Student student2 = student1;

	student2.setName(name);

	//student2.output();
	cout << student2;

	// clear student 1
	student1.clear();
	//student1.output();
	cout << student1;

	_getch();
	return 0;
}