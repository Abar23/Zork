#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

Room::Room(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom)
{
	this->items = new unordered_set<string>();
	north = northRoom;
	east = eastRoom;
	south = southRoom;
	west = westRoom;
}

Room::~Room()
{
	delete this->items;
}

void Room::addItem(string item)
{
	items->insert(item);
}

unordered_set<string> Room::getItems()
{
	return *items;
}

void Room::moveNorth(Room** currentRoom) 
{
	*currentRoom = north;
}

void Room::moveEast(Room** currentRoom) 
{
	*currentRoom = east;
}

void Room::moveSouth(Room** currentRoom) 
{
	*currentRoom = south;
}

void Room::moveWest(Room** currentRoom) 
{
	*currentRoom = west;
}
