/**
 * Student name: Artur Karolewski
 * Student number: 17388976
 * Lab 8 : Strings and Advanced types 
 * Part 2: Basic string manipulation 
 * 
 *  This program doesn't work as required.
 */

#include <ee108.h>

//------------------------------------------------------------
// constants
//------------------------------------------------------------

const int SUPERLOOP_DELAY_MS = 50;
const int STRING_SIZE = 10;

//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

char changePassword(char *pA, int len);

//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab8_PasswordGenStarter starting...\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() {
  int sw1Event;

  static char pass[STRING_SIZE +1] = "PASSWORD";

  sw1Event = readSwitchEvent(sw1Object);

  if (sw1Event == SW_CLICK) { // wait for click
    
    serialPrintf("[SW1 Click] current password is: %s\n\n", pass);
    
  } else if (sw1Event == SW_CLICK_LONG) {

    int len = random(4, STRING_SIZE);
    changePassword(pass, len);
    serialPrintf("[SW1 Long Click] new password (len = %d): %s\n\n", len, pass);
  }
  
  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------

char changePassword(char *pA, int len){

  char letters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* p;
  for(p = pA; p < len; p++){

      *p = random('A' + len);
  }

  return pA;
}
