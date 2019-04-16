#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Inventory.h"
#include "CommandParser.h"
#include "Room.h"

using namespace std;

class Game
{
private:
	Inventory inventory;
	CommandParser controller;
	Room *currentRoom;
	vector<Room *> gameRooms;

public:
	Game();
	~Game();

	void choosePath();
	void run();
	void setupFirstPath();
};

#endif
