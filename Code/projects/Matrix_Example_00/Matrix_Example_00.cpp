/*
 *
 */

#include <Bela.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "SPI.h"
#include <Gpio.h>
#include <Utilities.h> // for OUTPUT
#include <bitset>

/* Enable SPI Debug */
#define SPI_DBG


const int busSpeedHz = 10000; //100000;
const int csDelay = 0; // how long to delay after the last bit transfer before deselecting the device
unsigned char wordLength = 32;

//Constuct 01: 8 bits initialized to zero
// bitset<8> bitset1

Gpio inLoad;
Gpio outLatch;
const int inLoadPin = 46;
const int outLatchPin = 44;


// bitset<8> ToBits(unsigned char byte){
//    return bitset<8>(byte);
// }

int main(){



//    inLoad.open(inLoadPin, OUTPUT);
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

   int switchArray[0];

   #ifdef SPI_DBG
   while (1) {
      inLoad.write(0);
      inLoad.write(1);

      int transmissionLength = 4;
      unsigned char Tx_spi[transmissionLength];
      unsigned char Rx_spi[transmissionLength];
      Tx_spi[0] = 0b00000001; // LED rows - LSB output row to drive input shift register rows | 0 = on for LED, 1 = on for switch matrix
      Tx_spi[1] = 0b11111111; // LED coloums
      Tx_spi[2] = 0b11111000; // segment display cathode - 5 upper bits unused
      Tx_spi[3] = 0b11111111; // Segment display anode

      outLatch.write(1);
      outLatch.write(0);

      SPIDEV1_transfer(Tx_spi, Rx_spi, transmissionLength);

      printf("(Main)spidev1.0: Transaction Complete. Sent %d bytes, received: ", transmissionLength);
//       int n = 0;
//       for(n = 0; n < transmissionLength; ++n) {
//          printf("%#02x ", Rx_spi[n]);
//       }
      printf("%#02x ", Rx_spi[0]);
//       bitset<8> inputs=ToBits(Rx_spi[0]);

//       printf("%#02x ", inputs);

      printf("\n");

//       for (int i = 0; i < 7; i++){
//          if (Tx_spi[0] & (1 << i)) {
//             switchArray[i] = 1;
//          }
//          else {
//             switchArray[i] = 0;
//          }
//       }

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


/*
int switchCheck(char whichSwitch) {

   if (inputs & (1 << whichSwitch)) {
      return 0;
   }
   else {
      return 1;
   }

}


void inputTest() {

   while (1) {
      delay(100);
      unsigned short valueOut = lightBits;

      digitalWrite(SWITCHLATACH, 0);    //Pulse LOW to latch the switch data
      digitalWrite(SWITCHLATACH, 1);

      unsigned short valueIn = SPI.transfer16(valueOut);

      digitalWrite(LEDLATCH, 1);       //Pulse HIGH to assert light data
      digitalWrite(LEDLATCH, 0);

      inputs = valueIn;

      lcd.clear();
      lcd.print(inputs, BIN);

   }

}

int readSwitch(unsigned char switchGet) {						//Read a matrix switch. If switch is on and debounce is off, returns a 1, else 0

   if ((switchStatus[switchGet] == swRampDBTime[switchGet]) and (swDebounce[switchGet] == 0)) {			//Has switch been on for its minimum time?
      swDebounce[switchGet] = swDBTime[switchGet];													//Set switch timer to its standard debounce from the table
      return 1;																						//Return value of switch bit. The only way 1 will be returned is if Debounce has reset.
   }
   else {
      return 0;										//If timer not yet reset, return a 0.
   }

}

void test_cycleLED(){
   int timetoBlink = 100;




 result = value << 1;

 value = value << 1;

 value <<= 1;

 if (value & (1 << 15) == 0) {
  value <<= 1;
}
else (
   value = 1;
)
}

void edgeDetect() {       //Interrupt calls this 1000 times a second. Tells main loop to execute

   milliEdges++;

}


*/




