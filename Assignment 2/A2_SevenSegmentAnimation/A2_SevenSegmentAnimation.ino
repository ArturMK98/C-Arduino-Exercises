/**  
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Assignment 2: 7-segment display and lookup table
 *  Part 2: Optional Extra credit
 *  
 *    This program works as follows:
 *      - 1: Each time the loop runs it displays two different animations on the 7 segment display.
 *      - 2: It first displays the animation from the assignment video and then displays a custom animation.
 *      - 3: The serial monitor gives information about which animation is currently being displayed.
 */

#include <ee108.h>

// Global variables
const int SEG_DELAY = 150;
const int NUM_OF_SEGMENTS = 7; 
const int DIGIT_RANGE = 12;
const unsigned int REQUIRED_SEQUENCE [DIGIT_RANGE][NUM_OF_SEGMENTS] = {{0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0},  // Lookup tabel for the required animation
                                                                       {0, 1, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0},
                                                                       {1, 1, 1, 0, 0, 1, 0}, {1, 1, 0, 0, 1, 1, 0},
                                                                       {1, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 1, 1, 1, 0},
                                                                       {0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0},
                                                                       {1, 1, 0, 0, 0, 1, 1}, {0, 0, 1, 1, 1, 0, 1}};
                                                                       
const unsigned int CUSTOM_SEQUENCE [DIGIT_RANGE][NUM_OF_SEGMENTS] =   {{0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1},  // Lookup table for the custom animation
                                                                       {1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 0},
                                                                       {0, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1},
                                                                       {0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0},
                                                                       {0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1},
                                                                       {1, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 0, 1, 1, 0}};

// Function declerations
void setup7Seg(void);
void displayRequiredAnimation(void);
void displayCustomAnimation(void);

// Top level functions
void setup() {

  Serial.begin(9600);
  Serial.println("====== A2_SevenSegmentAnimation Starting ======");

  setup7Seg();
}

void loop() {
  
  Serial.println("Now displaying required animation.");
  displayRequiredAnimation();

  Serial.println("Now displaying custom animation.");
  displayCustomAnimation();

  Serial.println("===============================================");
}

// Helper functions
void displayRequiredAnimation(void){    // Displays the required animation on the 7 segment display   

  for(int loops = 0; loops < 2; loops++){
    for(int i = 0; i < DIGIT_RANGE - 2; i++){
      for(int index = 0; index < NUM_OF_SEGMENTS; index++){

        digitalWrite(SEG_A_PIN - index, REQUIRED_SEQUENCE[i][index]);
      }
      delay(SEG_DELAY);
    }
  }

  for(int loops = 0; loops < 3; loops++){
    for(int i = DIGIT_RANGE -2; i < DIGIT_RANGE; i++){
      for(int index = 0; index < NUM_OF_SEGMENTS; index++){

        digitalWrite(SEG_A_PIN - index, REQUIRED_SEQUENCE[i][index]);
      }
      delay(SEG_DELAY);
    }
  }
}

void displayCustomAnimation(void){    // Displays the custom animation on the 7 segment display

  for(int loops = 0; loops < 2; loops++){
    for(int i = 0; i < DIGIT_RANGE - 2; i++){
      for(int index = 0; index < NUM_OF_SEGMENTS; index++){

        digitalWrite(SEG_A_PIN - index, CUSTOM_SEQUENCE[i][index]);
      }
      delay(SEG_DELAY);
    }
  }

  for(int loops = 0; loops < 3; loops++){
    for(int i = DIGIT_RANGE -2; i < DIGIT_RANGE; i++){
      for(int index = 0; index < NUM_OF_SEGMENTS; index++){

        digitalWrite(SEG_A_PIN - index, CUSTOM_SEQUENCE[i][index]);
      }
      delay(SEG_DELAY);
    }
  }
}



void setup7Seg(void){     // Sets up the 7 segment display

   for (int ledIndex = 0; ledIndex < NUM_OF_SEGMENTS; ledIndex++){

    pinMode(SEG_G_PIN + ledIndex, OUTPUT);
  }
}
