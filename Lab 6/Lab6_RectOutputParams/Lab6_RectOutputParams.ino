/**  
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Lab 6: Scalar pointers and arrays
 *  Part 1: Function output parameters
 *  
 *    This program works as follows:
 *    - 1: The serial monitor prompts the user to press switch 1 on the Arduino UNO.
 *    - 2: Once switch 1 is pressed two random runbers between 0-99 incusive are generated,
 *         one for the width of the rectangle and the other for the length.
 *    - 3: The program then prints out the length, width, area and perimeter of the rectangle
 *         to the serial monitor.
 *    - 4: Area and perimeter of the rectangle are calculated with the use of pointers.
 */

#include <ee108.h>

// Global variables
const int RANDOM_RANGE = 100;   // Range of numbers for the random() function.
const int SUPERLOOP_MS = 20;

// Function declerations
void rectangle(int length, int width, int &area, int &perimeter);
void printInfo(int length, int width, int area, int perimeter);

// Top level functions
void setup() {

  Serial.begin(9600);
  Serial.println("========= Lab6_RectOutputParams starting ===========");
  Serial.println("Press SW1 to start...");
  Serial.println();
}

void loop() {

  int sw1Event = readSwitchEvent(sw1Object);
  int length;
  int width;
  int area;
  int perimeter;

  if (sw1Event == SW_CLICK){    // Checks to see if switch 1 has been clicked.

    length = random(RANDOM_RANGE);    // Generates radom value for length between 0-99 incusive.
    width = random(RANDOM_RANGE);     // Generates random value for width between 0-99 inclusive.

    rectangle(length, width, &area, &perimeter);    // parameters are passed to the rectangle() function.
    printInfo(length, width, area, perimeter);      // Parameters are passed to the printInfo() function.
  }

  delay(SUPERLOOP_MS);
}

// Helper functions
void rectangle(int l, int w, int* pArea, int* pPerimeter){    // Calculates the area and perimeter of rectangle using given values.

  *pArea = l * w;
  *pPerimeter = ((l * 2) + (w * 2));
}

void printInfo(int length, int width, int area, int perimeter){   // Prints the information about rectangle to the serial monitor.

  Serial.print("Rectangle: ");
  Serial.print("length ");
  Serial.print(length);
  Serial.print(", ");
  Serial.print("width ");
  Serial.print(width);
  Serial.print( " => ");
  Serial.print("area ");
  Serial.print(area);
  Serial.print(", ");
  Serial.print("perimeter ");
  Serial.println(perimeter);
  Serial.println();
  Serial.println("Press SW1 to do another rectangle");
  Serial.println("==========");
}
