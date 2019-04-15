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

	void displayInventory();
	void addToInventory(std::string itemName);
	void removeInventory(std::string itemName);
	bool hasItem(std::string itemName);
};

#endif // !INVENTORY_H
