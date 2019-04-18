#include <iostream>
#include<chrono>
#include<ctime>
#include "../Include/Game.h"

using namespace std;

int main()
{
	// Get the start time for the game
	auto start = chrono::system_clock::now();

	// Create instance of the game
	Game game = Game();

	// Prompt player to choose a particular path
	game.choosePath();
	
	// Run the game until the path is completed or the player quits
	game.run();

	// Get the end time for the game
	auto end = chrono::system_clock::now();

	// Calculate and report time elapsed
	chrono::duration<double> totalSeconds = end - start;
	int minutes = totalSeconds.count() / 60;
	int leftoverSeconds = (int)totalSeconds.count() % 60;
	cout << "Total time elapsed: " << minutes << " minutes and " << leftoverSeconds << " seconds" << endl;

	return 0;
}
