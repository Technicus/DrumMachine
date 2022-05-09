// https://www.daemon-systems.org/man/getch.3.html
// http://invisible-island.net/ncurses/ncurses.faq.html#modified_keys

#include <string>
#include <cstdlib>
#include <ncurses.h>
using namespace std;

main() {

   initscr(); // initialize Ncurses
   curs_set( 0 ); // hide the default screen cursor.
   noecho(); // disable echoing of characters on the screen

   int windowWidth = 10;
   int windowHeight = 3;

   WINDOW *windows[5];

   string bits[5][8] =
   {
      { "0", "0", "0", "0", "0", "0", "0", "0" },
      { "1", "0", "0", "0", "0", "0", "0", "1" },
      { "0", "1", "0", "0", "0", "0", "1", "0" },
      { "0", "0", "1", "0", "0", "1", "0", "0" },
      { "0", "0", "0", "1", "1", "0", "0", "0" }
   };
   int ch, i, j, k = 0;
   int place[4] = {0, 0, 0, 0};

   windows[0] = newwin( windowHeight, windowWidth, 1, 1 ); // create a new window
   box( windows[0], 0, 0 ); // sets default borders for the window

   windows[1] = newwin( windowHeight, windowWidth, 1, 2+windowWidth ); // create a new window
   box( windows[1], 0, 0 ); // sets default borders for the window

   windows[2] = newwin( windowHeight, windowWidth, 1+windowHeight, 1 ); // create a new window
   box( windows[2], 0, 0 ); // sets default borders for the window

   windows[3] = newwin( windowHeight, windowWidth, 1+windowHeight, 2+windowWidth ); // create a new window
   box( windows[3], 0, 0 ); // sets default borders for the window

   windows[4] = newwin( windowHeight, windowWidth, 1+windowHeight*2, 1 ); // create a new window
   box( windows[4], 0, 0 ); // sets default borders for the window

   // now print all the menu items and highlight the first one
   for(i=0; i<8; i++ ) {
      if(i == 0 )
         wattron( windows[0], A_STANDOUT ); // highlights the first item.
         else
            wattroff( windows[0], A_STANDOUT );
         mvwprintw(windows[0], 1, i+1, bits[0][i].c_str());
   }

   for(j = 1; j < 5; j++)
   {
      for(i=0; i < 8; i++ ) {
         mvwprintw(windows[j], 1, i+1, bits[j][i].c_str());
      }
      wrefresh( windows[j] ); // update the terminal screen
   }

   j = 0;

   keypad( windows[j], TRUE ); // enable keyboard input for the window.

   // get the input
   while(( ch = wgetch(windows[j])) != 'q'){

      // right pad with spaces to make the items appear with even width.
      mvwprintw(windows[j], 1, place[j]+1, bits[j][place[j]].c_str());

      // use a variable to increment or decrement the value based on the input.
      switch( ch ) {
         case KEY_LEFT:
            place[j]--;
            if ( place[j] < 0 )
            {
               place[j] = 7;
            }
            break;
         case KEY_RIGHT:
            place[j]++;
            if ( place[j] > 7 )
            {
               place[j] = 0;
            }
            break;
         case KEY_UP:
            bits[j][place[j]] = "1";
            break;
         case KEY_DOWN:
            bits[j][place[j]] = "0";
            break;
         case KEY_F(1):
            wattroff( windows[j], A_STANDOUT );
            keypad( windows[j], FALSE );
            j = 0;
            wattron( windows[j], A_STANDOUT );
            keypad( windows[j], TRUE );
            break;
         case KEY_F(2):
            wattroff( windows[j], A_STANDOUT );
            keypad( windows[j], FALSE );
            j = 1;
            wattron( windows[j], A_STANDOUT );
            keypad( windows[j], TRUE );
            break;
         case KEY_F(3):
            wattroff( windows[j], A_STANDOUT );
            keypad( windows[j], FALSE );
            j = 2;
            wattron( windows[j], A_STANDOUT );
            keypad( windows[j], TRUE );
            break;
         case KEY_F(4):
            wattroff( windows[j], A_STANDOUT );
            keypad( windows[j], FALSE );
            j = 3;
            wattron( windows[j], A_STANDOUT );
            keypad( windows[j], TRUE );
            break;
      }

      // now highlight the next item in the list.
      wattron( windows[j], A_STANDOUT );
      mvwprintw(windows[j], 1, place[j]+1, bits[j][place[j]].c_str());
      wattroff( windows[j], A_STANDOUT );

      for(k = 0; k < 5; k++)
      {
         wrefresh( windows[k] ); // update the terminal screen
      }
   }

   for(i = 0; i < 5; i++)
   {
      delwin( windows[i] );
   }
   endwin();
}