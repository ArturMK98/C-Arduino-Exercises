/**
 * Student name: Artur Karolewski
 * Student number: 17388976
 * Question 2
 * 
 * This program blinks LED1 once then LED8 three times and finally LED3 twice
 * each time the loop function is called
 */

#include <ee108.h>

const int SHORT_ON_MS = 100;
const int SHORT_OFF_MS = 500;
const int MED_ON_MS = 500;
const int MED_OFF_MS = 700;
const int LONG_ON_MS = 1200;
const int LONG_OFF_MS = 600;

void setupBarLeds();
void blinkBarLedOnce(int x);
void blinkBarLedTwice(int y);
void blinkBarLedThreeTimes(int z);

void setup() {

  Serial.begin(9600);
  Serial.println("====== Lab4_BlinkFunctions starting ========");

  setupBarLeds();
}

void loop() {

  int led1Index = 0;
  int led3Index = 2;
  int led8Index = 7;
  static int loopCount = 0;
  
  Serial.print("Loop ");
  Serial.print(loopCount);
  Serial.println();

  Serial.println("  Blink BarLED1 on/off long pattern x1");
  blinkBarLedOnce(led1Index);

  Serial.println("  Blink BarLED8 on/off short pattern x3 times");
  blinkBarLedThreeTimes(led8Index);

  Serial.println("  Blink BarLED3 on/off medium pattern x2 times");
  blinkBarLedTwice(led3Index);

  loopCount++;
}

void setupBarLeds(){
  int ledIndex;

  // set up the LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // set up the Bar LEDs
  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++){

    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  }
}

void blinkBarLedOnce(int barLedIndex){

  digitalWrite(BAR_LED_1_PIN + barLedIndex, HIGH);
  delay(LONG_ON_MS);
  digitalWrite(BAR_LED_1_PIN + barLedIndex, LOW);
  delay(LONG_OFF_MS);
}

void blinkBarLedTwice(int barLedIndex){

  for (int i=0; i < 2; i++){
    
    digitalWrite(BAR_LED_1_PIN + barLedIndex, HIGH);
    delay(MED_ON_MS);
    digitalWrite(BAR_LED_1_PIN + barLedIndex, LOW);
    delay(MED_OFF_MS);
  }
}

void blinkBarLedThreeTimes(int barLedIndex){

  for (int i=0; i < 3; i++){

    digitalWrite(BAR_LED_1_PIN + barLedIndex, HIGH);
    delay(SHORT_ON_MS);
    digitalWrite(BAR_LED_1_PIN + barLedIndex, LOW);
    delay(SHORT_OFF_MS);
  }
}
