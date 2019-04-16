#ifndef MAZEENDROOM_H
#define MAZEENDROOM_H

#include "Room.h"

class MazeEndRoom : public Room
{
public:
	MazeEndRoom();
	~MazeEndRoom();

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif

