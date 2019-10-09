/**
 * Name: Artur Karolewski
 * Student Number: 17388976
 * Question 3: Cascaded if-statements 
 * 
 */

#include <ee108.h>

const int DELAY = 1000;
const int RANGE = 9;
void setup() {

  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

}

void loop() {

  static int loopCounter = 0; 

  if((loopCounter > 0 && loopCounter < 1) || (loopCounter > 8 && loopCounter < 9)){

    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    Serial.print(loopCounter);
    Serial.print(", Both LEDs off");
    Serial.println();
    loopCounter++;
    delay(DELAY);
    
  }if(loopCounter == 2 || loopCounter == 7){

    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    Serial.print(loopCounter);
    Serial.print(", LED 1 only");
    Serial.println();
    loopCounter++;
    delay(DELAY);
    
  }if(loopCounter == 3 || loopCounter == 6){

    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED1_PIN, LOW);
    Serial.print(loopCounter);
    Serial.print(", LED 2 only");
    Serial.println();
    loopCounter++;
    delay(DELAY);
    
  }if(loopCounter == 4 || loopCounter == 5){

    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    Serial.print(loopCounter);
    Serial.print(", Both LEDs on");
    Serial.println();
    loopCounter++;
    delay(DELAY);
    
  }else{

    loopCounter = (loopCounter + 1) % RANGE;
  }
delay(DELAY);
}
