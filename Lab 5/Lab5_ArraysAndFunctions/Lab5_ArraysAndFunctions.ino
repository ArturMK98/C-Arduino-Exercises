/**   
 *    Student name: Artur Karolewski
 *    Student number: 17388976
 *    Question 2
 *    
 *    This program works as follows:
 *   - 1: An array of size 8 is initially filled with all zeroes.
 *   - 2: If switch 1 is pressed then the elements in the array are
 *        printed out to the screen.
 *   - 3: If the switch is long clicked then each element in the array 
 *        is filled with random integers from the specified range and 
 *        also printed out to the screen.
 */

 #include <ee108.h>

// Global variables
#define arraySize 8

// Function declerations
void printArray(int arr[], int arrayLength);
void fillArray(int arr[], int arrayLength);

// Top level functions
void setup() {

  Serial.begin(9600);
  Serial.println("Lab5_BasicArrays Starting...");
  
}

void loop() {
  
  int sw1Event = readSwitchEvent(sw1Object);
  static int arr[arraySize];
  static int arrayLength = (sizeof(arr)/sizeof(arr[0]));
  unsigned int randomRange = 100;

  if (sw1Event == SW_CLICK){     // Checks to see if switch 1 has been clicked
                                // if clicked the array is printed out
    Serial.print("[Click] ");
    Serial.print("array is ");
    printArray(arr, arrayLength);
  }

  if (sw1Event == SW_CLICK_LONG){      // Checks to see if switch 1 has been long clicked
                                      // if long clicked then the array is filled with
    Serial.print("[LongClick] ");     // random integers from a specified range and then printed out
    Serial.print("modified array ");
    fillArray(arr, arrayLength, randomRange);
    
  }
}

// Helper functions
void fillArray(int arr[], int arrayLength, int range){   // Fills the array with random numbers within a
                                                        // specified range and then calls the printArray function.
  for (int i = 0; i < arrayLength; i++){

    arr[i] = random(range);
  }

  printArray(arr, arrayLength);
}

void printArray(int arr[], int arrayLength){    // Prints out the elements in the array.

  Serial.print("{ ");
  for (int i = 0; i < arrayLength; i++){

    if (i == (arrayLength -1)){

      Serial.print(arr[i]);   // Prints last element in array without a comma after
      break;
    }

    Serial.print(arr[i]);
    Serial.print(", ");
  }
  
  Serial.println(" }");
}
