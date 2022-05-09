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

int main(){

   //    Output outputRow = {};
   DisplayCathode displayCathode = {};
   DisplayAnode displayAnode = {};

   struct DisplayCathode* setDisplayCathode;
   setDisplayCathode = &displayCathode;

   struct DisplayAnode* setDisplayAnode;
   setDisplayAnode = &displayAnode;

   inLoad.open(inLoadPin, OUTPUT);
   outLatch.open(outLatchPin, OUTPUT);
   inLoad.write(0);
   inLoad.write(1);

   int i = 0;
   if (SPI_DEV1_init(0, busSpeedHz, SPI_SS_LOW,
      csDelay, wordLength,
      SPI_MODE3) == -1)
      printf("(Main)spidev1.0 initialization failed\r\n");

   else
      printf("(Main)spidev1.0 initialized - READY\r\n");


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

//       toDisplayCathode(&displayCathode, 0b11111111);
//       toDisplayCathode(&displayAnode, 0b00011111);

      setDisplayAnode->Output.data.digit_0 = 0;
      setDisplayAnode->Output.data.digit_1 = 0;
      setDisplayAnode->Output.data.digit_2 = 0;

      setDisplayCathode->Output.data.segment_a = 1;
      setDisplayCathode->Output.data.segment_b = 1;
      setDisplayCathode->Output.data.segment_c = 1;
      setDisplayCathode->Output.data.segment_d = 1;
      setDisplayCathode->Output.data.segment_e = 1;
      setDisplayCathode->Output.data.segment_f = 1;
      setDisplayCathode->Output.data.segment_g = 1;
      setDisplayCathode->Output.data.segment_p = 1;

      Tx_spi[0] = 0b00000000; // LED input shift register rows | 0 = on for LED, 1 = on for switch matrix
      Tx_spi[1] = 0b00000000;// LED coloums
      Tx_spi[2] = displayAnode.Output.v;// Segment display anode
      Tx_spi[3] = displayCathode.Output.v;// segment display cathode - 5 upper bits unused

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
 *
 *
 *
 *
 * // struct DisplaySegment {
 * //    bool a:1;
 * //    bool b:1;
 * //    bool c:1;
 * //    bool d:1;
 * //    bool e:1;
 * //    bool f:1;
 * //    bool g:1;
 * //    bool dp:1;
 * // } *Display_Segment;
 * //
 * // struct DisplayElement {
 * //    bool unused:4;
 * //    bool anode_0:1;
 * //    bool anode_1:1;
 * //    bool anode_2:1;
 * // } *Display_Element;
 * //
 * // struct OutputRow {
 * //    bool row_0:1;
 * //    bool row_1:1;
 * //    bool row_2:1;
 * //    bool row_3:1;
 * //    bool row_4:1;
 * //    bool row_5:1;
 * //    bool row_6:1;
 * //    bool row_7:1;
 * // } *Output_Row;
 * //
 * // struct OutputCol {
 * //    bool col_0:1;
 * //    bool col_1:1;
 * //    bool col_2:1;
 * //    bool col_3:1;
 * //    bool col_4:1;
 * //    bool col_5:1;
 * //    bool col_6:1;
 * //    bool col_7:1;
 * // } *Output_Col;
 * //
 * // struct Input {
 * //    bool col_0:1;
 * //    bool col_1:1;
 * //    bool col_2:1;
 * //    bool col_3:1;
 * //    bool col_4:1;
 * //    bool col_5:1;
 * //    bool col_6:1;
 * //    bool col_7:1;
 * // } *Input_Data;
 *
 *
 *
 / /    struct DisplaySegment *Display_*Segment;
 //    struct DisplayElement *Display_Element;
 //    struct OutputRow *Output_Row; //   DisplayCathode = &d;
 //    struct OutputCol *Output_Col;
 //    struct Input *Input_Data;

 //    unsigned char TArray[4];
 //
 //    toOutput(&DisplayCathode, 123);
 //    TArray[0] = DisplayCathode.Output.v;
*

//       Tx_spi[0] = 0b00000001; // LED rows - LSB output row to drive input shift register rows | 0 = on for LED, 1 = on for switch matrix
//       Tx_spi[1] = 0b11111111; // LED coloums
//       Tx_spi[2] = 0b11111000; // segment display cathode - 5 upper bits unused
//       Tx_spi[3] = 0b00000000; // Segment display anode
//       Tx_spi[0] = (unsigned char) &Output_Row; // LED rows - LSB output row to drive input shift register rows
//       Tx_spi[1] = (unsigned char) &Output_Col; // LED coloums
//       Tx_spi[2] = (unsigned char) &Display_Element; // segment display cathode - 5 upper bits unused
//       Tx_spi[3] = (unsigned char) &Display_Segment; // Segment display anode

*


 * Example
 *
 * #include <iostream>
 * using namespace std;
 *
 * typedef struct DisplayCathode {
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
 * } DisplayCathode;
 *
 * static inline void toOutput(struct DisplayCathode* out, unsigned char value){
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
 *	DisplayCathode DisplayCathode = {};
 *	unsigned char TArray[4];
 *
 *	toOutput(&DisplayCathode, 123);
 *	TArray[0] = DisplayCathode.Output.v;
 *
 *	return 0;
 * }
 *
 */