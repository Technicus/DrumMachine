// I had problems getting mouse movement events working in ncurses, but after
// some research, it seems as if this is how you can do it. The magic is in the
// printf("\033[?1003h\n") which was the missing piece in the puzzle for me
// (see console_codes(4) for more information). 1003 means here that all events
// (even position updates) will be reported.
//
// This seems to work in at least three X-based terminals that I've tested:
// xterm, urxvt and gnome-terminal. It doesn't work when testing in a "normal"
// terminal, with GPM enabled. Perhaps something for the next gist version? :)

#include <curses.h>
#include <stdio.h>

int main()
{
   initscr();
   cbreak();
   noecho();

   // Enables keypad mode. This makes (at least for me) mouse events getting
   // reported as KEY_MOUSE, instead as of random letters.
   keypad(stdscr, TRUE);

   while( true )
   {
      char c = getch();
      if ( ERR == c )
         break;

      const char *name = keyname( c );

      move( 2, 2 );
      clear();
//       printw( "You entered: %s             ", name );
      printw( "KEY NAME : %s - %d\n", keyname(c),c);
      refresh();

   }

   endwin();

   return 0;
}