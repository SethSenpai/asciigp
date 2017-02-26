#include "stdafx.h"
#include "pFunc.h"
#include "Structures.h"

pFunc::pFunc()
{
}

bool pFunc::checkMove(Point currentPosition, int allowedMove, int move)
{
	if (currentPosition.x + 1 < worldHeight && move == 1) {
		return true;
	}
}


pFunc::~pFunc()
{
}
