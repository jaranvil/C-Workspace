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

	do {
		cout << "Enter course name: ";
		getline(cin, course);
		if (course == "done")
			break;

		student1.addCourse(course);
	} while (course != "done");

	student1.output();

	_getch();
	return 0;
}