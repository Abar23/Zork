#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game game = Game();

	game.choosePath();
	
	game.run();

	return 0;
}
