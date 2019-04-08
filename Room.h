// Room.h file
// Author: Daniel Greer
// Created: 4/4/19
// Updated: 4/4/19
#ifndef ROOM_H
#define ROOM_H

class Room {
private:
	Room* north;
	Room* east;
	Room* south;
	Room* west;
public:
	Room();
	void setRooms(Room* createNorth, Room* createEast, Room* createSouth, Room* createWest);
	void moveNorth(Room** currentRoom);
	void moveEast(Room** currentRoom);
	void moveSouth(Room** currentRoom);
	void moveWest(Room** currentRoom);
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};
#endif