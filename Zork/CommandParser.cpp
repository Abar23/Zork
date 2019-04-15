#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "CommandParser.h"
using namespace std;

CommandParser::CommandParser()
{
	this->recognizedCommands = new unordered_set<string>();
	recognizedCommands->insert("north");
	recognizedCommands->insert("south");
	recognizedCommands->insert("east");
	recognizedCommands->insert("west");
	recognizedCommands->insert("grab");
	recognizedCommands->insert("take");
}

CommandParser::~CommandParser()
{
	delete this->recognizedCommands;
}

void CommandParser::nextCommand(Room &currentRoom)
{
	string command = string();
	getline(cin, command);
	stringstream ss(command);
	string buf = string();
	bool recognized = true;
	bool grabbing = false;

	// Iterate through input by each word separated by spaces
	while (ss >> buf && recognized)
	{
		transform(buf.begin(), buf.end(), buf.begin(), ::tolower);  // change string to all lowercase
		if (grabbing)
		{
			executeCommand("grab", currentRoom, buf);
		}

		// If the command is recognized
		if (recognizedCommands->find(buf) != recognizedCommands->end())
		{
			if (buf == "grab" || buf == "take") 
			{
				grabbing = true;
			}
			else
			{
				executeCommand(buf, currentRoom, string());
			}
		}
		else
		{
			recognized = false;
			cout << "I do not recognize this command!" << endl;
		}

	}
}

void CommandParser::executeCommand(string command, Room &currentRoom, string item)
{
	if (command == "north")
	{
		//currentRoom.moveNorth(currentRoom);
	}
	else if (command == "south")
	{

	}
	else if (command == "east")
	{

	}
	else if (command == "west")
	{

	}
	else if (command == "grab" || command == "take")
	{
		if (currentRoom.getItems().find(item) != currentRoom.getItems().end())
		{

		}
	}
}
