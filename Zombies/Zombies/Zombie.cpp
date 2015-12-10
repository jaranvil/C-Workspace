#include <string>
#include <time.h>       
#include <iostream>
#include <conio.h>
#include "Zombie.h"
#include <windows.h>

using namespace std;

Zombie::Zombie(void) {}
Zombie::Zombie(City *city, int width, int height) {
	x = width;
	y = height;
	Zombie::city = city;
}
Zombie::~Zombie(void) {}

void Zombie::draw()
{
	HANDLE  hConsole;
	int k = 4;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);

	cout << 'X';
	moved = false;
}

void Zombie::move()
{
	if (!moved)
	{
		// look for humans
		int humanX = -1;
		int humanY = -1;
		// top left corner
		int x1 = this->x - 1;
		int y1 = this->y - 1;

		for (int row = x1; row < x1 + 3; row++)
		{
			for (int col = y1; col < y1 + 3; col++)
			{
				if (city->grid[row][col] != NULL) {
					if (col < 20 && row < 20) {
						if (city->grid[row][col]->whatAmI() == 0)
						{
							humanX = city->grid[row][col]->x;
							humanY = city->grid[row][col]->y;
							cout << "eat ";
						}
					}

				}
			}
		} // end for

		if (!(humanX == -1 || humanY == -1)) // if human was found
		{
			//eat
			cout << "eat ";
			city->setAt(this->x, this->y, NULL);
			this->y = humanY;
			this->x = humanX;
			city->setAt(this->x, this->y, this);
			moved = true;
		}
		else
		{
			// human was not found to eat
			// move like a human

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
		age++;
	}
	
}

void Zombie::action()
{
	if (age > 7) 
	{
		// look for humans
		int humanX = -1;
		int humanY = -1;
		// top left corner
		int x1 = this->x - 1;
		int y1 = this->y - 1;

		for (int row = x1; row < x1 + 3; row++)
		{
			for (int col = y1; col < y1 + 3; col++)
			{
				if (city->grid[row][col] != NULL) {
					if (col < 20 && row < 20) {
						if (city->grid[row][col]->whatAmI() == 0)
						{
							humanX = city->grid[row][col]->x;
							humanY = city->grid[row][col]->y;
						}
					}

				}
			}
		} // end for

		if (!(humanX == -1 || humanY == -1)) // if human was found
		{
			// convert
			// new zombie
			Zombie *pZombie = new Zombie(city, humanX, humanY); 
			Organism* newOrg = (Organism*) pZombie;
			// replace human
			city->setAt(humanX, humanY, newOrg);
		
			this->age = 0;
		}
	}
}

int Zombie::whatAmI()
{
	return 1;
}


