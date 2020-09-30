#include "MenuGameProgram.h"
#include "GameControl.h"
MenuGameProgram::MenuGameProgram()
{
}

void MenuGameProgram::printMenu()
{
	cout << "1. Start the game" << endl;
	cout << "2. See high score" << endl;
	cout << "3. Rules of game" << endl;
}

void MenuGameProgram::doTask(const int& choice)
{
	switch (choice)
	{
	case 1: startGame(); break;
	case 2: seeHighScore(); break;
	case 3: gameIntroduction(); break;
	default: // need catch exeption users o day
		break;
	}

}

void MenuGameProgram::startGame()
{
	GameControl gamecontrol;
	gamecontrol.run();
}

void MenuGameProgram::seeHighScore()
{
	string lineName,lineScore;
	ifstream playersName("playersName.txt");
	ifstream score("score.txt");
	while (getline(playersName, lineName))
	{
		getline(score, lineScore);
		cout << "Name: "<< lineName << " , " << "Score: " << lineScore << endl;
	}
	system("pause");
}

void MenuGameProgram::gameIntroduction()
{
	cout << endl <<"Sink all the oppoenent's ship and you will win. " << endl;
	system("pause");

}

MenuGameProgram::~MenuGameProgram()
{
	//delete object
}


