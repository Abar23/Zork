#ifndef CUSTOMROOM_H
#define CUSTOMROOM_H

#include "Room.h"

class CustomRoom : public Room
{
protected:
	string northDescLocked;
	string eastDescLocked;
	string southDescLocked;
	string westDescLocked;
public:
	CustomRoom();
	~CustomRoom();

	void setAreaDesc(string);
	void setNorthDesc(string);
	void setEastDesc(string);
	void setSouthDesc(string);
	void setWestDesc(string);
	void setNorthDescLocked(string);
	void setEastDescLocked(string);
	void setSouthDescLocked(string);
	void setWestDescLocked(string);

	void setNorthLock(pair<bool, string>);
	void setEastLock(pair<bool, string>);
	void setSouthLock(pair<bool, string>);
	void setWestLock(pair<bool, string>);

	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
