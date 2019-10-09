/**
 *  Name: Artur Karolewski
 *  Student Number: 17388976
 *  Question 3: Adding a library and modifying the Blink programme
 */

#include <ee108.h>

const int PIN_IN_USE = BAR_LED_5_PIN;  // the pin to use
const int ON_TIME_MS = 0;   // the on-time in ms during each blink
const int OFF_TIME_MS = 20; // the off-time in ms during each blink
const int LED_MS = 100;     // microseconds part of LED

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_IN_USE, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ON_TIME_MS);                // wait for a second
  delayMicroseconds(LED_MS);
  digitalWrite(PIN_IN_USE, LOW);    // turn the LED off by making the voltage LOW
  delay(OFF_TIME_MS);               // wait for a second
}
