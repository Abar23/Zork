// Room.h file
// Author: Daniel Greer
// Created: 4/4/19
// Updated: 4/4/19
#ifndef ROOM_H
#define ROOM_H

#include <unordered_set>
#include <string>
using namespace std;

class Room 
{
protected:
	Room* north;
	Room* east;
	Room* south;
	Room* west;
	unordered_set<string> *items;
public:
	Room(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);
	~Room();

	void addItem(string item);
	unordered_set<string> getItems();
	void moveNorth(Room** currentRoom);
	void moveEast(Room** currentRoom);
	void moveSouth(Room** currentRoom);
	void moveWest(Room** currentRoom);
	virtual void outputNorth() = 0;
	virtual void outputEast() = 0;
	virtual void outputSouth() = 0;
	virtual void outputWest() = 0;
};
#endif