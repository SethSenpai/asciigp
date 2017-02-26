#include "stdafx.h"
#include "WorldChunk.h"
#include <string>

string Chunk::getChunk(int type) {
	switch (type)
	{
	case 0:
		return "# You are in a open chamber. You can move in any direction.";
		break;
	case 1:
		return "# You find yourself in a hallway. You can go North or South.";
		break;

	case 2:
		return "# You find yourself in a hallway. You can go East or West.";
		break;
	default:
		return "The void calls out to you. Silence envelops you as your life drains from your body in an eternal space of nothingness.";
		break;
	}
	return 0;
}
// 0 == cant move, 1 == north, 2 == east, 3 == south, 4 == west
int Chunk::getMoveDiretions(int type) {
	switch (type)
	{
	case 0:
		return 1234;
		break;
	case 1:
		return 13;
		break;
	case 2:
		return 24;
		break;
		
	default:
		return 0;
		break;
	}
}

