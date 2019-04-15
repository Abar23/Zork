#include <iostream>
#include "Game.h"
using namespace std;

Game::Game()
{
	inventory = new Inventory();
	controller = new CommandParser();

}

Game::~Game()
{
	delete this->inventory;
	delete this->controller;
}

void Game::run()
{
	string choice;
	cout << "Welcome to the game. There are three paths. Choose one:  ";
	getline(cin, choice);

	while (true) {

		if (choice == "1")
		{

			break;
		}
		else if (choice == "2")
		{
			break;
		}
		else if (choice == "3")
		{
			break;
		}
		else
		{
			cout << "You must enter only 1, 2, or 3." << endl;
			cout << "Choice:  ";
			getline(cin, choice);
		}
	}
}
