#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <unordered_set>
#include "Room.h"
#include "Inventory.h"
using namespace std;

class CommandParser 
{
private:
	unordered_set<string> *recognizedCommands;
public:
	CommandParser();
	~CommandParser();

	void nextCommand(Room *currentRoom, Inventory *in);
	void executeCommand(string command, Room *currentRoom, string item, Inventory *in);
};

#endif