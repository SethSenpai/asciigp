#include "stdafx.h"
#include "WorldChunk.h"
#include <string>

string Chunk::getChunk() {
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
	case 3:
		return "# You see a dead end. You can only go back.";
		break;
	case 4:
		return "# You see a dead end. You can only go east.";
		break;
	case 5:
		return "# You see a dead end. You can only go south.";
		break;
	case 6:
		return "# You see a dead end. You can only go west.";
		break;
	case 7:
		return "# The dungeon lies before you. You can go south or east. West leads back out of the dungeon.";
		break;

	default:
		return "The void calls out to you. Silence envelops you as your life drains from your body in an eternal space of nothingness.";
		break;
	}
	return 0;
}
// 0 == cant move, 1 == north, 2 == east, 3 == south, 4 == west
int Chunk::getMoveDiretions() {
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
	case 3:
		return 0;
		break;
	case 4:
		return 2;
		break;
	case 5:
		return 3;
		break;
	case 6:
		return 4;
		break;
	case 7:
		return 234;
		break;
		
	default:
		return 0;
		break;
	}
}

