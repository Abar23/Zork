#include "CustomRoom.h"
#include <iostream>

CustomRoom::CustomRoom()
{
	this->areaDesc = "Default area description.";
	this->northDesc = "Default north unlocked descripton.";
	this->eastDesc = "Default east unlocked descripton.";
	this->southDesc = "Default south unlocked descripton.";
	this->westDesc = "Default west unlocked descripton.";
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
	if (this->northLock.first == true)
	{
		cout << northDescLocked << endl;
	}
	else
	{
		cout << northDesc << endl;
	}
}

void CustomRoom::outputEast()
{
	if (this->eastLock.first == true)
	{
		cout << eastDescLocked << endl;
	}
	else
	{
		cout << eastDesc << endl;
	}
}

void CustomRoom::outputSouth()
{
	if (this->southLock.first == true)
	{
		cout << southDescLocked << endl;
	}
	else
	{
		cout << southDesc << endl;
	}
}

void CustomRoom::outputWest()
{
	if (this->westLock.first == true)
	{
		cout << westDescLocked << endl;
	}
	else
	{
		cout << westDesc << endl;
	}
}
