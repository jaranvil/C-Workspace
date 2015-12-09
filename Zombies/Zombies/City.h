#ifndef _CITY_H
#define _CITY_H
#include <iostream>
#include "Organism.h"
using namespace std;


const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{

public:
	bool temp = true;
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];
	int gridStart[GRID_HEIGHT][GRID_WIDTH];
	City();
	virtual ~City();

	Organism *getOrganism(int x, int y);
	void setOrganism(Organism *organism, int x, int y);

	void startPositions();
	void drawCity();
	void move();

	friend ostream& operator<<(ostream &output, City &city);

};



#endif

