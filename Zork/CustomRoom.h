#ifndef CUSTOMROOM_H
#define CUSTOMROOM_H

#include "Room.h"

class CustomRoom : public Room
{
public:
	CustomRoom();
	~CustomRoom();

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
