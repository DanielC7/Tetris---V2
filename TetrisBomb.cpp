#include "TetrisBomb.h"


//Init a piece
void TetrisBomb::init() {
	setType(TetrisObject::Type::BOMB);
	size = 1;
	rotates = false;
	setColor(Color::LIGHTRED);
	body[0].setPoint(6, 4, '@', color);
}