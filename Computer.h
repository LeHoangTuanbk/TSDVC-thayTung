#pragma once
#include "Player.h"
class Computer : public Player
{
public:
	Computer();
	void choosePosition();
	void shoot();
	~Computer();
};

