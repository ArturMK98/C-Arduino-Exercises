/**  
 *  Student name: Artur Karolewski
 *  Student number: 17388976
 *  Assignment 1: Functions
 *
 *   This program works as follows:
 *   - 1: Bar LEDs 1 and 2 switch on for 300ms.
 *   - 2: Bar LEDs 3, 5 and 7 switch on for 600ms.
 *   - 3: Bar LEDs 9 and 10 switch on for 50ms and off for 250ms two times.
 *   - 4: A random set of Bar LEDs swithc on for 10ms and off for 140ms five times.
 *   
 *   - Each Bar LED that is on represents a binary 1 and each Bar LED that is off
 *     represents a binary 0. So if Bar LEDs 1 and 2 are on it represents the binary
 *     number (0 0 0 0 0 0 0 0 1 1) or 3 in decimal.
 *   - Each time the loop function executes the seial monitor prints out the binary 
 *     number represented by the Bar LEDs.
 */

#include <ee108.h>

// Global variables
const int DELAY1_MS = 300;
const int DELAY2_MS = 600;
const int DELAY3_MS = 50;
const int DELAY4_MS = 250;
const int DELAY5_MS = 10;
const int DELAY6_MS = 140;
const int LARGEST_10BIT = 1023;

// Function declerations
void setupBarLeds(void);
void printBits(int num);
void lightBarLeds(int num, int onTime);
void turnOffBarLeds(int offTime);
void blinkBarLeds(int ledStates, int numOfBlinks, int onTime, int offTime);

// Top level functions
void setup() {

  Serial.begin(9600);
  Serial.println("====== A1_BitsToBarLeds Starting ========");

  setupBarLeds();
}

void loop() {
  
  unsigned int ledStates = 3;    // Value of ledStates is given decimal values, the bitRead() function
                                 // reads the bits of the given number which are then printed out.
  printBits(ledStates);
  lightBarLeds(ledStates, DELAY1_MS);

  ledStates = 84;
  printBits(ledStates);
  lightBarLeds(ledStates, DELAY2_MS);

  ledStates = 768;
  printBits(ledStates);
  blinkBarLeds(ledStates, 2, DELAY3_MS, DELAY4_MS);

  ledStates = random((LARGEST_10BIT + 1));
  printBits(ledStates);
  blinkBarLeds(ledStates, 5, DELAY5_MS, DELAY6_MS);
  
  Serial.println("---------");
}

// Helper functions
void printBits(int num){    // Prints the bits of a given number.

  Serial.print("ledStates: ");
  
  for (int index = 9; index >= 0; index--){
    
    if (bitRead(num, index) == 1){

      Serial.print("1 ");
      
    } else {

      Serial.print("0 ");
    }
  }

  Serial.println();
}

void blinkBarLeds(int ledStates, int numOfBlinks, int onTime, int offTime){   // Blinks the Bar LEDs specified number of times.
  
  for (int i = 0; i < numOfBlinks; i++){
    
    lightBarLeds(ledStates, onTime);
    turnOffBarLeds(offTime);
  }
}

void lightBarLeds(int num, int onTime){   // Turns on the Bar LEDs for a specified time.
  
  for (int index = (NUM_BAR_LEDS - 1); index >= 0; index--){

    digitalWrite(BAR_LED_1_PIN + index, bitRead(num, index));
  }
  
  delay(onTime);
}

void turnOffBarLeds(int offTime){   // Turns off the Bar LEDs for a specified time.

  for (int index = 0; index < NUM_BAR_LEDS; index++){

    digitalWrite(BAR_LED_1_PIN + index, LOW);
  }
  
  delay(offTime);
}

void setupBarLeds(void){    // Sets up the Bar LEDs.

  for (int ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++){

    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  }
}
