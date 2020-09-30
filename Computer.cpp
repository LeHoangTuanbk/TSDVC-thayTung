#include "Computer.h"
Computer::Computer()
{
	this->name = "computer";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->Board[i][j] = 0;
		}
	}
	this->choosePosition();
}

void Computer::choosePosition()
{
	srand(time(0));
	int ship[6]; // chan:0,2,4 x, le:1,3,5 y
	for (int i = 0; i < 6; i++) {
		int r = rand() % 9 ; // 0 den 8
		int j = 1;
		bool flagr = false;
		while ((i % 2) && (j < 6)) // i le
		{
			if (ship[j] == r)
				r = rand() % 10; // lay r den khi khac het y, x giong nhau cung dk
			j += 2;
		}
		ship[i] = r;
	}
	// random tau ngang
	//ship 1
	this->Board[ship[0]][ship[1]] = 1;
	this->Board[ship[0] + 1][ship[1]] = 1;
	this->Board[ship[0] + 2][ship[1]] = 1;
	//ship 2
	this->Board[ship[2]][ship[3]] = 1;
	this->Board[ship[2] + 1][ship[3]] = 1;
	this->Board[ship[2] + 2][ship[3]] = 1;
	//ship 3
	this->Board[ship[4]][ship[5]] = 1;
	this->Board[ship[4] + 1][ship[5]] = 1;
	this->Board[ship[4] + 2][ship[5]] = 1;
}

void Computer::shoot()
{
	srand(time(0));
	int x = rand() % 10; 
	int y = rand() % 10;
	shootPositon[0] = x;
	shootPositon[1] = y;
}

Computer::~Computer()
{

}

