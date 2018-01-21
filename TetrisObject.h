#ifndef _TETRISOBJECT_H_
#define _TETRISOBJECT_H_

#include <cstring>
#include <iostream>
#include <time.h>
#include "Point.h"


class TetrisObject {
public:
	enum Type { SQUARE, LINE, PLUS, Z, L, BOMB, JOKER};

protected:
	enum { SIZE = 4 };
	Point body[SIZE];
	Type type;
	Color color;
	bool rotates;
	int size;

public:
	//TetrisObject() {
	//	cout << "Nihao";
	//}

	virtual void init() {};

	void move(int dir);

	void draw();

	void rotate();

	bool isLegalMoveSides(int dir);

	void setType(int newType) {
		type = (Type)newType;
	}

	int getType() {
		return (int)type;
	}

	int getSize() {
		return size;
	}

	void setSize(int newSize) {
		size = newSize;
	}

	Point getBody(int i) {
		return body[i];
	}

	void setBody(int i, Point newPoint) {
		body[i] = newPoint;
	}

	void setColor(Color c) {
		color = c;
	}

	bool getRotatability() {
		return rotates;
	}
};
#endif