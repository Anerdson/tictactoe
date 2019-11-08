#include "Board.h"
#include "Game.h"
#include <iostream>
using namespace std;

int main() {
	bool go = true;
	while (go) {
		Game g = Game();
		string in;
		g.play();

		cout << endl << endl << endl << "Play again? (y/n): ";
		cin >> in;

		if (in == "y") {
			cout << flush;
			continue;
		}
		else {
			cout << "Goodbye!";
			break;
		}
		 
	}

	return 0;
}