// Header file for this derived Room class.
// This class allows the programmer to set up all messages for a room.
// File: CustomRoom.h
// Created by: Kyle Lambert
// Created on: April 15, 2019

#ifndef CUSTOMROOM_H
#define CUSTOMROOM_H

#include "Room.h"

class CustomRoom : public Room
{
public:
	CustomRoom();	// constructor
	~CustomRoom();	// destructor

	// implements these functions from the base class
	void describeRoom();
	void outputNorth();
	void outputEast();
	void outputSouth();
	void outputWest();
};

#endif
