#include <iostream>
#include "Art.h"
#include "io_utils.h"

using namespace std;

//Print the menu
void printMenu() {
	setTextColor(Color::LIGHTGREY);
	gotoxy(22, 0);
	cout << "Menu:";
	gotoxy(22, 1);
	cout << "(1) New Game";
	gotoxy(22, 2);
	cout << "(2) Pause/Resume";
	gotoxy(39, 0);
	cout << "(3) Speed Down";
	gotoxy(39, 1);
	cout << "(4) Speed Up";
	gotoxy(39, 2);
	cout << "(9) Exit Game";
}

//Print Game Over big text
void printGameOver() {
	setTextColor(Color::LIGHTRED);
	gotoxy(16, 3);
	cout << R"( _______  _______  _______  _______ )" << endl;
	gotoxy(16, 4);
	cout << R"((  ____ \(  ___  )(       )(  ____ \)" << endl;
	gotoxy(16, 5);
	cout << R"(| (    \/| (   ) || () () || (    \/)" << endl;
	gotoxy(16, 6);
	cout << R"(| |      | (___) || || || || (__    )" << endl;
	gotoxy(16, 7);
	cout << R"(| | ____ |  ___  || |(_)| ||  __)   )" << endl;
	gotoxy(16, 8);
	cout << R"(| | \_  )| (   ) || |   | || (      )" << endl;
	gotoxy(16, 9);
	cout << R"(| (___) || )   ( || )   ( || (____/\)" << endl;
	gotoxy(16, 10);
	cout << R"((_______)|/     \||/     \|(_______/)" << endl << endl;

	gotoxy(16, 11);
	cout << R"( _______           _______  _______ )" << endl;
	gotoxy(16, 12);
	cout << R"((  ___  )|\     /|(  ____ \(  ____ ))" << endl;
	gotoxy(16, 13);
	cout << R"(| (   ) || )   ( || (    \/| (    )|)" << endl;
	gotoxy(16, 14);
	cout << R"(| |   | || |   | || (__    | (____)|)" << endl;
	gotoxy(16, 15);
	cout << R"(| |   | |( (   ) )|  __)   |     __))" << endl;
	gotoxy(16, 16);
	cout << R"(| |   | | \ \_/ / | (      | (\ (   )" << endl;
	gotoxy(16, 17);
	cout << R"(| (___) |  \   /  | (____/\| ) \ \__)" << endl;
	gotoxy(16, 18);
	cout << R"((_______)   \_/   (_______/|/   \__/)" << endl << endl;
}

//Print TETRIS big text
void printTetris() {
	setTextColor(Color::LIGHTRED);
	gotoxy(9, 11);
	cout << R"( _|_|_|_|_| )" << endl;
	gotoxy(9, 12);
	cout << R"(     _| )" << endl;
	gotoxy(9, 13);
	cout << R"(     _| )" << endl;
	gotoxy(9, 14);
	cout << R"(     _| )" << endl;
	gotoxy(9, 15);
	cout << R"(     _| )" << endl << endl;

	setTextColor(Color::MAGENTA);
	gotoxy(23, 11);
	cout << R"( _|_|_|_| )" << endl;
	gotoxy(23, 12);
	cout << R"( _|)" << endl;
	gotoxy(23, 13);
	cout << R"( _|_|_|)" << endl;
	gotoxy(23, 14);
	cout << R"( _|)" << endl;
	gotoxy(23, 15);
	cout << R"( _|_|_|_| )" << endl << endl;

	setTextColor(Color::YELLOW);
	gotoxy(35, 11);
	cout << R"( _|_|_|_|_| )" << endl;
	gotoxy(35, 12);
	cout << R"(     _| )" << endl;
	gotoxy(35, 13);
	cout << R"(     _| )" << endl;
	gotoxy(35, 14);
	cout << R"(     _| )" << endl;
	gotoxy(35, 15);
	cout << R"(     _| )" << endl << endl;

	setTextColor(Color::LIGHTGREEN);
	gotoxy(49, 11);
	cout << R"( _|_|_|   )" << endl;
	gotoxy(49, 12);
	cout << R"( _|    _| )" << endl;
	gotoxy(49, 13);
	cout << R"( _|_|_|   )" << endl;
	gotoxy(49, 14);
	cout << R"( _|    _| )" << endl;
	gotoxy(49, 15);
	cout << R"( _|    _| )" << endl << endl;

	setTextColor(Color::LIGHTCYAN);
	gotoxy(61, 11);
	cout << R"( _|_|_| )" << endl;
	gotoxy(61, 12);
	cout << R"(   _|   )" << endl;
	gotoxy(61, 13);
	cout << R"(   _|   )" << endl;
	gotoxy(61, 14);
	cout << R"(   _|   )" << endl;
	gotoxy(61, 15);
	cout << R"( _|_|_| )" << endl << endl;

	setTextColor(Color::LIGHTMAGENTA);
	gotoxy(71, 11);
	cout << R"(   _|_|_| )" << endl;
	gotoxy(71, 12);
	cout << R"( _|       )" << endl;
	gotoxy(71, 13);
	cout << R"(   _|_|   )" << endl;
	gotoxy(71, 14);
	cout << R"(       _| )" << endl;
	gotoxy(71, 15);
	cout << R"( _|_|_|   )" << endl << endl;

	setTextColor(Color::WHITE);
	gotoxy(33, 20);
	cout << "D a n i e l   C o h e n" << endl;
	gotoxy(36, 22);
	cout << "T a l   K o r e n" << endl;

	Sleep(3000);
	system("cls");
}