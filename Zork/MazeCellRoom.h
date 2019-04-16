#ifndef MAZECELLROOM_H
#define MAZECELLROOM_H

#include <iostream>
#include "Room.h"

class MazeCellRoom : public Room
{
public:
	MazeCellRoom(bool addKey, bool addExitDoor);
	~MazeCellRoom();

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
