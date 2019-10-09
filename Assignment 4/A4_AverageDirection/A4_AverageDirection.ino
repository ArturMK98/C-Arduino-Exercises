/**
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Assignment 4: Strings and Advanced Types
 *  Part 1: Read characters from serial input
 *  
 *    This program works as follows:
 *      - 1: The program promts the user to type in direction characters ( i = north, k = south, j = west, l = east),
 *           the characters used can be lower or upper case.
 *      - 2: The user can also input other characters which will not be included in the buffer but will also be
 *           printed out to the screen by the serial monitor.
 *      - 3: When return is hit, the contents of the fifo buffer are printed out by the serial monitor.
 *      - 4: The resultant vector, direction, slope and compass direction area also calculated and printed out by
 *           the serial monitor.
 *      - 5: The user is then prompted to enter more directions which will be added to the fifo buffer that can
 *           hold up to 10 most recent direction vectors.
 */

#include <ee108.h>

//------------------------------------------------------------
// Constants
//------------------------------------------------------------
#define BUF_SIZE 10
const int SUPERLOOP_DELAY_MS = 50;

//------------------------------------------------------------
// Types
//------------------------------------------------------------
typedef struct CharRingBuffer {
  int capacity;   // Size of the data array
  int used;       // How many elements in the buffer are used
  int writeIndex; // The next char will be written to data[writeIndex]
  char *data;     // Pointer to the underlying array used by this ring buffer
} RingBuffer;

//------------------------------------------------------------
// Function Declarations
//------------------------------------------------------------
void printDirection(int x);
void printSlope(int x, int y, int slope);
void printCompass(int x, int slope);
void calculateRes(char c, int* pX, int* pY);
void charRingBufferInit(CharRingBuffer *buf, char *data, int capacity);
void charRingBufferAppend(CharRingBuffer *buf, char value);
void charRingBufferPrint(CharRingBuffer* buf);
char charRingBufferGetAt(CharRingBuffer *buf, int index);
int charRingBufferUsed(CharRingBuffer *buf);
int charRingBufferFree(CharRingBuffer *buf);
int claculateSlope(int x, int y);

//------------------------------------------------------------
// Top Level Functions
//------------------------------------------------------------
void setup() {

  Serial.begin(9600);
  Serial.println("====== A4_AverageDirection Starting =======");
}

void loop() {

  // Local variables
  static char backingBuf[BUF_SIZE];
  static CharRingBuffer ringBuffer = {0};
  static int x = 0;
  static int y = 0;
  boolean b = true;
  int slope;

  Serial.println("Type direction characters: J, K, L, or I (upper or lower case) and hit return\n");
  
  if (ringBuffer.data == NULL){

    charRingBufferInit(&ringBuffer, backingBuf, BUF_SIZE);
  }

  while (true){

    char c;

    // Wait until at least 1 character has been entered.
    while (Serial.available() == 0){
      
      continue;
    }
      c = Serial.read();

      if (b == true){

        Serial.print("Received: ");
        b = false;
      }
      
      Serial.print(c);

      if (c == 'j' || c == 'J' || c == 'i' || c == 'I' ||
          c == 'l' || c == 'L' || c == 'k' || c == 'K'){  // Checks if any of the characters entered are the
                                                          // direction characters, if yes, then add them to buffer.
            calculateRes(c, &x, &y);
            charRingBufferAppend(&ringBuffer, c);
      }

      if ((c == '\n') || (c == '\r') || (c ==  isspace(c))) {   // If return is hit or there is a space stop the loop.
         
        break;
      }
  }
  
  charRingBufferPrint(&ringBuffer);
  serialPrintf("resultant: x=%d, y=%d\n", x, y);
  printDirection(x);
  slope = calculateSlope(x, y);
  printSlope(x, y, slope);
  printCompass(x, slope);
  
  Serial.println("\n");
  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// Helper Functions
//------------------------------------------------------------

// This function updates the resultant vector each time the value of x or y is changed.
void calculateRes(char c, int* pX, int* pY){
  
  if (c == 'j' || c == 'J'){

    *pX -= 1;
    
  } else if (c == 'i' || c == 'I'){

    *pY += 1;
    
  } else if (c == 'l' || c == 'L'){

    *pX += 1;
    
  } else {

    *pY -= 1;
  }
}

// This function prints out the direction that the vector is pointing.
void printDirection(int x){

  if (x > 0){

    Serial.print("Direction: RHS, ");
    
  } else if (x < 0){

    Serial.print("Direction: LHS, ");
    
  } else {

    Serial.print("Direction: MIDDLE, ");
  }
}

// This function prints out the slope of the vector.
void printSlope(int x, int y, int slope){

  if (x == 0){

    Serial.print("1000*slope=infinite, ");
    
  } else {
    
    serialPrintf("1000*slope=%d, ", slope);
  }
}

// This function calculates the slope of the vector
int calculateSlope(int x, int y){

  return ((y/x) * 1000);
}

// This function prints out the compass direction of vector.
void printCompass(int x, int slope){

  if (x < 0 && slope < 0){

    Serial.print("compass=NorthWest");
    
  } else if ( x < 0 && slope > 0){

    Serial.print("compass=NorthEast");
    
  } else if (x > 0 && slope < 0){

    Serial.print("compass=SouthEast");
    
  } else {

    Serial.print("compass=NorthWest");
  }
}

// This function sets up the ring buffer.
void charRingBufferInit(CharRingBuffer *buf, char *data, int capacity) {
  
  buf->data = data;
  buf->capacity = capacity;
  buf->writeIndex = 0;
  buf->used = 0;
}

// This function adds elements to the ring buffer.
void charRingBufferAppend(CharRingBuffer *buf, char value) {
  buf->data[buf->writeIndex] = value;

  // advance writeIndex for next time
  buf->writeIndex = (buf->writeIndex + 1) % buf->capacity;  

  // if the buffer still has space, indicate that one more space has been used
  // (if no space, then we've just overwritten the oldest element)
  if (buf->used < buf->capacity)
    buf->used++;
}

// This fuunction prints out all the elements in the ring buffer.
void charRingBufferPrint(CharRingBuffer* buf) {
  
  // calculate readIndex
  int readIndex = (buf->capacity + buf->writeIndex - buf->used) % buf->capacity;
  int i;
  
  Serial.print("Buffer contents: ");
  for (i=0; i<buf->used; i++) {
    
    int dataIndex = (readIndex + i) % buf->capacity;
    Serial.print(charRingBufferGetAt(buf, i));
  }
  
  Serial.println();
}

// This function gets the char at an index in the ring buffer.
char charRingBufferGetAt(CharRingBuffer *buf, int index) {
  
  int dataIndex = (buf->capacity + buf->writeIndex - buf->used + index) % buf->capacity;
  return buf->data[dataIndex];
}
