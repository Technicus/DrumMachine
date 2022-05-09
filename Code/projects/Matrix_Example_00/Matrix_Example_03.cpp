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

typedef struct Out {
   union {
      struct Data {
         bool a:1;
         bool b:1;
         bool c:1;
         bool d:1;
         bool e:1;
         bool f:1;
         bool g:1;
         bool h:1;
      } data;
      unsigned char v;
   } Output;
} Out;

static inline void toOutput(struct Out* out, unsigned char value){
   out->Output.data.a = value & (1 << 8);
   out->Output.data.b = value & (1 << 7);
   out->Output.data.c = value & (1 << 6);
   out->Output.data.d = value & (1 << 5);
   out->Output.data.e = value & (1 << 4);
   out->Output.data.f = value & (1 << 3);
   out->Output.data.g = value & (1 << 2);
   out->Output.data.h = value & 1;
}

// struct DisplaySegment {
//    bool a:1;
//    bool b:1;
//    bool c:1;
//    bool d:1;
//    bool e:1;
//    bool f:1;
//    bool g:1;
//    bool dp:1;
// } *Display_Segment;
//
// struct DisplayElement {
//    bool unused:4;
//    bool anode_0:1;
//    bool anode_1:1;
//    bool anode_2:1;
// } *Display_Element;
//
// struct OutputRow {
//    bool row_0:1;
//    bool row_1:1;
//    bool row_2:1;
//    bool row_3:1;
//    bool row_4:1;
//    bool row_5:1;
//    bool row_6:1;
//    bool row_7:1;
// } *Output_Row;
//
// struct OutputCol {
//    bool col_0:1;
//    bool col_1:1;
//    bool col_2:1;
//    bool col_3:1;
//    bool col_4:1;
//    bool col_5:1;
//    bool col_6:1;
//    bool col_7:1;
// } *Output_Col;
//
// struct Input {
//    bool col_0:1;
//    bool col_1:1;
//    bool col_2:1;
//    bool col_3:1;
//    bool col_4:1;
//    bool col_5:1;
//    bool col_6:1;
//    bool col_7:1;
// } *Input_Data;

const int busSpeedHz = 100000;
const int csDelay = 0; // how long to delay after the last bit transfer before deselecting the device
unsigned char wordLength = 32;

Gpio inLoad;
Gpio outLatch;
const int inLoadPin = 46;
const int outLatchPin = 44;

int main(){

//    struct DisplaySegment *Display_Segment;
//    struct DisplayElement *Display_Element;
//    struct OutputRow *Output_Row; //   outputRow = &d;
//    struct OutputCol *Output_Col;
//    struct Input *Input_Data;

   Out outputRow = {};
//    unsigned char TArray[4];
//
//    toOutput(&outputRow, 123);
//    TArray[0] = outputRow.Output.v;

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
      outLatch.write(1);
      outLatch.write(0);

      int transmissionLength = 4;
      unsigned char Tx_spi[transmissionLength];
      unsigned char Rx_spi[transmissionLength];

      toOutput(&outputRow, 0b11111111);

      Tx_spi[0] = outputRow.Output.v;
      Tx_spi[1] = outputRow.Output.v;
      Tx_spi[2] = outputRow.Output.v;
      Tx_spi[3] = outputRow.Output.v;

//       Tx_spi[0] = 0b00000001; // LED rows - LSB output row to drive input shift register rows | 0 = on for LED, 1 = on for switch matrix
//       Tx_spi[1] = 0b11111111; // LED coloums
//       Tx_spi[2] = 0b11111000; // segment display cathode - 5 upper bits unused
//       Tx_spi[3] = 0b00000000; // Segment display anode
//       Tx_spi[0] = (unsigned char) &Output_Row; // LED rows - LSB output row to drive input shift register rows
//       Tx_spi[1] = (unsigned char) &Output_Col; // LED coloums
//       Tx_spi[2] = (unsigned char) &Display_Element; // segment display cathode - 5 upper bits unused
//       Tx_spi[3] = (unsigned char) &Display_Segment; // Segment display anode

      SPIDEV1_transfer(Tx_spi, Rx_spi, transmissionLength);

      printf("(Main)spidev1.0: Transaction Complete. Sent %d bytes, received: ", transmissionLength);
      int n = 0;
      for(n = 0; n < transmissionLength; ++n)
      {
         printf("%#02x ", Rx_spi[n]);
      }
      printf("\n");

      usleep(100000);
      printf("%d\r\n", ++i);
   }
   #endif
}



/*
 * Example
 *
 *
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 * 10
 * 11
 * 12
 * 13
 * 14
 * 15
 * 16
 * 17
 * 18
 * 19
 * 20
 * 21
 * 22
 * 23
 * 24
 * 25
 * 26
 * 27
 * 28
 * 29
 * 30
 * 31
 * 32
 * 33
 * 34
 * 35
 * 36
 * 37
 * 38
 * 39
 *
 * #include <iostream>
 * using namespace std;
 *
 * typedef struct Out {
 *	union {
 *		struct Data {
 *			unsigned int a:1;
 *			unsigned int b:1;
 *			unsigned int c:1;
 *			unsigned int d:1;
 *			unsigned int e:1;
 *			unsigned int f:1;
 *			unsigned int g:1;
 *			unsigned int h:1;
 *		} data;
 *		unsigned char v;
 *	} Output;
 * } Out;
 *
 * static inline void toOutput(struct Out* out, unsigned char value){
 *	out->Output.data.a = value & (1 << 8);
 *	out->Output.data.b = value & (1 << 7);
 *	out->Output.data.c = value & (1 << 6);
 *	out->Output.data.d = value & (1 << 5);
 *	out->Output.data.e = value & (1 << 4);
 *	out->Output.data.f = value & (1 << 3);
 *	out->Output.data.g = value & (1 << 2);
 *	out->Output.data.h = value & 1;
 * }
 *
 * int main() {
 *	Out outputRow = {};
 *	unsigned char TArray[4];
 *
 *	toOutput(&outputRow, 123);
 *	TArray[0] = outputRow.Output.v;
 *
 *	return 0;
 * }
 *
 */