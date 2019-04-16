#include "MazeCellRoom.h"

MazeCellRoom::MazeCellRoom(bool addKey, bool addExitDoor)
{
	if (addKey)
	{
		this->addItem("key", "A mysterious key rusted and convered in moss. It looks like it could be used for some sort of gate.");
	}

	this->areaDesc = "A dense, hazy fog fills the air. You are surrounded by tall hedges on all sides. As you look closer at the \n"
					  "surrounding hedges, you see there are small gaps that you can fit through at each side. \n";

	this->eastDesc = "You see a small gap in the hedge that you can fit through. \n";
	this->southDesc = "You see a small gap in the hedge that you can fit through. \n";
	this->westDesc = "You see a small gap in the hedge that you can fit through. \n";

	if (addExitDoor)
	{
		this->northLock = std::make_pair(true, "key");
		this->northDesc = "As you look at the small gap in the hedge, you notice a small metal handle. You spread the foliage with \n"
						  "with your hands to reveal a rusted gate. \n";
	}
	else
	{
		this->northDesc = "You see a small gap in the hedge that you can fit through. \n";
	}
}

MazeCellRoom::~MazeCellRoom()
{
}

void MazeCellRoom::describeRoom()
{
	std::cout << this->areaDesc;
}

void MazeCellRoom::outputNorth()
{
	std::cout << this->northDesc;
}

void MazeCellRoom::outputEast()
{
	std::cout << this->eastDesc;
}

void MazeCellRoom::outputSouth()
{
	std::cout << this->southDesc;
}

void MazeCellRoom::outputWest()
{
	std::cout << this->westDesc;
}
