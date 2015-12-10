#ifndef _Organism_H
#define _Organism_H
#include <iostream>
//#include "City.h"

using namespace std;

class Organism
{
protected:
	
	
	int width;
	int height;
	
	//City *city;

	enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	int x;
	int y;
	int age = 0;
	bool moved = false;;
	Organism();
	//Organism(City *city, int width, int height);
	virtual ~Organism();

	virtual void draw();
	virtual void move();
	virtual int whatAmI();
	virtual void action();
	//virtual void spawn() = 0;
	//virtual int getSpecies() = 0; //this could also be coded concrete here
	//virtual void getPosition() = 0;

	void setPosition(int x, int y);
	void endTurn();
	bool isTurn();

	friend ostream& operator<<(ostream &output, Organism *organism);
};

#endif
