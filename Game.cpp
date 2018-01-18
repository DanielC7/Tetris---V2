#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Art.h"

//Init the game
void Game::init() {
	setArrowKeys("adxws");
	setMenuKeys("12349");

	exitFlag = false;
	isPaused = false;
	isGameOver = false;

	//Init the board
	board.init();

	//Init the first piece
	piece.init();

	//Draw the board
	board.draw();

	//Print the menu
	printMenu();

	//Print the game info format (number of pieces dropped + score)
	printGameInfo();

	sleepTime = 30;
	score = 0;
	piecesDropped = 0;
}

//Run the game
void Game::run() {
    char key = 0;
    int dir;
	int option;
	int distanceCounter = 0;

	//Update game info with inital values
	updateGameInfo(piecesDropped, score);

    do { //While pressing any key to move the pieces
		for (int i = 0; i < 15; i++) {
			if (_kbhit()) {
				key = _getch();

				if ((option = getMenuAction(key)) != -1) 
					menu(option);

				if (!isPaused) {
					if ((dir = getDirection(key)) != -1) {
						//Move the piece left
						if (dir == Direction::LEFT && board.checkSideCollision(piece, Direction::LEFT))       
							piece.move(Direction::LEFT);
						
						//Move the piece right
						if (dir == Direction::RIGHT && board.checkSideCollision(piece, Direction::RIGHT))     
							piece.move(Direction::RIGHT);

						//Drop the piece (Hard drop) 
						if (dir == Direction::DOWN) {

							//Move the piece down until it collides with the pieces on the board
							while (!board.checkBottomCollision(piece)) {
								piece.move(Direction::DOWN);
								distanceCounter++;
							}

							//Calculate hard-drop score according to the piece position
							score += 2 * distanceCounter;
							distanceCounter = 0;
						}
						
						//Rotate the piece - exclude rotation only for line
						if (dir == Direction::ROTATE && piece.getRotatability() && board.isRotatable(piece)) {
							piece.rotate();
						}
						
						//Place a joker on the board
						if (dir == Direction::PUT && piece.getType() == Piece::Type::JOKER) {
							piecesDropped++; 
							board.update(piece);
							board.checkFullRow(score);
							updateGameInfo(piecesDropped, score);
							piece.init();
						}
					}
				} 
			} 

			//If a piece has reached the bottom of the screen
			if (board.checkBottomCollision(piece)) { 

				//If a bomb reached the bottom, detonate a 3x3 block (if exists) and remove the bomb off the board
				if (piece.getType() == Piece::Type::BOMB) {
					board.detonate(piece.getBody(0).getX(), piece.getBody(0).getY(), score); 
					piece.setBody(0, Point(piece.getBody(0).getX(), piece.getBody(0).getY(), ' '));
				}

				//Check game over on every bottom collision, else put the piece on the board, make a new piece and continue the game
				if (!board.checkGameOver()) {
					piecesDropped++;
					board.update(piece);
					piece.init();
					board.checkFullRow(score);
					updateGameInfo(piecesDropped, score);
				} else
					isGameOver = true;
			}

			//Fix joker movement over pieces on the board
			if (piece.getType() == Piece::Type::JOKER)
				board.fixJokerMove(piece);

			//Draw the piece while it's moving
			piece.draw();

			Sleep(sleepTime);
		}

		//If game is over pause the game and print Game Over message
		if (isGameOver) {
			printGameOver();
			isPaused = true;
		}

		//If game is not paused, move the piece down
		if (!isPaused) {
			piece.move(Direction::DOWN);
		}

   } while (!exitFlag); 
}

//Control menu actions
void Game::menu(char key) {
	switch (key) {
		case 0: //Start a new game
			system("cls");
			init();
			run();
			break;

		case 1: //Pause current game
			if (!isPaused) 
				isPaused = true;
			else 
				isPaused = false;
			break;

		case 2: //Accelerate drop speed
			if (sleepTime < 50)
				setSleepTime(sleepTime + 5);
			break;

		case 3: //Slow down drop speed
			if (sleepTime > 10)
				setSleepTime(sleepTime - 5);
			break;

		case 4: //Exit program
			exitFlag = true;
			break;
	}
}

//Find if a pressed key is one of the direction keys (right, left, drop, place joker)
int Game::getDirection(char key) {
	for (int i = 0; i < NUM_KEYS; i++) {
		if (key == arrowKeys[i]) {
			return i;
		}
	}
	return -1;
}

//Find if a pressed key is a menu key (new game, pause, speed up, speed down, exit)
int Game::getMenuAction(char key) {
	for (int i = 0; i < NUM_KEYS; i++) {
		if (key == menuKeys[i]) {
			return i;
		}
	}
	return -1;
}

//Print game info format - number of pieces dropped and score
void Game::printGameInfo() {
	setTextColor(Color::LIGHTCYAN);
	gotoxy(0, 0);
	cout << "Pieces Dropped: " << endl;
	cout << "Score: " << endl;
}

//Update game info - number of pieces dropped and score
void Game::updateGameInfo(int piecesDropped, int score) { 
	setTextColor(Color::LIGHTCYAN);
	gotoxy(16, 0);
	cout << piecesDropped << endl;
	gotoxy(7, 1);
	cout << score << "   " << endl;
}