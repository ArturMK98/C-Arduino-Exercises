/**
 * Name: Artur Karolewski
 * Student Number: 17388976
 * Question 1: Nested if-statements
 * 
 */

#include <ee108.h>

const unsigned int NUMBER_OF_TICKS = 15;
const unsigned int DELAY_LOOP_MS = 100;

void setup() {
  //initiating pins
  pinMode(LED1_PIN, OUTPUT); 
  pinMode(LED2_PIN, OUTPUT);
  pinMode(SW1_PIN, INPUT);
}

void loop() {

  static unsigned int ticks;  //this variable will keep count of the ticks after button is pressed
  
  if (digitalRead(SW1_PIN) == SW_ACTIVE){ //runs if switch 1 is pressed

    ticks++;

     digitalWrite(LED1_PIN, HIGH);    //switches on led1 (red)

    if (ticks >= NUMBER_OF_TICKS){

      digitalWrite(LED2_PIN, HIGH);   //switches on led2 (green) after 1.5 seconds
    }
    
  }
  else{

    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    ticks = 0;
  }
  
delay(DELAY_LOOP_MS);   //delays loop by 100ms
}
