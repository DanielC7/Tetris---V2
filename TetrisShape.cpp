#include "TetrisShape.h"

//Init a piece - random piece each time
void TetrisShape::init()  {
	//Generate random type of piece
	srand((unsigned int)time(NULL));
	int randomType = rand() % 5;

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

	}
	else if (type == Type::SQUARE) {
		size = 4;
		rotates = false;
		setColor(Color::YELLOW);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(7, 4, '#', color);
		body[3].setPoint(7, 5, '#', color);

	}
	else if (type == Type::PLUS) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTMAGENTA);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(6, 6, '#', color);
		body[3].setPoint(7, 5, '#', color);

	}
	else if (type == Type::Z) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTRED);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(6, 5, '#', color);
		body[2].setPoint(7, 5, '#', color);
		body[3].setPoint(7, 6, '#', color);

	}
	else if (type == Type::L) {
		size = 4;
		rotates = true;
		setColor(Color::LIGHTBLUE);
		body[0].setPoint(6, 4, '#', color);
		body[1].setPoint(7, 4, '#', color);
		body[2].setPoint(7, 5, '#', color);
		body[3].setPoint(7, 6, '#', color);

	}

}