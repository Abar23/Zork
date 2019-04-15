#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "CommandParser.h"
using namespace std;

CommandParser::CommandParser()
{
	shouldQuit = false;
	this->recognizedCommands = new unordered_set<string>();
	recognizedCommands->insert("go north");
	recognizedCommands->insert("go south");
	recognizedCommands->insert("go east");
	recognizedCommands->insert("go west");
	recognizedCommands->insert("look north");
	recognizedCommands->insert("look south");
	recognizedCommands->insert("look east");
	recognizedCommands->insert("look west");
	recognizedCommands->insert("help");
	recognizedCommands->insert("look");
	recognizedCommands->insert("inventory");
	recognizedCommands->insert("quit");
}

CommandParser::~CommandParser()
{
	delete this->recognizedCommands;
}

void CommandParser::nextCommand(Room *currentRoom, Inventory *in)
{
	string command = string();
	cout << endl << " > ";
	getline(cin, command);
	cout << endl;
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
		bool grabbed = false;

		while (ss >> buf)
		{
			if (grabbing)
			{
				executeCommand("grab", currentRoom, buf, in);
				grabbed = true;
			}
			else
			{
				if (buf == "grab" || buf == "take")
				{
					grabbing = true;
				}
				else
				{
					cout << "I do not recognize this command!" << endl;
					grabbed = true;
					break;
				}
			}
		}

		if (!grabbed)
		{
			cout << "You didn't specify what to grab." << endl;
		}

	}
}
	

void CommandParser::executeCommand(string command, Room *currentRoom, string item, Inventory *in)
{
	if (command == "go north")
	{
		currentRoom->moveNorth(&currentRoom);
	}
	else if (command == "go south")
	{
		currentRoom->moveSouth(&currentRoom);
	}
	else if (command == "go east")
	{
		currentRoom->moveEast(&currentRoom);
	}
	else if (command == "go west")
	{
		currentRoom->moveWest(&currentRoom);
	}
	else if (command == "look north")
	{
		currentRoom->outputNorth();
	}
	else if (command == "look south")
	{
		currentRoom->outputSouth();
	}
	else if (command == "look east")
	{
		currentRoom->outputEast();
	}
	else if (command == "look west")
	{
		currentRoom->outputWest();
	}
	else if (command == "grab" || command == "take")
	{
		if (currentRoom->getItems()->find(item) != currentRoom->getItems()->end())
		{
			in->addToInventory(item);
			currentRoom->getItems()->erase(item);
		}
		else
		{
			cout << "There is no " << item << " in this room." << endl;
		}
	}
	else if (command == "look")
	{
		if (currentRoom->getItems()->size() == 0) 
		{
			cout << "You look around the room and see no items." << endl;
		}
		else
		{
			cout << "You look around the room and see the following items: " << endl;
			for (pair<string, string> element : *currentRoom->getItems())
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
	else if (command == "inventory")
	{
		in->displayInventory();
	}
	else if (command == "quit")
	{
		shouldQuit = true;
	}
}

bool CommandParser::getShouldQuit()
{
	return shouldQuit;
}