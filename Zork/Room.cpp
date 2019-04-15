#include "Room.h"
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

void Room::moveNorth(Room** currentRoom)
{
	if (north != NULL)
	{
		*currentRoom = north;
		cout << "You go north." << endl;
		describeRoom();
	}
	else
	{
		cout << "You can't go north!" << endl;
	}
}

void Room::moveEast(Room** currentRoom)
{
	if (east != NULL)
	{
		*currentRoom = east;
		cout << "You go east." << endl;
		describeRoom();
	}
	else
	{
		cout << "You can't go east!" << endl;
	}
		
}

void Room::moveSouth(Room** currentRoom)
{
	if (south != NULL)
	{
		*currentRoom = south;
		cout << "You go south." << endl;
		describeRoom();
	}		
	else
	{
		cout << "You can't go south!" << endl;
	}
		
}

void Room::moveWest(Room** currentRoom)
{
	if (west != NULL)
	{
		*currentRoom = west;
		cout << "You go west." << endl;
		describeRoom();
	}
	else
	{
		cout << "You can't go west!" << endl;
	}
		
}
