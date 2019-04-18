#ifndef MAZEENDROOM_H
#define MAZEENDROOM_H

#include "Room.h"

class MazeEndRoom : public Room
{
public:
	MazeEndRoom();
	~MazeEndRoom();

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

