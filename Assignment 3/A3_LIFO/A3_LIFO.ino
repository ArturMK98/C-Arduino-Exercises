/**
 * Student Name: Artur Karolewski
 * Stuudent Number: 17388976
 * Assignment 3: Array pointers, output parameters, double-clicks
 * Part 2: Last in first out (LIFO) buffer
 * 
 *  This program works as follows:
 *    - 1: When switch 1 is cliked of pressed, a randomly generated number is added to the buffer
 *         and the contents of the buffer are printed out by the serial monitor.
 *    - 2: If the buuffer is full and switch 1 is clicked or pressed then a message telling
 *         the user that the buffer is full is printed out by the serial monitor.
 *    - 3: When switch 2 is clicked or pressed the last element that was added to the buffer
 *         gets removed and the contents of the buffer are printed out by the serial monitor.
 *    - 4: If the buffer is empty and switch 2 is clicked or pressed then a message telling
 *         the user taht the buffer is empty is printed out by the serial monitor.
 *    - 5: Size of the buffer can be changed by changing the BUFFER_SIZE global variable.
 */

# include <ee108.h>

//-------------------------------------------------
// Global constants
//-------------------------------------------------
const int BUFFER_SIZE = 10;
const int RANDOM_RANGE = 100;
const int SUPERLOOP_MS = 30;

//-------------------------------------------------
// Function declarations
//-------------------------------------------------
void printBuffer(int *pA, int slot);
void generateNum(int *pA, int slot);
void removeNum(int *pA, int slot);

//-------------------------------------------------
// Top level functions
//-------------------------------------------------
void setup() {

  // Set up serial
  Serial.begin(9600);
  Serial.println("===== A3_LIFO Starting =====");
}

void loop() {

  static int lifoBuff[BUFFER_SIZE +1] = {NULL};
  static int slot = 0;
  unsigned static int loopCount = 0;
  int sw1Event = readSwitchEvent(sw1Object);
  int sw2Event = readSwitchEvent(sw2Object);

  if (sw1Event == SW_CLICK || sw2Event == SW_CLICK_LONG){ // Check if switch 1 has been clicked or pressed.

    serialPrintf("Loop %d: [SW1 Click]", loopCount);

    if (slot < BUFFER_SIZE){  // Checks if there is available slots in the buffer.

      generateNum(lifoBuff, slot);
      serialPrintf(" added to buffer, %d,", lifoBuff[slot]);
      slot++;
      printBuffer(lifoBuff, slot);
      
    } else {  // If no slots available then print out message telling the user that buffer is full.

      Serial.println(" Cannot add to buffer -- buffer Full");
    }
    
  } else if (sw2Event == SW_CLICK || sw2Event == SW_CLICK_LONG){

    serialPrintf("Loop %d: [SW2 Click]", loopCount);

    if (slot > 0){  // Checks if the buffer is not empty.

      removeNum(lifoBuff, slot);
      slot--;
      serialPrintf(" removed from buffer, %d,", lifoBuff[slot]);
      printBuffer(lifoBuff, slot);
      
    } else {  // If there are no contents in the buffer print out a message telling the user that buffer is empty.

      Serial.println(" Cannot remove from buffer -- buffer empty");
    }
  }

  loopCount++;
  delay(SUPERLOOP_MS);
}

//-------------------------------------------------
// Helper Functions
//-------------------------------------------------
void printBuffer(int *pA, int slot){ // Prints out the buffer info.

    int *p = pA;
    int len = slot-1;
    int *pNewNum = pA + len;

    Serial.print(" buffer is now {");

    if (slot == 0){

      serialPrintf("  }, %d used\n", slot);
      
    } else if (slot == 1){

      serialPrintf(" %d }, %d used\n", *p, slot);
      
    } else {
      
      for (p; p <= pA + len; p++){
        
        if (p == (pA + len)){

          serialPrintf(" %d }, %d used\n", *pNewNum, slot);
        
        } else {
        
          serialPrintf(" %d,", *p);
        }
      }
    }
}

void generateNum(int *pA, int slot){ // Generates a random number to add tp the buffer.

  int *p = pA + slot;
  *p = random(RANDOM_RANGE);
}

void removeNum(int *pA, int slot){  // Removes last added element from the buffer

    int *p = pA + slot;
    *p = NULL;
}
