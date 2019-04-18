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
	virtual ~Room();

	/**
	* Add item to the room
	*/
	void addItem(string item, string desc);

	/**
	* Retrieve list of items in the room
	*/
	unordered_map<string, string> * getItems();

	/**
	* Set the rooms that the player can move to from the this room
	*/
	void setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest);

	/**
	* Move the player to the north room if the room exists
	*/
	void moveNorth(Room** currentRoom, Inventory *in);

	/**
	* Move the player to the east room if the room exists
	*/
	void moveEast(Room** currentRoom, Inventory *in);

	/**
	* Move the player to the south room if the room exists
	*/
	void moveSouth(Room** currentRoom, Inventory *in);

	/**
	* Move the player to the west room if the room exists
	*/
	void moveWest(Room** currentRoom, Inventory *in);

	/**
	* Set has reached end flag. This indicates that the game is over when true
	*/
	void setHasReachedEndFlag(bool isEnd);

	/**
	* Check the has reached end flag. Game ends when true
	*/
	bool getHasReachedEndFlag();

	// Pure virtual functions to be overriden in derived classes
	virtual void describeRoom() = 0;
	virtual void outputNorth() = 0;
	virtual void outputEast() = 0;
	virtual void outputSouth() = 0;
	virtual void outputWest() = 0;

	/**
	* Set the room description
	*/
	void setAreaDesc(string s) { areaDesc = s; };

	/**
	* Set description of what is to the north
	*/
	void setNorthDesc(string s) { northDesc = s; };

	/**
	* Set description of what is to the east
	*/
	void setEastDesc(string s) { eastDesc = s; };

	/**
	* Set description of what is to the south
	*/
	void setSouthDesc(string s) { southDesc = s; };

	/**
	* Set description of what is to the west
	*/
	void setWestDesc(string s) { westDesc = s; };

	/**
	* Set description of what is to the north when the area is locked/blocked
	*/
	void setNorthDescLocked(string s) { northDescLocked = s; };

	/**
	* Set description of what is to the east when the area is locked/blocked
	*/
	void setEastDescLocked(string s) { eastDescLocked = s; };

	/**
	* Set description of what is to the south when the area is locked/blocked
	*/
	void setSouthDescLocked(string s) { southDescLocked = s; };

	/**
	* Set description of what is to the west when the area is locked/blocked
	*/
	void setWestDescLocked(string s) { westDescLocked = s; };

	/**
	* Set the north lock boolean and what item will unlock/unblock the path
	*/
	void setNorthLock(pair<bool, string> p) { northLock = p; };

	/**
	* Set the east lock boolean and what item will unlock/unblock the path
	*/
	void setEastLock(pair<bool, string> p) { eastLock = p; };

	/**
	* Set the south lock boolean and what item will unlock/unblock the path
	*/
	void setSouthLock(pair<bool, string> p) { southLock = p; };

	/**
	* Set the west lock boolean and what item will unlock/unblock the path
	*/
	void setWestLock(pair<bool, string> p) { westLock = p; };
};
#endif