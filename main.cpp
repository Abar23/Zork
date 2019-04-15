#include <iostream>
#include "Room.h"
#include "Inventory.h"

using namespace std;

int main()
{
	Inventory in;

	in.displayInventory();

	in.addToInventory("key");
	in.addToInventory("key");
	std::cout << in.hasItem("key") << std::endl;
	in.removeInventory("key");
	in.removeInventory("key");

	in.displayInventory();

	return 0;
}