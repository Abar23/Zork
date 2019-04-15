#include "MainRoom.h"
#include <iostream>


MainRoom::MainRoom()
{
	this->areaDesc = "You are in the main room.";
	this->northDesc = "North";
	this->eastDesc = "East";
	this->southDesc = "South";
	this->westDesc = "West";

	this->northLock = std::make_pair(true, "key");
	this->addItem("key", "This could be used to unlock the north door.");
}

MainRoom::~MainRoom()
{
}

void MainRoom::describeRoom()
{
	std::cout << this->areaDesc << std::endl;
}

void MainRoom::outputNorth()
{
	if (this->northLock.first == true)
	{
		std::cout << "Door locked" << std::endl;
	}
	else
	{
		std::cout << "Door unlocked" << std::endl;
	}
}

void MainRoom::outputEast()
{
}

void MainRoom::outputSouth()
{
}

void MainRoom::outputWest()
{
}
