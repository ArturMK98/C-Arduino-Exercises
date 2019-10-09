/**
 *  Student name: Artur Karolewski
 *  Student Number: 17388976
 *  Lab 8: Strings and Advanced Types
 *  Part 1: Basic Struct
 *  
 *    This program works as follows:
 *      - 1: When switch 1 is pressed the points of x1, y1, x2, y2 and slope are printed
 *           out by the serial monitor.
 *      - 2: When switch 1 is long clicked values of x2 and y2 are changed and new values
 *           are printed out to the screen.
 */

#include <ee108.h>

//------------------------------------------------------------
// types
//------------------------------------------------------------

// a structure to represent a 2d point in cartesian coordinates
typedef struct Point2d {
  int x;
  int y;
} Point2d;

//------------------------------------------------------------
// constants
//------------------------------------------------------------

const int SUPERLOOP_DELAY_MS = 50;

//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

float calculateSlope(int x1, int y1, int x2, int y2);
void printInfo(int x1, int y1, int x2, int y2, float slope);
int randomise();



//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab8_StructLineSlope Starter starting...\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() {
  int sw1Event;

  static Point2d point1;
  static Point2d point2;

  point1.x = 1500;
  point1.y = 500;

  sw1Event = readSwitchEvent(sw1Object);

  if (sw1Event == SW_CLICK) { // wait for click

    float slope = calculateSlope(point1.x, point1.y, point2.x, point2.y);
    Serial.print("[SW1 Click] ");
    printInfo(point1.x, point1.y, point2.x, point2.y, slope);

    Serial.println();
  } else if (sw1Event == SW_CLICK_LONG) {
    Serial.print("[SW1 Long Click] ");

    point2.x = randomise();
    point2.y = randomise();
    serialPrintf("new point2 {x=%d, y=%d}\n", point2.x, point2.y);
    Serial.println();
  }
  
  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------
float calculateSlope(int x1, int y1, int x2, int y2){

  float slope = (float)(y2 - y1)/(float)(x2 - x1);
  if (slope == 0){

    return 99999.99;
    
  } else {

    return slope;
  }
}

int randomise(){

  return random(-9999, 9999);
}

void printInfo(int x1, int y1, int x2, int y2, float slope){

  serialPrintf("point1 {x=%d, y=%d}, point2 {x=%d, y=%d}, slope=", x1, y1, x2, y2);
  Serial.println(slope);
}
