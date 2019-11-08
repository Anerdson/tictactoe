#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = '_';
		}
	}
}

void Board::setCell(int i, int j, char c) {
	b[i][j] = c;
}

char Board::getCell(int i, int j) const{
	return b[i][j];
}

void Board::printBoard() {
	string midLine = " ----+---+----";
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << " | " << b[i][j];
		}
		cout << " |" << endl;
		if (i < 2) {
			cout << midLine << endl;
		}
	}
}