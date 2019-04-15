#include <iostream>
#include "Game.h"
#include "MainRoom.h"

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
	cout << "Welcome to the game. There are three paths. Enter 1, 2, or 3:  ";
	getline(cin, chosenPath);
	cout << endl;

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
			currentRoom = new MainRoom();
			Room * anotherRoom = new MainRoom();

			// 2. Set connections between rooms
			currentRoom->setRooms(anotherRoom, NULL, NULL, NULL);
			anotherRoom->setRooms(NULL, NULL, currentRoom, NULL);

			// 3. Add all rooms to the gameRooms vector
			this->gameRooms.push_back(anotherRoom);
			this->gameRooms.push_back(currentRoom);

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
	currentRoom->describeRoom();
	while (!controller.getShouldQuit())
	{
		controller.nextCommand(&currentRoom, &inventory);
	}
}
