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
	int iterations = 0;
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];
	int gridStart[GRID_HEIGHT][GRID_WIDTH];
	City();
	virtual ~City();

	//Organism *getOrganism(int x, int y);
	//void setOrganism(Organism *organism, int x, int y);

	Organism* getAt(int x, int y);
	void setAt(int x, int y, Organism *org);

	void startPositions();
	void drawCity();
	void move();
	void action();

	friend ostream& operator<<(ostream &output, City &city);

};



#endif

