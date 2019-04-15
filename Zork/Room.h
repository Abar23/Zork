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
	Room* north;
	Room* east;
	Room* south;
	Room* west;
	string areaDesc;
	string northDesc;
	string eastDesc;
	string southDesc;
	string westDesc;
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
	virtual void describeRoom() = 0;
	virtual void outputNorth() = 0;
	virtual void outputEast() = 0;
	virtual void outputSouth() = 0;
	virtual void outputWest() = 0;
};
#endif