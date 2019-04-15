#pragma once
#ifndef KYLEROOM_H
#define KYLEROOM_H

#include <string>
#include "Room.h"
using namespace std;

class KyleRoom : public Room
{
protected:
	string areaDesc;
	string northDesc;
	string eastDesc;
	string southDesc;
	string westDesc;
public:
	KyleRoom();

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
