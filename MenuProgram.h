#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define EXIT 0

class MenuProgram
{
public:
	void run();
protected:
	void clearConsole();
	void printTitle();
	virtual void printMenu() = 0;
	virtual int getChoice();
	virtual void doTask(const int& choice) = 0;
};

