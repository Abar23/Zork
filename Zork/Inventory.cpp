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
	// Check if there are no items
	if (this->inventory.size() == 0)
	{
		std::cout << "There are no items in your inventory!" << std::endl;
	}
	else
	{
		// Output a each element that is in the inventory
		std::cout << "Current Inventory: " << std::endl;
		for (auto pair : this->inventory)
		{
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
}

void Inventory::addToInventory(std::string itemName)
{
	// Check if item is not already in the inventory
	if (this->inventory.find(itemName) == this->inventory.end())
	{
		this->inventory.insert(std::make_pair(itemName, 1));
	}
	else
	{
		// Get a pointer to the pair in the inventory
		auto pair = this->inventory.find(itemName);
		// Increment the amount of the particular item
		pair->second++;
	}
}

void Inventory::removeInventory(std::string itemName)
{
	// Prevent code from running when the item being removed does not exist
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


