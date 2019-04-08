#include "Room.h"
#include <iostream>
using namespace std;

Room::Room() {
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
}
void Room::setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest) {
	north = createNorth;
	east = createEast;
	south = createSouth;
	west = createWest;
}
void Room::moveNorth(Room** currentRoom) {
	*currentRoom = north;
}
void Room::moveEast(Room** currentRoom) {
	*currentRoom = east;
}
void Room::moveSouth(Room** currentRoom) {
	*currentRoom = south;
}
void Room::moveWest(Room** currentRoom) {
	*currentRoom = west;
}
void Room::outputNorth() {
	if (north != NULL) {
		cout << "There is a door to the north." << endl;
	}
	else {
		cout << "There is a wall to the north." << endl;
	}
}
void Room::outputEast() {
	if (east != NULL) {
		cout << "There is a door to the east." << endl;
	}
	else {
		cout << "There is a wall to the east." << endl;
	}
}
void Room::outputSouth() {
	if (south != NULL) {
		cout << "There is a door to the south." << endl;
	}
	else {
		cout << "There is a wall to the south." << endl;
	}
}
void Room::outputWest() {
	if (west != NULL) {
		cout << "There is a door to the west." << endl;
	}
	else {
		cout << "There is a wall to the west." << endl;
	}
}