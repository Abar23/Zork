#include <iostream>
#include "Game.h"
#include "KyleRoom.h"

Game::Game()
{
	inventory = new Inventory();
	controller = new CommandParser();
}

Game::~Game()
{
	delete this->inventory;
	delete this->controller;
	
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
			break;
		}
		else if (chosenPath == "2")
		{
			break;
		}
		else if (chosenPath == "3")
		{
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
	while (controller->getShouldQuit())
	{
		controller->nextCommand(currentRoom, inventory);
	}
}
