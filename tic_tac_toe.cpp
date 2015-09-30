#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <regex>
using namespace std;

// protoptypes 
class Board;
string getMoveChoice();
bool turnChoice();
void playerMove();
void computerTurn();
bool checkWin();

class Validator
{
public:
	bool validate(string* inputString)
	{
		char tempKey;
		const static int maxLineLength = 20;

		do {
			tempKey = _getch();
			if ((tempKey >= 32 && tempKey <= 126)) { //ASCI range
													 //when valid char is pressed, accept and print to screen
				if (maxLineLength > (*inputString).length())
				{
					(*inputString) += tempKey;
					printf("%c", tempKey);
				}
			}
			else if (tempKey == 8) { //backspace
				if ((*inputString).length() > 0) // verify there is something to delete
				{
					(*inputString).erase((*inputString).length() - 1);
					printf("\b \b");
				}
			}
			else if (tempKey == -32) // arrow
			{
				printf("\n");
			}
		} while (tempKey != 13);

		return true;
	} // end method
}; // end class

class Board
{
private:
	const int GRID_SIZE = 3;
	int grid[][3];
public:
	Board()
	{
		// setup grid
		for (int row = 0; row < GRID_SIZE; row++) {
			for (int col = 0; col < GRID_SIZE; col++) {
				grid[row][col] = 0;
			}
		}
	}

	// property procedures 
	int getVal(int row, int col)
	{
		return grid[row][col];
	}

	void setVal(int row, int col, int val)
	{
		grid[row][col] = val;
	}

	void draw()
	{
		cout << "\n" << endl;
		for (int row = 0; row < GRID_SIZE; row++) {
			if (row == 0)
			{
				cout << " (y)" << endl;
			}
			for (int col = 0; col < GRID_SIZE; col++) {

				if (col == 0)
					cout << " " << row + 1 << " ";

				int num = grid[row][col];
				string value = "";

				if (num == 0)
					value = " ";
				else if (num == 1)
					value = "X";
				else if (num == 2)
					value = "O";

				cout << "| " << value << " ";
				if (col == 2)
				{
					cout << "|" << endl;
				} 
			}
		}
		
		cout <<  "     1   2   3   (x)" << endl << endl;
	}
};

class AI
{
private:
	
	int moveCount = 0;
public:
	AI()
	{
		// constructor
	}



};

Board board;

int main()
{
	bool AITurn = false;
	bool winner = false;

	cout << "Welcome to Tic Tac Toe!" << endl << endl;
	board.draw();

	if (turnChoice())
		AITurn = true;

	while (!winner)
	{
		AITurn = AITurn != true;

		if (AITurn)
			computerTurn();
		else
			playerMove();

		system("CLS");
		board.draw();

		if (checkWin())
			break;
	}
	
	_getch();
	return 0;
}

bool turnChoice ()
{
	string input;
	Validator myVal;
	cout << "Would you like to go first? (y/n)" << endl;
	if (myVal.validate(&input)) {
		if (input == "n" || input == "N")
		{
			return false;
		}
		else if (input == "Y" || input == "y")
		{
			return true;
		}
		else {
			main();
		}
	}
	else {
		cout << "The input " << input << " is not valid" << endl;
		_getch();
		main();
	}
}

void playerMove()
{
	string choice = getMoveChoice();
	int x, y;
	string Sx = choice.substr(0, choice.find(","));
	string Sy = choice.substr(choice.find(",") + 1, choice.length());

	if ((Sx == "1" || Sx == "2" || Sx == "3") && (Sy == "1" || Sy == "2" || Sy == "3"))
	{
		sscanf_s(Sx.c_str(), "%d", &x);
		sscanf_s(Sy.c_str(), "%d", &y);

		board.setVal(y-1, x-1, 2);
	}
	else
	{
		cout << endl << "invalid input";
		_getch();
		getMoveChoice();
	}
}

string getMoveChoice()
{
	string input;
	Validator myVal;

	cout << endl << "Enter the position of your move. eg: x,y" << endl;

	if (myVal.validate(&input)) {

		// validate x,y input

		//if (regex_match(input, regex{ "/\d\,\d/g" }))
		//{
		//	cout << "match";
		//}
		//else {
		//	cout << "not match";
		//}

		return input;
	}
	else {
		cout << "The input " << input << " is not valid" << endl;
		_getch();
		getMoveChoice();
	}
}

void computerTurn()
{
	bool firstMove = true;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (board.getVal(row, col) != 0)
				firstMove = false;
		}
	}

}

bool checkWin()
{
	return true;
}