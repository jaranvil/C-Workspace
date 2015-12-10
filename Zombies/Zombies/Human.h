#ifndef _Human_H
#define _Human_H
#include "Organism.h"
#include "City.h"

class Human : public Organism
{
public:
	Human();
	Human(City *city, int width, int height);
	virtual ~Human();

	City* city;

	void draw();
	void move();
	int whatAmI();
	void action();
};

#endif
