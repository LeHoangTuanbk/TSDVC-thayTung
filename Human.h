#pragma once
#include "Player.h"
class Human : public Player
{
public:
	Human();
	int Board[10][10];
	void choosePosition();
	bool checkShipPosition(int x, int y, int direct);
	void shoot();
	~Human();
};

