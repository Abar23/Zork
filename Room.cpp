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