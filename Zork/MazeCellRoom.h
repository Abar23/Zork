#ifndef MAZECELLROOM_H
#define MAZECELLROOM_H

#include <iostream>
#include "Room.h"

class MazeCellRoom : public Room
{
public:
	MazeCellRoom(bool addKey, bool addExitDoor);
	~MazeCellRoom();

	/**
	* Outputs description of the room
	*/
	void describeRoom();

	/**
	* Outputs description of what is to the north
	*/
	void outputNorth();

	/**
	* Outputs description of what is to the east
	*/
	void outputEast();

	/**
	* Outputs description of what is to the south
	*/
	void outputSouth();

	/**
	* Outputs description of what is to the west
	*/
	void outputWest();
};

#endif
