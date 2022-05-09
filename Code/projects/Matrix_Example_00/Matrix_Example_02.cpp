/*
test
 */

#include <Bela.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "SPI.h"
#include <Gpio.h>
#include <Utilities.h> // for OUTPUT

/* Enable SPI Debug */
#define SPI_DBG

struct DisplayCathode {
   unsigned int a:1;
   unsigned int b:1;
   unsigned int c:1;
   unsigned int d:1;
   unsigned int e:1;
   unsigned int f:1;
   unsigned int g:1;
   unsigned int dp:1;
};

struct DisplayAnode {
   unsigned int unused:4;
   unsigned int anode_0:1;
   unsigned int anode_1:1;
   unsigned int anode_2:1;
};

struct OutputRow {
   unsigned int row_0:1;
   unsigned int row_1:1;
   unsigned int row_2:1;
   unsigned int row_3:1;
   unsigned int row_4:1;
   unsigned int row_5:1;
   unsigned int row_6:1;
   unsigned int row_7:1;
};

struct OutputCol {
   unsigned int col_0:1;
   unsigned int col_1:1;
   unsigned int col_2:1;
   unsigned int col_3:1;
   unsigned int col_4:1;
   unsigned int col_5:1;
   unsigned int col_6:1;
   unsigned int col_7:1;
};

struct Input {
   unsigned int col_0:1;
   unsigned int col_1:1;
   unsigned int col_2:1;
   unsigned int col_3:1;
   unsigned int col_4:1;
   unsigned int col_5:1;
   unsigned int col_6:1;
   unsigned int col_7:1;
};

const int busSpeedHz = 100000;
const int csDelay = 0; // how long to delay after the last bit transfer before deselecting the device
unsigned char wordLength = 32;

Gpio inLoad;
Gpio outLatch;
const int inLoadPin = 46;
const int outLatchPin = 44;

int main(){

   struct DisplayCathode displayCathode;
   struct DisplayAnode displayAnode;
   struct OutputRow outputRow;
   struct OutputCol outputCol;
   struct Input input;

   inLoad.open(inLoadPin, OUTPUT);
   outLatch.open(outLatchPin, OUTPUT);

   int i = 0;
   if (SPI_DEV1_init(0, busSpeedHz, SPI_SS_LOW,
      csDelay, wordLength,
      SPI_MODE3) == -1)
      printf("(Main)spidev1.0 initialization failed\r\n");

   else
      printf("(Main)spidev1.0 initialized - READY\r\n");

   inLoad.write(0);
   inLoad.write(1);

   #ifdef SPI_DBG
   while (1)

   {
      inLoad.write(0);
      inLoad.write(1);

      int transmissionLength = 4;
      unsigned char Tx_spi[transmissionLength];
      unsigned char Rx_spi[transmissionLength];
      Tx_spi[0] = outputRow[0]; // LED rows - LSB output row to drive input shift register rows
      Tx_spi[1] = outputCol[1]; // LED coloums
      Tx_spi[2] = outputRow[0]; // segment display cathode - 5 upper bits unused
      Tx_spi[3] = outputCol[1]; // Segment display anode



      outLatch.write(1);
      outLatch.write(0);

      SPIDEV1_transfer(Tx_spi, Rx_spi, transmissionLength);

      printf("(Main)spidev1.0: Transaction Complete. Sent %d bytes, received: ", transmissionLength);
      int n = 0;
      for(n = 0; n < transmissionLength; ++n)
      {
         printf("%#02x ", Rx_spi[n]);
      }
      printf("\n");

      //       if (SPIDEV1_transfer(Tx_spi, Rx_spi, transmissionLength) == 0)
      //       {
      //          printf("(Main)spidev1.0: Transaction Complete. Sent %d bytes, received: ", transmissionLength);
      //          int n = 0;
      //          for(n = 0; n < transmissionLength; ++n)
      //          {
      //             printf("%#02x ", Rx_spi[n]);
      //          }
      //          printf("\n");
      //       }
      //
      //       else
      //          printf("(Main)spidev1.0: Transaction Failed\r\n");

      usleep(100000);
      printf("%d\r\n", ++i);
   }
   #endif
}
