#pragma once
class Board
{
	char b[3][3]; 
public:
	Board();
	void printBoard();
	void setCell(int i, int j, char c);
	char getCell(int i, int j) const;
	char checkWin();
};

