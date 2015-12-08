#ifndef _City_H
#define _City_H
#include "Organism.h"
#include "City.h"

class Zombie : public Organism
{
public:
	Zombie();
	Zombie(City *city, int width, int height);
	virtual ~Zombie();

	string draw();
	void move();
};

#endif
