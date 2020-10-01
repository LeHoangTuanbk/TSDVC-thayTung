#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;
class Player
{
public:
	string name;
	int score;
	int shootPosition[2]; //x,y
	int Board[10][10];
	virtual void choosePosition() = 0;
	virtual void shoot() = 0;
	void setBoard(int x, int y, int v);
	int getBoard(int x, int y);
};

