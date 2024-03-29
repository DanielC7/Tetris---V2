#ifndef _BOARD_H_
#define _BOARD_H_
#include "Point.h"
#include "TetrisObject.h"

class Board {
	enum { BORDER_WIDTH = 1, OFFSET_TOP = 3 };
	enum { WIDTH = 10 + (2 * BORDER_WIDTH), HEIGHT = 15 + (2 * BORDER_WIDTH) + OFFSET_TOP }; //WIDTH = 12, HEIGHT = 20

	Point body[WIDTH][HEIGHT];
	Color color;

public:
	void init();

	void draw();

	bool checkBottomCollision(TetrisObject piece);
	
	bool checkSideCollision(TetrisObject piece, int dir);
	
	void update(TetrisObject piece);
	
	void checkFullRow(int& score);
	
	void deleteRow(int i);
	
	bool checkGameOver();
	
	void detonate(int x, int y, int& score);
	
	void fixJokerMove(TetrisObject piece);

	bool isRowContainsJoker(int row);
	
	char getBoardCh(int x, int y) {
		return body[x][y].getCh();
	}
	
	int getBoardColor(int x, int y) {
		return body[x][y].getColor();
	}
	bool isRotatable(TetrisObject piece);
};

#endif