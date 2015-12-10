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

		//if (city->grid[xNew][yNew] = NULL)
		//{
			city->setAt(this->x, this->y, NULL);
			this->y = yNew;
			this->x = xNew;
			city->setAt(this->x, this->y, this);
			moved = true;
		//}
	}
	
}

void Human::action()
{

}

int Human::whatAmI()
{
	return 0;
}

