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
		int num = grid[2][2];
		cout << "getVal " << num;
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

		cout << "     1   2   3   (x)" << endl << endl;
	}
};

class AI
{
private:
	int moveCount = 0;
	const int GRID_SIZE = 3;
	int ai_board[][3];
public:
	AI()
	{
		//constructor 
	}

	string getMove(Board p)
	{
		// copy the current state of the board into AI's array
		/*for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
		ai_board[row][col] = p.getVal(row, col);
		}
		}*/

		return checkPossiblePlayerWin(p);
	}

	string checkPossiblePlayerWin(Board p)
	{
		// check horizontals 
		for (int row = 0; row < 3; row++) {
			int X = 0;
			int O = 0;
			int emplyCol = 0;
			for (int col = 0; col < 3; col++) {
				if (p.getVal(row, col) == 1)
					X++;
				if (p.getVal(row, col) == 2)
					O++;
				if (p.getVal(row, col) == 0)
					emplyCol = col;
			}
			cout << p.getVal(2, 2);
			// if possible player win found, block it
			if (O == 2 && X == 0)
				return row + "," + emplyCol;
			X = 0;
			O = 0;
		}

		// check veritcals
		for (int col = 0; col < 3; col++) {
			int X = 0;
			int O = 0;
			int emplyRow = 0;
			for (int row = 0; row < 3; row++) {
				if (ai_board[row][col] == 1)
					X++;
				if (ai_board[row][col] == 2)
					O++;
				if (ai_board[row][col] == 0)
					emplyRow = row;
			}
			// if possible player win found, block it
			if (O == 2 && X == 0)
				return emplyRow + "," + col;
			X = 0;
			O = 0;
		}

		// check diagonal 1
		int X = 0;
		int O = 0;
		int emplyRow = 0;
		int col = 0;
		for (int row = 0; row < 3; row++) {
			if (ai_board[row][col] == 1)
				X++;
			if (ai_board[row][col] == 2)
				O++;
			if (ai_board[row][col] == 0)
				emplyRow = row;
			col++;
		}
		if (O == 2 && X == 0)
			return emplyRow + "," + col;

		// check diagonal 2
		X = 0;
		O = 0;
		emplyRow = 0;
		col = 0;
		for (int row = 2; row > -1; row--) {
			if (ai_board[row][col] == 1)
				X++;
			if (ai_board[row][col] == 2)
				O++;
			if (ai_board[row][col] == 0)
				emplyRow = row;
			col++;
		}
		if (O == 2 && X == 0)
			return emplyRow + "," + col;

		return "";
	}

};

Board board;
AI tom;

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
			//board.setVal(0, 0, 0);
			computerTurn();
		else
			playerMove();

		//system("CLS");
		board.draw();

		if (checkWin())
			break;
	}

	_getch();
	return 0;
}

bool turnChoice()
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

		board.setVal(y - 1, x - 1, 2);
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
	int x, y;
	string choice = tom.getMove(board);

	if (!(choice == ""))
	{
		string Sx = choice.substr(0, choice.find(","));
		string Sy = choice.substr(choice.find(",") + 1, choice.length());

		if ((Sx == "1" || Sx == "2" || Sx == "3") && (Sy == "1" || Sy == "2" || Sy == "3"))
		{
			sscanf_s(Sx.c_str(), "%d", &x);
			sscanf_s(Sy.c_str(), "%d", &y);

			board.setVal(y - 1, x - 1, 1);
		}
	}


}

bool checkWin()
{
	return false;
}