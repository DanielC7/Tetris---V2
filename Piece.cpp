#include <iostream>
#include <time.h>
#include "Piece.h"

//Init a piece - random piece each time
void Piece::init() {

	//Generate random type of piece
	srand((unsigned int) time(NULL));
	int randomType = rand() % 7;

	//Set a random piece type
	setType(randomType);

	if (type == Type::LINE) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTCYAN);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(6, 6, '#', color);
		body[3].setPoint(6, 7, '#', color);

	} else if (type == Type::SQUARE) {
		size = 4;
		rotates = false;
		setColor(Color::YELLOW);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(7, 4, '#', color);
		body[3].setPoint(7, 5, '#', color);

	} else if (type == Type::PLUS) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTMAGENTA);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(6, 6, '#', color);
		body[3].setPoint(7, 5, '#', color);

	} else if (type == Type::Z) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTRED);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(7, 5, '#', color);
		body[3].setPoint(7, 6, '#', color);

	} else if (type == Type::L) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTBLUE);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(7, 4, '#', color);
		body[2].setPoint(7, 5, '#', color);
		body[3].setPoint(7, 6, '#', color);

	} else if (type == Type::BOMB) {
		size = 1;
		rotates = false;
		setColor(Color::LIGHTRED);
		body[0].setPoint(6, 4, '@', color);

	} else if (type == Type::JOKER) {
		size = 1;
		rotates = false;
		setColor(Color::LIGHTGREEN);
		body[0].setPoint(6, 4, '#', color);
	}
}

//Move the piece to the Left, Right, or Down/Drop according the user input
void Piece::move(int dir) {
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
void Piece::rotate() { 
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
void Piece::draw() {
	for (int i = 0; i < size; i++) {
		body[i].draw();
	}
}

//Check if a move is legal, meaning the piece is inside the borders
bool Piece::isLegalMoveSides(int dir) {
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