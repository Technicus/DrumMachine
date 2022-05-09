#include <ncurses.h>
// #include <curses.h>
using namespace std;

int main(int argc, char ** argv){

   initscr();
   cbreak();
   //raw()
   noecho();
   keypad(stdscr, true);

   int height = 0;
   int width = 0;
   int start_y = 0;
   int start_x = 0;
   int height_terminal = 0;
   int width_terminal = 0;
   int x = 0;
   int y = 0;

   getmaxyx(stdscr, height_terminal, width_terminal);

   start_y = height_terminal/4;
   start_x = width_terminal/4;
   height = height_terminal/2;
   width = width_terminal/2;

   WINDOW * win = newwin(height, width, start_y, start_x);
   refresh();

   box(win, 0, 0);
   mvwprintw(win, 2, 2, "This is the box");
   wrefresh(win);


//    move(height_terminal/2, width_terminal/2);
//    printw("The Center");
   curs_set(1);
   refresh();
   getch();
   endwin();

}