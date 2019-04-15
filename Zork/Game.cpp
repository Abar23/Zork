#include <iostream>
#include "Game.h"
#include "KyleRoom.h"

Game::Game()
{
}

Game::~Game()
{	
	for (auto &room : gameRooms)
	{
		delete room;
	}
}

void Game::choosePath()
{
	string chosenPath;
	cout << "Welcome to the game. There are three paths. Choose one:  ";
	getline(cin, chosenPath);

	while (true) {

		if (chosenPath == "1")
		{
			// Rooms for Kyle's map
			// 1. Create rooms (MUST BE POINTERS)

			// 2. Set connections between rooms

			// 3. Add all rooms to the gameRooms vector

			break;
		}
		else if (chosenPath == "2")
		{
			// Rooms for Anthony's map
			// 1. Create rooms (MUST BE POINTERS)

			// 2. Set connections between rooms

			// 3. Add all rooms to the gameRooms vector

			break;
		}
		else if (chosenPath == "3")
		{
			// Rooms for Dan's map
			// 1. Create rooms (MUST BE POINTERS)

			// 2. Set connections between rooms

			// 3. Add all rooms to the gameRooms vector

			break;
		}
		else
		{
			cout << "You must enter only 1, 2, or 3." << endl;
			cout << "Choice:  ";
			getline(cin, chosenPath);
		}
	}
}

void Game::run()
{
	currentRoom = new KyleRoom();
	currentRoom->describeRoom();
	while (!controller.getShouldQuit())
	{
		controller.nextCommand(currentRoom, &inventory);
	}
}
