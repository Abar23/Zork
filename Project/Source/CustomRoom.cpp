// Function implementation for this derived Room class.
// This class allows the programmer to set up all messages for a room.
// File: CustomRoom.cpp
// Created by: Kyle Lambert
// Created on: April 15, 2019

#include "../Include/CustomRoom.h"
#include <iostream>

CustomRoom::CustomRoom()
{
	// Give each description a default value:

	// General description of the entire room
	this->areaDesc = "Default area description.";

	// If the direction is NOT locked, this description is printed when its examined.
	this->northDesc = "Default north unlocked descripton.";
	this->eastDesc = "Default east unlocked descripton.";
	this->southDesc = "Default south unlocked descripton.";
	this->westDesc = "Default west unlocked descripton.";

	// If the direction is locked, this description is printed when its examined.
	this->northDescLocked = "Default north locked description.";
	this->eastDescLocked = "Default east locked description.";
	this->southDescLocked = "Default south locked description.";
	this->westDescLocked = "Default west locked description.";
}

CustomRoom::~CustomRoom()
{
}

void CustomRoom::describeRoom()
{
	cout << this->areaDesc << endl;
}

void CustomRoom::outputNorth()
{
	if (this->northLock.first == true)	// direction locked
	{
		cout << northDescLocked << endl;
	}
	else   // direction unlocked
	{
		cout << northDesc << endl;
	}
}

void CustomRoom::outputEast()
{
	if (this->eastLock.first == true)	// direction locked
	{
		cout << eastDescLocked << endl;
	}
	else   // direction unlocked
	{
		cout << eastDesc << endl;
	}
}

void CustomRoom::outputSouth()
{
	if (this->southLock.first == true)	// direction locked
	{
		cout << southDescLocked << endl;
	}
	else   // direction unlocked
	{
		cout << southDesc << endl;
	}
}

void CustomRoom::outputWest()
{
	if (this->westLock.first == true)	// direction locked
	{
		cout << westDescLocked << endl;
	}
	else   // direction unlocked
	{
		cout << westDesc << endl;
	}
}
