#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : b(Board()), turn(0), p1(""), p2("") {}

void printEx() {
	string midLine = " ----+---+----";
	for (int i = 0, k = 1; i < 3; i++) {
		for (int j = 0; j < 3; j++, k++) {
			cout << " | " << k;
		}
		cout << " |" << endl;
		if (i < 2) {
			cout << midLine << endl;
		}
	}
}

char checkDone(Board b) {

	//check if any of the rows completely 
	if (b.getCell(0,0) == b.getCell(0,1) && b.getCell(0,1) == b.getCell(0,2)) {
		return b.getCell(0,0);
	}
	else if (b.getCell(1, 0) == b.getCell(1, 1) && b.getCell(1, 1) == b.getCell(1, 2)) {
		return b.getCell(1, 0);
	}
	else if (b.getCell(2, 0) == b.getCell(2, 1) && b.getCell(2, 1) == b.getCell(2, 2)) {
		return b.getCell(2, 0);
	}
	else if (b.getCell(0, 0) == b.getCell(1, 0) && b.getCell(1, 0) == b.getCell(2, 0)) {
		return b.getCell(0, 0);
	}
	else if (b.getCell(0, 1) == b.getCell(1, 1) && b.getCell(1, 1) == b.getCell(2, 1)) {
		return b.getCell(0, 1);
	}
	else if (b.getCell(0, 2) == b.getCell(1, 2) && b.getCell(1, 2) == b.getCell(2, 2)) {
		return b.getCell(0, 2);
	}
	else if (b.getCell(0, 0) == b.getCell(1, 1) && b.getCell(1, 1) == b.getCell(2, 2)) {
		return b.getCell(0, 0);
	}
	else if (b.getCell(2, 0) == b.getCell(1, 1) && b.getCell(1, 1) == b.getCell(0, 2)) {
		return b.getCell(2, 0);
	}
	else {
		//check if the board is full
		bool full = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (b.getCell(i, j) == '_') {
					full = false;
					break;
				}
			}
		}

		if (full) {
			return 'f'; //f will be interpreted as full
		}
		else {
			return 'n';
		}
	}
}

char Game::placeSymbol(int input, char symbol) {

	if (input < 1 || input > 9) {
		return 'o';
	}
	else if (input == 1) {
		if (b.getCell(0, 0) == '_') {
			b.setCell(0, 0, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 2) {
		if (b.getCell(0, 1) == '_') {
			b.setCell(0, 1, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 3) {
		if (b.getCell(0, 2) == '_') {
			b.setCell(0, 2, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 4) {
		if (b.getCell(1, 0) == '_') {
			b.setCell(1, 0, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 5) {
		if (b.getCell(1, 1) == '_') {
			b.setCell(1, 1, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 6) {
		if (b.getCell(1, 2) == '_') {
			b.setCell(1, 2, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 7) {
		if (b.getCell(2, 0) == '_') {
			b.setCell(2, 0, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 8) {
		if (b.getCell(2, 1) == '_') {
			b.setCell(2, 1, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
	else if (input == 9) {
		if (b.getCell(2, 2) == '_') {
			b.setCell(2, 2, symbol);
			return 'g';
		}
		else {
			return 'f';
		}
	}
}

void Game::play() {
	bool done = false;
	char symbol;
	//main loop
	while (true) {
		cout << "Lets play Tic Tac Toe!" << endl << "-------------------" << endl << "Please enter the name of player 1: ";
		cin >> p1;

		cout << endl << "Please enter the name of player 2: ";
		cin >> p2;

		cout << endl << endl << "When prompted, select a square to fill in based on the following number scheme:" << endl;
		printEx();

		//turn loop
		while (!done) {
			string name;
			if (turn == 0) {
				symbol = 'X';
				name = p1;
			}
			else {
				symbol = 'O';
				name = p2;
			}
			cout << endl << endl << endl << "--------- " << name << "'s Turn ---------" << endl << "Current Board: " << endl;
			b.printBoard();
			cout << endl << endl << "Please select a square to place your symbol (" << symbol << ") in square: ";

			//get the chosen square
			int input;
			cin >> input;

			

			//check their input & put it into the board, if valid
			char success = placeSymbol(input, symbol);
			if(cin.fail()){
				cout << "[ERROR] Invalid input, please try again.";
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
			else if (success == 'f') {
				cout << "[ERROR] Square is already full! Please choose another one";
				continue;
			}
			else if (success == 'o') {
				cout << "[ERROR] Please enter a number between 1 and 9.";
				continue;
			}
			else if (success == 'i') {
				cout << "[ERROR] ??? Contact the dev, this shouldn't happen" << endl;
				continue;
			}

			//check if the game has been won
			char check = checkDone(b);
			if (check == 'X') {
				cout << endl << endl << "----------------------------------------" << endl << "The game has been won by " << p1 << endl;
				b.printBoard();
				done = true;
			}
			else if (check == 'O') {
				cout << endl << endl << "----------------------------------------" << endl << "The game has been won by " << p2 << endl;
				b.printBoard();
				done = true;
			}
			else if (check == 'f') {
				cout << endl << endl << "----------------------------------------" << endl << "The game has ended in a draw" << endl;
				b.printBoard();
				done = true;
			}
			else { //switch turns
				if (turn == 0) {
					turn = 1;
				}
				else {
					turn = 0;
				}
			}
		}

		if (done) {
			break;
		}
	}
}

/*
1. ask # of players**
2. start game
3. generate board
4. print example board showing cell ids, print current board
5. ask for cell
6. check for cell validity, then check for win
7. if no win, repeat from 4
*/