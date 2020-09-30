#pragma once
#include "MenuProgram.h"
#include "Computer.h"
#include "Human.h"

class GameControl : public MenuProgram
{
public:
	GameControl();
	static int countTimes;
	Computer* comG;
	Human* huG;
	void takeTurn();
	void getBoard();
	void gameOver();
	bool isGameOver();
	void continueGame();
	void showStatus();
	~GameControl();
protected:
	void printMenu();
	void doTask(const int& choice);
};

