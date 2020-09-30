#include "Human.h"

Human::Human()
{
	string humanNam;
	cout << "Enter your name: ";
	cin >> humanNam;
	this->name = name;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->Board[i][j] = 0;
		}
	}
	this->choosePosition();
}
void Human::choosePosition()
{
	cout << "Choosing ship postion!" << endl;
	for (int i = 0; i < 3; i++)
	{
		while (1)
		{
			char direct;
			int x, y;
			// ship 1
			cout << "Enter ship" << i + 1 << "[x,y] and direct (h or v ): "; // horizontal:ngang, vertizontal: doc
			cin >> x >> y >> direct;
			if (checkShipPosition(x, y, direct))
			{
				if (direct == 'h')
				{
					Board[x - 1][y] = 1;
					Board[x][y] = 1;
					Board[x + 1][y] = 1;
				}
				if (direct == 'v')
				{
					Board[x][y - 1] = 1;
					Board[x][y] = 1;
					Board[x][y + 1] = 1;
				}
				break;
			}
			else {
				cout << "Your posion you type is invalid, please enter Ship[x,y] one more time!" << endl;
			}
		}

	}




}

void Human::shoot()
{
	cout << "Enter shoot positon: [x,y]= ";
	cin >> shootPositon[0] >> shootPositon[1];
}


bool Human::checkShipPosition(int x, int y, int direct)
{
	if (direct == 'h')
	{
		if(Board[x - 1][y] == 1) return false;
		if(Board[x][y] == 1) return false;
		if(Board[x + 1][y] == 1) return false;
	}
	if (direct == 'v')
	{
		if (Board[x][y-1] == 1) return false;
		if (Board[x][y] == 1) return false;
		if (Board[x][y=1] == 1) return false;
	}
	return true;
}
Human::~Human()
{

}
