#include <iostream>
#include <cassert>
#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::displayInventory()
{
	if (this->inventory.size() == 0)
	{
		std::cout << std::endl << "There are no items in your inventory!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "Current Inventory: " << std::endl;
		for (auto pair : this->inventory)
		{
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
}

void Inventory::addToInventory(std::string itemName)
{
	if (this->inventory.find(itemName) == this->inventory.end())
	{
		this->inventory.insert(std::make_pair(itemName, 1));
	}
	else
	{
		auto pair = this->inventory.find(itemName);
		pair->second++;
	}
}

void Inventory::removeInventory(std::string itemName)
{
	assert(this->inventory.find(itemName) != this->inventory.end());

	auto pair = this->inventory.find(itemName);
	if (pair->second == 1)
	{
		this->inventory.erase(itemName);
	}
	else
	{
		pair->second--;
	}
}

bool Inventory::hasItem(std::string itemName)
{
	return (this->inventory.find(itemName) != this->inventory.end());
}


