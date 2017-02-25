// asciipg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "WorldChunk.h"
#include "structures.h"

using namespace std;

///
///global variables
///
bool craysh = false;
const int worldWidth = 3;
const int worldHeight = 5;
Chunk world[worldHeight][worldWidth];
Point currentPosition;

///
/// functions
///
void populateWorld(int seed)
{
	for (int i = 0; i < worldHeight; i++) {
		for (int j = 0; j < worldWidth; j++) {
			srand(seed);
			Chunk k;
			k.type = rand() % 3;			
			world[i][j] = k;
		}
	}
}

void showCurrentChunk() {
	string description = world[currentPosition.x][currentPosition.y].getChunk(world[currentPosition.x][currentPosition.y].type);
	cout << description << endl;
}


void errorMessage(int i)
{
	switch (i)
	{
	case 1:
		cout << "You can't go that way!" << endl;
		break;
	case 2:
		cout << "move command not recognised." << endl;
		break;
	default:
		break;
	}
}

void movePlayer(int direction) {
	//1 == up, 2 == right, 3 == down, 4 == left
	if (currentPosition.x + 1 <= worldWidth && direction == 1) {
		currentPosition.x++;
	}
	else if (currentPosition.y + 1 <= worldWidth && direction == 2) {
		currentPosition.y++;
	}
	else if (currentPosition.x - 1 >= 0 && direction == 3) {
		currentPosition.x--;
	}
	else if (currentPosition.y - 1 >= 0 && direction == 4) {
		currentPosition.y--;
	}
	else
	{
		errorMessage(1);
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

	if (strncmp(coms.c_str(), "move", strlen("move")) == 0) 
	{
		string dir = coms.substr(5,1);
		
		if (dir == "u") {
			movePlayer(1);
		}
		else if (dir == "r") {
			movePlayer(2);
		}
		else if (dir == "d") {
			movePlayer(3);
		}
		else if (dir == "l") {
			movePlayer(4);
		}
		else
		{
			errorMessage(2);
		}
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

