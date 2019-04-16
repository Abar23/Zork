#ifndef MAZESTARTROOM_H
#define MAZESTARTROOM_H

#include "Room.h"

class MazeStartRoom : public Room
{
public:
	MazeStartRoom();
	~MazeStartRoom();

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif

