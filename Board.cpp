#include <iostream>
#include "Board.h"

//Init the board ('+' for the border, ' ' for the game board (10x15)
void Board::init() {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			//Check if a certain row/col is a border
			if ((i == 0 && j >= 3) || (i == 11 && j >= 3) || j == 3 || j == 19) 
				body[i][j].setPoint(i, j, '+');
			else
				body[i][j].setPoint(i, j, ' ');
		}
	}
}

//Draw the board
void Board::draw() {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = OFFSET_TOP; j < HEIGHT; j++) {
			body[i][j].draw();
		}
	}
}

//Check if a piece collides with the bottom of the board (meaning the piece can't move down anymore)
bool Board::checkBottomCollision(TetrisObject piece) {
	for (int i = 0; i < piece.getSize(); i++) {
		if (piece.getType() == TetrisObject::Type::BOMB) { //If it's a bomb, check if it hits the border or other pieces
			if (this->body[piece.getBody(i).getX()][piece.getBody(i).getY()].getCh() == '#')
				return true;
			else if (this->body[piece.getBody(i).getX()][piece.getBody(i).getY() + 1].getCh() == '+')
				return true;
		} else if (piece.getType() == TetrisObject::Type::JOKER) { //If it's a joker check if it hits the border only, otherwise let it through
			if (this->body[piece.getBody(i).getX()][piece.getBody(i).getY() + 1].getCh() == '+')
				return true;
		} else if (this->body[piece.getBody(i).getX()][piece.getBody(i).getY() + 1].getCh() != ' ') //Every other piece can't hit anything 
				return true;
	}
	return false;
}

//Update the points on the board when a piece has settled on the board
void Board::update(TetrisObject piece) {
	for (int i = 0; i < piece.getSize(); i++) {
		this->body[piece.getBody(i).getX()][piece.getBody(i).getY()].setPoint(piece.getBody(i).getX(), piece.getBody(i).getY(), piece.getBody(i).getCh(), piece.getBody(i).getColor());
		
		//If it's a joker, mark it as a joker for score calculations (in other functions)
		if (piece.getType() == TetrisObject::Type::JOKER)
			this->body[piece.getBody(i).getX()][piece.getBody(i).getY()].setIsJoker(true);
	}

	//Draw the board after it was updated
	draw();
}

//Check is there is a full row on the board that needs to be deleted
void Board::checkFullRow(int& score) {
	bool fullRow = true;
	int rowsDeleted = 0;

	for (int j = OFFSET_TOP + 1; j < HEIGHT - 1; j++) {
		fullRow = true;

		for (int i = 1; i < WIDTH - 1; i++) 
			if (body[i][j].getCh() == ' ')
				fullRow = false;

		if (fullRow) {
			rowsDeleted++;

			if (isRowContainsJoker(j) == true)
				score += 50;
			else
				score += 100;
			
			//Delete a full row and redraw the board
			deleteRow(j);
			draw();
		}
	}

	//Give bonuses for double, triple, tetris
	if (rowsDeleted == 2)
		score += 100; //Double line clear
	else if (rowsDeleted == 3)
		score += 200; //Triple line clear
	else if (rowsDeleted == 4)
		score += 400; //Tetris line clear - 4 lines at once (!)
}

//Delete a full row off the board
void Board::deleteRow(int row) {
	for (int j = row; j > OFFSET_TOP + 1; j--) {
		for (int i = 1; i < WIDTH - 1; i++) {
			body[i][j].setPoint(body[i][j].getX(), body[i][j].getY(), body[i][j - 1].getCh(), body[i][j - 1].getColor());
			body[i][j].setIsJoker(false);
		}
	}

	//For an animation effect
	Sleep(90);
}

//Check if game is over - when a piece hits the top of the board
bool Board::checkGameOver() {
	for (int i = 1; i < WIDTH - 1; i++) {
		if (body[i][OFFSET_TOP + 1].getCh() == '#') {
			return true;
		}
	}
	return false;
}

//Check if a piece is not colliding in the side of other pieces on the board
bool Board::checkSideCollision(TetrisObject piece, int dir) {

	//A joker can move over other blocks
	if (piece.getType() != TetrisObject::Type::JOKER) {
		for (int i = 0; i < piece.getSize(); i++) {
			if ((dir && piece.getBody(i).getCh() == this->body[piece.getBody(i).getX() + 1][piece.getBody(i).getY()].getCh()) ||
				(!dir && piece.getBody(i).getCh() == this->body[piece.getBody(i).getX() - 1][piece.getBody(i).getY()].getCh()))
				return false;
		}
	} else 
		return piece.isLegalMoveSides(dir);

	return true;				
}


//Detonate a block of 3x3 hit by a bomb piece
void Board::detonate(int x, int y, int& score) {  
	int piecesCounter = 0;

	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (body[i][j].getCh() != '+') {
				if (body[i][j].getCh() != ' ')
					piecesCounter++;

				//Set the points the were bombed to be ' ' (white space)
				body[i][j].setPoint(body[i][j].getX(), body[i][j].getY(), ' ');
				body[i][j].setIsJoker(false);
			}
		}
	}

	//Update the score according to the number of pieces that the bomb hit
	score = score - piecesCounter * 50;

	//Score cannot be zero
	if (score < 0)
		score = 0;
}

//Fix the joker while hovering on other pieces - prints back the original color of the pieces that were under the joker
void Board::fixJokerMove(TetrisObject piece) {
	//Get the coordinates of the piece
	int x = piece.getBody(0).getX();
	int y = piece.getBody(0).getY();

	//OffsetY will change to -1 to check the point on top of the current position of the piece
	int offsetY;

	for (int i = 0; i < 10; i++) { //This loop is for improved reaction

		//OffsetX will chane to -1, 0, 1 to check the points on the sides (-1 = left, 1 = right, 0 = top - when offsetY is -1 only)
		for (int offsetX = -1; offsetX < 2; offsetX++) {

			offsetY = (offsetX == 0) ? 1 : 0;

			char tempCh = body[x + offsetX][y - offsetY].getCh();
			int tempColor = body[x + offsetX][y - offsetY].getColor();

			//If the point that are being check was # than change it back to it's original color
			if (tempCh == '#') {
				Point(x + offsetX, y - offsetY, '#', tempColor).draw();
			}
		}
	}
	
}

//Check if a certain row given as a parameter cotains a joker - for score purposes
bool Board::isRowContainsJoker(int row) {
	for (int i = 1; i < WIDTH - 1; i++) {
		if (body[i][row].isJokerPoint()) {
			return true;
		}
	}
	return false;
}

//Check if the line piece can rotate without heating other pieces on the board
bool Board::isRotatable(TetrisObject piece) {
	for (int i = 0; i < piece.getSize(); i++) {
		int newX = -1 * (piece.getBody(i).getY() - piece.getBody(1).getY()) + piece.getBody(1).getX();
		int newY = 1 * (piece.getBody(i).getX() - piece.getBody(1).getX()) + piece.getBody(1).getY();

		if (this->body[newX][newY].getCh() != ' ')
			return false;
	}
	return true;
}