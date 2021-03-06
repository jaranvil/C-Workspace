#include <string>
#include <iostream>
#include <conio.h>
#include "City.h"
#include "Zombie.h"
#include "Human.h"
#include "Organism.h"
#include <windows.h>
using namespace std;

City::City(void){}
City::~City(void){}


void City::startPositions()
{
	int gridStart[GRID_WIDTH][GRID_HEIGHT] = { { 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, };


	//int gridStart[GRID_WIDTH][GRID_HEIGHT] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,1,2,1,2,1,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,1,1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,1,1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,1,1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,1,1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0 },
	//											{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, };

	for (int row = 0; row < GRID_WIDTH; row++) {
		for (int col = 0; col < GRID_HEIGHT; col++) {
			if (gridStart[row][col] == 1)
			{
				Organism *pOrganism = new Organism; //on heap
				Zombie *pZombie = new Zombie(this, row, col); //on heap
				grid[row][col] = (Organism*)pZombie;
			}
			else if (gridStart[row][col] == 2) {
				Organism *pOrganism = new Organism; //on heap
				Human *pHuman = new Human(this, row, col); //on heap
				grid[row][col] = (Organism*)pHuman;
			} else {
				grid[row][col] = NULL;
			}
		}
	}
}

void City::drawCity()
{
	HANDLE  hConsole;
	int k = 6;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);

	system("cls");
	cout << "Humans vs. Zombies!" << endl;
	cout << "Iterations: " << iterations << endl;

	if (temp) {
		for (int row = 0; row < GRID_WIDTH; row++) {
			cout << endl;
			for (int col = 0; col < GRID_HEIGHT; col++) {
				if (grid[row][col] != NULL)
					grid[row][col]->draw();
				else
					cout << " ";
			}
		}
	}
	
}

void City::move()
{
	iterations++;
	bool zombies = false;
	bool humans = false;
	// Zombies
	for (int row = 0; row < GRID_WIDTH; row++) {
		for (int col = 0; col < GRID_HEIGHT; col++) {
			if (grid[row][col] != NULL)
				if (grid[row][col]->whatAmI() == 1) {
					grid[row][col]->move();
					zombies = true;
				}	
		}
	}

	// Humans
	for (int row = 0; row < GRID_WIDTH; row++) {
		for (int col = 0; col < GRID_HEIGHT; col++) {
			if (grid[row][col] != NULL)
				if (grid[row][col]->whatAmI() == 0) {
					grid[row][col]->move();
					humans = true;
				}	
		}
	}

	if (!zombies || !humans)
	{
		cout << endl << "extinction" << endl;
		_getch();
	}
}

void City::action()
{
	// Zombies
	for (int row = 0; row < GRID_WIDTH; row++) {
		for (int col = 0; col < GRID_HEIGHT; col++) {
			if (grid[row][col] != NULL)
				if (grid[row][col]->whatAmI() == 1)
					grid[row][col]->action();
		}
	}

	// Human
	for (int row = 0; row < GRID_WIDTH; row++) {
		for (int col = 0; col < GRID_HEIGHT; col++) {
			if (grid[row][col] != NULL)
				if (grid[row][col]->whatAmI() == 0)
					grid[row][col]->action();
		}
	}
}

Organism* City::getAt(int x, int y) {
	return this->grid[x][y];
}

void City::setAt(int x, int y, Organism *org) {
	//cout << endl << x << "/t" << y << endl;
	grid[x][y] = org;
}



//Organism *getOrganism(int x, int y);
//{
//	return "Bicycle implementation of BlowHorn()";
//}