#pragma once
#include "MenuProgram.h"
#include "Computer.h"
#include "Human.h"

class GameControl : public MenuProgram
{
public:
	GameControl();
	int countTimes;
	Computer* comG;
	Human* huG;
	void takeTurn();
	void shootedPosition();
	void gameOver();
	bool isGameOver();
	void continueGame();
	void showStatus();
	~GameControl();
protected:
	void printMenu();
	void doTask(const int& choice);
};

