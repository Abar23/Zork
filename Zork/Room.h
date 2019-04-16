// Room.h file
// Author: Daniel Greer
// Created: 4/4/19
// Updated: 4/4/19
#ifndef ROOM_H
#define ROOM_H

#include "Inventory.h"
#include <unordered_map>
#include <string>
using namespace std;

class Room 
{
protected:
	bool hasReachedEnd;
	Room* north;
	Room* east;
	Room* south;
	Room* west;
	string areaDesc;
	string northDesc;
	string eastDesc;
	string southDesc;
	string westDesc;
	string northDescLocked;
	string eastDescLocked;
	string southDescLocked;
	string westDescLocked;
	pair<bool, string> northLock;
	pair<bool, string> southLock;
	pair<bool, string> eastLock;
	pair<bool, string> westLock;
	unordered_map<string, string> *items;
public:
	Room();
	~Room();

	void addItem(string item, string desc);
	unordered_map<string, string> * getItems();
	void setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest);
	void moveNorth(Room** currentRoom, Inventory *in);
	void moveEast(Room** currentRoom, Inventory *in);
	void moveSouth(Room** currentRoom, Inventory *in);
	void moveWest(Room** currentRoom, Inventory *in);
	void setHasReachedEndFlag(bool isEnd);
	bool getHasReachedEndFlag();
	virtual void describeRoom() = 0;
	virtual void outputNorth() = 0;
	virtual void outputEast() = 0;
	virtual void outputSouth() = 0;
	virtual void outputWest() = 0;

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
};
#endif