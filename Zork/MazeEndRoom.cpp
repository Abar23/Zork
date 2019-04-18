#include <iostream>
#include "MazeEndRoom.h"

MazeEndRoom::MazeEndRoom()
{
	// Set properties of the room
	this->areaDesc = "As you open the gate, you walk out into wide open country. You take one look back at the \n"
					 "nightmarish maze and walk off into the distance. \n\n"
					 "CONGRATULATIONS! You have successfully beaten the maze!";
	this->hasReachedEnd = true;
}

MazeEndRoom::~MazeEndRoom()
{
}

void MazeEndRoom::describeRoom()
{
	std::cout << this->areaDesc;
}

void MazeEndRoom::outputNorth()
{
	std::cout << this->northDesc;
}

void MazeEndRoom::outputEast()
{
	std::cout << this->eastDesc;
}

void MazeEndRoom::outputSouth()
{
	std::cout << this->southDesc;
}

void MazeEndRoom::outputWest()
{
	std::cout << this->westDesc;
}