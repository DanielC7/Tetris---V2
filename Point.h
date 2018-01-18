#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"

using namespace std;

class Point {
	int x, y;
	char ch;
	Color color;
	bool joker;

public:
	Point(int newX = 0, int newY = 0, char newCh = ' ', int newColor = Color::WHITE) {
		x = newX;
		y = newY;
		ch = newCh;
		color = (Color)newColor;
		joker = false;
	}

	void draw();

	void draw(char newCh);

	void setPoint(int newX, int newY, char newCh, int newColor = Color::WHITE) {
		x = newX;
		y = newY;
		ch = newCh;
		color = (Color)newColor;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	char getCh() {
		return ch;
	}

	int getColor() {
		return color;
	}

	bool isJokerPoint() {
		return joker;
	}

	void setIsJoker(bool flag) {
		joker = flag;
	}
};

#endif