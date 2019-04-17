#include <iostream>
#include "Game.h"
#include "CustomRoom.h"
#include "MazeStartRoom.h"
#include "MazeCellRoom.h"
#include "MazeEndRoom.h"

Game::Game()
{
}

Game::~Game()
{	
	for (auto &room : gameRooms)
	{
		delete room;
	}
}

void Game::choosePath()
{
	string chosenPath;
	cout << "Welcome to the game. There are three paths. Enter 1, 2, or 3:  ";
	getline(cin, chosenPath);
	cout << endl;

	while (true) {

		if (chosenPath == "1")
		{
			// Rooms for Kyle's map
			this->setupFirstPath();
			break;
		}
		else if (chosenPath == "2")
		{
			// Rooms for Anthony's map
			// 1. Create rooms (MUST BE POINTERS)
			currentRoom = new MazeStartRoom();
			Room *mazeCell1 = new MazeCellRoom(false, false);
			Room *mazeCell2 = new MazeCellRoom(true, false);
			Room *mazeCell3 = new MazeCellRoom(false, false);
			Room *mazeCell4 = new MazeCellRoom(false, true);
			Room *mazeEnd = new MazeEndRoom();


			// 2. Set connections between rooms
			currentRoom->setRooms(mazeCell1, NULL, NULL, NULL);
			mazeCell1->setRooms(mazeCell3, mazeCell2, currentRoom, mazeCell2);
			mazeCell2->setRooms(mazeCell3, mazeCell1, currentRoom, mazeCell1);
			mazeCell3->setRooms(mazeCell2, currentRoom, mazeCell2, mazeCell4);
			mazeCell4->setRooms(mazeEnd, mazeCell3, currentRoom, mazeCell1);
			mazeEnd->setRooms(NULL, NULL, NULL, NULL);

			// 3. Add all rooms to the gameRooms vector
			this->gameRooms.push_back(currentRoom);
			this->gameRooms.push_back(mazeCell1);
			this->gameRooms.push_back(mazeCell2);
			this->gameRooms.push_back(mazeCell3);
			this->gameRooms.push_back(mazeCell4);
			this->gameRooms.push_back(mazeEnd);


			break;
		}
		else if (chosenPath == "3")
		{
			// Rooms for Dan's map
			this->setupThirdPath();
			break;
		}
		else
		{
			cout << "You must enter only 1, 2, or 3." << endl;
			cout << "Choice:  ";
			getline(cin, chosenPath);
		}
	}
}

void Game::run()
{
	currentRoom->describeRoom();
	while (!controller.getShouldQuit())
	{
		controller.nextCommand(&currentRoom, &inventory);

		if (currentRoom->getHasReachedEndFlag())
		{
			controller.setShouldQuit(true);
		}
	}
}

