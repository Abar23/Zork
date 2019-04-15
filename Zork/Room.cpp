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
	if (north == NULL)
		*currentRoom = north;
	else
		cout << "You can't go north!" << endl;
}

void Room::moveEast(Room** currentRoom)
{
	if (east == NULL)
		*currentRoom = east;
	else
		cout << "You can't go east!" << endl;
}

void Room::moveSouth(Room** currentRoom)
{
	if (south == NULL)
		*currentRoom = south;
	else
		cout << "You can't go south!" << endl;
}

void Room::moveWest(Room** currentRoom)
{
	if (west == NULL)
		*currentRoom = west;
	else
		cout << "You can't go west!" << endl;
}
