/**
 * Name: Artur Karolewski
 * Student Number: 17388976
 * Part 1.2
 * 
 */

 #include <ee108.h>

const int BUTTON_POLL_MS = 50;

const int NUM_REPS = 10;
const int BETWEEN_REPS_MS = 500;

const int LED_ON_MS = 100;
const int LED_OFF_MS = 50;


void setup() {
  int ledNum;
  
  Serial.begin(9600);
  Serial.println("============== starting Lab3_BarLedScan_Starter ============");  

  // iterate over all Bar LED pins, enabling each one as an OUTPUT
  for (ledNum = 0; ledNum < NUM_BAR_LEDS; ledNum++)
    pinMode(BAR_LED_1_PIN + ledNum, OUTPUT);
}

void loop() {
  int sw1Event; // used when checking SW1
  int sw2Event; // used when checking SW2
  int count = 0;
  
  Serial.println("\nloop function starting -- click SW1 to begin");

  // wait until SW1 click (i.e. wait while sw1Event is not a click)
  
  do {
    delay(BUTTON_POLL_MS);
    sw1Event = readSwitchEvent(sw1Object);
  } while (sw1Event != SW_CLICK);

  if (sw1Event == SW_CLICK){
    Serial.println("Switch 1 has been clicked");
    do { 
      digitalWrite(BAR_LED_1_PIN, HIGH);
      delay(LED_ON_MS);
      digitalWrite(BAR_LED_1_PIN, LOW);

      sw2Event = readSwitchEvent(sw2Object);
      if ((sw2Event == SW_ON_START) || (sw2Event == SW_ON_CONTINUED)){
        Serial.println(count);
        continue;
      }
      
      Serial.println("Placeholder - bar LED scan would go here");
      delay(BETWEEN_REPS_MS);
      count++;
      Serial.println(count);
    } while (count < NUM_REPS);
  }

  Serial.println("all repetitions complete");
 
  Serial.println("loop function complete");  
}
