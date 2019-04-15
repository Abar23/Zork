#ifndef MAINROOM_H
#define MAINROOM_H

#include "Room.h"

class MainRoom : public Room
{
public:
	MainRoom();
	~MainRoom();

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
