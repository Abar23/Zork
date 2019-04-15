#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <unordered_set>
#include "Room.h"
using namespace std;

class CommandParser 
{
private:
	unordered_set<string> *recognizedCommands;
public:
	CommandParser();
	~CommandParser();

	void nextCommand(Room *currentRoom);
	void executeCommand(string command, Room *currentRoom, string item);
};

#endif