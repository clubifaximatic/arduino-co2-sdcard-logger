
#include <ShiftRegister74HC595.h>

/**
4 bitLed Segment Tube Module (using 74HC595)

https://www.ardumotive.com/4-digit-7seg-display-en.html

Pinout
/--------------------\
|   _   _   _   _    |- GND
|  | | | | | | | |   |- D/O
|   -   -   -   -    |- RCLK (Latch)
|  | | | | | | | |   |- SCLK
|   -   -   -   -    |- VCC 
\--------------------/
 */

//     ShiftRegister74HC595(const uint8_t serialDataPin, const uint8_t clockPin, const uint8_t latchPin);

#define PIN_LCD_SERIAL_DATA 7
#define PIN_LCD_REGISTER_CLOCK 6
#define PIN_LCD_SERIAL_CLOCK 5

ShiftRegister74HC595<4> sr(PIN_LCD_SERIAL_DATA, PIN_LCD_SERIAL_CLOCK, PIN_LCD_REGISTER_CLOCK); 

// uint8_t  numberB[] = { B11000000,   // 0
//                        B11111001,   // 1 
//                        B10100100,   // 2
//                        B10110000,   // 3 
//                        B10011001,   // 4
//                        B10010010,   // 5
//                        B10000011,   // 6
//                        B11111000,   // 7
//                        B10000000,   // 8
//                        B10011000 }; // 9
const uint8_t numberB[10] = {
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00100111, //7
    0b01111111, //8
    0b01101111, //9
};

void setupLCD() {
  pinMode(PIN_LCD_SERIAL_DATA, OUTPUT);
  pinMode(PIN_LCD_SERIAL_CLOCK, OUTPUT);
  pinMode(PIN_LCD_REGISTER_CLOCK, OUTPUT);
}

void lcdPrint(float number) {
  
  // // setting all pins at the same time to either HIGH or LOW
  // sr.setAllHigh(); // set all pins HIGH
  // delay(500);
  
  // sr.setAllLow(); // set all pins LOW
  // delay(500); 
  
  // int integerRepresentation = (int)(number * 10);
  // int digit0 = integerRepresentation % 10;
  // int digit1 = (integerRepresentation / 10) % 10;
  // int digit2 = (integerRepresentation / 100) % 10;
  // int digit3 = (integerRepresentation / 1000) % 10;

  // uint8_t numberToPrint[]= { numberB[1], numberB[1], numberB[1], numberB[1] };
  // sr.setAll(numberToPrint);
  // delay(1000);

  // setting single pins
  //for (int i = 0; i < 8; i++) {
    sr.set(2, HIGH); // set single pin HIGH
    sr.set(4, HIGH); // set single pin HIGH
    delay(1000); 
  //}
  
  // set all pins at once
  // uint8_t pinValues[] = { numberB[1] }; 
  // sr.setAll(pinValues); 
  // delay(1000);
  
  // // read pin (zero based, i.e. 6th pin)
  // uint8_t stateOfPin5 = sr.get(5);
  // sr.set(6, stateOfPin5);

  // // set pins without immediate update
  // sr.setNoUpdate(0, HIGH);
  // sr.setNoUpdate(1, LOW);
  // // at this point of time, pin 0 and 1 did not change yet
  // sr.updateRegisters(); // update the pins to the set values
}