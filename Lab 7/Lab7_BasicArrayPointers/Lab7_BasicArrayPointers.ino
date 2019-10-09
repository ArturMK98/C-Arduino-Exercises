/** 
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Lab 7 Part 1: Basic Array Pointers
 *  
 *    This program works as follows:
 *      - 1: When switch 1 is pressed on the Arduino board an array of size 6 is
 *           filled with random numbers between 0-99 inclusive.
 *      - 2: The Array is then printed out to the screen.
 *      - 3: A slice of the array with the values at index 1-3 is then printed out.
 *      - 4: If switch 1 is pressed again anotehr array of random numbers is generated
 *           and printed out.
 */

#include <ee108.h>

//------------------------------------------------------------
// constants
//------------------------------------------------------------

#define DATA_LEN  6

const int SUPERLOOP_DELAY_MS = 50;

//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

void randomizeArray(int array[], int len, int minVal, int maxVal);
void printArray(const int array[], int len);


//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab7_BasicArrayPointers starting...\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() {
  // note: we don't need to remember the element values in this
  // array from one execution of the loop function to the next
  int data[DATA_LEN] = { 0 }; // initialize array to all zeros
  long result;
  int index;


  if (readSwitchEvent(sw1Object) == SW_CLICK) { // was there a click?
  
    randomizeArray(data, DATA_LEN, 0, 99);
  
    Serial.println("  Array has been filled with random values");
    printArray(data, DATA_LEN);

    Serial.println("  Array slice 1..3");
    printArray(data +1, 3);

    Serial.println("\nClick SW1 to restart\n");
  }
  
  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------

/**
 * fill the array with random values
 *
 * @param array   the array to fill (an input/output parameter)
 * @param len     the lenght of the array
 * @param minVal  the minimum random value to fill with (inclusive)
 * @param maxVal  the maximum random value to fill with (inclusive)
 */
void randomizeArray(int array[], int len, int minVal, int maxVal) {
   
  int *pA;
  
  for (pA = array; pA < array + len; pA++){

    *pA = random(minVal, maxVal + 1);
  }
}

  

/**
 * pretty-print the contents of an array surrounded by braces
 *
 * @param array   the array to print (read only, so const)
 * @param len     the length of the array
 */
void printArray(const int array[], int len) {

  int *pA;
  
  Serial.print("  printArray { ");
  
  Serial.print(array[0]);

  for (pA = array+1; pA < array + len; pA++) {
    Serial.print(", ");
    Serial.print(*pA);
  }
  Serial.println(" }");
}
