#include <iostream>
#include "../Include/Game.h"

using namespace std;

int main()
{
	// Create instance of the game
	Game game = Game();

	// Prompt player to choose a particular path
	game.choosePath();
	
	// Run the game until the path is completed or the player quits
	game.run();

	return 0;
}
