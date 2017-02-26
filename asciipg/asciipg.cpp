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
Point currentPosition;

///
/// functions
///
void populateWorld(int seed)
{
	for (int i = 0; i < worldHeight; i++) {
		srand(seed * i * time(NULL));
		for (int j = 0; j < worldWidth; j++) {
			Chunk k;
			int w = rand() % 3;
			k.type = w;
			world[i][j] = k;
			cout << w << " ";
		}
		cout << endl;
	}
}

void showCurrentChunk() {
	string description = world[currentPosition.x][currentPosition.y].getChunk(world[currentPosition.x][currentPosition.y].type);
	cout << description << endl;
}


void movePlayer(int direction) {
	// 0 == cant move, 1 == north, 2 == east, 3 == south, 4 == west
	int q = checkMove(currentPosition, world[currentPosition.x][currentPosition.y].getMoveDiretions(world[currentPosition.x][currentPosition.y].type), direction);
	switch (q)
	{
	case 1:
		currentPosition.x--;
		break;
	case 2:
		currentPosition.y++;
		break;
	case 3:
		currentPosition.x++;
		break;
	case 4:
		currentPosition.y--;
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
	populateWorld(234);
	currentPosition.x = 0;
	currentPosition.y = 0;

	//main gameloop
	while (craysh == false)
	{
		showCurrentChunk();
		readCommand();
	
	}

	return 0;
}

