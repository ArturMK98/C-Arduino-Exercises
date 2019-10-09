/**
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Lab 7 Part 2: More Array Pointers
 *  
 *    This program works as follows:
 *    - 1: When switch 1 is pressed a random index in the array is selected.
 *    - 2: The number of the number at that index is then incremented by 1.
 *    - 3: The array before and after the increment is printed out.
 *    - 4: The array keeps its modified value after each loop.
 * 
 */

#include <ee108.h>

//------------------------------------------------------------
// constants
//------------------------------------------------------------

#define ARRAY_LENGTH  10

//------------------------------------------------------------
// function declarations
//------------------------------------------------------------

void updateElement(int *p);
void printArray(int arr[]);

//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {

  // Set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab7_UpdateArrayPointerArithmetic...\n");
  Serial.println("\nClick SW1 to start\n"); 
}

void loop() {

  static int numbers[ARRAY_LENGTH] = { 100, 110, 120, 130, 140, 150, 160, 170, 180, 190 };
  int *pA;

  // Checks if switch 1 is clicked
  if (readSwitchEvent(sw1Object) == SW_CLICK){

    Serial.println("Initial data array contents: ");
    printArray(numbers);

    int i = random(0, (ARRAY_LENGTH -2));
    serialPrintf("Chosen offset into array was %d\n", i);
    pA = numbers + i;
    updateElement(pA);

    Serial.println("Modified data array contents: ");
    printArray(numbers);
    
  }
  
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------

// Increments teh value of what is pointed at by the pointer by 1
void updateElement(int *pA){
 
  *pA += 1;
}

// Prints the contents of the array
void printArray(int arr[]){

  Serial.print("{ ");
  Serial.print(arr[0]);

  for(int i = 1; i < ARRAY_LENGTH; i++){

    Serial.print(", ");
    Serial.print(arr[i]);
  }

  Serial.println(" }");
}
