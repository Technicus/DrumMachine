#include <string>
#include <cstdlib>
#include <ncurses.h>
using namespace std;


int main(int argc, char ** argv)
{
   //Ncurses start
   initscr();
   noecho();
   cbreak();

   // screen size
   int yMax, xMax;
   getmaxyx(stdscr, yMax, xMax);

   // create window for input
   WINDOW * bitwindow = newwin(3, 10, yMax/2, xMax/2);
   box(bitwindow, 0, 0);
   refresh();
   wrefresh(bitwindow);

   // enable keys
   keypad(bitwindow, true);

   string bits[8] = {"0", "0", "0", "0", "0", "0", "0", "0"};
   int bitChoice = 0;
   int bitHighlight = 0;

   while(1)
   {
      for(int i = 0; i < 7; i++)
      {
         if(i == bitHighlight)
         {
            wattron(bitwindow, A_REVERSE);
         }
         mvwprintw(bitwindow, 1, i+1, bits[i].c_str());
         wattron(bitwindow, A_REVERSE);
      }
      bitChoice = wgetch(bitwindow);

      switch(bitChoice)
      {
         case KEY_LEFT:
            bitHighlight--;
            if(bitHighlight == -1)
            {
               bitHighlight = 0;
            }
            break;
         case KEY_RIGHT:
            bitHighlight--;
            if(bitHighlight == +1)
            {
               bitHighlight = 7;
            }
            break;
         default:
            break;
      }
      if(bitChoice == 10)
      {
         break;
      }
   }
   //printw("the bit is: %s", bits[bitChoice].c_str());
   curs_set(1);
   refresh();
   getch();
   endwin();
}
      /*
       *  ----------------------
       *  WINDOW *w;
       *  char list[5][7] = { "One", "Two", "Three", "Four", "Five" };
       *  char item[7];
       *  int ch, i = 0, width = 7;
       *
       *  initscr(); // initialize Ncurses
       *  w = newwin( 10, 12, 1, 1 ); // create a new window
       *  box( w, 0, 0 ); // sets default borders for the window
       *
       *  // now print all the menu items and highlight the first one
       *  for( i=0; i<5; i++ ) {
       *     if( i == 0 )
       *        wattron( w, A_STANDOUT ); // highlights the first item.
       *        else
       *           wattroff( w, A_STANDOUT );
       *        sprintf(item, "%-7s",  list[i]);
       *     mvwprintw( w, i+1, 2, "%s", item );
   }

   wrefresh( w ); // update the terminal screen

   i = 0;
   noecho(); // disable echoing of characters on the screen
   keypad( w, TRUE ); // enable keyboard input for the window.
   curs_set( 0 ); // hide the default screen cursor.

   // get the input
   while(( ch = wgetch(w)) != 'q'){

      // right pad with spaces to make the items appear with even width.
      sprintf(item, "%-7s",  list[i]);
      mvwprintw( w, i+1, 2, "%s", item );
      // use a variable to increment or decrement the value based on the input.
      switch( ch ) {
         case KEY_UP:
            i--;
            i = ( i<0 ) ? 4 : i;
            break;
         case KEY_DOWN:
            i++;
            i = ( i>4 ) ? 0 : i;
            break;
   }
   // now highlight the next item in the list.
   wattron( w, A_STANDOUT );

   sprintf(item, "%-7s",  list[i]);
   mvwprintw( w, i+1, 2, "%s", item);
   wattroff( w, A_STANDOUT );
   }

   delwin( w );
   endwin();*/
//    }