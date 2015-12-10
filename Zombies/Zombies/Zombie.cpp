#include <string>
#include <iostream>
#include <conio.h>
#include "Zombie.h"
using namespace std;

Zombie::Zombie(void){}
Zombie::Zombie(City *city, int width, int height) {
	x = width;
	y = height;
	Zombie::city = city;
}
Zombie::~Zombie(void){}

string Zombie::draw()
{
	return "X";
}

void Zombie::move()
{	
	Organism *pOrganism = new Organism; //on heap
	
	*(pOrganism) = *(city->grid[x][y]);
	city->grid[x + 1][y] = pOrganism;
	city->grid[x][y] = NULL;
}
