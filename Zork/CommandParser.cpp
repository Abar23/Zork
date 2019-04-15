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
	recognizedCommands->insert("help");
	recognizedCommands->insert("look");
}

CommandParser::~CommandParser()
{
	delete this->recognizedCommands;
}

void CommandParser::nextCommand(Room *currentRoom, Inventory *in)
{
	string command = string();
	getline(cin, command);
	transform(command.begin(), command.end(), command.begin(), ::tolower);  // change string to all lowercase

	if (recognizedCommands->find(command) != recognizedCommands->end())
	{
		executeCommand(command, currentRoom, string(), in);
	}
	else
	{
		stringstream ss(command);
		string buf = string();
		bool grabbing = false;

		while (ss >> buf)
		{
			if (grabbing)
			{
				executeCommand("grab", currentRoom, buf, in);
			}

			if (buf == "grab" || buf == "take")
			{
				grabbing = true;
			}
			else
			{
				cout << "I do not recognize this command!" << endl;
				break;
			}
		}
	}
}
	

void CommandParser::executeCommand(string command, Room *currentRoom, string item, Inventory *in)
{
	if (command == "north")
	{
		currentRoom->moveNorth(&currentRoom);
	}
	else if (command == "south")
	{
		currentRoom->moveSouth(&currentRoom);
	}
	else if (command == "east")
	{
		currentRoom->moveSouth(&currentRoom);
	}
	else if (command == "west")
	{
		currentRoom->moveSouth(&currentRoom);
	}
	else if (command == "grab" || command == "take")
	{
		if (currentRoom->getItems().find(item) != currentRoom->getItems().end())
		{
			in->addToInventory(item);
			currentRoom->getItems().erase(item);
		}
		else
		{
			cout << "There is no " << item << " in this room." << endl;
		}
	}
	else if (command == "look")
	{
		if (currentRoom->getItems().size == 0) 
		{
			cout << "You look around the room and see no items." << endl;
		}
		else
		{
			cout << "You look around the room and see the following items: " << endl;
			for (pair<string, string> element : currentRoom->getItems())
			{
				cout << element.first << "  ::  " << element.second << endl;
			}
		}
	}
	else if (command == "help")
	{
		cout << "You can enter the following commands: " << endl;
		for (string c : *recognizedCommands) 
		{
			cout << c << endl;
		}
		cout << "grab <item name>    or     take <item name>" << endl;
	}
}
