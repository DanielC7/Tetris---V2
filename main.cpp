#include <windows.h>
#include <iostream>
#include "Art.h"
#include "Game.h"

using namespace std;

int main() {

	hideCursor();

	Game game;

	printTetris();
	game.init();
	game.run();

    system("pause");
	return 0;
}