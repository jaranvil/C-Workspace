#include <iostream>
#include <conio.h>
#include <time.h>
#include "City.h"
using namespace std;

class timer {
private:
	unsigned long begTime;
public:
	void start() {
		begTime = clock();
	}

	unsigned long elapsedTime() {
		return ((unsigned long)clock() - begTime) / CLOCKS_PER_SEC; 
	}

	bool isTimeout(unsigned long seconds) {
		return seconds >= elapsedTime();
	}
};

int main()
{

	City city;
	city.startPositions();
	city.drawCity();

	unsigned long seconds = 1;
	timer t;

	
	city.drawCity();
	t.start();

	while (true) {
		if (t.elapsedTime() >= seconds) {
			system("cls");
			cout << "Humans vs. Zombies!" << endl;

			city.move();
			city.drawCity();
			city.action();
			t.start();

		}
		else {
			// do other things
		}
	}


	_getch();
	return 0;
}

