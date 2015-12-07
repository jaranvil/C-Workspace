#include <string>
#include "City.h"
#include "Zombie.h"
#include "Organism.h"
using namespace std;

City::City(void){}
City::~City(void){}

void City::startPositions()
{
	for (int row = 0; row < GRID_WIDTH; row++) {
		cout << endl;
		for (int col = 0; col < GRID_HEIGHT; col++) {
			
			// first try
			//Organism *pOrganism= new Zombie;
			//grid[row][col] = pOrganism;

			// second

			Organism *pOrganism = new Organism; //on heap
			Zombie *pZombie = new Zombie; //on heap

			grid[row][col] = (Organism*) pZombie;
		}
	}
}

void City::drawCity()
{
	for (int row = 0; row < GRID_WIDTH; row++) {
		cout << endl;
		for (int col = 0; col < GRID_HEIGHT; col++) {			
			//cout << grid[row][col]->draw();
		}
	}
}

void City::move()
{

}


//Organism *getOrganism(int x, int y);
//{
//	return "Bicycle implementation of BlowHorn()";
//}