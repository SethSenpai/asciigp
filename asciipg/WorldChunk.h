#pragma once
#include <string>
using namespace std;

class Chunk {
public:
	int type;
	
	string getChunk(int type);

	int getMoveDiretions(int type);

};

