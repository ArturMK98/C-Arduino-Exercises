/**
 *  Student Name: Artur Karolewski
 *  Studnent Number: 17389876
 *  Lab 6: Scalar pointers and arrays
 *  Part 2: In-out optional output parameters
 *  
 *    This program works as follows:
 *    - 1: Prints out values read by the LDR to the serial monitor
 *    - 2: Prints out FIFO average
 **/

#include <ee108.h>
#include <limits.h>

const int SAMPLE_MS = 250;
const int ANALOG_PIN = LDR_PIN;

int MIN_VAL = INT_MAX;
int MAX_VAL = INT_MIN;

const int NUM_SAMPLES = 8;
const int FIFO_LEN = 4;

int sampleAnalogIn(int pin, int &minVal, int &maxVal); // TODO - will need to be modified
int addToFifoAndAverage(int pin, int &AVERAGE);

void setup() {
  Serial.begin(9600);
  Serial.println("========= Lab6_OptionalInOut starting ===========");
}

void loop() {
  int i;

  Serial.println("-----------");

  Serial.println("sample with optional params...");
  for (i = 0; i < NUM_SAMPLES; i++) {
    int value = sampleAnalogIn(ANALOG_PIN, &MIN_VAL, &MAX_VAL); // TODO - will need to be modified
    int average = addToFifoAndAverage(ANALOG_PIN);
    
    Serial.print("Sample ");
    Serial.print(i+1);
    Serial.print(", value=");
    Serial.print(value);
    Serial.print(", min=");
    Serial.print(MIN_VAL);
    Serial.print(", max=");
    Serial.print(MAX_VAL);
    Serial.print(", Fifo average = ");
    Serial.println(average);
    
    delay(SAMPLE_MS);  
  }
  
  Serial.println("sample with no optional params...");
  
  for (i = 0; i < NUM_SAMPLES; i++) {
  
    int value = sampleAnalogIn(ANALOG_PIN, &MIN_VAL, &MAX_VAL); // TODO - will need to be modified
    
    Serial.print("Sample ");
    Serial.print(i+1);
    Serial.print(", value=");
    Serial.println(value);

    delay(SAMPLE_MS);
  }
  
  delay(8000);
}

int sampleAnalogIn(int pin, int* pMinVal, int* pMaxVal) {
  int value = analogRead(pin);

  if(value < MIN_VAL){

    *pMinVal = value;
    
  }
  
  if (value > MAX_VAL){

    *pMaxVal = value;
  }
  
  return value;
}

int addToFifoAndAverage(int pin){

  int fifoArr[FIFO_LEN] = {0};
  int average = 0;

  for(int i = 0; i < FIFO_LEN; i++){

    fifoArr[i] = analogRead(pin);
    average += fifoArr[i];
  }

  return average / FIFO_LEN;
}
