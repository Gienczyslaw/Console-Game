#include "game.h"

int main() 
{
#ifdef CURSES_AVAILABLE
	
	if (!initscr())
		return -1;

	Game game(20, 10, ' ', true, true, '#', 2, 2, 'O', '$');
	game.show();
	
	while (1)
	{
		game.newFrame();
		if(game.isEnded())
			break;
		refresh();
	}

	
	endwin();
#else

	printf("Can't find curses library, so program can't run. Please try install it. If you don't know how to do it, you can look for some tutorials in internet.\nWrite something and press enter to exit.");
	scanf(" ");

#endif
	
	return 0;
}