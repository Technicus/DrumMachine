// https://www.daemon-systems.org/man/getch.3.html
// http://invisible-island.net/ncurses/ncurses.faq.html#modified_keys

#include <string>
#include <cstdlib>
#include <ncurses.h>
using namespace std;

main() {

   WINDOW *w;
   string bits[8] = {"0", "0", "0", "0", "0", "0", "0", "0"};
   int ch, i = 0;

   initscr(); // initialize Ncurses
   w = newwin( 3, 10, 1, 2 ); // create a new window
   box( w, 0, 0 ); // sets default borders for the window

   // now print all the menu items and highlight the first one
   for( i=0; i<8; i++ ) {
      if( i == 0 )
         wattron( w, A_STANDOUT ); // highlights the first item.
         else
            wattroff( w, A_STANDOUT );
      mvwprintw(w, 1, i+1, bits[i].c_str());
   }

   wrefresh( w ); // update the terminal screen

   i = 0;
   noecho(); // disable echoing of characters on the screen
   keypad( w, TRUE ); // enable keyboard input for the window.
   curs_set( 0 ); // hide the default screen cursor.

   // get the input
   while(( ch = wgetch(w)) != 'q'){

      // right pad with spaces to make the items appear with even width.
      mvwprintw(w, 1, i+1, bits[i].c_str());

      // use a variable to increment or decrement the value based on the input.
      switch( ch ) {
         case KEY_LEFT:
            i--;
            i = ( i<0 ) ? 7 : i;
            break;
         case KEY_RIGHT:
            i++;
            i = ( i>7 ) ? 0 : i;
            break;
         case KEY_UP:
            bits[i] = "1";
            break;
         case KEY_DOWN:
            bits[i] = "0";
            break;
      }
      // now highlight the next item in the list.
      wattron( w, A_STANDOUT );
      mvwprintw(w, 1, i+1, bits[i].c_str());
      wattroff( w, A_STANDOUT );
   }

   delwin( w );
   endwin();
}