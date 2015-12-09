#include <string>
#include <iostream>
#include <conio.h>
#include "City.h"
#include "Zombie.h"
#include "Human.h"
#include "Organism.h"
using namespace std;

City::City(void){}
City::~City(void){}


void City::startPositions()
{
	int gridStart[GRID_WIDTH][GRID_HEIGHT] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,1,0,1,0,0,0,0,2,2,2,0,0,0,0,0,0 }, 
												{ 0,0,0,0,1,1,1,0,0,0,2,2,0,2,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,1,0,2,0,2,2,2,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
												{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, };

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
				Human *pHuman = new Human; //on heap
				grid[row][col] = (Organism*)pHuman;
			} else {
				grid[row][col] = 0;
			}
		}
	}
}

void City::drawCity()
{
	if (temp) {
		for (int row = 0; row < GRID_WIDTH; row++) {
			cout << endl;
			for (int col = 0; col < GRID_HEIGHT; col++) {
				if (grid[row][col] != NULL)
					cout << grid[row][col]->draw();
				else
					cout << " ";
			}
		}
	}
	
}

void City::move()
{
	for (int row = 0; row < GRID_WIDTH; row++) {
		for (int col = 0; col < GRID_HEIGHT; col++) {
			if (grid[row][col] != NULL)
				grid[row][col]->move();
		}
	}
}


//Organism *getOrganism(int x, int y);
//{
//	return "Bicycle implementation of BlowHorn()";
//}