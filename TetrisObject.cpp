#include <iostream>
#include <time.h>
#include "TetrisObject.h"




//Move the piece to the Left, Right, or Down/Drop according the user input
void TetrisObject::move(int dir) {
	//If it's a legal move to the sides (won't hit the borders)
	if (isLegalMoveSides(dir)) {
		for (int i = 0; i < size; i++) {

			//Remove old points off the screen
			body[i].draw(' ');

			if (dir == Direction::LEFT) //left
				body[i].setPoint(body[i].getX() - 1, body[i].getY(), body[i].getCh(), body[i].getColor());

			if (dir == Direction::RIGHT) // right
				body[i].setPoint(body[i].getX() + 1, body[i].getY(), body[i].getCh(), body[i].getColor());

			if (dir == Direction::DOWN) // drop/down
				body[i].setPoint(body[i].getX(), body[i].getY() + 1, body[i].getCh(), body[i].getColor());
		}
	}
}

//Rotate a piece using linear algebra- works only with a LINE piece
void TetrisObject::rotate() {
	bool legal = true;

	//Check if the rotation won't hit the borders
	for (int i = 0; i < size; i++) {
		int newX = -1 * (body[i].getY() - body[1].getY()) + body[1].getX();
		int newY = 1 * (body[i].getX() - body[1].getX()) + body[1].getY();

		if (newX > 10 || newX < 1 || newY > 18 || newY < 4)
			legal = false;
	}

	if (legal)
		for (int i = 0; i < size; i++) {
			//Remove old points off the screen
			body[i].draw(' ');
			//Set the new points
			body[i].setPoint(-1 * (body[i].getY() - body[1].getY()) + body[1].getX(), 1 * (body[i].getX() - body[1].getX()) + body[1].getY(), body[i].getCh(), body[i].getColor());
		}
}

//Draw the piece on the screen
void TetrisObject::draw() {
	for (int i = 0; i < size; i++) {
		body[i].draw();
	}
}

//Check if a move is legal, meaning the piece is inside the borders
bool TetrisObject::isLegalMoveSides(int dir) {
	if (dir == Direction::LEFT) {
		for (int i = 0; i < size; i++) {
			if (body[i].getX() < 2)
				return false;
		}
	}

	if (dir == Direction::RIGHT) {
		for (int i = 0; i < size; i++) {
			if (body[i].getX() > 9)
				return false;
		}
	}

	return true;
}