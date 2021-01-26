#include "game.h"

int main() 
{
	Game game(20, 10, ' ', true, true, '#', 2, 2, 2, '$');
	game.show();

	while(1)
	game.newFrame();

	return 0;
}