// Function implementation for the class which allows user input.
// This class also executes the user's command.
// File: CommandParser.cpp
// Created by: Kyle Lambert
// Created on: April 15, 2019

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "../Include/CommandParser.h"
using namespace std;

CommandParser::CommandParser()
{
	shouldQuit = false;
	this->recognizedCommands = new unordered_set<string>();

	// add all the default commands
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

void CommandParser::nextCommand(Room **currentRoom, Inventory *in)
{
	string command = string();
	cout << endl << " > ";
	getline(cin, command);
	cout << endl;
	transform(command.begin(), command.end(), command.begin(), ::tolower);  // change string to all lowercase

	// if the user's input was an already recognized command
	if (recognizedCommands->find(command) != recognizedCommands->end())
	{
		executeCommand(command, currentRoom, string(), in);
	}
	else  // otherwise, it was a grab/take command or an invalid command
	{
		stringstream ss(command);
		string buf = string();
		bool grabbing = false;
		bool grabbed = false;

		while (ss >> buf)
		{
			if (grabbing)	// the first word was grab/take, so the second word is the item to take
			{
				executeCommand("grab", currentRoom, buf, in);	// pick up the item
				grabbed = true;
			}
			else
			{
				if (buf == "grab" || buf == "take")	// the input was a grab/take command
				{
					grabbing = true;
				}
				else  // the input was invalid
				{
					cout << "I do not recognize this command!" << endl;
					grabbed = true;
					break;
				}
			}
		}

		if (!grabbed)	// only grab/take was input, no item was specified
		{
			cout << "You didn't specify what to grab." << endl;
		}

	}
}
	

void CommandParser::executeCommand(string command, Room **currentRoom, string item, Inventory *in)
{
	if (command == "go north")  // movement commands
	{
		(*currentRoom)->moveNorth(currentRoom, in);
	}
	else if (command == "go south")
	{
		(*currentRoom)->moveSouth(currentRoom, in);
	}
	else if (command == "go east")
	{
		(*currentRoom)->moveEast(currentRoom, in);
	}
	else if (command == "go west")
	{
		(*currentRoom)->moveWest(currentRoom, in);
	}
	else if (command == "look north")  // examine direction commands
	{
		(*currentRoom)->outputNorth();
	}
	else if (command == "look south")
	{
		(*currentRoom)->outputSouth();
	}
	else if (command == "look east")
	{
		(*currentRoom)->outputEast();
	}
	else if (command == "look west")
	{
		(*currentRoom)->outputWest();
	}
	else if (command == "grab" || command == "take")  // try to pick up the item
	{
		// check if the desired item is in the current room
		if ((*currentRoom)->getItems()->find(item) != (*currentRoom)->getItems()->end())
		{
			cout << "You pick up the " << item << " and add it to your inventory." << endl;
			in->addToInventory(item);
			(*currentRoom)->getItems()->erase(item);	// remove the item from the room
		}
		else  // the desired item is not in the room
		{
			cout << "There is no " << item << " in this room." << endl;
		}
	}
	else if (command == "look")		// examine the room for items to pick up
	{
		if ((*currentRoom)->getItems()->size() == 0)	// no items in the room
		{
			cout << "You look around the room and see no items." << endl;
		}
		else
		{
			cout << "You look around the room and see the following items: " << endl;
			// list every item in the room and its description
			for (pair<string, string> element : *(*currentRoom)->getItems())
			{
				cout << element.first << "  -  " << element.second << endl;
			}
		}
	}
	else if (command == "help")		// displays available commands to the user
	{
		cout << "You can enter the following commands: " << endl;
		cout << "look" << endl;
		cout << "look north/south/east/west" << endl;
		cout << "go north/south/east/west" << endl;
		cout << "grab <item name>  or  take <item name>" << endl;
		cout << "help" << endl << "inventory" << endl << "quit" << endl;
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

void CommandParser::setShouldQuit(bool b)
{
	shouldQuit = b;
}
