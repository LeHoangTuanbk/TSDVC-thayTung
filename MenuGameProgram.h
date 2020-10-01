#pragma once
#include "MenuProgram.h"
class MenuGameProgram : public MenuProgram
{
public:
	MenuGameProgram();
	void startGame();
	void seeHighScore();
	void gameIntroduction();
	~MenuGameProgram();
protected:
	void printMenu();
	void doTask(const int& choice);


};

