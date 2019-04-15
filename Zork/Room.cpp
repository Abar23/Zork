#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

Room::Room() 
{
	this->items = new unordered_set<string>();
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
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

void Room::setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest) 
{
	north = createNorth;
	east = createEast;
	south = createSouth;
	west = createWest;
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
