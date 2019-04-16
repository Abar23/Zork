#include <iostream>
#include "Game.h"
#include "MazeStartRoom.h"
#include "MazeCellRoom.h"

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
			currentRoom = new MazeStartRoom();
			Room *mazeCell1 = new MazeCellRoom(false, false);
			Room *mazeCell2 = new MazeCellRoom(true, false);
			Room *mazeCell3 = new MazeCellRoom(false, false);
			Room *mazeCell4 = new MazeCellRoom(false, true);


			// 2. Set connections between rooms
			currentRoom->setRooms(mazeCell1, NULL, NULL, NULL);
			mazeCell1->setRooms(mazeCell3, mazeCell2, currentRoom, mazeCell2);
			mazeCell2->setRooms(mazeCell3, mazeCell1, currentRoom, mazeCell1);
			mazeCell3->setRooms(mazeCell2, currentRoom, mazeCell2, mazeCell4);
			mazeCell4->setRooms(NULL, mazeCell3, currentRoom, mazeCell1);

			// 3. Add all rooms to the gameRooms vector
			this->gameRooms.push_back(currentRoom);
			this->gameRooms.push_back(mazeCell1);
			this->gameRooms.push_back(mazeCell2);
			this->gameRooms.push_back(mazeCell3);
			this->gameRooms.push_back(mazeCell4);


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
