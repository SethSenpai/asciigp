#include "stdafx.h"
#include "WorldChunk.h"
#include <string>

string Chunk::getChunk(int type) {
	switch (type)
	{
	case 1:
		return "You find yourself in an empty room. You can go forward or backward.";
		break;

	case 2:
		return "You find yourself in a dead-end, no other way to go but back.";
		break;
	default:
		return "The void calls out to you. Nothingness envelops you as your life drains from your body in an eternal space of nothingness.";
		break;
	}
	return 0;
}
// 0 == cant move, 1 == forward, 2 == right, 3 == back, 4 == left
int Chunk::getMoveDiretions(int type) {
	switch (type)
	{
	case 1:
		return 13;
		break;
	case 2:
		return 3;
		break;

	default:
		return 0;
		break;
	}
}

