#ifndef _GAME_H_
#define _GAME_H_

#include "io_utils.h"
#include "Board.h"
#include "TetrisObject.h"
#include "TetrisShape.h"

#include "TetrisBomb.h"
#include "TetrisJoker.h"

class Game {
	enum { NUM_KEYS = 5 };

	Board board;

	TetrisShape shapePiece;
	TetrisJoker jokerPiece;
	TetrisBomb bombPiece;
	TetrisObject *piece = &jokerPiece;

	char menuKeys[5];
	char arrowKeys[5];
	
	bool isPaused;
	bool isGameOver; 
	bool exitFlag;

	int sleepTime;
	int score;
	int piecesDropped;

public:
	void init();

	void run();
	
	void menu(char key);

	void updateGameInfo(int piecesDropped, int score);

	void setMenuKeys(const char* keys) {
		menuKeys[0] = keys[0];
		menuKeys[1] = keys[1];
		menuKeys[2] = keys[2];
		menuKeys[3] = keys[3];
		menuKeys[4] = keys[4];
	}

	void setArrowKeys(const char* keys) {
		arrowKeys[0] = keys[0];
		arrowKeys[1] = keys[1];
		arrowKeys[2] = keys[2];
		arrowKeys[3] = keys[3];
		arrowKeys[4] = keys[4];
	}

	void setSleepTime(int newSleepTime) {
		sleepTime = newSleepTime;
	}

	int getSleepTime() {
		return sleepTime;
	}

	int getDirection(char key);

	int getMenuAction(char key);

	void printGameInfo();

	void randObject();
};

#endif