#include<ncurses.h>

main() {

   WINDOW *w;
   char list[8][8] = { "0", "0", "0", "0", "0", "0", "0", "0" };
   char item[8];
   int ch, i = 0, width = 1;

   initscr(); // initialize Ncurses
   w = newwin( 3, 10, 1, 2 ); // create a new window
   box( w, 0, 0 ); // sets default borders for the window

   // now print all the menu items and highlight the first one
   for( i=0; i<8; i++ ) {
      if( i == 0 )
         wattron( w, A_STANDOUT ); // highlights the first item.
         else
            wattroff( w, A_STANDOUT );
         sprintf(item, "%-1s",  list[i]);
      mvwprintw( w, 1, i+1, "%s", item );
   }

   wrefresh( w ); // update the terminal screen

   i = 0;
   noecho(); // disable echoing of characters on the screen
   keypad( w, TRUE ); // enable keyboard input for the window.
   curs_set( 0 ); // hide the default screen cursor.

   // get the input
   while(( ch = wgetch(w)) != 'q'){

      // right pad with spaces to make the items appear with even width.
      //sprintf(item, "%-1s",  list[i]);
      mvwprintw( w, 1, i+1, "%s", item );
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
            item[i] = '1';
            break;
         case KEY_DOWN:
            item[i] = '0';
            break;
      }
      // now highlight the next item in the list.
      wattron( w, A_STANDOUT );

      //sprintf(item, "%-1s",  list[i]);
      mvwprintw( w, 1, i+1, "%s", item);
      wattroff( w, A_STANDOUT );
   }

   delwin( w );
   endwin();
}