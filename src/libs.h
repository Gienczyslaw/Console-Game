#ifdef PDCURSES_AVAILABLE
#	include <curses.h>
#	define CURSES_AVAILABLE
#else
#	if __has_include(<ncurses.h>)
#		include <ncurses.h>
#		define CURSES_AVAILABLE
#	elif __has_include(<ncurses.h>)
#		include <ncurses.h>
#		define CURSES_AVAILABLE
#   else
#		include <stdio.h>
#	endif
#endif
