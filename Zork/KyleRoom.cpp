#include <iostream>
#include "Room.h"
#include "KyleRoom.h"
using namespace std;

KyleRoom::KyleRoom()
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	areaDesc = "Default room description";
	northDesc = "Default north description";
	southDesc = "Default south description";
	eastDesc = "Default east description";
	westDesc = "Default west description";
}

void KyleRoom::describeRoom()
{
	cout << areaDesc << endl;
}

void KyleRoom::outputNorth()
{
	cout << "To the north: " << northDesc << endl;
}

void KyleRoom::outputSouth()
{
	cout << "To the south: " << southDesc << endl;
}

void KyleRoom::outputEast()
{
	cout << "To the east: " << eastDesc << endl;
}

void KyleRoom::outputWest()
{
	cout << "To the west: " << westDesc << endl;
}
