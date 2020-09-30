#include "GameControl.h"

GameControl::GameControl()  // start state
{
	// initilize GameControl, and computer and human
	// start the game
	Computer* com = new Computer;
	this->comG = com; // comGame la con tro, tro den Computer
	this->countTimes = 1;
	showStatus();
	Human* hu = new Human;
	this->huG = hu;
	showStatus(); //showStatus cua game.

}


void GameControl::printMenu()
{
	//need more implement
	cout << "1. Continue play" << endl;
	cout << "2. End game to see the ship boad matrix" << endl;
}

void GameControl::doTask(const int& choice)
{
	switch(choice)
	{
	case 1: continueGame(); break;
	case 2: gameOver(); break;
	default:
		break;
	}
}

void GameControl::showStatus()
{
	cout << "  Computer            Human" << endl;
	if (countTimes == 1) {
		countTimes++;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 34; j++)
			{
				if (i == 0)
				{
					// print 0 . 9 , 0 . 9 truc ox
					if (j < 2) cout << " ";
					if (j == 2 || j == 23) cout << "0";
					if (j > 3 && j < 12) cout << " ";
					if (j == 12 || j == 31) cout << "9";
					if (j > 12 && j < 31) cout << " ";
				}
				else if (i < 11)  // in ra cua thang computer
				{
					if (j < 2 && i!=1 && i !=10) cout << " ";
					if (i == 1 && j == 1) cout << " 0"; // cho truc 0y
					if (i == 10 && j == 1) cout << " 9";
					if (j >= 3 && j <= 12) cout << ".";
					if (j > 12 && j <=22) cout << " "; // in ra khoang trang giua computer va human board
					if (j > 22 && j < 33) cout << ".";
				}
				if (j == 33) cout << endl;

			}
		}
	}
	else
	{
		// start morning there
		// show status new here;
		cout << endl << "The status of battle ship: " << endl;
		cout << "  Computer            Human" << endl;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 34; j++)
			{
				if (i == 0)
				{
					// print 0 . 9 , 0 . 9 truc ox, khong can doi khi showtatus
					if (j < 2) cout << " ";
					if (j == 2 || j == 23) cout << "0";
					if (j > 3 && j < 12) cout << " ";
					if (j == 12 || j == 31) cout << "9";
					if (j > 12 && j < 31) cout << " ";

				}
				else if (i < 11)  // in ra cua thang computer
				{
					if (j < 2 && i != 1 && i != 10) cout << " "; // Khoang trang can le
					if (i == 1 && j == 1) cout << " 0"; // cho truc oy
					if (i == 10 && j == 1) cout << " 9";// cho truc oy 
					if (j >= 3 && j <= 12)
					{
						// In matrix cho thang computer
						switch (comG->Board[i - 1][(j - 3) % 10])
						{
						case 0:
							cout << ".";
							break;
						case  -2:
							cout << "!";
							break;
						case -1:
							cout << "&";
							break;
						case 1:
							cout << "1";
							break;
						}
					}
					if (j > 12 && j <= 22) cout << " "; // in ra khoang trang giua computer va human board
					if (j > 22 && j < 33)
					{
						// In matrix cho thang human
						switch (huG->Board[i - 1][(j - 3) % 10])
						{
						case 0:
							cout << ".";
							break;
						case  -2:
							cout << "!";
							break;
						case -1:
							cout << "&";
							break;
						case 1:
							cout << "1";
							break;
						}
					}
				}
				if (j == 33) cout << endl;
			}
		}
	}
}

void GameControl::continueGame() // continue state
{
	if (!isGameOver()) {
		// show status
		// print shooted position
		// take turn
		// print menu
		// continue game
		showStatus(); // okay
		shootedPosition();
		if (countTimes > 2) //coutTime = 2;start game
		{
			printMenu();
		}
		
	}
	else
	{
		gameOver();
	}
}

void GameControl::takeTurn()
{

}

void GameControl::shootedPosition()
{
	// . : empty,      !: shooted no ship, &: sink, shooted at ship, 1: ship.
	// . : 0, * k in: -2: shooted no ship, -1: sink, shooted at ship, 1: ship havent shooted.
	if (countTimes > 2)
	{
		cout << "Computer shooted at [x,y] = "<<"["<<comG->shootPositon[0]<<","<< comG->shootPositon[1] <<"]"<<endl;
		cout << "Human shooted at [x,y] = " << "[" << huG->shootPositon[0] << "," << huG->shootPositon[1] << "]" << endl;
	}
	comG->shoot();
	int x1 = comG->shootPositon[0];
	int y1 = comG->shootPositon[1];
	if (*huG->Board[x1, y1] == 1 ) // shoot at ship
	{
		*huG->Board[x1, y1] = -1;
	}
	else 
	{
		*huG->Board[x1, y1] = -2;
	}

	huG->shoot();
	int x2 = huG->shootPositon[0];
	int y2 = huG->shootPositon[1];
	if (*comG->Board[x2, y2] == 1) // shoot at ship
	{
		*comG->Board[x2, y2] = -1;
	}
	else
	{
		*comG->Board[x2, y2] = -2;
	}
}

bool GameControl::isGameOver()
{
	// check gameover
	return false;
}

void GameControl::gameOver() // endgame state
{
	//Show result all
	//Print ra x,y shoot, sink, empty. 
	// . : empty,      !: shooted no ship, &: sink, shooted at ship, 1: ship.
	// . : 0, * k in: -2: shooted no ship, -1: sink, shooted at ship, 1: ship havent shooted.
	cout << endl << "The results of battle ship: " << endl;
	cout << "  Computer            Human" << endl;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 34; j++)
		{
			if (i == 0)
			{
				// print 0 . 9 , 0 . 9 truc ox, khong can doi khi showtatus
				if (j < 2) cout << " ";
				if (j == 2 || j == 23) cout << "0";
				if (j > 3 && j < 12) cout << " ";
				if (j == 12 || j == 31) cout << "9";
				if (j > 12 && j < 31) cout << " ";
				
			}
			else if (i < 11)  // in ra cua thang computer
			{
				if (j < 2 && i != 1 && i != 10) cout << " "; // Khoang trang can le
				if (i == 1 && j == 1) cout << " 0"; // cho truc oy
				if (i == 10 && j == 1) cout << " 9";// cho truc oy 
				if (j >= 3 && j <= 12)
				{
					// In matrix cho thang computer
					switch (comG->Board[i-1][(j - 3) % 10])
					{
					case 0: 
						cout << ".";
						break;
					case  -2:
						cout << "!";
						break;
					case -1:
						cout << "&";
						break;
					case 1:
						cout << "1";
						break;
					}
				}
				if (j > 12 && j <= 22) cout << " "; // in ra khoang trang giua computer va human board
				if (j > 22 && j < 33)
				{
					 // In matrix cho thang human
					switch (huG->Board[i-1][(j - 3) % 10])
					{
					case 0:
						cout << ".";
						break;
					case  -2:
						cout << "!";
						break;
					case -1:
						cout << "&";
						break;
					case 1:
						cout << "1";
						break;
					}
				}
			}
			if (j == 33) cout << endl;

		}
	}

	// need implement score sorted

	system("pause");
}

GameControl::~GameControl()
{
	//des players
}