#include "Player.h"

void Player::setBoard(int x, int y, int v)
{
	this->Board[x][y] = v;
}

int Player::getBoard(int x, int y)
{
	return this->Board[x][y];
}
