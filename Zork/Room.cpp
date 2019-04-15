#include "Room.h"
#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std;

Room::Room() 
{
	this->items = new unordered_map<string, string>();
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	northLock = make_pair(false, string());
	southLock = make_pair(false, string());
	eastLock = make_pair(false, string());
	westLock = make_pair(false, string());
}

Room::~Room()
{
	delete this->items;
}

void Room::addItem(string item, string desc)
{
	items->insert(make_pair(item, desc));
}

unordered_map<string, string> * Room::getItems()
{
	return items;
}

void Room::setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest) 
{
	north = createNorth;
	east = createEast;
	south = createSouth;
	west = createWest;
}

void Room::moveNorth(Room** currentRoom, Inventory *in)
{
	if (in->hasItem(northLock.second))
	{
		northLock = make_pair(true, northLock.second);
	}

	if ((north != NULL) && !northLock.first)
	{
		*currentRoom = north;
		cout << "You go north." << endl;
		describeRoom();
	}
	else if (northLock.first)
	{
		cout << "You can't go north yet! The path is blocked/locked." << endl;
	}
	else
	{
		cout << "There is no path to the north!" << endl;
	}
}

void Room::moveEast(Room** currentRoom, Inventory *in)
{
	if (in->hasItem(eastLock.second))
	{
		eastLock = make_pair(true, eastLock.second);
	}

	if ((east != NULL) && !eastLock.first)
	{
		*currentRoom = east;
		cout << "You go east." << endl;
		describeRoom();
	}
	else if (eastLock.first)
	{
		cout << "You can't go east yet! The path is blocked/locked." << endl;
	}
	else
	{
		cout << "There is no path to the east!" << endl;
	}
		
}

void Room::moveSouth(Room** currentRoom, Inventory *in)
{
	if (in->hasItem(southLock.second))
	{
		southLock = make_pair(true, southLock.second);
	}

	if ((south != NULL) && !southLock.first)
	{
		*currentRoom = south;
		cout << "You go south." << endl;
		describeRoom();
	}
	else if (southLock.first)
	{
		cout << "You can't go south yet! The path is blocked/locked." << endl;
	}
	else
	{
		cout << "There is no path to the south!" << endl;
	}
		
}

void Room::moveWest(Room** currentRoom, Inventory *in)
{
	if (in->hasItem(westLock.second))
	{
		westLock = make_pair(true, westLock.second);
	}

	if ((west != NULL) && !westLock.first)
	{
		*currentRoom = west;
		cout << "You go west." << endl;
		describeRoom();
	}
	else if (westLock.first)
	{
		cout << "You can't go west yet! The path is blocked/locked." << endl;
	}
	else
	{
		cout << "There is no path to the west!" << endl;
	}		
}
