// https://www.daemon-systems.org/man/getch.3.html
// http://invisible-island.net/ncurses/ncurses.faq.html#modified_keys

#include <string>
#include <cstdlib>
#include <ncurses.h>
#include <Bela.h>
#include <stdio.h>
#include <unistd.h>
#include "SPI.h"
#include <Gpio.h>
#include <Utilities.h> // for OUTPUT
using namespace std;

/* Enable SPI Debug */
#define SPI_DBG

typedef struct DisplayCathode {
   union {
      struct Data {
         bool segment_a:1;
         bool segment_b:1;
         bool segment_c:1;
         bool segment_d:1;
         bool segment_e:1;
         bool segment_f:1;
         bool segment_g:1;
         bool segment_p:1;
      } data;
      unsigned char v;
   } Output;
} DisplayCathode;

static inline void toDisplayCathode(struct DisplayCathode* out, unsigned char value){
   out->Output.data.segment_a = value & (1 << 8);
   out->Output.data.segment_b = value & (1 << 7);
   out->Output.data.segment_c = value & (1 << 6);
   out->Output.data.segment_d = value & (1 << 5);
   out->Output.data.segment_e = value & (1 << 4);
   out->Output.data.segment_f = value & (1 << 3);
   out->Output.data.segment_g = value & (1 << 2);
   out->Output.data.segment_p = value & (1 << 1);
}

typedef struct DisplayAnode {
   union {
      struct Data {
         bool digit_0:1;
         bool digit_1:1;
         bool digit_2:1;
         bool digit_3:1;
         bool digit_4:1;
         bool digit_5:1;
         bool digit_6:1;
         bool digit_7:1;
      } data;
      unsigned char v;
   } Output;
} DisplayAnode;

static inline void toDisplayAnode(struct DisplayAnode* out, unsigned char value){
   out->Output.data.digit_0 = value & (1 << 8);
   out->Output.data.digit_1 = value & (1 << 7);
   out->Output.data.digit_2 = value & (1 << 6);
   out->Output.data.digit_3 = value & (1 << 5);
   out->Output.data.digit_4 = value & (1 << 4);
   out->Output.data.digit_5 = value & (1 << 3);
   out->Output.data.digit_6 = value & (1 << 2);
   out->Output.data.digit_7 = value & (1 << 1);
}




const int busSpeedHz = 100000;
const int csDelay = 0; // how long to delay after the last bit transfer before deselecting the device
unsigned char wordLength = 32;

Gpio inLoad;
Gpio outLatch;
const int inLoadPin = 46;
const int outLatchPin = 44;

void bitSet(int bitRegister, int bit, int toggle);

void bitSet(int bitRegister, int bit, int toggle)
{

   // Output outputRow = {};
   DisplayCathode displayCathode = {};
   DisplayAnode displayAnode = {};

   struct DisplayCathode* setDisplayCathode;
   setDisplayCathode = &displayCathode;

   struct DisplayAnode* setDisplayAnode;
   setDisplayAnode = &displayAnode;

   switch(bitRegister)
   {
      case 0:
         switch(bit)
         {
            case 0:
               if (toggle == 0)
               {

               } else {

               }
               break;
            case 1:
               if (toggle == 0)
               {

               } else {

               }
               break;
            case 2:
               if (toggle == 0)
               {

               } else {

               }
               break;
            case 3:
               if (toggle == 0)
               {

               } else {

               }
               break;
            case 4:
               if (toggle == 0)
               {

               } else {

               }
               break;
            case 5:
               if (toggle == 0)
               {
                  setDisplayAnode->Output.data.digit_0 = 0;
               } else {
                  setDisplayAnode->Output.data.digit_0 = 1;
               }
               break;
            case 6:
               if (toggle == 0)
               {
                  setDisplayAnode->Output.data.digit_1 = 0;
               } else {
                  setDisplayAnode->Output.data.digit_1 = 1;
               }
               break;
            case 7:
               if (toggle == 0)
               {
                  setDisplayAnode->Output.data.digit_2 = 0;
               } else {
                  setDisplayAnode->Output.data.digit_2 = 1;
               }
               break;
         }
         break;
      case 1:
         switch(bit)
         {
            case 0:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_a = 0;
               } else {
                  setDisplayCathode->Output.data.segment_a = 1;
               }
               break;
            case 1:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_b = 0;
               } else {
                  setDisplayCathode->Output.data.segment_b = 1;
               }
               break;
            case 2:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_c = 0;
               } else {
                  setDisplayCathode->Output.data.segment_c = 1;
               }
               break;
            case 3:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_d = 0;
               } else {
                  setDisplayCathode->Output.data.segment_d = 1;
               }
               break;
            case 4:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_e = 0;
               } else {
                  setDisplayCathode->Output.data.segment_e = 1;
               }
               break;
            case 5:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_f = 0;
               } else {
                  setDisplayCathode->Output.data.segment_f = 1;
               }
               break;
            case 6:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_g = 0;
               } else {
                  setDisplayCathode->Output.data.segment_g = 1;
               }
               break;
            case 7:
               if (toggle == 0)
               {
                  setDisplayCathode->Output.data.segment_p = 0;
               } else {
                  setDisplayCathode->Output.data.segment_p = 1;
               }
               break;
         }
         break;
   }
   inLoad.write(0);
   inLoad.write(1);
   outLatch.write(1);
   outLatch.write(0);

   int transmissionLength = 4;
   unsigned char Tx_spi[transmissionLength];
   unsigned char Rx_spi[transmissionLength];

   Tx_spi[0] = 0b00000000; // LED input shift register rows | 0 = on for LED, 1 = on for switch matrix
   Tx_spi[1] = 0b00000000;// LED coloums
   Tx_spi[2] = displayAnode.Output.v;// Segment display anode
   Tx_spi[3] = displayCathode.Output.v;// segment display cathode - 5 upper bits unused

   SPIDEV1_transfer(Tx_spi, Rx_spi, transmissionLength);

//    printf("(Main)spidev1.0: Transaction Complete. Sent %d bytes, received: ", transmissionLength);
   int n = 0;
   for(n = 0; n < transmissionLength; ++n)
   {
//       printf("%#02x ", Rx_spi[n]);
   }
//    printf("\n");

   usleep(100000);
//    printf("%d\r\n", ++i);
}


main() {

   inLoad.open(inLoadPin, OUTPUT);
   outLatch.open(outLatchPin, OUTPUT);
   inLoad.write(0);
   inLoad.write(1);

   if (SPI_DEV1_init(0, busSpeedHz, SPI_SS_LOW,
      csDelay, wordLength,
      SPI_MODE3) == -1)
      printf("(Main)spidev1.0 initialization failed\r\n");

   else
      printf("(Main)spidev1.0 initialized - READY\r\n");

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

//    #ifdef SPI_DBG

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
            bitSet(j, place[j], 1);
            break;
         case KEY_DOWN:
            bits[j][place[j]] = "0";
            bitSet(j, place[j], 0);
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