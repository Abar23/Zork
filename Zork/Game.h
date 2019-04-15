#ifndef GAME_H
#define GAME_H

#include "Inventory.h"
#include "CommandParser.h"

class Game
{
protected:
	Inventory *inventory;
	CommandParser *controller;

public:
	Game();
	~Game();

	void run();
};

#endif
