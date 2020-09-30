#include "MenuProgram.h"
void MenuProgram::run()
{
	bool running = true;
	while (running)
	{
		clearConsole();
		printTitle();
		printMenu();
		int choice = getChoice();
		if (choice == EXIT) running = false;
		doTask(choice);
	}
}

int MenuProgram::getChoice()
{
	cout << "Choose an option (0 to quit): ";
	int choice;
	cin >> choice;

	return choice;
}

void MenuProgram::clearConsole()
{
	system("CLS");
}

void MenuProgram::printTitle()
{
	cout << "---------------------------------------------------" << endl;
	cout << "*******************BATTLESHIP GAME*****************" << endl;
	cout << "---------------------------------------------------" << endl;
}
