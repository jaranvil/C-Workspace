#include <iostream>
#include <conio.h>
#include "City.h"
using namespace std;

int main()
{
	system("cls");
	cout << "Humans vs. Zombies!" << endl;

	City city;

	city.startPositions();
	city.drawCity();

	_getch();
	return 0;
}