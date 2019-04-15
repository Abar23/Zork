#include <iostream>
#include "Game.h"
#include "KyleRoom.h"

Game::Game()
{
	inventory = new Inventory();
	controller = new CommandParser();
	chosenPath = "";
}

Game::~Game()
{
	delete this->inventory;
	delete this->controller;

	
}

void Game::choosePath()
{
	cout << "Welcome to the game. There are three paths. Choose one:  ";
	getline(cin, chosenPath);

	while (true) {

		if (chosenPath == "1")
		{
			Room *k = new KyleRoom(NULL, NULL, NULL, NULL);
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



}
