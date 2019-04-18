#include <iostream>
#include "../Include/MazeStartRoom.h"

MazeStartRoom::MazeStartRoom()
{
	// Set properties of the room
	this->areaDesc = "You are in a maze with extremely tall hedges. To your west, east, and south are impenetrable hedge walls. To the \n"
					  "north, you see an opening the in hedges along with a curious sign next to it. The sign reads: \n"
					  "\t \"To traverse this treacherous maze, you must follow the path: ghkma - kbzam - ni - pxlm\" \n";

	this->northDesc = "There is an opening in the hedge. Seems to be the entrance to the maze. \n";
	this->westDesc = "There is nothing here but a hedge wall. \n";
	this->eastDesc = "There is nothing here but a hedge wall. \n";
	this->southDesc = "There is nothing here but a hedge wall. \n";
}

MazeStartRoom::~MazeStartRoom()
{
}

void MazeStartRoom::describeRoom()
{
	std::cout << this->areaDesc;
}

void MazeStartRoom::outputNorth()
{
	std::cout << this->northDesc;
}

void MazeStartRoom::outputEast()
{
	std::cout << this->eastDesc;
}

void MazeStartRoom::outputSouth()
{
	std::cout << this->southDesc;
}

void MazeStartRoom::outputWest()
{
	std::cout << this->westDesc;
}

