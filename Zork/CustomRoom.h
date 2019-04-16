#ifndef CUSTOMROOM_H
#define CUSTOMROOM_H

#include "Room.h"

class CustomRoom : public Room
{
public:
	CustomRoom();
	~CustomRoom();

	void setAreaDesc(string s) { areaDesc = s; };
	void setNorthDesc(string s) { northDesc = s; };
	void setEastDesc(string s) { eastDesc = s; };
	void setSouthDesc(string s) { southDesc = s; };
	void setWestDesc(string s) { westDesc = s; };
	void setNorthDescLocked(string s) { northDescLocked = s; };
	void setEastDescLocked(string s) { eastDescLocked = s; };
	void setSouthDescLocked(string s) { southDescLocked = s; };
	void setWestDescLocked(string s) { westDescLocked = s; };

	void setNorthLock(pair<bool, string> p) { northLock = p; };
	void setEastLock(pair<bool, string> p) { eastLock = p; };
	void setSouthLock(pair<bool, string> p) { southLock = p; };
	void setWestLock(pair<bool, string> p) { westLock = p; };

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
