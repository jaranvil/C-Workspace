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
	Organism *pNew = city->grid[x][y];
	city->grid[x + 1][y] = pNew;
	city->grid[x][y] = 0;
	pNew->x++;
}
