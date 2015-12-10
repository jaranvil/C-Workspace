#include <string>
#include "Human.h"
#include <windows.h> 
using namespace std;

Human::Human(void) {}
Human::Human(City *city, int width, int height) {
	x = width;
	y = height;
	Human::city = city;
}
Human::~Human(void) {}

void Human::draw()
{
	HANDLE  hConsole;
	int k = 2;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
	cout << "O";
	moved = false;
}

void Human::move()
{
	if (!moved)
	{
		// random num 1 - 4
		int min = 1;
		int max = 5;
		double x = rand() / static_cast<double>(RAND_MAX + 1);
		int num = min + static_cast<int>(x * (max - min));

		//new position
		int xNew = this->x;
		int yNew = this->y;

		if (num == 1)
		{ // up
			if (xNew > 1)
			{
				xNew = this->x - 1;
				yNew = this->y;
			}
		}
		else if (num == 2)
		{ // right 
			if (yNew < 20)
			{
				xNew = this->x;
				yNew = this->y + 1;
			}
		}
		else if (num == 3)
		{ // down
			if (xNew < 20)
			{
				xNew = this->x + 1;
				yNew = this->y;
			}
		}
		else if (num == 4)
		{ // left
			if (yNew > 0) {
				xNew = this->x;
				yNew = this->y - 1;
			}
		}

		if (city->grid[xNew][yNew] == NULL)
		{
			city->setAt(this->x, this->y, NULL);
			this->y = yNew;
			this->x = xNew;
			city->setAt(this->x, this->y, this);
			moved = true;
		}
	}
	age++;
	
}

void Human::action()
{
	if (age > 2)
	{
		// new human
		int newX = -1;
		int newY = -1;

		if (this->x - 1 >= 0)
		{
			if (city->grid[this->x - 1][this->y] == NULL)
			{
				newX = this->x - 1;
				newY = this->y;
			}
		} else if (this->x + 1 < 20)
		{
			if (city->grid[this->x + 1][this->y] == NULL)
			{
				newX = this->x + 1;
				newY = this->y;
			}
		} else if (this->y - 1 >= 0)
		{
			if (city->grid[this->x][this->y - 1] == NULL)
			{
				newX = this->x;
				newY = this->y - 1;
			}
		}
		else if (this->y + 1 >= 0)
		{
			if (city->grid[this->x][this->y + 1] == NULL)
			{
				newX = this->x;
				newY = this->y + 1;
			}
		}
		
		if (newX != -1 && newY != -1)
		{
			Human *pHuman = new Human(city, newX, newY);
			Organism* newOrg = (Organism*)pHuman;
			city->setAt(newX, newY, newOrg);
		}
		this->age = 0;
	}
}

int Human::whatAmI()
{
	return 0;
}

