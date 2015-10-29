#include <conio.h>
#include <iostream>
#include <sstream>
#include "Student.h"
using namespace std;

int main()
{
	string name;
	string course;
	Student student1;
	Student student2;

	// get name
	cout << "Begin Student Test" << endl;
	cout << "Enter student name: ";
	getline(cin, name);

	// create student 1
	student1 = Student(name);

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
	student1.output();

	// name second student
	cout << "Enter name of second student: ";
	getline(cin, name);

	// user of assignment operator
	student2 = student1;

	student2.setName(name);

	student2.output();

	// clear student 1
	student1.clear();
	student1.output();

	_getch();
	return 0;
}