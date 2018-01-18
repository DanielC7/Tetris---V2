#include "Point.h"

//Draw a point on the screen accodring to it's character, color and coordinates
void Point::draw() {
	setTextColor(color);
	gotoxy(x, y);
	cout << ch << endl;
}

//Draw a point on the screen with a new character instead of it's own character
void Point::draw(char newCh) {
	setTextColor(color);
	gotoxy(x, y);
	cout << newCh << endl;
}