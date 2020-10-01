#pragma once
#include "Player.h"
class Human : public Player
{
public:
	Human();
	void choosePosition();
	bool checkShipPosition(int x, int y, int direct);
	void shoot();
	~Human();
};