void Game::setupFirstPath()
{
	cout << "You wake up on a dusty old mattress in an empty jail cell. Where are you? Why can't you remember anything?"  << endl;
	cout << "Try to escape!" << endl << endl;

	// 1. Create rooms (MUST BE POINTERS)
	Room *room1 = new CustomRoom();
	room1->setAreaDesc("This room is empty except for an old mattress and a small table.");
	room1->setNorthDescLocked("There is a single wooden door to the north. It appears to be locked by a small key.");
	room1->setNorthDesc("There is a single wooden door to the north. You unlocked it earlier with a small key.");
	room1->setEastDescLocked("The area to the east is blocked by vertical bars as if this were a jail cell.\nThere is a man on the other side. He looks at you and mutters, \"Password?\".");
	room1->setSouthDesc("There is a solid wall to the south.");
	room1->setWestDesc("There is a solid wall to the west.");
	room1->setEastLock(make_pair(true, "password"));
	room1->setNorthLock(make_pair(true, "key"));
	room1->addItem("key", "A small key on the table that looks like it could unlock an ordinary door.");

	Room *room2 = new CustomRoom();
	room2->setAreaDesc("This room is empty except for a large area rug. It looks expensive.");
	room2->setNorthDesc("There is an opening in the wall to the north.");
	room2->setSouthDesc("There is a wooden door to the south that you unlocked earlier.");
	room2->setWestDesc("There is a stone door to the west. It appears unlocked.");
	room2->setEastDesc("There is a solid wall to the east.");

	Room *room3 = new CustomRoom();
	room3->setAreaDesc("This room has no roof. There are clear skies and you can see the sunshine above.");
	room3->addItem("torch", "There is a lit torch attached to the south wall. It appears removable.");
	room3->setNorthDesc("There is a solid wall to the north.");
	room3->setSouthDesc("There is a solid wall to the south.");
	room3->setWestDesc("There is a solid wall to the west.");
	room3->setEastDesc("There is a stone door to the east.");

	Room *room4 = new CustomRoom();
	room4->setAreaDesc("This room has a pile of bones in the corner. It looks like they've been there awhile.");
	room4->setNorthLock(make_pair(true, "bomb"));
	room4->setNorthDescLocked("There is a large crack in the wall to the north. Maybe there's a way behind it.");
	room4->setNorthDesc("There is now a large hole in the wall from the bomb explosion.");
	room4->setSouthDesc("There is an opening in the wall to the south.");
	room4->setWestDesc("There is a solid wall to the west.");
	room4->setEastDesc("There is a set of double doors to the east. They are unlocked.");

	Room *room5 = new CustomRoom();
	room5->setAreaDesc("This appears to be just a long hallway. There are double doors to the east and west.");
	room5->setNorthDesc("There is a solid wall to the north.");
	room5->setSouthDesc("There is a solid wall to the south.");
	room5->setWestDesc("There are double doors to the west. They are unlocked.");
	room5->setEastDesc("There are double doors to the east. They are unlocked.");

	Room *room6 = new CustomRoom();
	room6->setAreaDesc("This room is covered in cobwebs. It is dark and dusty.");
	room6->setSouthLock(make_pair(true, "torch"));
	room6->setNorthDesc("There is a solid wall to the north.");
	room6->setSouthDescLocked("There appears to be a way to the south, but there are too many spider webs blocking this path.");
	room6->setSouthDesc("There is now an opening to the south after all the webbing was burned away.");
	room6->setWestDesc("There are double doors to the west. They are unlocked.");
	room6->setEastDesc("There is a solid wall to the east.");

	Room *room7 = new CustomRoom();
	room7->setAreaDesc("After the smoke clears, you see the room is empty except for a wooden crate in the center.");
	room7->addItem("bomb", "Inside the crate, there is a single bomb, labeled \"TNT\".");
	room7->setNorthDesc("The burnt spider web opening is to the north.");
	room7->setSouthDesc("There is a solid wall to the south.");
	room7->setWestDesc("There is a solid wall to the west.");
	room7->setEastDesc("There is a solid wall to the east.");

	Room *room8 = new CustomRoom();
	room8->setAreaDesc("Hidden away, this room appears to be an abandoned library. There is a table in the center...");
	room8->addItem("password", "On the table is a note that reads, \"The password is: LET ME GO!\".");
	room8->setNorthDesc("The wall to the north is covered in old bookshelves.");
	room8->setSouthDesc("There is an opening to the south from the bomb you set off.");
	room8->setWestDesc("The wall to the west is covered in old bookshelves.");
	room8->setEastDesc("The wall to the east is covered in old bookshelves.");

	Room *room9 = new CustomRoom();
	room9->setAreaDesc("Congratulations! The jailor accepts the password and hands you $200. You are now free to go. THE END");
	room9->setHasReachedEndFlag(true);
	//controller.setShouldQuit(true);

	// 2. Set connections between rooms
	room1->setRooms(room2, room9, NULL, NULL);
	room2->setRooms(room4, NULL, room1, room3);
	room3->setRooms(NULL, room2, NULL, NULL);
	room4->setRooms(room8, room5, room2, NULL);
	room5->setRooms(NULL, room6, NULL, room4);
	room6->setRooms(NULL, NULL, room7, room5);
	room7->setRooms(room6, NULL, NULL, NULL);
	room8->setRooms(NULL, NULL, room4, NULL);
	room9->setRooms(NULL, NULL, NULL, room1);
	currentRoom = room1;

	// 3. Add all rooms to the gameRooms vector
	this->gameRooms.push_back(room9);
	this->gameRooms.push_back(room8);
	this->gameRooms.push_back(room7);
	this->gameRooms.push_back(room6);
	this->gameRooms.push_back(room5);
	this->gameRooms.push_back(room4);
	this->gameRooms.push_back(room3);
	this->gameRooms.push_back(room2);
	this->gameRooms.push_back(room1);
}

