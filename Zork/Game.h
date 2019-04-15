#ifndef GAME_H
#define GAME_H

#include <string>
#include "Inventory.h"
#include "CommandParser.h"
#include "Room.h"

using namespace std;

class Game
{
private:
	Inventory *inventory;
	CommandParser *controller;
	Room *currentRoom;
	string chosenPath;

public:
	Game();
	~Game();

	void choosePath();
	void run();
};

#endif
