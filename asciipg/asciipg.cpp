// asciipg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include "WorldChunk.h"
#include "structures.h"
#include "pFunc.h"

using namespace std;

///
///global variables
///
bool craysh = false;
const extern int worldWidth = 5;
const extern int worldHeight = 5;
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

void movePlayer(int direction) {
	//1 == up, 2 == right, 3 == down, 4 == left
	if (currentPosition.x + 1 < worldHeight && direction == 1) {
		currentPosition.x++;
	}
	else if (currentPosition.y + 1 < worldWidth && direction == 2) {
		currentPosition.y++;
	}
	else if (currentPosition.x - 1 > 0 && direction == 3) {
		currentPosition.x--;
	}
	else if (currentPosition.y - 1 > 0 && direction == 4) {
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

	else if (strncmp(coms.c_str(), "move", strlen("move")) == 0) 
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