void Game::setupThirdPath() {
	
	cout << "You have finally arrived at the castle's gates.  Why were you here?  You check your pockets and read the note again: \'HELP WANTED - DRAGON SLAYER\' You know you need this job to get your adventuring career back on track, so you enter the castle." << endl;

	// 1. Create rooms (MUST BE POINTERS)
	Room* room1 = new CustomRoom();
	room1->setAreaDesc("This giant room is filled with tapestries and golden items.  A fitting entrance for a castle.");
	room1->setNorthDesc("There is a wooden door to the north.");
	room1->setEastDesc("There is a solid stone wall to the east, covered by a tapestry.");
	room1->setSouthDesc("The castle's gate is to the south.");
	room1->setWestDesc("There is a solid stone wall to the west, with several tables with glimmering golden cups.");

	Room* room3 = new CustomRoom();
	room3->setAreaDesc("This is a standard stone hallway, connecting other parts of the castle.");
	room3->setNorthDescLocked("There is a solid stone wall to the north, but some bricks look loose.");
	room3->setNorthDesc("There is a solid stone wall with a person-sized hole to the north.");
	room3->setNorthLock(make_pair(true, "book"));
	room3->setEastDesc("There is a wooden door to the east.");
	room3->setSouthDesc("There is a wooden door to the south, back to the castle entrance.");
	room3->setWestDesc("There is a wooden door to the west.");

	Room* room2 = new CustomRoom();
	room2->setAreaDesc("This room appears to be an old servant's quarters, with cots and clothes covering the floor.");
	room2->setNorthDesc("There is a solid stone wall to the north.");
	room2->setEastDesc("There is a wooden door to the east, back to the hallway.");
	room2->setSouthDesc("There is a solid stone wall to the south.");
	room2->setWestDesc("There is a solid stone wall to the west.");

	Room* room4 = new CustomRoom();
	room4->setAreaDesc("This room is an old library, filled to the brim with dusty old books.");
	room4->setNorthDesc("Books cover the north wall.");
	room4->setEastDesc("Books cover the east wall.");
	room4->setSouthDesc("Books cover the south wall.");
	room4->addItem("book", "A mysterious book is poking out of the southern bookshelves.");
	room4->setWestDesc("There is a wooden door to the west, back to the hallway.");

	Room* room5 = new CustomRoom();
	room5->setAreaDesc("This is yet another stone hallway.");
	room5->setNorthDesc("There is a wooden door to the north.");
	room5->setEastDesc("There is a solid stone wall to the east.");
	room5->setSouthDesc("There is a wooden door to the south, back to the other parts of the castle.");
	room5->setWestDesc("There is a solid stone wall to the west.");

	Room* room6 = new CustomRoom();
	room6->setAreaDesc("This is a magnificent armory, filled with shiny swords and plenty of armor.");
	room6->setNorthDesc("Plates of armor cover the north wall.");
	room6->setEastDesc("There is a wooden door to the east, back to the hallway.");
	room6->setSouthDesc("Plates of armor cover the south wall.");
	room6->setWestDesc("Weapons sit on tables to the west.");
	room6->addItem("sword", "A magnificent sword is in the middle of the room, with an almost magical aura to it.");

	Room* room7 = new CustomRoom();
	room7->setAreaDesc("Another stone hallway?  How big is this place?");
	room7->setNorthDescLocked("There is a wooden door to the north with the words \"WARNING - DRAGON AHEAD\" printed on it.");
	room7->setNorthDesc("The door to the north still looks forboding, but your sword gives you confidence.");
	room7->setNorthLock(make_pair(true, "sword"));
	room7->setEastDesc("There is a wooden door to the east.");
	room7->setSouthDesc("There is a wooden door to the south, back to the rest of the castle.");
	room7->setWestDesc("There is a wooden door to the west.");

	Room* room8 = new CustomRoom();
	room8->setAreaDesc("This is the throne room!  Or so it seems, as there is nothing but a golden chair in the middle of the room.");
	room8->setNorthDesc("There is a solid stone wall to the north.");
	room8->setEastDesc("There is a solid stone wall to the east, with a huge tapestry of the king covering most of the wall!");
	room8->setSouthDesc("There is a solid stone wall to the south.");
	room8->setWestDesc("There is a wooden door to the west, back to the hallway.");

	Room* room9 = new CustomRoom();
	room9->setAreaDesc("The dragon awaits you.  You give a ferocious yell and charge towards him, holding your magic sword above your head.  He too yells, for he is scared and confused.  In his self defense, he blows a huge fireball directly at you, burning you to a crisp instantly.  THE END");
	room9->setHasReachedEndFlag(true);


	// 2. Set connections between rooms
	room1->setRooms(room3, NULL, NULL, NULL);
	room2->setRooms(NULL, room3, NULL, NULL);
	room3->setRooms(room5, room4, room1, room2);
	room4->setRooms(NULL, NULL, NULL, room3);
	room5->setRooms(room7, NULL, room3, NULL);
	room6->setRooms(NULL, room7, NULL, NULL);
	room7->setRooms(room9, room8, room5, room6);
	room8->setRooms(NULL, NULL, NULL, room7);
	room9->setRooms(NULL, NULL, room7, NULL);
	currentRoom = room1;

	// 3. Add all rooms to the gameRooms vector
	this->gameRooms.push_back(room9);
	this->gameRooms.push_back(room8);
	this->gameRooms.push_back(room7);
	this->gameRooms.push_back(room6);
	this->gameRooms.push_back(room5);
	this->gameRooms.push_back(room4);
	this->gameRooms.push_back(room3);
	this->gameRooms.push_back(room2);
	this->gameRooms.push_back(room1);
	

}
