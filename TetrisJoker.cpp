#include "TetrisJoker.h"


//Init a piece
void TetrisJoker::init() {
	setType(TetrisObject::Type::JOKER);
	size = 1;
	rotates = false;
	setColor(Color::LIGHTGREEN);
	body[0].setPoint(6, 4, '#', color);
}