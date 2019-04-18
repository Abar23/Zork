#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <unordered_map>

class Inventory
{
private:
	std::unordered_map<std::string, int> inventory;

public:
	Inventory();
	~Inventory();

    /**
	 * Outputs the all items currently in the inventory
	 */
	void displayInventory();

	/**
	 * Adds an item to the inventory
	 *
	 * @param itemName
	 *		A string of the item name that will be added to the inventory
	 */
	void addToInventory(std::string itemName);

	/**
	 * Removes an item from the inventory
	 *
	 * @param itemName
	 *		A string of the item name that will be removed the the invetory
	 */
	void removeInventory(std::string itemName);

	/**
	 * Checks if the item is in the inventory
	 *
	 * @param itemName
	 *		A string of the item name that is checked if it is in the inventory
	 * @return
	 *		A boolean value that indicates if the item is in the inventory
	 */
	bool hasItem(std::string itemName);
};

#endif // !INVENTORY_H
