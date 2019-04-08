#include "Room.h"
#include <iostream>
using namespace std;

int main() {
	Room test;
	Room testConnect;
	test.setRooms(NULL, NULL, &testConnect, NULL);
	testConnect.setRooms(&test, NULL, NULL, NULL);
	test.outputNorth();
	test.outputEast();
	test.outputSouth();
	test.outputWest();

	cout << endl << "Current Room Test: " << endl;
	Room* currentRoom;
	currentRoom = &testConnect;
	currentRoom->outputNorth();

	currentRoom->moveNorth(&currentRoom);
	currentRoom->outputNorth();


	return 0;
}