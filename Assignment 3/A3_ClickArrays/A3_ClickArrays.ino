/**
 * Student Name: Artur Karolewski
 * Student Number: 17388976
 * Assignment 3: Array pointers, output parameters, double-clicks
 * Part 1: Arrays, pointers, and clicks
 * 
 *    This program works as follows:
 *      - 1: When switch 1 is normal-clicked (less than 1 second) on the arduino board the elements of two arrays 
 *           are printed out by the serial monitor.
 *      - 2: When switch 1 is long-clicekd (between 1-3 seconds) the each element in the first array is given 
 *           a random value between 0-99 inclusive and then both arrays are printed out by the serial monitor.
 *      - 3: When switch 1 is very-long-cliked (more than 3 seconds) all the elements in teh first array are
 *           set to zero and both arrays are then printed out by the serial monitor.
 *      - 4: When switch 2 is normal-clicked (less than 1 second) the elements from the first array are copied
 *           into the second array and then printed out by the serial monitor.
 */

#include <ee108.h>

//-------------------------------------------------
// Global constants
//-------------------------------------------------
const int ONE_SECOND = 1000;
const int THREE_SECONDS = 3000;
const int LENGTH_OF_ARRAYS = 10;
const int RANDOM_RANGE = 100;

//-------------------------------------------------
// Function declarations
//-------------------------------------------------
void printArray(int *pA);
void randomiseArray(int *pA);
void zeroArray(int *pA);
void copyArrayValues(int *pA1, int *pA2);

//-------------------------------------------------
// Top level functions
//-------------------------------------------------
void setup() {

  // Set up serial monitor
  Serial.begin(9600);
  Serial.println("======== A3_ClickArrays Starting ========");
}

void loop() {

  // Local variables
  int sw1Event = readSwitchEvent(sw1Object);
  int sw2Event = readSwitchEvent(sw2Object);
  int clickDurationMs = 0;
  static unsigned long pressTimeMs;
  static int arr1 [LENGTH_OF_ARRAYS] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  static int arr2 [LENGTH_OF_ARRAYS] = {0};

  if (sw1Event == SW_ON_START){

    pressTimeMs = millis();
    
  } else if (sw1Event  == SW_CLICK || sw1Event == SW_CLICK_LONG){   // Checks if sw1 was clicked or long clicked.

    clickDurationMs = millis() - pressTimeMs;
    
    if (clickDurationMs < ONE_SECOND){    // Checks if sw1 was clicked for less than 1 second.

      Serial.println("Switch 1 Normal click:");
      printArray(arr1);
      printArray(arr2);
      Serial.println("-----------------------------------------");
      Serial.println();
      
    } else if (clickDurationMs > ONE_SECOND && clickDurationMs < THREE_SECONDS){  // Checks if sw1 was clicked for longer than 1 second but less than 3.

      Serial.println("Switch 1 Long click:");
      randomiseArray(arr1);
      printArray(arr1);
      printArray(arr2);
      Serial.println("-----------------------------------------");
      Serial.println();
      
    } else {    // If sw1 was not clicked for less than  1 second and not between 1 and 3 it must be more than 3 seconds.

      Serial.println("Switch 1 Very long click:");
      zeroArray(arr1);
      printArray(arr1);
      printArray(arr2);
      Serial.println("-----------------------------------------");
      Serial.println();
    }
  }

  if (sw2Event == SW_ON_START){

    pressTimeMs = millis();
    
  } else if (sw2Event  == SW_CLICK){  // Checks if sw2 was clicked.

    clickDurationMs = millis() - pressTimeMs;

    if (clickDurationMs < ONE_SECOND){  // Checks if the click duration was less than 1 second.

      Serial.println("Switch 2 Normal Click:");
      copyArrayValues(arr1, arr2);
      printArray(arr1);
      printArray(arr2);
      Serial.println("-----------------------------------------");
      Serial.println();
    }
  }
}

//-------------------------------------------------
// Helper Functions
//-------------------------------------------------

// This function prints out the contents of an array.
void printArray(int *pA){

  int *p = pA;
  Serial.print("{");
  Serial.print(*p);

  for (p = p+1; p < pA + LENGTH_OF_ARRAYS; p++){

    Serial.print(", ");
    Serial.print(*p);
  }

  Serial.println("}");
}

// This function randomises each element in an array with random values in a specified range.
void randomiseArray(int *pA){

  int *p = pA;
  for (p = pA; p < pA + LENGTH_OF_ARRAYS; p++){

    *p = random(RANDOM_RANGE);
  }
}

// This function sets all the elements in an array to zero.
void zeroArray(int *pA){

  int *p = pA;
  for (p = pA; p < pA + LENGTH_OF_ARRAYS; p++){

    *p = 0;
  }
}

// This function copies all the elements from array1 to array2.
void copyArrayValues(int *pA1, int *pA2){

  int *p1 = pA1;
  int *p2 = pA2;

  for (p1 = pA1; p1 < pA1 + LENGTH_OF_ARRAYS; p1++, p2++){
    
    *p2 = *p1;
  }
}
