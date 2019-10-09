/**  
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Assignment 2: 7-segment display and lookup table
 *  Part 1: 7 segment display
 *  
 *    This program works as follows:
 *    - 1: Each time the loop runs a random number between 0 and 15 (0xF in HEX) inclusive is generated.
 *    - 2: This number is then printed out to the screen on the serial monitor in HEX, decimal and binary form.
 *    - 3: The number is displayed on the 7 segment display on the Arduino UNO board in HEX form.
 *    - 4: Loop keeps running until the Arduino UNO is plugged out.
 */

#include <ee108.h>

// Global variables
const int SEG_ON_DURATION = 600;
const int SEG_OFF_DURATION = 100;
const int NUM_OF_SEGMENTS = 7; 
const int DIGIT_RANGE = 15;      // 15 = 0xF in HEX
const unsigned int HEX_0_TO_15 [DIGIT_RANGE + 1][NUM_OF_SEGMENTS] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},    // Lookup table
                                                                     {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                                                                     {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                                                                     {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                                                                     {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1},
                                                                     {1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1},
                                                                     {1, 0, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 1, 0, 1},
                                                                     {1, 0, 0, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 1, 1}};

// Function declerations
void setup7Seg(void);
void printInfo(int i);
void display7Seg(int i);
void turnOff7Seg(void);

// Top level functions
void setup() {

  Serial.begin(9600);
  Serial.println("====== A2_SevenSegment Starting ======");

  setup7Seg();
}

void loop() {
  
  int randomDigit = random(DIGIT_RANGE + 1);
  printInfo(randomDigit);
  display7Seg(randomDigit);
}

// Helper functions
void printInfo(int digit){      // Prints out the random digit generated in HEX, decimal and binary using the serial monitor
  
  Serial.print("Number generated in HEX: ");
  Serial.println(digit, HEX);

  Serial.print("Number generated in Decimal: ");
  Serial.println(digit);

  Serial.print("Number generated in binary ");
  Serial.println(digit, BIN);

  Serial.println("======================================");
}

void display7Seg(int digit){    // Displays randomly generated digit on the 7 segment display.

  for (int index = 0 ; index <  NUM_OF_SEGMENTS; index++){
    
    digitalWrite(SEG_A_PIN - index, HEX_0_TO_15[digit][index]);
  }
  
  delay(SEG_ON_DURATION);
  turnOff7Seg();
}

void turnOff7Seg(void){   // Turns off all the parts of the 7 segment display so that there is a short pause between each digit.
  
  for (int index = 0 ; index <  NUM_OF_SEGMENTS; index++){
    
    digitalWrite(SEG_A_PIN - index, LOW);
  }

  delay(SEG_OFF_DURATION);
}

void setup7Seg(void){     // Sets up the 7 segment display

   for (int ledIndex = 0; ledIndex < NUM_OF_SEGMENTS; ledIndex++){

    pinMode(SEG_G_PIN + ledIndex, OUTPUT);
  }
}
