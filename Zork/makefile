CXX = g++
CXXFLAGS = -Wall -g -std=c++11
main: main.o CommandParser.o CustomRoom.o Game.o Inventory.o MazeCellRoom.o MazeEndRoom.o MazeStartRoom.o Room.o
	$(CXX) $(CXXFLAGS) -o main main.o CommandParser.o CustomRoom.o Game.o Inventory.o MazeCellRoom.o MazeEndRoom.o MazeStartRoom.o Room.o
main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp
CommandParser.o: CommandParser.h CommandParser.h
CustomRoom.o: CustomRoom.h CustomRoom.h
Game.o: Game.h CustomRoom.h MazeStartRoom.h MazeCellRoom.h MazeEndRoom.h
Inventory.o: Inventory.h
MazeCellRoom.o: MazeCellRoom.h
MazeEndRoom.o: MazeEndRoom.h
MazeStartRoom.o: MazeStartRoom.h
Room.o: Room.h Inventory.h