#include "stdafx.h"
#include "pFunc.h"
#include "Structures.h"
#include "ConstVar.h"
#include <iostream>

using std::cout;
using std::endl;

void errorMessage(int i)
{
	switch (i)
	{
	case 1:
		cout << "% You can't go that way!" << endl;
		break;
	case 2:
		cout << "% Move command not recognised." << endl;
		break;
	case 3:
		cout << "% Command not recognised." << endl;
		break;
	default:
		break;
	}
}

int checkMove(Point currentPosition, int allowedMove, int move)
{
	// 0 == cant move, 1 == north, 2 == east, 3 == south, 4 == west
	if (currentPosition.x + 1 < worldHeight && move == 3) {
		//south
		if (allowedMove == 1234 || allowedMove == 13 || allowedMove == 3 || allowedMove == 234) 
		{
			return 3;
		}
		return 0;
	}

	else if (currentPosition.x - 1 > -1 && move == 1) {
		//north
		if (allowedMove == 1234 || allowedMove == 13 || allowedMove == 1)
		{
			return 1;
		}
		return 0;
	}
	
	else if (currentPosition.y + 1 < worldWidth && move == 2) {
		//east
		if (allowedMove == 1234 || allowedMove == 24 || allowedMove == 2 || allowedMove == 234)
		{
			return 2;
		}
		return 0;
	}

	else if (currentPosition.y - 1 > -1 && move == 4) {
		//west
		if (allowedMove == 1234 || allowedMove == 24 || allowedMove == 4 || allowedMove == 234)
		{
			return 4;
		}
		return 0;
	}
	else
	{
		return 0;
	}

}
