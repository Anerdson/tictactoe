#pragma once
#include "Board.h"
#include <iostream>
using namespace std;

class Game
{
public:
	Board b;
	int turn;
	string p1, p2;
	Game();
	void play();
	char placeSymbol(int input, char symbol);
};

/*
1. ask # of players**
2. start game
3. generate board
4. print example board showing cell ids, print current board
5. ask for cell
6. check for cell validity, then check for win
7. if no win, repeat from 4
*/