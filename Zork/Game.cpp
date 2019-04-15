#include "Game.h"

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

}
