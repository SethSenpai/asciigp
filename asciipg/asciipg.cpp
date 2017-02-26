// asciipg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include "WorldChunk.h"
#include "structures.h"
#include "ConstVar.h"
#include "pFunc.h"

using namespace std;

///
///global variables
///
bool craysh = false;
const int worldWidth = 5;
const int worldHeight = 5;
Chunk world[worldHeight][worldWidth];
Point curPos;
Point curPosOld;

///
/// functions
///
void populateWorld(int seed)
{
	Chunk p;
	p.type = 7;
	world[0][0] = p;
	cout << 7 << " ";
	int j = 1;

	for (int i = 0; i < worldHeight; i++) {
		srand(seed + time(NULL) * i);
		for (; j < worldWidth;j++) {
			Chunk k;
			int w = 0;
			k.type = w;
			world[i][j] = k;
			cout << w << " ";			
		}
		j = 0;
		cout << endl;
	}
}

void showCurrentChunk() {
	string description = world[curPos.x][curPos.y].getChunk();
	cout << description << endl;
}


void movePlayer(int direction) {
	// 0 == cant move, 1 == north, 2 == east, 3 == south, 4 == west
	int q = checkMove(curPos, world[curPos.x][curPos.y].getMoveDiretions(), direction);
	switch (q)
	{
	case 1:
		curPosOld = curPos;
		curPos.x--;
		break;
	case 2:
		curPosOld = curPos;
		curPos.y++;
		break;
	case 3:
		curPosOld = curPos;
		curPos.x++;
		break;
	case 4:
		curPosOld = curPos;
		curPos.y--;
		break;
	default:
		errorMessage(1);
		break;
	}
}

void readCommand() {
	char com[100];
	cout << "> ";
	cin.getline(com, 100);
	string coms = com;

	if (coms == "exit")
	{
		craysh = true;
	}
	else if (coms == "back") {
		curPos = curPosOld;
	}

	else if (strncmp(coms.c_str(), "move", strlen("move")) == 0) 
	{
		string dir = coms.substr(5,1);
		
		if (dir == "n") {
			movePlayer(1);
		}
		else if (dir == "e") {
			movePlayer(2);
		}
		else if (dir == "s") {
			movePlayer(3);
		}
		else if (dir == "w") {
			movePlayer(4);
		}
		else
		{
			errorMessage(2);
		}
	}
	else {
		errorMessage(3);
	}
}


int main()
{
	cout << "Welcome to the dungeon adventurer!" << endl << "===================================" << endl;
	populateWorld(time(NULL));
	curPos.x = 0;
	curPos.y = 0;

	//main gameloop
	while (craysh == false)
	{
		showCurrentChunk();
		readCommand();
	
	}

	return 0;
}

