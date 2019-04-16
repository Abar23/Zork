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

void CustomRoom::setAreaDesc(string s)
{
	this->areaDesc = s;
}

void CustomRoom::setNorthDesc(string s)
{
	this->northDesc = s;
}

void CustomRoom::setEastDesc(string s)
{
	this->eastDesc = s;
}

void CustomRoom::setSouthDesc(string s)
{
	this->southDesc = s;
}

void CustomRoom::setWestDesc(string s)
{
	this->westDesc = s;
}

void CustomRoom::setNorthDescLocked(string s)
{
	this->northDescLocked = s;
}

void CustomRoom::setEastDescLocked(string s)
{
	this->eastDescLocked = s;
}

void CustomRoom::setSouthDescLocked(string s)
{
	this->southDescLocked = s;
}

void CustomRoom::setWestDescLocked(string s)
{
	this->westDescLocked = s;
}

void CustomRoom::setNorthLock(pair<bool, string> p)
{
	this->northLock = p;
}

void CustomRoom::setEastLock(pair<bool, string> p)
{
	this->eastLock = p;
}

void CustomRoom::setSouthLock(pair<bool, string> p)
{
	this->southLock = p;
}

void CustomRoom::setWestLock(pair<bool, string> p)
{
	this->westLock = p;
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
	if (this->southLock.first == true)
	{
		cout << westDescLocked << endl;
	}
	else
	{
		cout << westDesc << endl;
	}
}
