// Room.cpp file
// Author: Daniel Greer
// Created: 4/5/19
// Updated: 4/18/19

#include "../Include/Room.h"
#include "../Include/Inventory.h"
#include <iostream>
#include <string>
using namespace std;

// Create a new room object with no connections to other rooms
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
	this->hasReachedEnd = false;
}

Room::~Room()
{
	delete this->items;
}


// Add an item to a room, with a name and description
void Room::addItem(string item, string desc)
{
	items->insert(make_pair(item, desc));
}

// Display the items currently in the room
unordered_map<string, string> * Room::getItems()
{
	return items;
}

// Connect the room to other rooms, with either a pointer to a room or NULL to signify a wall
void Room::setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest) 
{
	north = createNorth;
	east = createEast;
	south = createSouth;
	west = createWest;
}

// Move the player to the north by changing currentRoom to the north room
void Room::moveNorth(Room** currentRoom, Inventory *in)
{
	// Unlock/unblock the path when the player has the item when they move north
	if (in->hasItem(northLock.second))
	{
		cout << "You used the " << northLock.second << " to open the way forward." << endl;
		northLock = make_pair(false, northLock.second);
		in->removeInventory(northLock.second);
	}
	
	// Move the player north when north pointer is not null and it is not locked/blocked
	if ((north != NULL) && !northLock.first)
	{
		*currentRoom = north;
		cout << "You go north. \n" << endl;
		(*currentRoom)->describeRoom();
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

// Move the player to the east by changing currentRoom to the east room
void Room::moveEast(Room** currentRoom, Inventory *in)
{
	// Unlock/unblock the path when the player has the item when they move east
	if (in->hasItem(eastLock.second))
	{
		cout << "You used the " << eastLock.second << " to open the way forward." << endl;
		eastLock = make_pair(false, eastLock.second);
		in->removeInventory(eastLock.second);
	}

	// Move the player north when east pointer is not null and it is not locked/blocked
	if ((east != NULL) && !eastLock.first)
	{
		*currentRoom = east;
		cout << "You go east. \n" << endl;
		(*currentRoom)->describeRoom();
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

// Move the player to the south by changing currentRoom to the south room
void Room::moveSouth(Room** currentRoom, Inventory *in)
{
	// Unlock/unblock the path when the player has the item when they move south
	if (in->hasItem(southLock.second))
	{
		cout << "You used the " << southLock.second << " to open the way forward. \n" << endl;
		southLock = make_pair(false, southLock.second);
		in->removeInventory(southLock.second);
	}

	// Move the player south when north pointer is not null and it is not locked/blocked
	if ((south != NULL) && !southLock.first)
	{
		*currentRoom = south;
		cout << "You go south. \n" << endl;
		(*currentRoom)->describeRoom();
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

// Move the player to the west by changing currentRoom to the south room
void Room::moveWest(Room** currentRoom, Inventory *in)
{
	// Unlock/unblock the path when the player has the item when they move west
	if (in->hasItem(westLock.second))
	{
		cout << "You used the " << westLock.second << " to open the way forward." << endl;
		westLock = make_pair(false, westLock.second);
		in->removeInventory(westLock.second);
	}

	// Move the player west when north pointer is not null and it is not locked/blocked
	if ((west != NULL) && !westLock.first)
	{
		*currentRoom = west;
		cout << "You go west. \n" << endl;
		(*currentRoom)->describeRoom();
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

// Determine the player has reached the end of the path
void Room::setHasReachedEndFlag(bool isEnd)
{
	this->hasReachedEnd = isEnd;
}

// Report whether the player has reached the end of the path or not
bool Room::getHasReachedEndFlag()
{
	return this->hasReachedEnd;
}
