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
	Inventory inventory;	// stores items the player has found
	CommandParser controller;	// gets and executes input from user
	Room *currentRoom;
	vector<Room *> gameRooms;	// a vector of all the rooms in the current path

public:
	Game();		// constructor
	~Game();	// destructor - destroys each room in the gameRooms vector

	void choosePath();	// inital function to allow the user to pick which path to take at the start
	void run();		// gameplay loop which prompts for input until the player beats the game
	void setupFirstPath();	// creates rooms, descriptions, and items for one of the game's paths
	void setupThirdPath();	// creates rooms, descriptions, and items for one of the game's paths
};

#endif
