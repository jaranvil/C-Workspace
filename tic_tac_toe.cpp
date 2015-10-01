#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <regex>
#include <sstream>
using namespace std;

// protoptypes 
class Board;
string getMoveChoice();
bool turnChoice();
void playerMove();
void computerTurn();
int checkWin(int grid[][3]);



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

public:
	int grid[][3];
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

	string getMove(int grid[][3])
	{
		string move;

		// can the AI win this turn?
		move = checkPossibleWin(grid, 1);
		if (!(move == ""))
			return move;

		// can the human win this thurn?
		move = checkPossibleWin(grid, 2);
		if (!(move == ""))
			return move;

		// make other move
		move = chooseOtherMove(grid);

		return move;
	}

	string checkPossibleWin(int grid[][3], int player)
	{
		bool returned = false;
		// check horizontals 
		for (int row = 0; row < 3; row++) {
			int X = 0;
			int O = 0;
			int emplyCol = 0;
			for (int col = 0; col < 3; col++) {
				if (grid[row][col] == 1)
					X++;
				if (grid[row][col] == 2)
					O++;
				if (grid[row][col] == 0)
					emplyCol = col;
			}
			// if possible player win found, block it
			if ((O == 2 && X == 0 && player == 2) || (O == 0 && X == 2 && player == 1)) {
				stringstream move;
				move << row << "," << emplyCol;
				if (grid[row][emplyCol] == 0) {
					return move.str();
					returned = true;
				}
			}

			X = 0;
			O = 0;
		}

		// check veritcals
		for (int col = 0; col < 3; col++) {
			int X = 0;
			int O = 0;
			int emptyRow = 0;
			for (int row = 0; row < 3; row++) {
				if (grid[row][col] == 1)
					X++;
				if (grid[row][col] == 2)
					O++;
				if (grid[row][col] == 0)
					emptyRow = row;
			}
			// if possible player win found, block it
			if ((O == 2 && X == 0 && player == 2) || (O == 0 && X == 2 && player == 1)) {
				stringstream move;
				move << emptyRow << "," << col;

				if (grid[emptyRow][col] == 0) {
					return move.str();
					returned = true;
				}
			}
			X = 0;
			O = 0;
		}

		// check diagonal 1
		int X = 0;
		int O = 0;
		int emptyRow = 0;
		int emptyCol = 0;
		int col = 0;
		for (int row = 0; row < 3; row++) {
			if (grid[row][col] == 1)
				X++;
			if (grid[row][col] == 2)
				O++;
			if (grid[row][col] == 0) {
				emptyRow = row;
				emptyCol = col;
			}

			col++;
		}
		if ((O == 2 && X == 0 && player == 2) || (O == 0 && X == 2 && player == 1)) {
			stringstream move;
			move << emptyRow << "," << emptyCol;

			if (grid[emptyRow][emptyCol] == 0) {
				return move.str();
				returned = true;
			}
		}

		// check diagonal 2
		X = 0;
		O = 0;
		emptyRow = 0;
		emptyCol = 0;
		col = 0;
		for (int row = 2; row > -1; row--) {
			if (grid[row][col] == 1)
				X++;
			if (grid[row][col] == 2)
				O++;
			if (grid[row][col] == 0) {
				emptyRow = row;
				emptyCol = col;
			}

			col++;
		}
		if ((O == 2 && X == 0 && player == 2) || (O == 0 && X == 2 && player == 1)) {
			stringstream move;
			move << emptyRow << "," << emptyCol;

			if (grid[emptyRow][emptyCol] == 0) {
				return move.str();
				returned = true;
			}
		}

		if (!returned)
			return "";
	}

	string chooseOtherMove(int grid[][3])
	{
		if (grid[0][0] == 0)
			return "0,0";
		if (grid[2][2] == 0)
			return "2,2";
		if (grid[0][2] == 0)
			return "0,2";
		if (grid[2][0] == 0)
			return "2,0";

		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				if (grid[row][col] == 0) {
					stringstream choice;
					choice << row << "," << col;
					return choice.str();
				}
			}
		}

		return "";
	}

};

Board board;
AI tom;
int win = 0;

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

		system("CLS");
		board.draw();

		win = checkWin(board.grid);
		if (win > 0)
			break;
	}

	system("CLS");

	if (win == 3) {
		cout << endl << "Tie";
	}
	else if (win == 1) {
		cout << endl << "Computer Wins";
	}
	else if (win == 2) {
		cout << endl << "You Win!";
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
	string choice = tom.getMove(board.grid);

	if (!(choice == ""))
	{
		string Sx = choice.substr(0, choice.find(","));
		string Sy = choice.substr(choice.find(",") + 1, choice.length());

		if ((Sx == "0" || Sx == "1" || Sx == "2") && (Sy == "0" || Sy == "1" || Sy == "2"))
		{
			sscanf_s(Sx.c_str(), "%d", &x);
			sscanf_s(Sy.c_str(), "%d", &y);

			board.setVal(x, y, 1);
		}
	}


}

int checkWin(int grid[][3])
{
	bool returned = false;
	// check horizontals 
	for (int row = 0; row < 3; row++) {
		int X = 0;
		int O = 0;
		int emplyCol = 0;
		for (int col = 0; col < 3; col++) {
			if (grid[row][col] == 1)
				X++;
			if (grid[row][col] == 2)
				O++;
			if (grid[row][col] == 0)
				emplyCol = col;
		}

		if (O == 3 && X == 0) {
			return 2;
		}
		if (O == 0 && X == 3) {
			return 1;
		}

		X = 0;
		O = 0;
	}

	// check veritcals
	for (int col = 0; col < 3; col++) {
		int X = 0;
		int O = 0;
		int emptyRow = 0;
		for (int row = 0; row < 3; row++) {
			if (grid[row][col] == 1)
				X++;
			if (grid[row][col] == 2)
				O++;
			if (grid[row][col] == 0)
				emptyRow = row;
		}
		if (O == 3 && X == 0) {
			return 2;
		}
		if (O == 0 && X == 3) {
			return 1;
		}
		X = 0;
		O = 0;
	}

	// check diagonal 1
	int X = 0;
	int O = 0;
	int emptyRow = 0;
	int emptyCol = 0;
	int col = 0;
	for (int row = 0; row < 3; row++) {
		if (grid[row][col] == 1)
			X++;
		if (grid[row][col] == 2)
			O++;
		if (grid[row][col] == 0) {
			emptyRow = row;
			emptyCol = col;
		}

		col++;
	}
	if (O == 3 && X == 0) {
		return 2;
	}
	if (O == 0 && X == 3) {
		return 1;
	}


	// check diagonal 2
	X = 0;
	O = 0;
	emptyRow = 0;
	emptyCol = 0;
	col = 0;
	for (int row = 2; row > -1; row--) {
		if (grid[row][col] == 1)
			X++;
		if (grid[row][col] == 2)
			O++;
		if (grid[row][col] == 0) {
			emptyRow = row;
			emptyCol = col;
		}

		col++;
	}
	if (O == 3 && X == 0) {
		return 2;
	}
	if (O == 0 && X == 3) {
		return 1;
	}

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (grid[row][col] == 0)
				return 0;
		}
	}

	return 3;
}