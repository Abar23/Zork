// Header file for the class which allows user input.
// The class also executes the user's command.
// File: CommandParser.h
// Created by: Kyle Lambert
// Created on: April 15, 2019

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <unordered_set>
#include "Room.h"
#include "Inventory.h"
using namespace std;

/*
 CommandParser class is used to take input from the user's keyboard and carry out
 the appropriate action in the game. 
*/
class CommandParser 
{
private:
	unordered_set<string> *recognizedCommands;	// a set of standard commands that are recognized
	bool shouldQuit;	// true if the program should exit before the next command
public:
	CommandParser();	// constructor
	~CommandParser();	// destructor

	// Function to prompt user for next command and interpret what was entered
	// @param **currentRoom - the room the player is in
	// @param *in - the player's inventory
	void nextCommand(Room **currentRoom, Inventory *in);

	// Function which executes the command passed as the first parameter
	// @param command - the command entered which will be executed
	// @param **currentRoom - the room the player is in
	// @param item - if command is grab or take, then the item passed will be added to inventory
	// @param *in - the player's inventory
	void executeCommand(string command, Room **currentRoom, string item, Inventory *in);


	bool getShouldQuit();	// returns private variable shouldQuit
	void setShouldQuit(bool);	// sets private variable shouldQuit
};

#endif